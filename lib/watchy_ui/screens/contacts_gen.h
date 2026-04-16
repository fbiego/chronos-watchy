/**
 * @file contacts_gen.h
 */

#ifndef CONTACTS_H
#define CONTACTS_H

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



lv_obj_t * contacts_create(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*CONTACTS_H*/