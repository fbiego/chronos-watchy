/**
 * @file activity_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "activity_gen.h"
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

lv_obj_t * activity_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_row;
    static lv_style_t style_cont;
    static lv_style_t style_chart;
    static lv_style_t style_chart_items;

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

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, 200);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_height(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_radius(&style_cont, 0);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_text_align(&style_cont, LV_TEXT_ALIGN_CENTER);
        lv_style_set_flex_main_place(&style_cont, LV_FLEX_ALIGN_SPACE_AROUND);

        lv_style_init(&style_chart);
        lv_style_set_width(&style_chart, 200);
        lv_style_set_height(&style_chart, 85);
        lv_style_set_border_width(&style_chart, 0);
        lv_style_set_radius(&style_chart, 0);
        lv_style_set_pad_column(&style_chart, 2);

        lv_style_init(&style_chart_items);
        lv_style_set_pad_column(&style_chart_items, 0);
        lv_style_set_pad_row(&style_chart_items, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "activity_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * status_bar_0 = status_bar_create(lv_obj_0);
    
    lv_obj_t * a_date = lv_label_create(lv_obj_0);
    lv_obj_set_name(a_date, "a_date");
    lv_label_set_text(a_date, "Today");
    lv_obj_set_align(a_date, LV_ALIGN_TOP_MID);
    lv_obj_set_y(a_date, 24);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_label_set_text(lv_label_0, "No Data");
    
    lv_obj_t * bar_chart = lv_chart_create(lv_obj_0);
    lv_obj_set_name(bar_chart, "bar_chart");
    lv_obj_set_y(bar_chart, 40);
    lv_chart_set_point_count(bar_chart, 17);
    lv_chart_set_hor_div_line_count(bar_chart, 0);
    lv_chart_set_ver_div_line_count(bar_chart, 0);
    lv_obj_add_style(bar_chart, &style_chart, 0);
    lv_chart_set_axis_min_value(bar_chart, LV_CHART_AXIS_PRIMARY_Y, 0);
    lv_chart_set_axis_max_value(bar_chart, LV_CHART_AXIS_PRIMARY_Y, 1000);
    lv_chart_series_t * lv_chart_series_0 = lv_chart_add_series(bar_chart, lv_color_hex(0x000000), LV_CHART_AXIS_PRIMARY_Y);
    static const int32_t bar_chart_values_0[] = {650, 345, 0, 245, 56, 80, 345, 65, 245, 456, 850, 345, 150, 345, 65, 245, 56};
    lv_chart_set_series_values(bar_chart, lv_chart_series_0, bar_chart_values_0, 17);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(lv_obj_1, -45);
    lv_obj_set_x(lv_obj_1, 0);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_1);
    lv_image_set_src(lv_image_0, ic_steps);
    
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_1);
    lv_image_set_src(lv_image_1, ic_calories);
    
    lv_obj_t * lv_image_2 = lv_image_create(lv_obj_1);
    lv_image_set_src(lv_image_2, ic_distance);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_2, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(lv_obj_2, -20);
    lv_obj_set_x(lv_obj_2, 0);
    lv_obj_set_style_text_font(lv_obj_2, NS_Regular_20, 0);
    lv_obj_add_style(lv_obj_2, &style_cont, 0);
    lv_obj_t * a_steps = lv_label_create(lv_obj_2);
    lv_obj_set_name(a_steps, "a_steps");
    lv_obj_set_width(a_steps, 60);
    lv_label_set_text(a_steps, "1234");
    
    lv_obj_t * a_calories = lv_label_create(lv_obj_2);
    lv_obj_set_name(a_calories, "a_calories");
    lv_obj_set_width(a_calories, 60);
    lv_label_set_text(a_calories, "324");
    
    lv_obj_t * a_distance = lv_label_create(lv_obj_2);
    lv_obj_set_name(a_distance, "a_distance");
    lv_obj_set_width(a_distance, 60);
    lv_label_set_text(a_distance, "1.3");
    
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_3, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(lv_obj_3, -1);
    lv_obj_set_x(lv_obj_3, 0);
    lv_obj_add_style(lv_obj_3, &style_cont, 0);
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_3);
    lv_obj_set_width(lv_label_1, 60);
    lv_label_set_text(lv_label_1, "steps");
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_3);
    lv_obj_set_width(lv_label_2, 60);
    lv_label_set_text(lv_label_2, "kcal");
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_3);
    lv_obj_set_width(lv_label_3, 60);
    lv_label_bind_text(lv_label_3, &subject_distance_unit, NULL);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

