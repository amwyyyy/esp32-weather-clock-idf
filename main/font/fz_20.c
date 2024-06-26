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

#ifndef FZ_20
#define FZ_20 1
#endif

#if FZ_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap_fz_20[] = {
    /* U+0020 " " */
    0x0,

    /* U+0025 "%" */
    0x38, 0x10, 0x7c, 0x10, 0xc6, 0x20, 0xc6, 0x20,
    0xc6, 0x40, 0xc6, 0x40, 0x7c, 0x80, 0x7c, 0x80,
    0x11, 0x0, 0x1, 0x1e, 0x2, 0x33, 0x2, 0x21,
    0x4, 0x21, 0x4, 0x33, 0x8, 0x1e,

    /* U+002E "." */
    0xc0,

    /* U+0030 "0" */
    0x1e, 0xc, 0xc6, 0x19, 0x2, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0x61,
    0x9c, 0xe1, 0xe0,

    /* U+0031 "1" */
    0x18, 0xc6, 0x7f, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x60,

    /* U+0032 "2" */
    0x1f, 0x18, 0x64, 0xf, 0x3, 0xc0, 0xc0, 0x30,
    0x1c, 0x1e, 0xf, 0xf, 0x87, 0x81, 0xc0, 0xc0,
    0x30, 0xf, 0xfc,

    /* U+0033 "3" */
    0x3e, 0x18, 0xcc, 0x1b, 0x6, 0xc1, 0x80, 0x60,
    0x30, 0x3c, 0x1, 0x80, 0x3c, 0xf, 0x3, 0xc0,
    0xd8, 0x63, 0xf0,

    /* U+0034 "4" */
    0x3, 0x1, 0xc0, 0x70, 0x3c, 0x1b, 0x4, 0xc3,
    0x31, 0x8c, 0x63, 0x30, 0xcf, 0xfc, 0xc, 0x3,
    0x0, 0xc0, 0x30,

    /* U+0035 "5" */
    0x3f, 0x88, 0x2, 0x1, 0x80, 0x60, 0x1f, 0x86,
    0x18, 0x3, 0x0, 0xc0, 0x3c, 0xd, 0x6, 0x61,
    0x8f, 0xc0,

    /* U+0036 "6" */
    0x1f, 0xc, 0x66, 0x9, 0x3, 0xc0, 0x30, 0xd,
    0xf3, 0x86, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0x40,
    0x98, 0x61, 0xf0,

    /* U+0037 "7" */
    0xff, 0xc0, 0x60, 0x18, 0xc, 0x2, 0x1, 0x80,
    0x40, 0x30, 0xc, 0x6, 0x1, 0x80, 0x60, 0x30,
    0xc, 0x0,

    /* U+0038 "8" */
    0x3e, 0x18, 0xcc, 0x1b, 0x6, 0xc1, 0xb0, 0x66,
    0x30, 0xfc, 0x61, 0xb0, 0x3c, 0xf, 0x3, 0xc0,
    0xd8, 0x63, 0xf0,

    /* U+0039 "9" */
    0x3c, 0x31, 0xb0, 0x58, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x63, 0x9f, 0xc0, 0x78, 0x2c, 0x33, 0x10,
    0xf0,

    /* U+2103 "℃" */
    0x70, 0x0, 0x88, 0x0, 0x88, 0xfc, 0x8b, 0xde,
    0x76, 0x3, 0x6, 0x3, 0xc, 0x0, 0xc, 0x0,
    0xc, 0x0, 0xc, 0x0, 0xc, 0x0, 0xc, 0x3,
    0x4, 0x3, 0x6, 0x3, 0x3, 0xe, 0x0, 0xf8,

    /* U+4E00 "一" */
    0xff, 0xff, 0x80,

    /* U+4E09 "三" */
    0x7f, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xff, 0xfc,

    /* U+4E8C "二" */
    0x3f, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xff,

    /* U+4E94 "五" */
    0x7f, 0xff, 0x80, 0x60, 0x0, 0x18, 0x0, 0x6,
    0x0, 0x1, 0x80, 0x0, 0x60, 0x3, 0xff, 0xe0,
    0x4, 0x18, 0x3, 0x4, 0x0, 0xc1, 0x0, 0x30,
    0x40, 0xc, 0x10, 0x2, 0xc, 0x3f, 0xff, 0xf0,

    /* U+516D "六" */
    0x1, 0x80, 0x0, 0xc0, 0x0, 0x30, 0x0, 0x18,
    0x0, 0x0, 0x7, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x6, 0x30, 0x3, 0x18, 0x3, 0x6, 0x3,
    0x1, 0x81, 0x80, 0x61, 0x80, 0x31, 0x80, 0xd,
    0x80, 0x6,

    /* U+5468 "周" */
    0x1f, 0xff, 0xc6, 0x18, 0x31, 0x86, 0xc, 0x6f,
    0xfb, 0x18, 0x60, 0xc6, 0x18, 0x31, 0x86, 0xc,
    0x7f, 0xfb, 0x18, 0x0, 0xc6, 0xff, 0x31, 0xb0,
    0xcc, 0x6c, 0x33, 0x33, 0xc, 0xcc, 0xff, 0x37,
    0x0, 0xd, 0x80, 0xf, 0x0, 0x3, 0x80,

    /* U+56DB "四" */
    0xff, 0xff, 0x8d, 0x8f, 0x1b, 0x1e, 0x36, 0x3c,
    0x6c, 0x78, 0xd8, 0xf1, 0x31, 0xe6, 0x63, 0xdc,
    0xf7, 0xf0, 0xef, 0x40, 0x1e, 0x0, 0x3f, 0xff,
    0xf8, 0x0, 0xf0, 0x1, 0xe0, 0x3,

    /* U+65E5 "日" */
    0xff, 0xfc, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c,
    0x3, 0xff, 0xfc, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3c, 0x3, 0xff, 0xfc, 0x3, 0xc0, 0x3c, 0x3,

    /* U+6708 "月" */
    0xf, 0xfe, 0x18, 0xc, 0x30, 0x18, 0x60, 0x30,
    0xff, 0xe1, 0x80, 0xc3, 0x1, 0x86, 0x3, 0xc,
    0x6, 0x1f, 0xfc, 0x30, 0x18, 0xe0, 0x31, 0x80,
    0x67, 0x0, 0xdc, 0x7, 0xf0, 0xf, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_fz_20[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 89, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 284, .box_w = 16, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 31, .adv_w = 89, .box_w = 2, .box_h = 1, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 178, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 178, .box_w = 5, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 178, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 178, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 178, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 178, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 136, .adv_w = 178, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 178, .box_w = 10, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 178, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 178, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 320, .box_w = 16, .box_h = 16, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 320, .box_w = 17, .box_h = 1, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 244, .adv_w = 320, .box_w = 17, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 274, .adv_w = 320, .box_w = 18, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 301, .adv_w = 320, .box_w = 18, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 333, .adv_w = 320, .box_w = 17, .box_h = 16, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 367, .adv_w = 320, .box_w = 18, .box_h = 17, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 406, .adv_w = 320, .box_w = 15, .box_h = 16, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 436, .adv_w = 320, .box_w = 12, .box_h = 16, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 460, .adv_w = 320, .box_w = 15, .box_h = 17, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0_fz_20[] = {
    0x0, 0x5, 0xe, 0x10, 0x11, 0x12, 0x13, 0x14,
    0x15, 0x16, 0x17, 0x18, 0x19, 0x20e3, 0x4de0, 0x4de9,
    0x4e6c, 0x4e74, 0x514d, 0x5448, 0x56bb, 0x65c5, 0x66e8
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps_fz_20[] =
{
    {
        .range_start = 32, .range_length = 26345, .glyph_id_start = 1,
        .unicode_list = unicode_list_0_fz_20, .glyph_id_ofs_list = NULL, .list_length = 23, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
static lv_font_fmt_txt_dsc_t font_dsc_fz_20 = {
#endif
    .glyph_bitmap = glyph_bitmap_fz_20,
    .glyph_dsc = glyph_dsc_fz_20,
    .cmaps = cmaps_fz_20,
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
const lv_font_t fz_20 = {
#else
lv_font_t fz_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc_fz_20           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FZ_20*/

