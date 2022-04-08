#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/portmacro.h"
#include "lvgl_helpers.h"
#include "esp_log.h"
#include "gui.h"
#include "sntp_time.h"
#include "weather.h"

#include "assets/taikongren01.c"
#include "assets/taikongren02.c"
#include "assets/taikongren03.c"
#include "assets/taikongren04.c"
#include "assets/taikongren05.c"
#include "assets/taikongren06.c"
#include "assets/taikongren07.c"
#include "assets/taikongren08.c"
#include "assets/taikongren09.c"
#include "assets/taikongren10.c"
#include "assets/taikongren11.c"
#include "assets/taikongren12.c"
#include "assets/taikongren13.c"
#include "assets/taikongren14.c"
#include "assets/taikongren15.c"

#include "assets/temperature.c"
#include "assets/humidity.c"

#include "assets/d00.c"
#include "assets/d01.c"
#include "assets/d02.c"
#include "assets/d03.c"
#include "assets/d04.c"
#include "assets/d05.c"
#include "assets/d06.c"
#include "assets/d07.c"
#include "assets/d08.c"
#include "assets/d09.c"
#include "assets/d10.c"
#include "assets/d11.c"
#include "assets/d12.c"
#include "assets/d13.c"
#include "assets/d14.c"
#include "assets/d15.c"
#include "assets/d16.c"
#include "assets/d17.c"
#include "assets/d18.c"
#include "assets/d19.c"
#include "assets/d20.c"
#include "assets/d21.c"
#include "assets/d22.c"
#include "assets/d23.c"
#include "assets/d24.c"
#include "assets/d25.c"
#include "assets/d26.c"
#include "assets/d27.c"
#include "assets/d28.c"
#include "assets/d29.c"
#include "assets/d30.c"
#include "assets/d31.c"
#include "assets/d53.c"
#include "assets/n00.c"
#include "assets/n01.c"
#include "assets/n03.c"
#include "assets/n15.c"
#include "assets/qr_code.c"

#include "lv_font/lv_font.h"
LV_FONT_DECLARE(lv_font_montserrat_22);

#include "font/fz_20.c"
LV_FONT_DECLARE(fz_20);

#include "font/fz_22.c"
LV_FONT_DECLARE(fz_22);

#include "font/mkb_30.c"
LV_FONT_DECLARE(mkb_30);

#include "font/mkb_70.c"
LV_FONT_DECLARE(mkb_70);

#include "font/myfont_3500hz_18.c"
LV_FONT_DECLARE(myfont_3500hz_18);

/* Littlevgl specific */
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#define TAG "gui"
#define LV_TICK_PERIOD_MS 1

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_tick_task(void *arg);
static void guiTask(void *pvParameter);
static void draw_weather_icon(uint32_t day_or_night, uint32_t weacode);

static lv_obj_t * scr;
static lv_obj_t * hour_label;
static lv_obj_t * minute_label;
static lv_obj_t * second_label;
static lv_obj_t * date_label;
static lv_obj_t * temperature_label;
static lv_obj_t * humidity_label;
static lv_obj_t * city_label;
static lv_obj_t * weather_label;
static lv_obj_t * aqi_label;
static lv_obj_t * wifi_label;
static lv_obj_t * temperature_bar;
static lv_obj_t * humidity_bar;
static lv_obj_t * img_gif;
static lv_obj_t * weather_img;
static lv_obj_t * loading_label;
static lv_obj_t * aqi_canvas;

static uint32_t in = 0;
static weather_t weather;
static uint32_t wifi_status = 0;

void gui_init(void) {
    /* If you want to use a task to create the graphic, you NEED to create a Pinned task
     * Otherwise there can be problem such as memory corruption and so on.
     * NOTE: When not using Wi-Fi nor Bluetooth you can pin the guiTask to core 0 */
    xTaskCreatePinnedToCore(guiTask, "gui", 2048 * 4, NULL, 0, NULL, 1);
}

void clock_task(lv_task_t * task) {
    date_time_t dt = get_now_time();
    lv_label_set_text_fmt(hour_label, "%02d", dt.hour);
    lv_label_set_text_fmt(minute_label, "%02d", dt.minute);
    lv_label_set_text_fmt(second_label, "%02d", dt.second);
    lv_label_set_text_fmt(date_label, "%02d月%02d日  %s", dt.month, dt.day, get_week_text(dt.week));

    if (wifi_status == 1) {
        lv_label_set_text(wifi_label, LV_SYMBOL_WIFI);
    } else {
        lv_label_set_text(wifi_label, "");
    }
}

