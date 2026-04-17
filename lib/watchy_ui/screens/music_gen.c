/**
 * @file music_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "music_gen.h"
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

lv_obj_t * music_create(void)
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
    lv_obj_set_name_static(lv_obj_0, "music_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    status_bar_create(lv_obj_0);
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_width(lv_label_0, 180);
    lv_obj_set_y(lv_label_0, 25);
    lv_obj_set_x(lv_label_0, 5);
    lv_label_set_text(lv_label_0, "Music Control\nConnected");
    lv_label_bind_text(lv_label_0, &subject_bluetooth_state, "Music Control\n%s");
    lv_obj_set_style_text_font(lv_label_0, NS_Bold_20, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_obj_set_y(lv_label_1, 64);
    lv_obj_set_width(lv_label_1, 200);
    lv_obj_set_align(lv_label_1, LV_ALIGN_TOP_MID);
    lv_label_set_translation_tag(lv_label_1, "track_volume");
    lv_obj_set_style_text_align(lv_label_1, LV_TEXT_ALIGN_CENTER, 0);
    
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
    lv_obj_set_width(lv_label_2, 140);
    lv_obj_set_y(lv_label_2, 0);
    lv_obj_set_align(lv_label_2, LV_ALIGN_BOTTOM_MID);
    lv_label_set_translation_tag(lv_label_2, "tap_next");
    lv_obj_set_style_text_align(lv_label_2, LV_TEXT_ALIGN_CENTER, 0);
    
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, ic_previous);
    lv_obj_set_align(lv_image_0, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_x(lv_image_0, -5);
    lv_obj_set_y(lv_image_0, 30);
    lv_obj_bind_flag_if_not_eq(lv_image_0, &subject_music_view, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_t * lv_image_1 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_1, ic_next);
    lv_obj_set_align(lv_image_1, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_x(lv_image_1, -5);
    lv_obj_set_y(lv_image_1, -5);
    lv_obj_bind_flag_if_not_eq(lv_image_1, &subject_music_view, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_t * lv_image_2 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_2, ic_pause);
    lv_obj_set_align(lv_image_2, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_x(lv_image_2, 5);
    lv_obj_set_y(lv_image_2, -5);
    lv_obj_bind_flag_if_not_eq(lv_image_2, &subject_music_view, LV_OBJ_FLAG_HIDDEN, 0);
    
    lv_obj_t * lv_image_3 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_3, ic_volume_up);
    lv_obj_set_align(lv_image_3, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_x(lv_image_3, -5);
    lv_obj_set_y(lv_image_3, 30);
    lv_obj_bind_flag_if_not_eq(lv_image_3, &subject_music_view, LV_OBJ_FLAG_HIDDEN, 1);
    
    lv_obj_t * lv_image_4 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_4, ic_volume_down);
    lv_obj_set_align(lv_image_4, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_x(lv_image_4, -5);
    lv_obj_set_y(lv_image_4, -5);
    lv_obj_bind_flag_if_not_eq(lv_image_4, &subject_music_view, LV_OBJ_FLAG_HIDDEN, 1);
    
    lv_obj_t * lv_image_5 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_5, ic_mute);
    lv_obj_set_align(lv_image_5, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_x(lv_image_5, 5);
    lv_obj_set_y(lv_image_5, -5);
    lv_obj_bind_flag_if_not_eq(lv_image_5, &subject_music_view, LV_OBJ_FLAG_HIDDEN, 1);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

