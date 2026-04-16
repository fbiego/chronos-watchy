/**
 * @file forecast_gen.h
 */

#ifndef FORECAST_H
#define FORECAST_H

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

lv_obj_t * forecast_create(lv_obj_t * parent, const char * day, const void * icon, const char * temp);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*FORECAST_H*/