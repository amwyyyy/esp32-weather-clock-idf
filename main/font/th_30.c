/*******************************************************************************
 * Size: 30 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef TH_30
#define TH_30 1
#endif

#if TH_30

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap_th_30[] = {
    /* U+0020 " " */
    0x0,

    /* U+0030 "0" */
    0x6, 0x0, 0xf7, 0xf, 0xbc, 0xf0, 0x77, 0x3,
    0xb0, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1e, 0x0,
    0xf0, 0x7, 0x80, 0x3c, 0x3, 0x30, 0x19, 0x81,
    0xce, 0x3c, 0x3f, 0xc0, 0x7c, 0x0,

    /* U+0031 "1" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+0032 "2" */
    0x7, 0xc0, 0xff, 0xe, 0x1c, 0xe0, 0x67, 0x1,
    0xf0, 0xf, 0x80, 0x7c, 0x3, 0xe0, 0x18, 0x1,
    0xc0, 0x1c, 0x3, 0xc1, 0xfc, 0x1f, 0x0, 0xc0,
    0x47, 0x1e, 0x1f, 0xe0, 0xf8, 0x0,

    /* U+0033 "3" */
    0x7, 0xe0, 0x7f, 0xc3, 0x87, 0x98, 0xf, 0xc0,
    0x1f, 0x0, 0x7c, 0x1, 0xf0, 0x7, 0xc0, 0x38,
    0x3, 0xc1, 0xfc, 0x7, 0xf8, 0x0, 0x70, 0x0,
    0xc0, 0x3, 0x6, 0x1c, 0x3f, 0xe0, 0x3e, 0x0,

    /* U+0034 "4" */
    0xe0, 0x3, 0x81, 0x8e, 0x6, 0x38, 0x18, 0xe0,
    0x63, 0x81, 0x8e, 0x6, 0x38, 0x18, 0xe0, 0x63,
    0x81, 0x8e, 0x7, 0xb9, 0xff, 0xff, 0xfb, 0xff,
    0x8f, 0x86, 0x0, 0x18, 0x0, 0x60, 0x1, 0x80,

    /* U+0035 "5" */
    0x7f, 0xfb, 0xff, 0xd8, 0x0, 0xc0, 0x6, 0x0,
    0x30, 0x1, 0x9f, 0xf, 0xfc, 0x70, 0x73, 0x1,
    0xd8, 0x6, 0x0, 0x30, 0x1, 0x80, 0xd, 0x0,
    0xde, 0xe, 0x7f, 0xe0, 0xfc, 0x0,

    /* U+0036 "6" */
    0x7, 0xc0, 0xff, 0x8f, 0x1c, 0x60, 0x66, 0x0,
    0x30, 0x3, 0x7, 0x98, 0xfe, 0xde, 0x3e, 0xc0,
    0xf6, 0x7, 0x80, 0x3e, 0x1, 0xb0, 0xd, 0xc0,
    0xc7, 0xe, 0x1f, 0xe0, 0x7c, 0x0,

    /* U+0037 "7" */
    0x1f, 0xff, 0xff, 0xf8, 0xf, 0xc0, 0x6e, 0x7,
    0x40, 0x38, 0x1, 0xc0, 0xc, 0x0, 0xe0, 0x7,
    0x0, 0x38, 0x1, 0x80, 0x1c, 0x0, 0xe0, 0x7,
    0x0, 0x38, 0x1, 0x80, 0x1c, 0x0,

    /* U+0038 "8" */
    0xf, 0xc1, 0xff, 0x9f, 0xc, 0xe0, 0x3f, 0x1,
    0xf0, 0xf, 0x80, 0x7c, 0x3, 0xe0, 0x33, 0x83,
    0x8f, 0xf0, 0x3f, 0xc3, 0x87, 0x18, 0x18, 0xc0,
    0xc7, 0xe, 0x1f, 0xe0, 0x7c, 0x0,

    /* U+0039 "9" */
    0xf, 0xc0, 0xff, 0x1e, 0x1c, 0xc0, 0x6c, 0x0,
    0x60, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1b, 0x3,
    0xdc, 0x3e, 0x7f, 0xb0, 0xf1, 0x80, 0xc, 0x0,
    0x60, 0x3, 0x0, 0x18, 0x0, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_th_30[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 240, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 243, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 31, .adv_w = 243, .box_w = 3, .box_h = 18, .ofs_x = 6, .ofs_y = 1},
    {.bitmap_index = 38, .adv_w = 243, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 68, .adv_w = 243, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 100, .adv_w = 243, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 132, .adv_w = 243, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 162, .adv_w = 243, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 192, .adv_w = 243, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 222, .adv_w = 243, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 252, .adv_w = 243, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps_th_30[] =
{
    {
        .range_start = 32, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 2,
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
static lv_font_fmt_txt_dsc_t font_dsc_th_30 = {
#endif
    .glyph_bitmap = glyph_bitmap_th_30,
    .glyph_dsc = glyph_dsc_th_30,
    .cmaps = cmaps_th_30,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
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
const lv_font_t th_30 = {
#else
lv_font_t th_30 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc_th_30           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if TH_30*/

