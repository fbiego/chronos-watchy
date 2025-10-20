/**
 * @file qr_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "qr_gen.h"
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

lv_obj_t * qr_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, NS_Bold_20);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * q_info = lv_label_create(lv_obj_0);
    lv_obj_set_name(q_info, "q_info");
    lv_obj_set_width(q_info, 180);
    lv_obj_set_align(q_info, LV_ALIGN_CENTER);
    lv_label_set_text(q_info, "There are no QR codes available, connect to Chronos App and sync them first");
    lv_obj_set_style_text_font(q_info, NS_Regular_20, 0);
    
    lv_obj_t * q_app = lv_label_create(lv_obj_0);
    lv_obj_set_name(q_app, "q_app");
    lv_obj_set_align(q_app, LV_ALIGN_TOP_MID);
    lv_label_set_text(q_app, "Chronos");
    
    lv_obj_t * q_link = lv_qrcode_create(lv_obj_0);
    lv_obj_set_name(q_link, "q_link");
    lv_obj_set_align(q_link, LV_ALIGN_CENTER);
    lv_obj_set_y(q_link, 10);
    lv_qrcode_set_size(q_link, 180);
    lv_qrcode_set_data(q_link, "https://chronos.ke/");

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "qr");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