void wea_task(lv_task_t * task) {
    if (weather.temp != NULL) {
        // 计算温度比例，按 50℃ 为 100%
        int temp = strtol(weather.temp, NULL, 10);
        int t = temp * 100 / 50;

        char * weacode = weather.weathercode;
        uint32_t day_or_night = 0;

        // 判断是否夜间，夜间取夜间天气编码
        if (get_now_time().hour > 18) {
            weacode = weather.weathercoden;
            day_or_night = 1;
        }
        char code[2];
        strncpy(code, weacode + 1, strlen(weacode) - 1);

        char level[5];
        uint32_t color;
        get_aqi_level(weather.aqi, level, &color);

        lv_bar_set_value(temperature_bar, t, LV_ANIM_OFF);
        lv_bar_set_value(humidity_bar, strtol(weather.sd, NULL, 10), LV_ANIM_OFF);
        lv_label_set_text_fmt(temperature_label, "%s℃",  weather.temp);
        lv_label_set_text_fmt(humidity_label, "%s%",  weather.sd);
        draw_weather_icon(day_or_night, strtol(code, NULL, 10));
        lv_label_set_text(city_label, weather.city);
        lv_label_set_text_fmt(aqi_label, "%s", level);

        lv_draw_rect_dsc_t rect_dsc;
        lv_draw_rect_dsc_init(&rect_dsc);
        rect_dsc.radius = 5;
        rect_dsc.bg_color = lv_color_hex(color);
        rect_dsc.border_width = 0;
        lv_canvas_draw_rect(aqi_canvas, 5, 5, 60, 30, &rect_dsc);
    }
}

uint32_t info_index = 0;
void wea_info_task(lv_task_t * task) {
    lv_label_set_text(weather_label, weather.weather[info_index]);
    if (info_index++ >= 4) {
        info_index = 0;
    }
}

void img_task(lv_task_t * task) {
    switch (in++)
    {
    case 0:lv_img_set_src(img_gif, &taikongren01);break;
    case 1:lv_img_set_src(img_gif, &taikongren02);break;
    case 2:lv_img_set_src(img_gif, &taikongren03);break;
    case 3:lv_img_set_src(img_gif, &taikongren04);break;
    case 4:lv_img_set_src(img_gif, &taikongren05);break;
    case 5:lv_img_set_src(img_gif, &taikongren06);break;
    case 6:lv_img_set_src(img_gif, &taikongren07);break;
    case 7:lv_img_set_src(img_gif, &taikongren08);break;
    case 8:lv_img_set_src(img_gif, &taikongren09);break;
    case 9:lv_img_set_src(img_gif, &taikongren10);break;
    case 10:lv_img_set_src(img_gif, &taikongren11);break;
    case 11:lv_img_set_src(img_gif, &taikongren12);break;
    case 12:lv_img_set_src(img_gif, &taikongren13);break;
    case 13:lv_img_set_src(img_gif, &taikongren14);break;
    case 14:lv_img_set_src(img_gif, &taikongren15);break;
    default:
        break;
    }

    if (in >= 14) {
        in = 0;
    }
}

