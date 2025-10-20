/**
 * @file contacts_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "contacts_gen.h"
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

lv_obj_t * contacts_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_contacts;
    static lv_style_t style_scrollbar;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, NS_Regular_16);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));

        lv_style_init(&style_contacts);
        lv_style_set_width(&style_contacts, 200);
        lv_style_set_height(&style_contacts, 175);
        lv_style_set_pad_all(&style_contacts, 0);
        lv_style_set_radius(&style_contacts, 0);
        lv_style_set_layout(&style_contacts, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_contacts, LV_FLEX_FLOW_COLUMN);
        lv_style_set_pad_row(&style_contacts, 0);
        lv_style_set_border_width(&style_contacts, 0);

        lv_style_init(&style_scrollbar);
        lv_style_set_bg_color(&style_scrollbar, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_scrollbar, 255);
        lv_style_set_pad_all(&style_scrollbar, 0);
        lv_style_set_pad_right(&style_scrollbar, 2);
        lv_style_set_radius(&style_scrollbar, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * status_bar_0 = status_bar_create(lv_obj_0);
    
    lv_obj_t * c_info = lv_label_create(lv_obj_0);
    lv_obj_set_name(c_info, "c_info");
    lv_obj_set_width(c_info, 180);
    lv_obj_set_align(c_info, LV_ALIGN_CENTER);
    lv_label_set_text(c_info, "There are no contacts available, connect to Chronos App and sync them first");
    lv_obj_set_style_text_font(c_info, NS_Regular_20, 0);
    
    lv_obj_t * c_list = lv_obj_create(lv_obj_0);
    lv_obj_set_name(c_list, "c_list");
    lv_obj_set_align(c_list, LV_ALIGN_TOP_MID);
    lv_obj_set_y(c_list, 25);
    lv_obj_add_style(c_list, &style_contacts, 0);
    lv_obj_add_style(c_list, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_t * Taylor = contact_item_create(c_list, "Taylor", "03903456726", false);
    
    lv_obj_t * John = contact_item_create(c_list, "John", "03903456726", true);
    
    lv_obj_t * Sarah = contact_item_create(c_list, "Sarah", "03903456726", true);
    
    lv_obj_t * Jane = contact_item_create(c_list, "Jane", "03903456726", true);
    
    lv_obj_t * Rodgers = contact_item_create(c_list, "Rodgers", "03903456726", true);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "contacts");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

