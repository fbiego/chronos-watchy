/**
 * @file bluetooth_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "bluetooth_gen.h"
#include "watchy_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * bluetooth_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

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

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, ic_bt_con);
    lv_obj_bind_flag_if_not_eq(lv_image_0, &subject_bluetooth, LV_OBJ_FLAG_HIDDEN, 2);
    
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_1, ic_bt_on);
    lv_obj_bind_flag_if_not_eq(lv_image_1, &subject_bluetooth, LV_OBJ_FLAG_HIDDEN, 1);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "bluetooth_#");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

