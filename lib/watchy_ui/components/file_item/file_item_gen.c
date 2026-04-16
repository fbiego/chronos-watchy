/**
 * @file file_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "file_item_gen.h"
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

lv_obj_t * file_item_create(lv_obj_t * parent, const void * icon, const char * text, const char * size)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_checked;
    static lv_style_t style_icon_checked;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, 200);
        lv_style_set_height(&style_main, 35);
        lv_style_set_bg_opa(&style_main, 255);
        lv_style_set_pad_all(&style_main, 5);
        lv_style_set_pad_column(&style_main, 5);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_radius(&style_main, 0);
        lv_style_set_text_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_font(&style_main, NS_Regular_20);
        lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_main, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_cross_place(&style_main, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_main, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&style_checked);
        lv_style_set_bg_color(&style_checked, lv_color_hex(0x000000));
        lv_style_set_text_color(&style_checked, lv_color_hex(0xffffff));

        lv_style_init(&style_icon_checked);
        lv_style_set_image_recolor(&style_icon_checked, lv_color_hex(0xffffff));
        lv_style_set_image_recolor_opa(&style_icon_checked, 255);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "file_item_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_STATE_TRICKLE, true);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_add_style(lv_obj_0, &style_checked, LV_STATE_CHECKED);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, icon);
    lv_obj_add_style(lv_image_0, &style_icon_checked, LV_STATE_CHECKED);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_flex_grow(lv_label_0, 1);
    lv_label_set_text(lv_label_0, text);
    lv_obj_set_style_pad_top(lv_label_0, 5, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_1, size);
    lv_obj_set_style_text_font(lv_label_1, NS_Regular_16, 0);
    lv_obj_set_style_pad_top(lv_label_1, 3, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

