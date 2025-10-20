/**
 * @file forecast_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "forecast_gen.h"
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

lv_obj_t * forecast_create(lv_obj_t * parent, const char * day, const void * icon, const char * temp)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_cont;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, 180);
        lv_style_set_height(&style_main, 30);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_text_font(&style_main, NS_Regular_20);
        lv_style_set_border_width(&style_main, 1);
        lv_style_set_border_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_border_side(&style_main, LV_BORDER_SIDE_TOP);
        lv_style_set_radius(&style_main, 0);

        lv_style_init(&style_cont);
        lv_style_set_height(&style_cont, lv_pct(100));
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_width(&style_cont, LV_SIZE_CONTENT);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_pad_column(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_flex_cross_place(&style_cont, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_track_place(&style_cont, LV_FLEX_ALIGN_CENTER);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, day);
    lv_obj_set_y(lv_label_0, 2);
    lv_obj_set_align(lv_label_0, LV_ALIGN_LEFT_MID);
    
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
    lv_image_set_src(lv_image_0, icon);
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_RIGHT_MID);
    lv_obj_set_y(lv_obj_1, 2);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_1, temp);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_2, &subject_temp_unit, NULL);
    lv_obj_set_style_text_font(lv_label_2, NS_Regular_16, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "forecast_#");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

