#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"

#include "esp_heap_caps.h"
#include "esp_spi_flash.h"
#include "esp_system.h"

#include "esp_log.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "esp_wifi_types.h"
#include "storage.h"

static nvs_handle_t storage_handle;

static const char *TAG = "storage";

esp_err_t get_wifi_info(char *ssid, char *passwd) {
    char ssid_tmp[32] = {0};
    char passwd_tmp[64] = {0};
    
    size_t len = sizeof(ssid_tmp);
    esp_err_t result = nvs_get_blob(storage_handle, "_ssid", ssid_tmp, &len);
    if (result != ESP_OK) {
        ESP_LOGE(TAG, "This auth is not WIFI_AUTH_OPEN!");
        return result;
    } else {
        ESP_LOGI(TAG, "SSID=%.*s;len=%d;", len, ssid_tmp, len);
        for (size_t i = 0; i < len; i++) {
            ssid[i] = ssid_tmp[i];
        }
    }        

    len = sizeof(passwd_tmp);
    result = nvs_get_blob(storage_handle, "_passwd", passwd_tmp, &len);
    if (result != ESP_OK) {
        ESP_LOGE(TAG, "This auth is not WIFI_AUTH_OPEN!");
        ESP_LOGE(TAG, "But the password acquisition failed!");
        return result;
    } else {
        ESP_LOGI(TAG, "PASSWD=%.*s;len=%d;", len, passwd_tmp, len);

        for (size_t i = 0; i < len; i++) {
            passwd[i] = passwd_tmp[i];
        }
    }

    return ESP_OK;
}

esp_err_t set_wifi_info(char ssid[32], char passwd[64]) {
    ESP_LOGI(TAG, "设置WIFI信息到 NVS");
    esp_err_t result = 0;
    if (ssid != NULL) {
        ESP_LOGI(TAG, "set ssid: %s", ssid);
        ESP_ERROR_CHECK(nvs_set_blob(storage_handle, "_ssid", ssid, 32));
    }
    
    if (passwd != NULL) {
        ESP_LOGI(TAG, "set passwd: %s", passwd);
        ESP_ERROR_CHECK(nvs_set_blob(storage_handle, "_passwd", passwd, 64));
    }

    return result;
}

esp_err_t get_setting_bl(uint32_t *value) {
    esp_err_t err = nvs_get_u32(storage_handle, "_bl", value);
    switch (err) {
        case ESP_OK:
            ESP_LOGI(TAG, "读取背光信息(%d)", *value);
            break;
        case ESP_ERR_NVS_NOT_FOUND:
            ESP_LOGW(TAG, "背光配置未初始化!");
            break;
        default :
            ESP_LOGE(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
    }
    return err;
}

esp_err_t set_setting_bl(uint32_t value) {
    ESP_LOGI(TAG, "设置背光信息(%d)", value);

    esp_err_t err = nvs_set_u32(storage_handle, "_bl", value);
    if (err != ESP_OK) {
        ESP_LOGW(TAG, "set bl failed! Error (%s)", esp_err_to_name(err));
    }
    return err;
}

esp_err_t get_city_name(char *city_name) {
    char city_name_tmp[32] = {0};
    size_t len = sizeof(city_name_tmp);

    esp_err_t err = nvs_get_blob(storage_handle, "_ct_name", city_name_tmp, &len);

    switch (err) {
        case ESP_OK:
            ESP_LOGI(TAG, "city_name=%.*s;len=%d;", len, city_name_tmp, len);
            if (strlen(city_name_tmp) == 0) {
                return ESP_ERR_NVS_NOT_FOUND;
            }

            for (size_t i = 0; i < len; i++) {
                city_name[i] = city_name_tmp[i];
            }
            break;
        default :
            ESP_LOGE(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
    }
    return err;
}

esp_err_t set_city_name(char city_name[32]) {
    ESP_LOGI(TAG, "设置城市名称(%s)", city_name);

    if (city_name != NULL) {
        ESP_ERROR_CHECK(nvs_set_blob(storage_handle, "_ct_name", city_name, 32));
    }
 
    return 0;
}

esp_err_t get_city_code(char *city_code) {
    char city_code_tmp[16] = {0};
    size_t len = sizeof(city_code_tmp);

    esp_err_t err = nvs_get_blob(storage_handle, "_ct_code", city_code_tmp, &len);

    switch (err) {
        case ESP_OK:
            ESP_LOGI(TAG, "city_code=%.*s;len=%d;", len, city_code_tmp, len);
            for (size_t i = 0; i < len; i++) {
                city_code[i] = city_code_tmp[i];
            }
            break;
        default :
            ESP_LOGE(TAG, "Error (%s) reading!\n", esp_err_to_name(err));
    }
    return err;
}

esp_err_t set_city_code(char city_code[16]) {
    ESP_LOGI(TAG, "设置城市编码(%s)", city_code);

    if (city_code != NULL) {
        ESP_ERROR_CHECK(nvs_set_blob(storage_handle, "_ct_code", city_code, 16));
    }
 
    return 0;
}

esp_err_t storage_init(void) {
    // Initialize NVS
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        // Retry nvs_flash_init
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK( err );

    err = nvs_open("storage_tv", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error (%s) opening NVS handle!", esp_err_to_name(err));
        return err;
    }
    return ESP_OK;
}