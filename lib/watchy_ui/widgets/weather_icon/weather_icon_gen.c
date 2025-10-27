/**
 * @file weather_icon_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "weather_icon_private_gen.h"
#include "src/core/lv_obj_class_private.h"
#include "watchy_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void weather_icon_constructor_hook(lv_obj_t * obj);
void weather_icon_destructor_hook(lv_obj_t * obj);
void weather_icon_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void weather_icon_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void weather_icon_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void weather_icon_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t weather_icon_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = weather_icon_constructor,
    .destructor_cb = weather_icon_destructor,
    .event_cb = weather_icon_event,
    .instance_size = sizeof(weather_icon_t),
    .editable = 1,
    .name = "weather_icon"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * weather_icon_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&weather_icon_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void weather_icon_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    weather_icon_t * widget = (weather_icon_t *)obj;
    static lv_style_t style_main;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, LV_SIZE_CONTENT);
        lv_style_set_height(&style_main, LV_SIZE_CONTENT);
        lv_style_set_radius(&style_main, 0);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_bg_opa(&style_main, 0);
        lv_style_set_pad_all(&style_main, 0);

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_main, 0);
    lv_obj_t * img_no_weather = lv_image_create(obj);
    lv_obj_set_name(img_no_weather, "img_no_weather");
    lv_image_set_src(img_no_weather, ic_no_weather);
    widget->img_no_weather = img_no_weather;
    lv_obj_bind_flag_if_not_eq(img_no_weather, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, -1);
    
    lv_obj_t * img_sun_cloud = lv_image_create(obj);
    lv_obj_set_name(img_sun_cloud, "img_sun_cloud");
    lv_image_set_src(img_sun_cloud, ic_sun_cloud);
    widget->img_sun_cloud = img_sun_cloud;
    lv_obj_bind_flag_if_not_eq(img_sun_cloud, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_t * img_sunny = lv_image_create(obj);
    lv_obj_set_name(img_sunny, "img_sunny");
    lv_image_set_src(img_sunny, ic_sunny);
    widget->img_sunny = img_sunny;
    lv_obj_bind_flag_if_not_eq(img_sunny, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, 1);
    
    lv_obj_t * img_snow = lv_image_create(obj);
    lv_obj_set_name(img_snow, "img_snow");
    lv_image_set_src(img_snow, ic_snow);
    widget->img_snow = img_snow;
    lv_obj_bind_flag_if_not_eq(img_snow, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, 2);
    
    lv_obj_t * img_rainy = lv_image_create(obj);
    lv_obj_set_name(img_rainy, "img_rainy");
    lv_image_set_src(img_rainy, ic_rainy);
    widget->img_rainy = img_rainy;
    lv_obj_bind_flag_if_not_eq(img_rainy, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, 3);
    
    lv_obj_t * img_cloud = lv_image_create(obj);
    lv_obj_set_name(img_cloud, "img_cloud");
    lv_image_set_src(img_cloud, ic_cloud);
    widget->img_cloud = img_cloud;
    lv_obj_bind_flag_if_not_eq(img_cloud, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, 4);
    
    lv_obj_t * img_tornado = lv_image_create(obj);
    lv_obj_set_name(img_tornado, "img_tornado");
    lv_image_set_src(img_tornado, ic_tornado);
    widget->img_tornado = img_tornado;
    lv_obj_bind_flag_if_not_eq(img_tornado, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, 5);
    
    lv_obj_t * img_wind = lv_image_create(obj);
    lv_obj_set_name(img_wind, "img_wind");
    lv_image_set_src(img_wind, ic_wind);
    widget->img_wind = img_wind;
    lv_obj_bind_flag_if_not_eq(img_wind, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, 6);
    
    lv_obj_t * img_haze = lv_image_create(obj);
    lv_obj_set_name(img_haze, "img_haze");
    lv_image_set_src(img_haze, ic_haze);
    widget->img_haze = img_haze;
    lv_obj_bind_flag_if_not_eq(img_haze, &subject_weather_icon, LV_OBJ_FLAG_HIDDEN, 7);


    weather_icon_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void weather_icon_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    weather_icon_destructor_hook(obj);
}

static void weather_icon_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&weather_icon_class, e);
    if(res != LV_RESULT_OK) return;

    weather_icon_event_hook(e);
}

