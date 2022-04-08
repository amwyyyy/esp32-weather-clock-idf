/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef TH_20
#define TH_20 1
#endif

#if TH_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap_th_20[] = {
    /* U+0030 "0" */
    0x1b, 0x1d, 0xdc, 0x6c, 0x1c, 0xe, 0x7, 0x3,
    0x81, 0xc0, 0xe0, 0x98, 0xcf, 0xc3, 0xc0,

    /* U+0031 "1" */
    0xff, 0xff, 0xff, 0xc0,

    /* U+0032 "2" */
    0xf, 0xf, 0xe7, 0x1d, 0x83, 0x60, 0xf8, 0x30,
    0xc, 0x6, 0x1f, 0xe, 0x3, 0x38, 0xfe, 0x3c,
    0x0,

    /* U+0033 "3" */
    0x1e, 0x3f, 0x98, 0xf8, 0x3c, 0x1e, 0xc, 0xc,
    0x3c, 0x1f, 0x0, 0x80, 0x47, 0xe1, 0xe0,

    /* U+0034 "4" */
    0xc0, 0x61, 0xb0, 0xd8, 0x6c, 0x36, 0x1b, 0xd,
    0x87, 0xdf, 0xff, 0xb8, 0xc0, 0x60, 0x30,

    /* U+0035 "5" */
    0xff, 0xff, 0xc0, 0xc0, 0xdc, 0xfe, 0xc7, 0xc3,
    0x3, 0x3, 0x87, 0xfe, 0x7c,

    /* U+0036 "6" */
    0x1e, 0x1f, 0xdc, 0x6c, 0x2c, 0x6, 0x3b, 0x7f,
    0xb1, 0xd0, 0xf0, 0x5c, 0x6f, 0xe1, 0xe0,

    /* U+0037 "7" */
    0x3f, 0xff, 0xf0, 0x78, 0x28, 0x30, 0x18, 0xc,
    0x4, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60, 0x60,

    /* U+0038 "8" */
    0x1e, 0x3f, 0xb8, 0xf8, 0x3c, 0x1e, 0xf, 0x8c,
    0xfc, 0x3e, 0x31, 0x98, 0xcf, 0xc3, 0xc0,

    /* U+0039 "9" */
    0x1e, 0x3f, 0x98, 0xd8, 0xc, 0x1e, 0xf, 0x7,
    0x87, 0x67, 0xbe, 0xce, 0x60, 0x30, 0x18, 0xc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_th_20[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 162, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 15, .adv_w = 162, .box_w = 2, .box_h = 13, .ofs_x = 4, .ofs_y = 1},
    {.bitmap_index = 19, .adv_w = 162, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 36, .adv_w = 162, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 51, .adv_w = 162, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 66, .adv_w = 162, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 79, .adv_w = 162, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 94, .adv_w = 162, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 162, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 125, .adv_w = 162, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps_th_20[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc_th_20 = {
#endif
    .glyph_bitmap = glyph_bitmap_th_20,
    .glyph_dsc = glyph_dsc_th_20,
    .cmaps = cmaps_th_20,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t th_20 = {
#else
lv_font_t th_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc_th_20           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if TH_20*/

