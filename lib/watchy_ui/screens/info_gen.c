/**
 * @file info_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "info_gen.h"
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

lv_obj_t * info_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));
        lv_style_set_text_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_text_font(&style_main, NS_Regular_20);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * info_icon = lv_image_create(lv_obj_0);
    lv_obj_set_name(info_icon, "info_icon");
    lv_image_set_src(info_icon, ic_sleep_mode);
    lv_obj_set_align(info_icon, LV_ALIGN_TOP_MID);
    lv_obj_set_y(info_icon, 10);
    
    lv_obj_t * info_text = lv_label_create(lv_obj_0);
    lv_obj_set_name(info_text, "info_text");
    lv_obj_set_y(info_text, 80);
    lv_obj_set_width(info_text, lv_pct(100));
    lv_label_set_text(info_text, "Watchy is sleeping until 07:00. Wake it up by pressing any button.");
    lv_obj_set_style_text_align(info_text, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_all(info_text, 5, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "info");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

