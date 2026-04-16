/**
 * @file weather_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "weather_gen.h"
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

lv_obj_t * weather_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_row;
    static lv_style_t style_cont;
    static lv_style_t style_forecast;
    static lv_style_t style_scrollbar;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));
        lv_style_set_text_color(&style_main, lv_color_hex(0x000000));

        lv_style_init(&style_row);
        lv_style_set_layout(&style_row, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_row, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_row(&style_row, 5);

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, 200);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_height(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_radius(&style_cont, 0);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_text_align(&style_cont, LV_TEXT_ALIGN_CENTER);
        lv_style_set_flex_main_place(&style_cont, LV_FLEX_ALIGN_SPACE_AROUND);

        lv_style_init(&style_forecast);
        lv_style_set_width(&style_forecast, 190);
        lv_style_set_height(&style_forecast, 90);
        lv_style_set_pad_all(&style_forecast, 0);
        lv_style_set_radius(&style_forecast, 0);
        lv_style_set_layout(&style_forecast, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_forecast, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_track_place(&style_forecast, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_row(&style_forecast, 0);
        lv_style_set_border_width(&style_forecast, 0);

        lv_style_init(&style_scrollbar);
        lv_style_set_bg_color(&style_scrollbar, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_scrollbar, 255);
        lv_style_set_pad_all(&style_scrollbar, 0);
        lv_style_set_pad_right(&style_scrollbar, -2);
        lv_style_set_radius(&style_scrollbar, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "weather_#");
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    status_bar_create(lv_obj_0);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_1, 50);
    lv_obj_set_style_flex_main_place(lv_obj_1, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(lv_obj_1, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_t * w_icon = lv_image_create(lv_obj_1);
    lv_obj_set_name(w_icon, "w_icon");
    lv_image_set_src(w_icon, ic_sun_cloud);
    lv_obj_set_x(w_icon, 46);
    lv_obj_set_y(w_icon, 51);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_0, &subject_temperature, NULL);
    lv_obj_set_style_text_font(lv_label_0, NS_Bold_40, 0);
    lv_obj_set_style_pad_top(lv_label_0, 10, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_1, &subject_temp_unit, NULL);
    lv_obj_set_style_text_font(lv_label_1, NS_Bold_20, 0);
    
    lv_obj_t * w_city = lv_label_create(lv_obj_0);
    lv_obj_set_name(w_city, "w_city");
    lv_label_set_text(w_city, "Nairobi");
    lv_obj_set_align(w_city, LV_ALIGN_TOP_MID);
    lv_obj_set_y(w_city, 30);
    lv_obj_set_style_text_font(w_city, NS_Regular_20, 0);
    
    lv_obj_t * w_forecast = lv_obj_create(lv_obj_0);
    lv_obj_set_name(w_forecast, "w_forecast");
    lv_obj_set_align(w_forecast, LV_ALIGN_TOP_MID);
    lv_obj_set_y(w_forecast, 110);
    lv_obj_add_style(w_forecast, &style_forecast, 0);
    lv_obj_add_style(w_forecast, &style_scrollbar, LV_PART_SCROLLBAR);
    forecast_create(w_forecast, "MON", ic_cloud, "24");
    
    forecast_create(w_forecast, "TUE", ic_sun_cloud, "23");
    
    forecast_create(w_forecast, "WED", ic_sunny, "25");
    
    forecast_create(w_forecast, "MON", ic_cloud, "24");
    
    forecast_create(w_forecast, "TUE", ic_sun_cloud, "23");
    
    forecast_create(w_forecast, "WED", ic_sunny, "25");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

