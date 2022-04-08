#include <stdio.h>

#include "esp_err.h"
#include "esp_log.h"
#include "esp_sntp.h"
#include "freertos/event_groups.h"

#include "sntp_time.h"
#include "event.h"

#define TAG "sntp"

extern xQueueHandle basic_evt_queue;

esp_err_t sntp_time_init(void) {
    ESP_LOGI(TAG, "Initializing SNTP");
	sntp_setoperatingmode(SNTP_OPMODE_POLL);  
	sntp_setservername(0, "ntp.aliyun.com"); 
    sntp_setservername(1, "ntp1.aliyun.com"); 
	sntp_init();

    // 设置时区
    setenv("TZ", "CST-8", 1);
	tzset();

    time_t now = 0;
    struct tm timeinfo = {0};

    int s_retry_num = 0;

    do {
        if (s_retry_num++ >= 20) {
            uint32_t event_flag = EVENT_SINT_FAILURE;
            xQueueSend(basic_evt_queue, &event_flag, NULL);

            return ESP_ERR_TIMEOUT;
        }
        time(&now);
        localtime_r(&now, &timeinfo);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    } while (timeinfo.tm_year < 100);

    ESP_LOGI(TAG, "Finish SNTP init.");

    uint32_t event_flag = EVENT_SNTP_INIT;
    xQueueSend(basic_evt_queue, &event_flag, NULL);

    return ESP_OK;
}

char * get_week_text(int week) {
    switch (week) {
    case 0:return "周日";break;
    case 1:return "周一";break;
    case 2:return "周二";break;
    case 3:return "周三";break;
    case 4:return "周四";break;
    case 5:return "周五";break;
    case 6:return "周六";break;
    default:return "";break;
    }
}

date_time_t get_now_time(void) {
    time_t now = 0;
    struct tm timeinfo = {0};
    date_time_t dt;

    time(&now);
    localtime_r(&now, &timeinfo);

    dt.year   = timeinfo.tm_year + 1900;
    dt.month  = timeinfo.tm_mon + 1;
    dt.day    = timeinfo.tm_mday;
    dt.hour   = timeinfo.tm_hour;
    dt.minute = timeinfo.tm_min;
    dt.second = timeinfo.tm_sec;
    dt.week   = timeinfo.tm_wday;

    ESP_LOGD(TAG, "current time: %d-%d-%d %d:%d:%d",
			 dt.year, dt.month,
			 dt.day, dt.hour,
			 dt.minute, dt.second); 

    return dt;       
}