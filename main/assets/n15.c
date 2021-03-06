#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif
#ifndef LV_ATTRIBUTE_IMG_N15
#define LV_ATTRIBUTE_IMG_N15
#endif
const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_N15 uint8_t n15_map[] = {
  0x00, 0x00, 0x00, 0x00, 	/*Color of index 0*/
  0xff, 0xff, 0xff, 0x01, 	/*Color of index 1*/
  0x9a, 0x9a, 0x9a, 0x67, 	/*Color of index 2*/
  0x9a, 0x9a, 0x9a, 0xb7, 	/*Color of index 3*/
  0x9a, 0x9a, 0x9a, 0xed, 	/*Color of index 4*/
  0x95, 0x95, 0x97, 0x17, 	/*Color of index 5*/
  0x02, 0xc0, 0xfd, 0x19, 	/*Color of index 6*/
  0x04, 0xc0, 0xfc, 0x77, 	/*Color of index 7*/
  0x03, 0xc0, 0xfc, 0xf0, 	/*Color of index 8*/
  0x5a, 0xc1, 0xd1, 0xfd, 	/*Color of index 9*/
  0xfb, 0xca, 0x86, 0x0b, 	/*Color of index 10*/
  0xf4, 0xc2, 0x81, 0x37, 	/*Color of index 11*/
  0xf7, 0xc5, 0x80, 0x6d, 	/*Color of index 12*/
  0xf5, 0xc4, 0x82, 0xb7, 	/*Color of index 13*/
  0xf6, 0xc4, 0x81, 0xe5, 	/*Color of index 14*/
  0xdd, 0xc3, 0x8e, 0xfc, 	/*Color of index 15*/

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x67, 0x67, 0x66, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1a, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xa1, 0x00, 0x06, 0x67, 0x78, 0x88, 0x76, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0xbc, 0xcc, 0xcc, 0xcc, 0xcb, 0xaa, 0x00, 0x67, 0x78, 0x88, 0x88, 0x76, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xab, 0xbc, 0xdd, 0xee, 0xee, 0xed, 0xdc, 0xcb, 0xb6, 0x77, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0xcd, 0xde, 0xde, 0xee, 0xee, 0xee, 0xee, 0xdd, 0xdc, 0x88, 0x88, 0x88, 0x87, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xbc, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xe9, 0x98, 0x88, 0x88, 0x87, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xac, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xf9, 0x88, 0x88, 0x88, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xbc, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xff, 0xff, 0x99, 0x88, 0x87, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xf9, 0x88, 0x88, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xac, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xf9, 0x98, 0x88, 0x76, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xcc, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xff, 0x98, 0x88, 0x87, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xff, 0xf8, 0x88, 0x88, 0x76, 0x66, 0x66, 0x66, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xff, 0xf9, 0x88, 0x88, 0x87, 0x76, 0x66, 0x66, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xff, 0xf9, 0x88, 0x88, 0x88, 0x77, 0x77, 0x77, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xac, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xff, 0xff, 0xff, 0xf9, 0x99, 0x88, 0x88, 0x88, 0x88, 0x87, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf9, 0xf9, 0x98, 0x88, 0x87, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x0a, 0xaa, 0xbc, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x88, 0x76, 0x60, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0xa5, 0xbc, 0xcd, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x98, 0x76, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0a, 0xbc, 0xdd, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xb0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0a, 0xac, 0xdd, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xed, 0xca, 0xa0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0a, 0xbd, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xee, 0xcb, 0xa0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xab, 0xdd, 0xfe, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xef, 0xef, 0xfe, 0xfe, 0xee, 0xee, 0xdc, 0xa0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xac, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xec, 0xb0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xbd, 0xdf, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xed, 0xb0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xbd, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xed, 0xb0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xbe, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xed, 0xb0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xbd, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xed, 0xa0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xbd, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xdc, 0xb0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xad, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xdc, 0xa0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xbb, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xed, 0xca, 0xa0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xab, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xdd, 0xb1, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x0a, 0xbc, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xcb, 0xa0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xab, 0xcd, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xed, 0xdc, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xaa, 0xbb, 0xdd, 0xde, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xed, 0xdc, 0xca, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xaa, 0xbb, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xbc, 0xbb, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x50, 0x05, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x52, 0x25, 0x55, 0x22, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x53, 0x32, 0x53, 0x32, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x15, 0x55, 0x55, 0x00, 0x00, 0x00, 0x55, 0x53, 0x33, 0x33, 0x32, 0x50, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x32, 0x25, 0x55, 0x23, 0x55, 0x10, 0x00, 0x05, 0x55, 0x53, 0x34, 0x44, 0x32, 0x55, 0x51, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x52, 0x34, 0x25, 0x52, 0x34, 0x25, 0x50, 0x00, 0x05, 0x22, 0x23, 0x34, 0x44, 0x23, 0x22, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x34, 0x42, 0x23, 0x43, 0x25, 0x10, 0x00, 0x05, 0x23, 0x44, 0x44, 0x44, 0x44, 0x33, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x23, 0x43, 0x34, 0x33, 0x50, 0x00, 0x00, 0x05, 0x22, 0x23, 0x44, 0x44, 0x32, 0x22, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x23, 0x44, 0x44, 0x32, 0x55, 0x55, 0x51, 0x00, 0x00, 0x52, 0x33, 0x43, 0x35, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x22, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x22, 0x55, 0x00, 0x05, 0x53, 0x42, 0x23, 0x32, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x53, 0x34, 0x34, 0x44, 0x44, 0x44, 0x34, 0x32, 0x55, 0x00, 0x05, 0x53, 0x22, 0x52, 0x32, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x53, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x32, 0x55, 0x00, 0x05, 0x52, 0x55, 0x55, 0x25, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x25, 0x23, 0x44, 0x44, 0x32, 0x25, 0x25, 0x51, 0x00, 0x01, 0x55, 0x51, 0x05, 0x55, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x23, 0x43, 0x34, 0x42, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x34, 0x42, 0x23, 0x43, 0x25, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x43, 0x35, 0x52, 0x34, 0x25, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x33, 0x55, 0x55, 0x33, 0x25, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x55, 0x15, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const lv_img_dsc_t n15 = {
  .header.cf = LV_IMG_CF_INDEXED_4BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 64,
  .header.h = 64,
  .data_size = 2113,
  .data = n15_map,
};
