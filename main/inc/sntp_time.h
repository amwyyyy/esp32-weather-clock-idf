#ifndef _sntp_h_
#define _sntp_h_

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int week;
} date_time_t;

/**
 * @brief 初始化 sntp
 *
 */
esp_err_t sntp_time_init(void);

/**
 * @brief 获取当前时间
 */
date_time_t get_now_time(void);

/**
 * @brief 获取星期的字符串
 * 
 */
char * get_week_text(int week);

#endif