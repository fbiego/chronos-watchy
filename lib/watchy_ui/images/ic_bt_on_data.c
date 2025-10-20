
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

#ifndef LV_ATTRIBUTE_IC_BT_ON_DATA
#define LV_ATTRIBUTE_IC_BT_ON_DATA
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IC_BT_ON_DATA
uint8_t ic_bt_on_data_map[] = {

    0x00,0x00,0x00,0xc3,0x00,0x00,0x00,0x06,

    0xfe,0xff,
    0xfe,0x7f,
    0xfe,0x1f,
    0xfe,0x0f,
    0xe6,0x67,
    0xf2,0x4f,
    0xf8,0x1f,
    0xfc,0x3f,
    0xfc,0x3f,
    0xf8,0x1f,
    0xf2,0x4f,
    0xe6,0x67,
    0xfe,0x0f,
    0xfe,0x3f,
    0xfe,0x7f,
    0xfe,0xff,

};

const lv_image_dsc_t ic_bt_on_data = {
  .header = {
    .magic = LV_IMAGE_HEADER_MAGIC,
    .cf = LV_COLOR_FORMAT_I1,
    .flags = 0,
    .w = 16,
    .h = 16,
    .stride = 2,
    .reserved_2 = 0,
  },
  .data_size = sizeof(ic_bt_on_data_map),
  .data = ic_bt_on_data_map,
  .reserved = NULL,
};

