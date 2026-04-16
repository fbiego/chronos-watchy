/**
 * @file face_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "face_item_gen.h"
#include "../../watchy_ui.h"

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

lv_obj_t * face_item_create(lv_obj_t * parent, const void * image, const char * name)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_cont;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, 200);
        lv_style_set_height(&style_main, 200);
        lv_style_set_radius(&style_main, 0);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_pad_top(&style_main, 10);
        lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_main, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_text_font(&style_main, NS_Bold_20);

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, 154);
        lv_style_set_height(&style_cont, 154);
        lv_style_set_border_width(&style_cont, 2);
        lv_style_set_border_color(&style_cont, lv_color_hex(0x000000));
        lv_style_set_radius(&style_cont, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "face_item_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, image);
    lv_obj_add_style(lv_image_0, &style_cont, 0);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, name);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

