/**
 * @file watchy_ui.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "watchy_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_font_t NS_Regular_16_rt;
static lv_font_t NS_Regular_20_rt;
static lv_font_t NS_Regular_30_rt;
static lv_font_t NS_Bold_20_rt;
static lv_font_t NS_Bold_30_rt;
static lv_font_t NS_Bold_40_rt;

extern lv_font_t NS_Regular_16_data;
extern lv_font_t NS_Regular_20_data;
extern lv_font_t NS_Regular_30_data;
extern lv_font_t NS_Bold_20_data;
extern lv_font_t NS_Bold_30_data;
extern lv_font_t NS_Bold_40_data;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void watchy_ui_init(const char * asset_path)
{
    watchy_ui_init_gen(asset_path);

    /* Add your own custom code here if needed */

    NS_Regular_16_rt = NS_Regular_16_data;
    NS_Regular_20_rt = NS_Regular_20_data;
    NS_Regular_30_rt = NS_Regular_30_data;
    NS_Bold_20_rt = NS_Bold_20_data;
    NS_Bold_30_rt = NS_Bold_30_data;
    NS_Bold_40_rt = NS_Bold_40_data;

    NS_Regular_16 = &NS_Regular_16_rt;
    NS_Regular_20 = &NS_Regular_20_rt;
    NS_Regular_30 = &NS_Regular_30_rt;
    NS_Bold_20 = &NS_Bold_20_rt;
    NS_Bold_30 = &NS_Bold_30_rt;
    NS_Bold_40 = &NS_Bold_40_rt;

    NS_Regular_16->fallback = NS_Regular_ru_16;
    NS_Regular_20->fallback = NS_Regular_ru_20;
    NS_Regular_30->fallback = NS_Regular_ru_30;
    NS_Bold_20->fallback = NS_Bold_ru_20;
    NS_Bold_30->fallback = NS_Bold_ru_30;
    NS_Bold_40->fallback = NS_Bold_ru_40;
}

void watchy_ui_set_language(uint8_t id)
{
    switch(id) {
        case 1: lv_translation_set_language("en"); break;
        case 5: lv_translation_set_language("ru"); break;
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/