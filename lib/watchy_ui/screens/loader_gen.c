/**
 * @file loader_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "loader_gen.h"
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

lv_obj_t * loader_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_cont;
    static lv_style_t style_list;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, NS_Regular_16);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));

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

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "loader_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * status_bar_0 = status_bar_create(lv_obj_0);
    
    lv_obj_t * c_info = lv_label_create(lv_obj_0);
    lv_obj_set_name(c_info, "c_info");
    lv_obj_set_width(c_info, 180);
    lv_obj_set_align(c_info, LV_ALIGN_CENTER);
    lv_label_set_text(c_info, "There are no files available on the flash storage");
    lv_obj_set_style_text_font(c_info, NS_Regular_20, 0);
    
    lv_obj_t * file_list = lv_obj_create(lv_obj_0);
    lv_obj_set_name(file_list, "file_list");
    lv_obj_set_y(file_list, 25);
    lv_obj_set_scrollbar_mode(file_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(file_list, &style_cont, 0);
    lv_obj_add_style(file_list, &style_list, 0);
    lv_obj_t * file_item_0 = file_item_create(file_list, ic_steps, "Bluetooth", "12kb");
    lv_obj_set_state(file_item_0, LV_STATE_CHECKED, true);
    
    lv_obj_t * file_item_1 = file_item_create(file_list, ic_steps, "Bluetooth", "12kb");
    
    lv_obj_t * file_item_2 = file_item_create(file_list, ic_steps, "Bluetooth", "12kb");
    
    lv_obj_t * file_item_3 = file_item_create(file_list, ic_steps, "Bluetooth", "12kb");
    
    lv_obj_t * file_item_4 = file_item_create(file_list, ic_steps, "Bluetooth", "12kb");
    
    lv_obj_t * file_item_5 = file_item_create(file_list, ic_steps, "Bluetooth", "12kb");
    
    lv_obj_t * file_item_6 = file_item_create(file_list, ic_steps, "Bluetooth", "12kb");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

