/**
 * @file analog_hand_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "analog_hand_gen.h"
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

void * analog_hand_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = analog_hand_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create analog_hand");
        return NULL;
    }

    return item;
}

void analog_hand_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("pivot_x", name)) {
            analog_hand_set_pivot_x(item, lv_xml_atoi(value));
        }

        if(lv_streq("pivot_y", name)) {
            analog_hand_set_pivot_y(item, lv_xml_atoi(value));
        }

        if(lv_streq("src", name)) {
            analog_hand_set_src(item, lv_xml_get_image(&state->scope, value));
        }

        if(lv_streq("offset", name)) {
            analog_hand_set_offset(item, lv_xml_atoi(value));
        }

        if(lv_streq("bind_rotation", name)) {
            analog_hand_bind_rotation(item, lv_xml_get_subject(&state->scope, value));
        }
    }
}

void analog_hand_register(void)
{
    lv_xml_register_widget("analog_hand", analog_hand_xml_create, analog_hand_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */