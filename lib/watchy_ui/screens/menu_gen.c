/**
 * @file menu_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "menu_gen.h"
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

lv_obj_t * menu_create(void)
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
    lv_obj_set_name_static(lv_obj_0, "menu_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    status_bar_create(lv_obj_0);
    
    lv_obj_t * m_icon = lv_image_create(lv_obj_0);
    lv_obj_set_name(m_icon, "m_icon");
    lv_image_set_src(m_icon, ic_notifications);
    lv_obj_set_align(m_icon, LV_ALIGN_CENTER);
    
    lv_obj_t * m_text = lv_label_create(lv_obj_0);
    lv_obj_set_name(m_text, "m_text");
    lv_label_set_translation_tag(m_text, "notifications");
    lv_obj_set_align(m_text, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_y(m_text, -10);
    lv_obj_set_style_text_font(m_text, NS_Bold_20, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

