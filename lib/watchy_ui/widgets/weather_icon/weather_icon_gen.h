/**
 * @file weather_icon_gen.h
 *
 */

#ifndef WEATHER_ICON_GEN_H
#define WEATHER_ICON_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl.h"
#endif

#include "watchy_ui_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a weather_icon object
 * @param parent pointer to an object, it will be the parent of the new weather_icon
 * @return pointer to the created weather_icon
 */
lv_obj_t * weather_icon_create(lv_obj_t * parent);
/**
 * weather_icon no_weather
 * @param obj   pointer to a weather_icon
 * @param no_weather  no_weather
 */
void weather_icon_set_no_weather(lv_obj_t * weather_icon, const void * no_weather);

/**
 * weather_icon sun_cloud
 * @param obj   pointer to a weather_icon
 * @param sun_cloud  sun_cloud
 */
void weather_icon_set_sun_cloud(lv_obj_t * weather_icon, const void * sun_cloud);

/**
 * weather_icon sunny
 * @param obj   pointer to a weather_icon
 * @param sunny  sunny
 */
void weather_icon_set_sunny(lv_obj_t * weather_icon, const void * sunny);

/**
 * weather_icon snow
 * @param obj   pointer to a weather_icon
 * @param snow  snow
 */
void weather_icon_set_snow(lv_obj_t * weather_icon, const void * snow);

/**
 * weather_icon rainy
 * @param obj   pointer to a weather_icon
 * @param rainy  rainy
 */
void weather_icon_set_rainy(lv_obj_t * weather_icon, const void * rainy);

/**
 * weather_icon cloud
 * @param obj   pointer to a weather_icon
 * @param cloud  cloud
 */
void weather_icon_set_cloud(lv_obj_t * weather_icon, const void * cloud);

/**
 * weather_icon tornado
 * @param obj   pointer to a weather_icon
 * @param tornado  tornado
 */
void weather_icon_set_tornado(lv_obj_t * weather_icon, const void * tornado);

/**
 * weather_icon wind
 * @param obj   pointer to a weather_icon
 * @param wind  wind
 */
void weather_icon_set_wind(lv_obj_t * weather_icon, const void * wind);

/**
 * weather_icon haze
 * @param obj   pointer to a weather_icon
 * @param haze  haze
 */
void weather_icon_set_haze(lv_obj_t * weather_icon, const void * haze);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WEATHER_ICON_GEN_H*/