/**
 * @file bluetooth_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "bluetooth_private_gen.h"
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

void bluetooth_constructor_hook(lv_obj_t * obj);
void bluetooth_destructor_hook(lv_obj_t * obj);
void bluetooth_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void bluetooth_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void bluetooth_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void bluetooth_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t bluetooth_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = bluetooth_constructor,
    .destructor_cb = bluetooth_destructor,
    .event_cb = bluetooth_event,
    .instance_size = sizeof(bluetooth_t),
    .editable = 1,
    .name = "bluetooth"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * bluetooth_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&bluetooth_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void bluetooth_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    bluetooth_t * widget = (bluetooth_t *)obj;
    static lv_style_t style_main;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_height(&style_main, LV_SIZE_CONTENT);
        lv_style_set_width(&style_main, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_bg_opa(&style_main, 0);
        lv_style_set_radius(&style_main, 0);
        lv_style_set_border_width(&style_main, 0);

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_main, 0);
    lv_obj_t * lv_image_0 = lv_image_create(obj);
    lv_image_set_src(lv_image_0, ic_bt_con);
    widget->lv_image_0 = lv_image_0;
    lv_obj_bind_flag_if_not_eq(lv_image_0, &subject_bluetooth, LV_OBJ_FLAG_HIDDEN, 2);
    
    lv_obj_t * lv_image_1 = lv_image_create(obj);
    lv_image_set_src(lv_image_1, ic_bt_on);
    widget->lv_image_1 = lv_image_1;
    lv_obj_bind_flag_if_not_eq(lv_image_1, &subject_bluetooth, LV_OBJ_FLAG_HIDDEN, 1);


    bluetooth_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void bluetooth_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    bluetooth_destructor_hook(obj);
}

static void bluetooth_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&bluetooth_class, e);
    if(res != LV_RESULT_OK) return;

    bluetooth_event_hook(e);
}

