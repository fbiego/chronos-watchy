/**
 * @file navigation_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "navigation_gen.h"
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

lv_obj_t * navigation_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_panel;
    static lv_style_t style_cont;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, NS_Regular_16);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));

        lv_style_init(&style_panel);
        lv_style_set_width(&style_panel, lv_pct(100));
        lv_style_set_height(&style_panel, 175);
        lv_style_set_radius(&style_panel, 0);
        lv_style_set_border_width(&style_panel, 0);
        lv_style_set_pad_all(&style_panel, 0);
        lv_style_set_pad_top(&style_panel, 5);
        lv_style_set_pad_row(&style_panel, 5);
        lv_style_set_layout(&style_panel, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_panel, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_cross_place(&style_panel, LV_FLEX_ALIGN_CENTER);
        lv_style_set_text_align(&style_panel, LV_TEXT_ALIGN_CENTER);
        lv_style_set_text_font(&style_panel, NS_Regular_16);

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, 48);
        lv_style_set_height(&style_cont, 48);
        lv_style_set_radius(&style_cont, 0);
        lv_style_set_border_color(&style_cont, lv_color_hex(0x000000));
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_bg_image_src(&style_cont, ic_chronos_40);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "navigation_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * status_bar_0 = status_bar_create(lv_obj_0);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_y(lv_obj_1, 25);
    lv_obj_add_style(lv_obj_1, &style_panel, 0);
    lv_obj_t * n_text = lv_label_create(lv_obj_1);
    lv_obj_set_width(n_text, lv_pct(100));
    lv_obj_set_name(n_text, "n_text");
    lv_label_set_text(n_text, "10:20 ETA\n5 mins | 1.6km");
    
    lv_obj_t * n_distance = lv_label_create(lv_obj_1);
    lv_obj_set_width(n_distance, lv_pct(100));
    lv_obj_set_name(n_distance, "n_distance");
    lv_label_set_text(n_distance, "100m");
    lv_obj_set_style_text_font(n_distance, NS_Bold_20, 0);
    
    lv_obj_t * n_icon = lv_obj_create(lv_obj_1);
    lv_obj_set_name(n_icon, "n_icon");
    lv_obj_add_style(n_icon, &style_cont, 0);
    
    lv_obj_t * n_direction = lv_label_create(lv_obj_1);
    lv_obj_set_width(n_direction, lv_pct(100));
    lv_obj_set_name(n_direction, "n_direction");
    lv_label_set_text(n_direction, "Turn left towards Kenyatta avenue at the round about");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

