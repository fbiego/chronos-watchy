
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

#ifndef LV_ATTRIBUTE_IC_BT_CON_DATA
#define LV_ATTRIBUTE_IC_BT_CON_DATA
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IC_BT_CON_DATA
uint8_t ic_bt_con_data_map[] = {

    0x00,0x00,0x00,0xb3,0x00,0x00,0x00,0x10,

    0xf8,0x1f,
    0xe3,0xc7,
    0xce,0x73,
    0x9e,0x39,
    0xbe,0x5d,
    0x32,0x4c,
    0x78,0x1e,
    0x7c,0x7e,
    0x7e,0x3e,
    0x78,0x1e,
    0x32,0x4c,
    0xbf,0x5d,
    0x9e,0x39,
    0xce,0x73,
    0xe3,0xc7,
    0xf8,0x1f,

};

const lv_image_dsc_t ic_bt_con_data = {
  .header = {
    .magic = LV_IMAGE_HEADER_MAGIC,
    .cf = LV_COLOR_FORMAT_I1,
    .flags = 0,
    .w = 16,
    .h = 16,
    .stride = 2,
    .reserved_2 = 0,
  },
  .data_size = sizeof(ic_bt_con_data_map),
  .data = ic_bt_con_data_map,
  .reserved = NULL,
};

