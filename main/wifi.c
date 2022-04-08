#include <stdio.h>
#include <string.h>

#include "sdkconfig.h"
#include "esp_heap_caps.h"
#include "esp_spi_flash.h"
#include "esp_system.h"

#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_spiffs.h"
#include "wifi.h"
#include "esp_wifi_types.h"
#include <esp_wifi.h>
#include "esp_wifi_types.h"
#include "freertos/event_groups.h"
#include "event.h"

/* The event group allows multiple bits for each event, but we only care about two events:
 * - we are connected to the AP with an IP
 * - we failed to connect after the maximum amount of retries */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1

extern xQueueHandle basic_evt_queue;

static EventGroupHandle_t s_wifi_event_group;
static const char *TAG = "wifi_init";

static void wifi_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    uint32_t wifi_sta_flag;
    static int s_retry_num = 0;

    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        /*
         *   发送连接开始
         */
        wifi_sta_flag = EVENT_WIFI_STA_START;
        xQueueSend(basic_evt_queue, &wifi_sta_flag, NULL);
        
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        wifi_sta_flag = EVENT_WIFI_STA_DISCONNECTED;
        xQueueSend(basic_evt_queue, &wifi_sta_flag, NULL);

        if (s_retry_num < 10) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);

            /*
             *   发送连接失败
             */
            wifi_sta_flag = EVENT_WIFI_STA_FAILURE;
            xQueueSend(basic_evt_queue, &wifi_sta_flag, NULL);
        }
        vTaskDelay(1000 * 30 / portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "connect to the AP fail");
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);

        /*
         *   发送已连接
         */
        wifi_sta_flag = EVENT_WIFI_STA_CONNECTED;
        xQueueSend(basic_evt_queue, &wifi_sta_flag, NULL);
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_LOST_IP) {
        ESP_LOGI(TAG, "lost ip!");

        wifi_sta_flag = EVENT_WIFI_STA_DISCONNECTED;
        xQueueSend(basic_evt_queue, &wifi_sta_flag, NULL);
    } else {
        ESP_LOGI(TAG, "event: %s, %d", event_base, event_id);
    }
}

void wifi_init_sta(char *ssid, char *pass) {
    ESP_LOGI(TAG, "Init WiFi...");
    ESP_ERROR_CHECK(esp_netif_init());  // 初始化网络接口

    s_wifi_event_group = xEventGroupCreate();   // 创建WIFI连接事件组
    ESP_ERROR_CHECK(esp_event_loop_create_default());   // 默认事件循环

    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    // 注册 WiFi 事件
    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL));
	ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifi_event_handler, NULL));
	ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_LOST_IP, &wifi_event_handler, NULL));

    wifi_config_t wifi_config;
    bzero(&wifi_config, sizeof(wifi_config_t));
    memcpy(wifi_config.sta.ssid, ssid, sizeof(wifi_config.sta.ssid));
    memcpy(wifi_config.sta.password, pass, sizeof(wifi_config.sta.password));
    ESP_LOGI(TAG, "WiFi ssid: %s\tpasswd: %s", ssid, pass);

    // 设置 WiFi 运行模式为: STA
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    // 设置 WiFi 连接参数
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    // 启动 WiFi
    ESP_ERROR_CHECK(esp_wifi_start());
    // 设置 WiFi 省电模式
    ESP_ERROR_CHECK(esp_wifi_set_ps(WIFI_PS_MAX_MODEM));

    ESP_LOGI(TAG, "Init WiFi end.");

    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
     * number of re-tries (WIFI_FAIL_BIT). The bits are set by event_handler() (see above) */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
                                           WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                           pdFALSE,
                                           pdFALSE,
                                           portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
     * happened. */
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s", ssid, pass);
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s", ssid, pass);
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }

    // ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifi_event_handler));
    // ESP_ERROR_CHECK(esp_event_handler_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler));
    // vEventGroupDelete(s_wifi_event_group);
}