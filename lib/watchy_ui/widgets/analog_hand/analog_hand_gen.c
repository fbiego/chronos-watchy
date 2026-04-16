/**
 * @file analog_hand_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "analog_hand_private_gen.h"
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "src/core/lv_obj_class_private.h"
#else
    #include "lvgl.h"
    #include "src/core/lv_obj_class_private.h"
#endif
#include "../../watchy_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void analog_hand_constructor_hook(lv_obj_t * obj);
void analog_hand_destructor_hook(lv_obj_t * obj);
void analog_hand_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void analog_hand_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void analog_hand_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void analog_hand_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t analog_hand_class = {
    .base_class = &lv_image_class,
    .constructor_cb = analog_hand_constructor,
    .destructor_cb = analog_hand_destructor,
    .event_cb = analog_hand_event,
    .instance_size = sizeof(analog_hand_t),
    .editable = 1,
    .name = "analog_hand"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * analog_hand_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&analog_hand_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void analog_hand_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    analog_hand_t * widget = (analog_hand_t *)obj;
    static lv_style_t style_main;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, LV_SIZE_CONTENT);
        lv_style_set_height(&style_main, LV_SIZE_CONTENT);

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_main, 0);


    analog_hand_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void analog_hand_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    analog_hand_destructor_hook(obj);
}

static void analog_hand_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&analog_hand_class, e);
    if(res != LV_RESULT_OK) return;

    analog_hand_event_hook(e);
}

