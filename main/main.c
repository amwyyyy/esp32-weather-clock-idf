/* LVGL Example project
 *
 * Basic project to test LVGL on ESP32 based projects.
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esp_wifi_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/portmacro.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "lv_misc/lv_color.h"
#include "nvs_flash.h"

#include "event.h"
#include "storage.h"
#include "pwm.h"
#include "gui.h"
#include "wifi.h"
#include "sntp_time.h"
#include "weather.h"
#include "smart_config.h"

#define TAG "main"

#define BTN_GPIO 0

static uint32_t is_init = 1;
xQueueHandle basic_evt_queue;

static void event_handle(void *pvParameter);
static void update_data_task(void *pvParameter);
static void backlight_upgrade(void *pvParameter);
static char * city_code();

/**
 * @brief 开机自动连接wifi
 *
 */
void connect_wifi() {
    char get_ssid[32];
    char get_pwd[64];

    if (get_wifi_info(get_ssid, get_pwd) == ESP_OK) {
        ESP_LOGI(TAG, "ssid 配置有效 进行开机自动连接 wifi ssid: %s pwd: %s", get_ssid, get_pwd);
        wifi_init_sta(get_ssid, get_pwd);
    } else {
        ESP_LOGI(TAG, "ssid 配置无效，开始自动配网。");
        start_smart_config();

        vTaskDelay(1000 * 5 / portTICK_PERIOD_MS);
        // 显示配置界面
        display(DISP_SMART_CONFIG);
    }
}

/**
 * @brief 定时更新数据
 * 
 * @param pvParameter 
 */
static void update_data_task(void *pvParameter) {
    while (1) {
        vTaskDelay(1000 * 60 * 60 / portTICK_PERIOD_MS);

        char * code = city_code();
        weather_t wea = weather_init(code);
        set_weather_info(wea);
        free(code);
    }
}

static void mem_monitor(void *pvParameter) {
    while (1) {
        ESP_LOGI(TAG, "[APP] Free internal memory: %d", esp_get_free_internal_heap_size());
        ESP_LOGI(TAG, "[APP] Free all memory: %d", esp_get_free_heap_size());
        ESP_LOGI(TAG, "[APP] Min free memory: %d", esp_get_minimum_free_heap_size());

        vTaskDelay(1000 * 60 / portTICK_PERIOD_MS);
    }
}

/**
 * @brief 自动背光调节
 *  
 */
static void backlight_upgrade(void *pvParameter) {
    while (1) {
        date_time_t dt = get_now_time();
        if (dt.hour >= 0 && dt.hour < 7) {
            set_bl_pwm(0);
        } else if (dt.hour >=7 && dt.hour < 15) {
            set_bl_pwm(7);
        } else if (dt.hour >= 15 && dt.hour < 22) {
            set_bl_pwm(5);
        } else {
            set_bl_pwm(3);
        }
        vTaskDelay(1000 * 60 * 60 / portTICK_PERIOD_MS);
    }
}

static char * city_code() {
    char ct_code[16];
    if (get_city_code(ct_code) != ESP_OK) {
        char ct_name[32];
        if (get_city_name(ct_name) == ESP_OK) {
            char * tmp_ct_code = query_city_code(ct_name);
            strcpy(ct_code, tmp_ct_code);
        } else {
            char * tmp_ct_code = query_city_code_by_ip();
            strcpy(ct_code, tmp_ct_code);
        }
        set_city_code(ct_code);
    }

    ESP_LOGI(TAG, "city_code: %s", ct_code);
    char * code = malloc(sizeof(char) * strlen(ct_code));
    strcpy(code, ct_code);
    return code;
}

static void event_handle(void *pvParameter) {
    uint32_t event_flag;

    while (1) {
        if (xQueueReceive(basic_evt_queue, &event_flag, portMAX_DELAY)) {
            switch (event_flag)
            {
            case EVENT_WIFI_STA_CONNECTED:
                set_wifi_status(1);

                if (is_init) {
                    set_loading_text("Sntp init...");
                    sntp_time_init();

                    set_loading_text("Weather init...");
                    weather_t wea = weather_init(city_code());
                    set_weather_info(wea);
                }

                break;
            case EVENT_SNTP_INIT:
                set_loading_text("Success!");
                vTaskDelay(500 / portTICK_PERIOD_MS);

                // 显示天气时间界面
                display(DISP_CLOCK);

                // 初始化完成修改标志位
                is_init = 0;

                // 启动更新数据任务
                xTaskCreate(update_data_task, "update", 1024 * 10, NULL, 1, NULL);
                
                // 设置背光
                xTaskCreate(backlight_upgrade, "bl", 1024 * 4, NULL, 3, NULL);

                break;
            case EVENT_WIFI_STA_FAILURE:
                if (is_init) {
                    set_loading_text("Wifi error...");
                }
                vTaskDelay(1000 / portTICK_PERIOD_MS);

                ESP_LOGI(TAG, "Wifi connect error restart.");
                ESP_ERROR_CHECK(nvs_flash_erase());
                esp_restart();
                break;
            case EVENT_WIFI_STA_DISCONNECTED:
                set_wifi_status(0);
                break;
            case EVENT_SINT_FAILURE:
                set_loading_text("Sntp error...");
                vTaskDelay(1000 / portTICK_PERIOD_MS);

                ESP_LOGI(TAG, "Sntp sync error restart.");
                esp_restart();
                break;
            default:
                break;
            }
        }

        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
}

static void btn_event(void *pvParameter) {
    uint8_t flag = 0;
    while (1) {
        int button_state = gpio_get_level(BTN_GPIO);
	    if (button_state == 0 && flag == 0) {
            flag = 1;

            uint32_t value;
            get_setting_bl(&value);
            set_bl_pwm((value + 1) % 11);
	    } else if (button_state == 1) {
            flag = 0;
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void btn_init() {
    gpio_reset_pin(BTN_GPIO);
    gpio_set_direction(BTN_GPIO, GPIO_MODE_INPUT);

    xTaskCreate(btn_event, "btn_event", 1024 * 2, NULL, 1, NULL);
}

void app_main() {
    basic_evt_queue = xQueueCreate(10, sizeof(uint32_t));

    btn_init();

    storage_init();

    pwm_init();

    gui_init();

    xTaskCreate(event_handle, "event", 1024 * 16, NULL, 1, NULL);

    connect_wifi();

    // xTaskCreate(mem_monitor, "mem_monitor", 1024 * 4, NULL, 1, NULL);

    ESP_LOGI(TAG, "[APP] Idf version: %s", esp_get_idf_version());
}