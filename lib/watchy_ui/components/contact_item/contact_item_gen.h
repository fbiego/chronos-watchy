/**
 * @file contact_item_gen.h
 */

#ifndef CONTACT_ITEM_H
#define CONTACT_ITEM_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "src/core/lv_obj_class_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/src/core/lv_obj_class_private.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * contact_item_create(lv_obj_t * parent, const char * name, const char * number, bool normal);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*CONTACT_ITEM_H*/