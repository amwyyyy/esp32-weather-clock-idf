#ifndef _gui_h_
#define _gui_h_

#include "weather.h"

typedef enum {
    DISP_LOADING = 0,
    DISP_CLOCK,
    DISP_SMART_CONFIG,

} display_type_t;

/**
 * @brief 初始化 lvgl
 *
 */
void gui_init(void);

/**
 * @brief 设置 loading 的显示文字
 * 
 * @param text 
 */
void set_loading_text(const char * text);

/**
 * @brief 设置天气信息
 * 
 * @param wea 
 */
void set_weather_info(weather_t wea);

/**
 * @brief 设置显示类型
 * 
 * @param type 
 */
void display(display_type_t type);

/**
 * @brief 设置 wifi 图标
 * 
 */
void set_wifi_status(uint32_t status);

#endif