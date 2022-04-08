#ifndef _weather_h_
#define _weather_h_

typedef struct {
    char * weather[5];
    char * temp;
    char * sd;
    char * weathercode;
    char * weathercoden;
    char * city;
    uint32_t aqi;
} weather_t;

/**
 * @brief 初始化天气信息
 *
 */
weather_t weather_init(char * city_code);

/**
 * @brief 根据城市名称查询城市编码
 * 
 * @param city_name 城市名称
 * @return char* 城市编码
 */
char * query_city_code(char * city_name);

/**
 * @brief 根据 ip 获取城市编码
 * 
 * @return char* 
 */
char * query_city_code_by_ip();

/**
 * @brief 获取空气质量等级
 * 
 */
void get_aqi_level(uint32_t aqi, char * aqi_level, uint32_t * bg_color);

#endif