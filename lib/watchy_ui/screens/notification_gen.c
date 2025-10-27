/**
 * @file notification_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "notification_gen.h"
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

lv_obj_t * notification_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_row;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));
        lv_style_set_text_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_font(&style_main, NS_Regular_16);

        lv_style_init(&style_row);
        lv_style_set_layout(&style_row, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_row, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_row(&style_row, 5);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "notification_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * status_bar_0 = status_bar_create(lv_obj_0);
    
    lv_obj_t * n_icon = lv_image_create(lv_obj_0);
    lv_obj_set_name(n_icon, "n_icon");
    lv_image_set_src(n_icon, ic_whatsapp);
    lv_obj_set_x(n_icon, 5);
    lv_obj_set_y(n_icon, 30);
    
    lv_obj_t * n_title = lv_label_create(lv_obj_0);
    lv_obj_set_name(n_title, "n_title");
    lv_label_set_text(n_title, "Whatsapp");
    lv_obj_set_style_text_font(n_title, NS_Regular_20, 0);
    lv_obj_set_x(n_title, 45);
    lv_obj_set_y(n_title, 30);
    lv_obj_set_width(n_title, 150);
    lv_obj_set_height(n_title, 20);
    
    lv_obj_t * n_count = lv_label_create(lv_obj_0);
    lv_obj_set_name(n_count, "n_count");
    lv_label_set_text(n_count, "1/10");
    lv_obj_set_align(n_count, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_y(n_count, 50);
    lv_obj_set_x(n_count, -5);
    
    lv_obj_t * n_message = lv_label_create(lv_obj_0);
    lv_obj_set_name(n_message, "n_message");
    lv_label_set_text(n_message, "Notifications are sent from the phone via Chronos app when connected. Not realtime since bluetooth is not always on to reduce power consumption.");
    lv_obj_set_width(n_message, 200);
    lv_obj_set_y(n_message, 70);
    lv_obj_set_height(n_message, 130);
    lv_obj_set_style_pad_all(n_message, 5, 0);
    
    lv_obj_t * n_time = lv_label_create(lv_obj_0);
    lv_obj_set_name(n_time, "n_time");
    lv_label_set_text(n_time, "12:40");
    lv_obj_set_x(n_time, 45);
    lv_obj_set_y(n_time, 50);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

