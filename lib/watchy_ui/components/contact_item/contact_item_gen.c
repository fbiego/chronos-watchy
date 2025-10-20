/**
 * @file contact_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "contact_item_gen.h"
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

lv_obj_t * contact_item_create(lv_obj_t * parent, const char * name, const char * number, bool normal)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, 190);
        lv_style_set_height(&style_main, 50);
        lv_style_set_pad_all(&style_main, 5);
        lv_style_set_text_font(&style_main, NS_Regular_20);
        lv_style_set_border_width(&style_main, 1);
        lv_style_set_border_side(&style_main, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_border_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_radius(&style_main, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLL_ONE, true);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SNAPPABLE, true);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, name);
    lv_obj_set_style_text_font(lv_label_0, NS_Bold_20, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
    lv_obj_set_align(lv_label_1, LV_ALIGN_BOTTOM_LEFT);
    lv_label_set_text(lv_label_1, number);
    
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_obj_set_align(lv_image_0, LV_ALIGN_RIGHT_MID);
    lv_image_set_src(lv_image_0, ic_sos);
    lv_obj_set_flag(lv_image_0, LV_OBJ_FLAG_HIDDEN, normal);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "contact_item_#");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

