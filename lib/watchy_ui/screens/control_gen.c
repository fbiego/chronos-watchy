/**
 * @file control_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "control_gen.h"
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

lv_obj_t * control_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, NS_Regular_16);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * status_bar_0 = status_bar_create(lv_obj_0);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_x(lv_label_0, -45);
    lv_obj_set_y(lv_label_0, 38);
    lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(lv_label_0, "Find Phone");
    lv_obj_set_style_text_align(lv_label_0, LV_TEXT_ALIGN_CENTER, 0);
    
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, ic_search);
    lv_obj_set_align(lv_image_0, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_x(lv_image_0, -5);
    lv_obj_set_y(lv_image_0, 30);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_obj_set_width(lv_label_1, 180);
    lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
    lv_label_set_text(lv_label_1, "Camera\nReady");
    lv_label_bind_text(lv_label_1, &subject_camera_state, "Camera\n%s");
    lv_obj_set_style_text_align(lv_label_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font(lv_label_1, NS_Bold_20, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
    lv_obj_set_y(lv_label_2, -5);
    lv_obj_set_align(lv_label_2, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(lv_label_2, "Press buttons\nor Double tap");
    lv_obj_set_style_text_align(lv_label_2, LV_TEXT_ALIGN_CENTER, 0);
    
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_1, ic_camera);
    lv_obj_set_align(lv_image_1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_x(lv_image_1, 5);
    lv_obj_set_y(lv_image_1, -5);
    
    lv_obj_t * lv_image_2 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_2, ic_camera);
    lv_obj_set_align(lv_image_2, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_x(lv_image_2, -5);
    lv_obj_set_y(lv_image_2, -5);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "control");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

