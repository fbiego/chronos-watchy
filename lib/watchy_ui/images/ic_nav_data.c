
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_LVGL_H_INCLUDE_SYSTEM)
#include <lvgl.h>
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IC_NAV_DATA
#define LV_ATTRIBUTE_IC_NAV_DATA
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IC_NAV_DATA
uint8_t ic_nav_data_map[] = {

    0x00,0x00,0x00,0x16,0x00,0x00,0x00,0xfc,

    0x00,0x00,
    0x01,0x80,
    0x03,0xc0,
    0x07,0xc0,
    0x07,0xe0,
    0x07,0xe0,
    0x0f,0xf0,
    0x1f,0xf0,
    0x1f,0xf8,
    0x1f,0xf8,
    0x3f,0xfc,
    0x7f,0xfc,
    0x7f,0xfe,
    0x7f,0x7e,
    0x78,0x1e,
    0x00,0x00,

};

const lv_image_dsc_t ic_nav_data = {
  .header = {
    .magic = LV_IMAGE_HEADER_MAGIC,
    .cf = LV_COLOR_FORMAT_I1,
    .flags = 0,
    .w = 16,
    .h = 16,
    .stride = 2,
    .reserved_2 = 0,
  },
  .data_size = sizeof(ic_nav_data_map),
  .data = ic_nav_data_map,
  .reserved = NULL,
};

