#ifndef _event_h_
#define _event_h_

typedef enum {
    /* Wifi 连接成功 */
    EVENT_WIFI_STA_CONNECTED = 0,
    /* Wifi 断开连接 */
    EVENT_WIFI_STA_DISCONNECTED,
    /* Wifi 连接失败 */
    EVENT_WIFI_STA_FAILURE,
    /* Wifi 开始连接 */
    EVENT_WIFI_STA_START,
    /* 初始化网络时间 */
    EVENT_SNTP_INIT,
    /* 网络时间初始化失败 */
    EVENT_SINT_FAILURE,
    /* 配网中 */
    EVENT_SMART_CONFIG

} basic_event_t;

#endif