/**
 * @file weather_icon.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "weather_icon_private_gen.h"
#include "watchy_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void weather_icon_constructor_hook(lv_obj_t * obj)
{

}

void weather_icon_destructor_hook(lv_obj_t * obj)
{

}

void weather_icon_event_hook(lv_event_t * e)
{

}

void weather_icon_set_no_weather(lv_obj_t * weather_icon, const void * no_weather)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->no_weather = no_weather;
    lv_image_set_src(widget->img_no_weather, widget->no_weather);
}

void weather_icon_set_sun_cloud(lv_obj_t * weather_icon, const void * sun_cloud)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->sun_cloud = sun_cloud;
    lv_image_set_src(widget->img_sun_cloud, widget->sun_cloud);
}

void weather_icon_set_sunny(lv_obj_t * weather_icon, const void * sunny)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->sunny = sunny;
    lv_image_set_src(widget->img_sunny, widget->sunny);
}

void weather_icon_set_snow(lv_obj_t * weather_icon, const void * snow)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->snow = snow;
    lv_image_set_src(widget->img_snow, widget->snow);

}

void weather_icon_set_rainy(lv_obj_t * weather_icon, const void * rainy)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->rainy = rainy;
    lv_image_set_src(widget->img_rainy, widget->rainy);
}

void weather_icon_set_cloud(lv_obj_t * weather_icon, const void * cloud)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->cloud = cloud;
    lv_image_set_src(widget->img_cloud, widget->cloud);
}

void weather_icon_set_tornado(lv_obj_t * weather_icon, const void * tornado)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->tornado = tornado;
    lv_image_set_src(widget->img_tornado, widget->tornado);
}

void weather_icon_set_wind(lv_obj_t * weather_icon, const void * wind)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->wind = wind;
    lv_image_set_src(widget->img_wind, widget->wind);
}

void weather_icon_set_haze(lv_obj_t * weather_icon, const void * haze)
{
    weather_icon_t * widget = (weather_icon_t *)weather_icon;
    widget->haze = haze;
    lv_image_set_src(widget->img_haze, widget->haze);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/