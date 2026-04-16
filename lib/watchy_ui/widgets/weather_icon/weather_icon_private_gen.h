/**
 * @file weather_icon_private_gen.h
 *
 */

#ifndef WEATHER_ICON_PRIVATE_H
#define WEATHER_ICON_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl_private.h"
#else
    #include "lvgl_private.h"
#endif
#include "weather_icon.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WEATHER_ICON_USER_DATA
#define WEATHER_ICON_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    const void * no_weather;
    const void * sun_cloud;
    const void * sunny;
    const void * snow;
    const void * rainy;
    const void * cloud;
    const void * tornado;
    const void * wind;
    const void * haze;
    lv_obj_t * img_no_weather;
    lv_obj_t * img_sun_cloud;
    lv_obj_t * img_sunny;
    lv_obj_t * img_snow;
    lv_obj_t * img_rainy;
    lv_obj_t * img_cloud;
    lv_obj_t * img_tornado;
    lv_obj_t * img_wind;
    lv_obj_t * img_haze;
    WEATHER_ICON_USER_DATA
} weather_icon_t;

extern const lv_obj_class_t weather_icon_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void weather_icon_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WEATHER_ICON_PRIVATE_H*/