/**
 * @file weather_icon_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "weather_icon_gen.h"
#include "src/others/xml/parsers/lv_xml_obj_parser.h"
#include "src/others/xml/lv_xml_widget.h"
#include "src/others/xml/lv_xml_parser.h"

#if LV_USE_XML

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

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void * weather_icon_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = weather_icon_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create weather_icon");
        return NULL;
    }

    return item;
}

void weather_icon_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("no_weather", name)) {
            weather_icon_set_no_weather(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("sun_cloud", name)) {
            weather_icon_set_sun_cloud(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("sunny", name)) {
            weather_icon_set_sunny(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("snow", name)) {
            weather_icon_set_snow(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("rainy", name)) {
            weather_icon_set_rainy(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("cloud", name)) {
            weather_icon_set_cloud(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("tornado", name)) {
            weather_icon_set_tornado(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("wind", name)) {
            weather_icon_set_wind(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("haze", name)) {
            weather_icon_set_haze(item, lv_xml_get_image(&state->scope, value));
        }
    }
}

void weather_icon_register(void)
{
    lv_xml_register_widget("weather_icon", weather_icon_xml_create, weather_icon_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */