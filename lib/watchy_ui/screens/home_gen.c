/**
 * @file home_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "home_gen.h"
#include "../watchy_ui.h"

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

lv_obj_t * home_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_cont;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));
        lv_style_set_text_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_font(&style_main, NS_Regular_16);
        lv_style_set_pad_all(&style_main, 5);

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_pad_column(&style_cont, 5);
        lv_style_set_height(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_bg_opa(&style_cont, 0);
        lv_style_set_radius(&style_cont, 0);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_text_align(&style_cont, LV_TEXT_ALIGN_CENTER);
        lv_style_set_flex_main_place(&style_cont, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_cont, LV_FLEX_ALIGN_CENTER);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "home_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * bluetooth_0 = bluetooth_create(lv_obj_0);
    lv_obj_set_align(bluetooth_0, LV_ALIGN_TOP_RIGHT);
    
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, ic_nav);
    lv_obj_bind_flag_if_not_eq(lv_image_0, &subject_navigation, LV_OBJ_FLAG_HIDDEN, 1);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_0, &subject_time, NULL);
    lv_obj_set_style_text_font(lv_label_0, NS_Bold_40, 0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_0, 5);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_label_bind_text(lv_label_1, &subject_date, NULL);
    lv_obj_set_style_text_font(lv_label_1, NS_Regular_20, 0);
    lv_obj_set_align(lv_label_1, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_1, 45);
    
    lv_obj_t * icon_text_0 = icon_text_create(lv_obj_0);
    lv_obj_set_y(icon_text_0, 105);
    icon_text_set_icon(icon_text_0, ic_steps);
    icon_text_bind_text(icon_text_0, &subject_steps);
    
    lv_obj_t * icon_text_1 = icon_text_create(lv_obj_0);
    lv_obj_set_y(icon_text_1, 135);
    icon_text_set_icon(icon_text_1, ic_calories);
    icon_text_bind_text(icon_text_1, &subject_calories);
    
    lv_obj_t * icon_text_2 = icon_text_create(lv_obj_0);
    lv_obj_set_y(icon_text_2, 165);
    icon_text_set_icon(icon_text_2, ic_distance);
    icon_text_bind_text(icon_text_2, &subject_distance);
    icon_text_set_bind_format(icon_text_2, "%s");
    
    lv_obj_t * icon_text_3 = icon_text_create(lv_obj_0);
    lv_obj_set_align(icon_text_3, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_flex_flow(icon_text_3, LV_FLEX_FLOW_ROW_REVERSE);
    lv_obj_set_y(icon_text_3, 105);
    icon_text_set_icon(icon_text_3, ic_watch);
    icon_text_bind_text(icon_text_3, &subject_battery);
    icon_text_set_bind_format(icon_text_3, "%d%%");
    
    lv_obj_t * icon_text_4 = icon_text_create(lv_obj_0);
    lv_obj_set_align(icon_text_4, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_flex_flow(icon_text_4, LV_FLEX_FLOW_ROW_REVERSE);
    lv_obj_set_y(icon_text_4, 135);
    icon_text_set_icon(icon_text_4, ic_phone);
    icon_text_bind_text(icon_text_4, &subject_phone_battery);
    icon_text_set_bind_format(icon_text_4, "%d%%");
    
    lv_obj_t * icon_text_5 = icon_text_create(lv_obj_0);
    lv_obj_set_align(icon_text_5, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_flex_flow(icon_text_5, LV_FLEX_FLOW_ROW_REVERSE);
    lv_obj_set_y(icon_text_5, 165);
    icon_text_set_icon(icon_text_5, ic_sync);
    icon_text_bind_text(icon_text_5, &subject_last_sync);
    icon_text_set_bind_format(icon_text_5, "%s");
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_obj_1, 65);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_t * h_icon = lv_image_create(lv_obj_1);
    lv_obj_set_name(h_icon, "h_icon");
    lv_image_set_src(h_icon, ic_sun_cloud);
    lv_obj_set_x(h_icon, 46);
    lv_obj_set_y(h_icon, 51);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_2, &subject_temperature, NULL);
    lv_obj_set_style_text_font(lv_label_2, NS_Regular_30, 0);
    lv_obj_set_style_pad_top(lv_label_2, 5, 0);
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_3, &subject_temp_unit, NULL);
    lv_obj_set_style_text_font(lv_label_3, NS_Regular_16, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

