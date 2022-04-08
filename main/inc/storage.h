#ifndef _storage_h_
#define _storage_h_

/**
 * @brief wifi信息相关存储操作
 *
 * @param ssid
 * @param passwd
 * @return esp_err_t
 */
esp_err_t get_wifi_info(char *ssid, char *passwd);
esp_err_t set_wifi_info(char ssid[32], char passwd[64]);

/**
 * @brief 背光相关存储操作
 *
 * @param value
 * @return esp_err_t
 */
esp_err_t get_setting_bl(uint32_t *value);
esp_err_t set_setting_bl(uint32_t value);

/**
 * @brief 城市名称
 *
 * @param value
 * @return esp_err_t
 */
esp_err_t get_city_name(char *city_name);
esp_err_t set_city_name(char city_name[16]);

/**
 * @brief 城市编码
 *
 * @param value
 * @return esp_err_t
 */
esp_err_t get_city_code(char *city_code);
esp_err_t set_city_code(char city_code[16]);

/**
 * @brief 初始化存储
 */
esp_err_t storage_init(void);

#endif
