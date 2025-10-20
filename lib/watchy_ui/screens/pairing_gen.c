/**
 * @file pairing_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "pairing_gen.h"
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

lv_obj_t * pairing_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_text;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, NS_Regular_16);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));

        lv_style_init(&style_text);
        lv_style_set_width(&style_text, 170);
        lv_style_set_height(&style_text, 18);
        lv_style_set_text_align(&style_text, LV_TEXT_ALIGN_CENTER);
        lv_style_set_transform_pivot_x(&style_text, 85);
        lv_style_set_transform_pivot_y(&style_text, 9);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * status_bar_0 = status_bar_create(lv_obj_0);
    
    lv_obj_t * p_qr = lv_qrcode_create(lv_obj_0);
    lv_obj_set_name(p_qr, "p_qr");
    lv_obj_set_y(p_qr, 30);
    lv_obj_set_align(p_qr, LV_ALIGN_TOP_MID);
    lv_qrcode_set_size(p_qr, 150);
    lv_qrcode_set_data(p_qr, "https://chronos.ke/");
    
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(lv_label_0, "Scan with Chronos");
    
    lv_obj_t * p_name = lv_label_create(lv_obj_0);
    lv_obj_set_name(p_name, "p_name");
    lv_label_bind_text(p_name, &subject_ble_name, NULL);
    lv_obj_set_style_transform_rotation(p_name, -900, 0);
    lv_obj_set_align(p_name, LV_ALIGN_LEFT_MID);
    lv_obj_set_x(p_name, -72);
    lv_obj_add_style(p_name, &style_text, 0);
    
    lv_obj_t * p_address = lv_label_create(lv_obj_0);
    lv_obj_set_name(p_address, "p_address");
    lv_obj_set_align(p_address, LV_ALIGN_RIGHT_MID);
    lv_label_bind_text(p_address, &subject_address, NULL);
    lv_obj_set_style_transform_rotation(p_address, 900, 0);
    lv_obj_set_x(p_address, 70);
    lv_obj_add_style(p_address, &style_text, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "pairing");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

