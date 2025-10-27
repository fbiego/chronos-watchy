/**
 * @file settings_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_gen.h"
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

lv_obj_t * settings_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_cont;
    static lv_style_t style_list;
    static lv_style_t style_chart;
    static lv_style_t style_bar;
    static lv_style_t style_bar_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, NS_Regular_16);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));
        lv_style_set_text_color(&style_main, lv_color_hex(0x000000));

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, lv_pct(100));
        lv_style_set_height(&style_cont, 175);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_pad_row(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_text_color(&style_cont, lv_color_hex(0x000000));
        lv_style_set_text_font(&style_cont, NS_Regular_16);

        lv_style_init(&style_list);
        lv_style_set_layout(&style_list, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_list, LV_FLEX_FLOW_COLUMN);

        lv_style_init(&style_chart);
        lv_style_set_width(&style_chart, 200);
        lv_style_set_height(&style_chart, 100);
        lv_style_set_border_width(&style_chart, 0);
        lv_style_set_radius(&style_chart, 0);
        lv_style_set_pad_column(&style_chart, 2);

        lv_style_init(&style_bar);
        lv_style_set_width(&style_bar, 180);
        lv_style_set_height(&style_bar, 30);
        lv_style_set_radius(&style_bar, 5);
        lv_style_set_bg_opa(&style_bar, 0);
        lv_style_set_border_width(&style_bar, 4);

        lv_style_init(&style_bar_indicator);
        lv_style_set_radius(&style_bar_indicator, 5);
        lv_style_set_bg_color(&style_bar_indicator, lv_color_hex(0x000000));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "settings_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * status_bar_0 = status_bar_create(lv_obj_0);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_1, 25);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_add_style(lv_obj_1, &style_list, 0);
    lv_obj_bind_flag_if_not_eq(lv_obj_1, &subject_settings_view, LV_OBJ_FLAG_HIDDEN, 0);
    lv_obj_t * list_item_0 = list_item_create(lv_obj_1, ic_bluetooth, "Interval", 0);
    
    lv_obj_t * list_item_1 = list_item_create(lv_obj_1, ic_configs, "Configs", 1);
    
    lv_obj_t * list_item_2 = list_item_create(lv_obj_1, ic_battery, "Battery", 2);
    
    lv_obj_t * list_item_3 = list_item_create(lv_obj_1, ic_storage, "Storage", 3);
    
    lv_obj_t * list_item_4 = list_item_create(lv_obj_1, ic_info, "About", 4);
    
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_2, 25);
    lv_obj_add_style(lv_obj_2, &style_cont, 0);
    lv_obj_bind_flag_if_not_eq(lv_obj_2, &subject_settings_view, LV_OBJ_FLAG_HIDDEN, 1);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_2);
    lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_MID);
    lv_obj_set_width(lv_label_0, 180);
    lv_obj_set_y(lv_label_0, 5);
    lv_label_set_text(lv_label_0, "BLE connect interval");
    lv_obj_set_style_text_font(lv_label_0, NS_Bold_20, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    lv_obj_set_align(lv_label_1, LV_ALIGN_TOP_MID);
    lv_obj_set_width(lv_label_1, 180);
    lv_obj_set_y(lv_label_1, 50);
    lv_label_set_text(lv_label_1, "NB: Connection to the phone is not always guaranteed");
    
    lv_obj_t * s_interval = lv_label_create(lv_obj_2);
    lv_obj_set_name(s_interval, "s_interval");
    lv_obj_set_align(s_interval, LV_ALIGN_TOP_MID);
    lv_label_set_text(s_interval, "10 mins");
    lv_obj_set_y(s_interval, 130);
    lv_obj_set_style_text_font(s_interval, NS_Bold_30, 0);
    
    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_3, 25);
    lv_obj_set_x(lv_obj_3, 0);
    lv_obj_add_style(lv_obj_3, &style_cont, 0);
    lv_obj_bind_flag_if_not_eq(lv_obj_3, &subject_settings_view, LV_OBJ_FLAG_HIDDEN, 2);
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_3);
    lv_obj_set_align(lv_label_2, LV_ALIGN_TOP_MID);
    lv_obj_set_width(lv_label_2, 190);
    lv_obj_set_y(lv_label_2, 5);
    lv_label_set_text(lv_label_2, "These can be changed from Chronos app");
    
    lv_obj_t * s_configs = lv_label_create(lv_obj_3);
    lv_obj_set_name(s_configs, "s_configs");
    lv_obj_set_align(s_configs, LV_ALIGN_TOP_MID);
    lv_obj_set_width(s_configs, 190);
    lv_obj_set_y(s_configs, 50);
    lv_label_set_text(s_configs, "Sleep time: 22:00 - 0700\n24 hour mode\nTemp units: C\nDistance units: miles\nDisplay: Dark");
    
    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_4, 25);
    lv_obj_add_style(lv_obj_4, &style_cont, 0);
    lv_obj_bind_flag_if_not_eq(lv_obj_4, &subject_settings_view, LV_OBJ_FLAG_HIDDEN, 3);
    lv_obj_t * a_date = lv_label_create(lv_obj_4);
    lv_obj_set_name(a_date, "a_date");
    lv_label_set_text(a_date, "Today");
    lv_obj_set_align(a_date, LV_ALIGN_TOP_MID);
    lv_obj_set_y(a_date, 0);
    
    lv_obj_t * bar_chart = lv_chart_create(lv_obj_4);
    lv_obj_set_name(bar_chart, "bar_chart");
    lv_obj_set_y(bar_chart, 22);
    lv_chart_set_point_count(bar_chart, 24);
    lv_chart_set_hor_div_line_count(bar_chart, 0);
    lv_chart_set_ver_div_line_count(bar_chart, 0);
    lv_obj_add_style(bar_chart, &style_chart, 0);
    lv_chart_set_axis_min_value(bar_chart, LV_CHART_AXIS_PRIMARY_Y, 0);
    lv_chart_set_axis_max_value(bar_chart, LV_CHART_AXIS_PRIMARY_Y, 100);
    lv_chart_series_t * lv_chart_series_0 = lv_chart_add_series(bar_chart, lv_color_hex(0x000000), LV_CHART_AXIS_PRIMARY_Y);
    static const int32_t bar_chart_values_0[] = {60, 43, 34, 24, 38, 54, 54, 20, 45, 0, 25, 56, 80, 34, 65, 45, 56, 50, 35, 15, 34, 65, 25, 56};
    lv_chart_set_series_values(bar_chart, lv_chart_series_0, bar_chart_values_0, 24);
    
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_4);
    lv_obj_set_align(lv_label_3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_x(lv_label_3, 10);
    lv_obj_set_y(lv_label_3, -10);
    lv_label_bind_text(lv_label_3, &subject_battery, "%d%%");
    lv_obj_set_style_text_font(lv_label_3, NS_Bold_20, 0);
    
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_4);
    lv_obj_set_align(lv_label_4, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_x(lv_label_4, -10);
    lv_obj_set_y(lv_label_4, -10);
    lv_label_bind_text(lv_label_4, &subject_voltage, "%dmV");
    lv_obj_set_style_text_font(lv_label_4, NS_Bold_20, 0);
    
    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_5, 25);
    lv_obj_add_style(lv_obj_5, &style_cont, 0);
    lv_obj_bind_flag_if_not_eq(lv_obj_5, &subject_settings_view, LV_OBJ_FLAG_HIDDEN, 4);
    lv_obj_t * s_total = lv_label_create(lv_obj_5);
    lv_obj_set_name(s_total, "s_total");
    lv_obj_set_x(s_total, 10);
    lv_obj_set_y(s_total, 10);
    lv_label_set_text(s_total, "1334kB");
    lv_obj_set_style_text_font(s_total, NS_Regular_20, 0);
    
    lv_obj_t * s_bar = lv_bar_create(lv_obj_5);
    lv_obj_set_name(s_bar, "s_bar");
    lv_bar_set_value(s_bar, 50, false);
    lv_obj_set_align(s_bar, LV_ALIGN_TOP_MID);
    lv_obj_set_y(s_bar, 30);
    lv_obj_add_style(s_bar, &style_bar, 0);
    lv_obj_add_style(s_bar, &style_bar_indicator, LV_PART_INDICATOR);
    
    lv_obj_t * s_used = lv_label_create(lv_obj_5);
    lv_obj_set_name(s_used, "s_used");
    lv_obj_set_x(s_used, 10);
    lv_obj_set_y(s_used, 64);
    lv_label_set_text(s_used, "134kB\nused");
    
    lv_obj_t * s_free = lv_label_create(lv_obj_5);
    lv_obj_set_name(s_free, "s_free");
    lv_obj_set_align(s_free, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_x(s_free, -10);
    lv_obj_set_y(s_free, 65);
    lv_obj_set_style_text_align(s_free, LV_TEXT_ALIGN_RIGHT, 0);
    lv_label_set_text(s_free, "954kB\nfree");
    
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_5);
    lv_label_set_text(lv_label_5, "Data Records");
    lv_obj_set_align(lv_label_5, LV_ALIGN_TOP_MID);
    lv_obj_set_y(lv_label_5, 105);
    lv_obj_set_style_text_font(lv_label_5, NS_Regular_20, 0);
    lv_obj_set_style_text_decor(lv_label_5, LV_TEXT_DECOR_UNDERLINE, 0);
    
    lv_obj_t * s_steps = lv_label_create(lv_obj_5);
    lv_obj_set_name(s_steps, "s_steps");
    lv_obj_set_x(s_steps, 10);
    lv_obj_set_y(s_steps, 130);
    lv_label_set_text(s_steps, "Steps\n21");
    
    lv_obj_t * s_battery = lv_label_create(lv_obj_5);
    lv_obj_set_name(s_battery, "s_battery");
    lv_obj_set_x(s_battery, -10);
    lv_obj_set_y(s_battery, 130);
    lv_obj_set_align(s_battery, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_style_text_align(s_battery, LV_TEXT_ALIGN_RIGHT, 0);
    lv_label_set_text(s_battery, "Battery\n21");
    
    lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_6, 25);
    lv_obj_add_style(lv_obj_6, &style_cont, 0);
    lv_obj_bind_flag_if_not_eq(lv_obj_6, &subject_settings_view, LV_OBJ_FLAG_HIDDEN, 5);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_6);
    lv_image_set_src(lv_image_0, ic_chronos_40);
    lv_obj_set_x(lv_image_0, 10);
    lv_obj_set_y(lv_image_0, 10);
    
    lv_obj_t * lv_label_6 = lv_label_create(lv_obj_6);
    lv_label_set_text(lv_label_6, "Chronos\nWatchy");
    lv_obj_set_x(lv_label_6, 60);
    lv_obj_set_y(lv_label_6, 10);
    lv_obj_set_style_text_font(lv_label_6, NS_Bold_20, 0);
    
    lv_obj_t * about_version = lv_label_create(lv_obj_6);
    lv_obj_set_name(about_version, "about_version");
    lv_label_set_text(about_version, "v1.0.0 (20251018)");
    lv_obj_set_x(about_version, 10);
    lv_obj_set_y(about_version, 60);
    
    lv_obj_t * lv_label_7 = lv_label_create(lv_obj_6);
    lv_label_set_text(lv_label_7, "");
    lv_label_bind_text(lv_label_7, &subject_address, NULL);
    lv_obj_set_x(lv_label_7, 10);
    lv_obj_set_y(lv_label_7, 80);
    
    lv_obj_t * about_ch_esp = lv_label_create(lv_obj_6);
    lv_obj_set_name(about_ch_esp, "about_ch_esp");
    lv_label_set_text(about_ch_esp, "ChronosESP32 v1.8.2");
    lv_obj_set_x(about_ch_esp, 10);
    lv_obj_set_y(about_ch_esp, 110);
    
    lv_obj_t * about_ch_app = lv_label_create(lv_obj_6);
    lv_obj_set_name(about_ch_app, "about_ch_app");
    lv_label_set_text(about_ch_app, "Chronos v3.8.5 (53)\nLast sync: 2h 34m ago");
    lv_obj_set_x(about_ch_app, 10);
    lv_obj_set_y(about_ch_app, 130);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

