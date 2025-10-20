/**
 * @file status_bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "status_bar_gen.h"
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

lv_obj_t * status_bar_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, 200);
        lv_style_set_height(&style_main, 22);
        lv_style_set_radius(&style_main, 0);
        lv_style_set_border_width(&style_main, 1);
        lv_style_set_border_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_border_side(&style_main, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_pad_top(&style_main, 0);
        lv_style_set_pad_left(&style_main, 5);
        lv_style_set_pad_right(&style_main, 5);
        lv_style_set_pad_column(&style_main, 5);
        lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
        lv_style_set_flex_track_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_text_font(&style_main, NS_Regular_16);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_0, &subject_time, NULL);
    lv_obj_set_flex_grow(lv_label_0, 1);
    lv_obj_set_style_pad_top(lv_label_0, 4, 0);
    
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, ic_nav);
    lv_obj_bind_flag_if_not_eq(lv_image_0, &subject_navigation, LV_OBJ_FLAG_HIDDEN, 1);
    
    lv_obj_t * bluetooth_0 = bluetooth_create(lv_obj_0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_1, &subject_battery, "%d%%");
    lv_obj_set_style_pad_top(lv_label_1, 4, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "status_bar_#");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