static void draw_weather_icon(uint32_t day_or_night, uint32_t weacode) {
    uint32_t code = weacode;
    if (day_or_night == 1) {
        if (weacode == 0) {
            code = 100;
        } else if (weacode == 1) {
            code = 101;
        } else if (weacode == 3) {
            code = 102;
        } else if (weacode == 15) {
            code = 103;
        }
    }

    switch (code)
    {
    case 0:lv_img_set_src(weather_img, &d00);break;
    case 1:lv_img_set_src(weather_img, &d01);break;
    case 2:lv_img_set_src(weather_img, &d02);break;
    case 3:lv_img_set_src(weather_img, &d03);break;
    case 4:lv_img_set_src(weather_img, &d04);break;
    case 5:lv_img_set_src(weather_img, &d05);break;
    case 6:lv_img_set_src(weather_img, &d06);break;
    case 7:lv_img_set_src(weather_img, &d07);break;
    case 8:lv_img_set_src(weather_img, &d08);break;
    case 9:lv_img_set_src(weather_img, &d09);break;
    case 10:lv_img_set_src(weather_img, &d10);break;
    case 11:lv_img_set_src(weather_img, &d11);break;
    case 12:lv_img_set_src(weather_img, &d12);break;
    case 13:lv_img_set_src(weather_img, &d13);break;
    case 14:lv_img_set_src(weather_img, &d14);break;
    case 15:lv_img_set_src(weather_img, &d15);break;
    case 16:lv_img_set_src(weather_img, &d16);break;
    case 17:lv_img_set_src(weather_img, &d17);break;
    case 18:lv_img_set_src(weather_img, &d18);break;
    case 19:lv_img_set_src(weather_img, &d19);break;
    case 20:lv_img_set_src(weather_img, &d20);break;
    case 21:lv_img_set_src(weather_img, &d21);break;
    case 22:lv_img_set_src(weather_img, &d22);break;
    case 23:lv_img_set_src(weather_img, &d23);break;
    case 24:lv_img_set_src(weather_img, &d24);break;
    case 25:lv_img_set_src(weather_img, &d25);break;
    case 26:lv_img_set_src(weather_img, &d26);break;
    case 27:lv_img_set_src(weather_img, &d27);break;
    case 28:lv_img_set_src(weather_img, &d28);break;
    case 29:lv_img_set_src(weather_img, &d29);break;
    case 30:lv_img_set_src(weather_img, &d30);break;
    case 31:lv_img_set_src(weather_img, &d31);break;
    case 53:lv_img_set_src(weather_img, &d53);break;
    case 100:lv_img_set_src(weather_img, &n00);break;
    case 101:lv_img_set_src(weather_img, &n01);break;
    case 102:lv_img_set_src(weather_img, &n03);break;
    case 103:lv_img_set_src(weather_img, &n15);break;
    default:
        break;
    }
}

void set_loading_text(const char * text) {
    lv_label_set_text(loading_label, text);
}

void set_weather_info(weather_t wea) {
    weather = wea;
}

void set_wifi_status(uint32_t status) {
    wifi_status = status;
}

