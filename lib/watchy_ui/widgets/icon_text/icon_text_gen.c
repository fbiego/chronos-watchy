/**
 * @file icon_text_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "icon_text_private_gen.h"
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

void icon_text_constructor_hook(lv_obj_t * obj);
void icon_text_destructor_hook(lv_obj_t * obj);
void icon_text_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void icon_text_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void icon_text_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void icon_text_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t icon_text_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = icon_text_constructor,
    .destructor_cb = icon_text_destructor,
    .event_cb = icon_text_event,
    .instance_size = sizeof(icon_text_t),
    .editable = 1,
    .name = "icon_text"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * icon_text_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&icon_text_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void icon_text_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    icon_text_t * widget = (icon_text_t *)obj;
    static lv_style_t style_main;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, LV_SIZE_CONTENT);
        lv_style_set_height(&style_main, LV_SIZE_CONTENT);
        lv_style_set_bg_opa(&style_main, 0);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_pad_column(&style_main, 2);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_radius(&style_main, 0);
        lv_style_set_text_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_font(&style_main, NS_Regular_16);
        lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_main, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_cross_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_main, LV_FLEX_ALIGN_CENTER);

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_main, 0);
    lv_obj_t * img_icon = lv_image_create(obj);
    lv_obj_set_name(img_icon, "img_icon");
    widget->img_icon = img_icon;
    
    lv_obj_t * lv_label_0 = lv_label_create(obj);
    lv_obj_set_style_pad_top(lv_label_0, 5, 0);
    widget->lv_label_0 = lv_label_0;


    icon_text_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void icon_text_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    icon_text_destructor_hook(obj);
}

static void icon_text_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&icon_text_class, e);
    if(res != LV_RESULT_OK) return;

    icon_text_event_hook(e);
}