static void loading_page() {
    lv_obj_t * preload = lv_spinner_create(scr, NULL);
    lv_obj_set_size(preload, 100, 100);
    lv_obj_align(preload, NULL, LV_ALIGN_CENTER, 0, 0);

    static lv_style_t label_style;
    lv_style_init(&label_style);	
    lv_style_set_text_color(&label_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    loading_label = lv_label_create(scr, NULL);
    lv_label_set_long_mode(loading_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(loading_label, NULL, LV_ALIGN_IN_BOTTOM_MID, -30, -30);
    lv_obj_add_style(loading_label, LV_LABEL_PART_MAIN, &label_style);
    
    set_loading_text("Loading...");
}

static void clock_page() {
    lv_obj_t * scene_main = lv_obj_create(scr, NULL);
    lv_obj_reset_style_list(scene_main, LV_OBJ_PART_MAIN);
    lv_obj_set_size(scene_main, lv_obj_get_width(scr), lv_obj_get_height(scr));
    lv_obj_align(scene_main, NULL, LV_ALIGN_CENTER, 0, 0);

    // 时间显示
    // 小时
    static lv_style_t hour_style;
    lv_style_init(&hour_style);	
    lv_style_set_text_font(&hour_style, LV_STATE_DEFAULT, &mkb_70);
    lv_style_set_text_color(&hour_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    hour_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(hour_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(hour_label, NULL, LV_ALIGN_IN_LEFT_MID, 15, -35);
    lv_obj_add_style(hour_label, LV_LABEL_PART_MAIN, &hour_style);

    // 分钟
    static lv_style_t minute_style;
    lv_style_init(&minute_style);	
    lv_style_set_text_font(&minute_style, LV_STATE_DEFAULT, &mkb_70);
    lv_style_set_text_color(&minute_style, LV_STATE_DEFAULT, LV_COLOR_ORANGE);

    minute_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(minute_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(minute_label, NULL, LV_ALIGN_IN_LEFT_MID, 103, -35);
    lv_obj_add_style(minute_label, LV_LABEL_PART_MAIN, &minute_style);

    // 秒
    static lv_style_t second_style;
    lv_style_init(&second_style);	
    lv_style_set_text_font(&second_style, LV_STATE_DEFAULT, &mkb_30);
    lv_style_set_text_color(&second_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    second_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(second_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(second_label, NULL, LV_ALIGN_IN_LEFT_MID, 190, -5);
    lv_obj_add_style(second_label, LV_LABEL_PART_MAIN, &second_style);

    // 日期
    static lv_style_t fz_20_style;
    lv_style_init(&fz_20_style);	
    lv_style_set_text_font(&fz_20_style, LV_STATE_DEFAULT, &fz_20);
    lv_style_set_text_color(&fz_20_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    date_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(date_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(date_label, NULL, LV_ALIGN_IN_LEFT_MID, 20, 35);
    lv_obj_add_style(date_label, LV_LABEL_PART_MAIN, &fz_20_style);

    // 太空人动画
    img_gif = lv_img_create(scene_main, NULL);
    lv_obj_align(img_gif, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 10, -50);

    // 温度图标
    lv_obj_t * temperature_img = lv_img_create(scene_main, NULL);
    lv_obj_align(temperature_img, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 10, -25);
    lv_img_set_src(temperature_img, &temperature);

    // 湿度图标
    lv_obj_t * humidity_img = lv_img_create(scene_main, NULL);
    lv_obj_align(humidity_img, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 10, 10);
    lv_img_set_src(humidity_img, &humidity);

    // 温度条
    temperature_bar = lv_bar_create(scene_main, NULL);
    lv_obj_set_size(temperature_bar, 60, 6);
    lv_obj_align(temperature_bar, NULL, LV_ALIGN_IN_BOTTOM_MID, -38, -47);

    // 湿度条
    humidity_bar = lv_bar_create(scene_main, NULL);
    lv_obj_set_size(humidity_bar, 60, 6);
    lv_obj_align(humidity_bar, NULL, LV_ALIGN_IN_BOTTOM_MID, -38, -12);

    // 温度
    temperature_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(temperature_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(temperature_label, NULL, LV_ALIGN_IN_BOTTOM_MID, 17, -40);
    lv_obj_add_style(temperature_label, LV_LABEL_PART_MAIN, &fz_20_style);

    // 湿度
    humidity_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(humidity_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(humidity_label, NULL, LV_ALIGN_IN_BOTTOM_MID, 17, -10);
    lv_obj_add_style(humidity_label, LV_LABEL_PART_MAIN, &fz_20_style);

    // 天气图标
    weather_img = lv_img_create(scene_main, NULL);
    lv_obj_align(weather_img, NULL, LV_ALIGN_IN_TOP_RIGHT, 15, 0);

    // wifi 图标
    static lv_style_t wifi_style;
    lv_style_init(&wifi_style);	
    lv_style_set_text_color(&wifi_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    wifi_label = lv_label_create(scene_main, NULL);
    lv_obj_align(wifi_label, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 8);
    lv_obj_add_style(wifi_label, LV_LABEL_PART_MAIN, &wifi_style);

    // 城市
    static lv_style_t city_style;
    lv_style_init(&city_style);	
    lv_style_set_text_font(&city_style, LV_STATE_DEFAULT, &fz_22);
    lv_style_set_text_color(&city_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    city_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(city_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(city_label, NULL, LV_ALIGN_IN_TOP_LEFT, 30, 5);
    lv_obj_add_style(city_label, LV_LABEL_PART_MAIN, &city_style);

    // 天气状况
    weather_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(weather_label, LV_LABEL_LONG_EXPAND);
    lv_obj_align(weather_label, NULL, LV_ALIGN_IN_TOP_LEFT, 15, 40);
    lv_obj_add_style(weather_label, LV_LABEL_PART_MAIN, &city_style);
    lv_obj_set_width(weather_label, 120);
    lv_label_set_align(weather_label, LV_LABEL_ALIGN_CENTER);

    // 空气质量底框
    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(70, 35)];
    aqi_canvas = lv_canvas_create(scene_main, NULL);
    lv_canvas_set_buffer(aqi_canvas, cbuf, 70, 35, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(aqi_canvas, NULL, LV_ALIGN_IN_TOP_MID, 15, -3);
    lv_canvas_fill_bg(aqi_canvas, LV_COLOR_BLACK, LV_OPA_COVER);

    // 空气质量
    static lv_style_t aqi_style;
    lv_style_init(&aqi_style);	
    lv_style_set_text_font(&aqi_style, LV_STATE_DEFAULT, &fz_22);
    lv_style_set_text_color(&aqi_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    aqi_label = lv_label_create(scene_main, NULL);
    lv_label_set_long_mode(aqi_label, LV_LABEL_LONG_BREAK);
    lv_obj_align(aqi_label, aqi_canvas, LV_ALIGN_CENTER, 0, -1);
    lv_obj_add_style(aqi_label, LV_LABEL_PART_MAIN, &aqi_style);
    lv_obj_set_width(aqi_label, 35);
    lv_label_set_align(aqi_label, LV_LABEL_ALIGN_CENTER);
}

void display(display_type_t type) {
    lv_obj_clean(scr);

    if (type == DISP_CLOCK) {
        clock_page();

        // 每秒刷新时间
        lv_task_t * time_task = lv_task_create(clock_task, 1000, LV_TASK_PRIO_MID, NULL);
        lv_task_ready(time_task);

        // 动画
        lv_task_t * gif_task = lv_task_create(img_task, 80, LV_TASK_PRIO_MID, NULL);
        lv_task_ready(gif_task);

        // 刷新天气
        lv_task_t * weather_task = lv_task_create(wea_task, 1000 * 60 * 5, LV_TASK_PRIO_MID, NULL);
        lv_task_ready(weather_task);

        // 天气信息文本刷新
        lv_task_t * weather_info_task = lv_task_create(wea_info_task, 1000 * 5, LV_TASK_PRIO_MID, NULL);
        lv_task_ready(weather_info_task);
    } else if (type == DISP_LOADING) {
        loading_page();
    } else if (type == DISP_SMART_CONFIG) {
        lv_obj_t * qr_img = lv_img_create(scr, NULL);
        lv_obj_align(qr_img, NULL, LV_ALIGN_CENTER, -35, -100);
        lv_img_set_src(qr_img, &qr_code);

        static lv_style_t sc_style;
        lv_style_init(&sc_style);	
        lv_style_set_text_font(&sc_style, LV_STATE_DEFAULT, &myfont_3500hz_18);
        lv_style_set_text_color(&sc_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);

        lv_obj_t * sc_label = lv_label_create(scr, NULL);
        lv_label_set_long_mode(sc_label, LV_LABEL_LONG_EXPAND);
        lv_obj_align(sc_label, NULL, LV_ALIGN_IN_BOTTOM_MID, -80, -50);
        lv_obj_add_style(sc_label, LV_LABEL_PART_MAIN, &sc_style);
        lv_label_set_text(sc_label, "请连接热点: esp32_clock");

        lv_obj_t * tip_label = lv_label_create(scr, NULL);
        lv_label_set_long_mode(tip_label, LV_LABEL_LONG_EXPAND);
        lv_obj_align(tip_label, NULL, LV_ALIGN_IN_BOTTOM_MID, -80, -15);
        lv_obj_add_style(tip_label, LV_LABEL_PART_MAIN, &sc_style);
        lv_label_set_text(tip_label, "连接后请扫描二维码");
    }
}

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

static void guiTask(void *pvParameter) {
    (void) pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();

    lv_init();

    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    lv_color_t* buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1 != NULL);

    /* Use double buffered when not working with monochrome displays */
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    lv_color_t* buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf2 != NULL);
#else
    static lv_color_t *buf2 = NULL;
#endif

    static lv_disp_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;

    /* Initialize the working buffer depending on the selected display.
     * NOTE: buf2 == NULL when using monochrome displays. */
    lv_disp_buf_init(&disp_buf, buf1, buf2, size_in_px);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_driver_flush;

    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"
    };
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    static lv_style_t bg_style;
    lv_style_init(&bg_style);	
    lv_style_set_bg_color(&bg_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);

    scr = lv_scr_act();
    lv_obj_clean(scr);
    lv_obj_add_style(scr, LV_OBJ_PART_MAIN, &bg_style);

    display(DISP_LOADING);

    while (1) {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
       }
    }

    /* A task should NEVER return */
    free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    free(buf2);
#endif
    vTaskDelete(NULL);
}

static void lv_tick_task(void *arg) {
    (void) arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}
