/**
 * @file icon_text_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "icon_text_gen.h"
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

void * icon_text_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = icon_text_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create icon_text");
        return NULL;
    }

    return item;
}

void icon_text_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("icon", name)) {
            icon_text_set_icon(item, lv_xml_get_image(&state->scope, value));
        }
        if(lv_streq("bind_text", name)) {
            icon_text_bind_text(item, lv_xml_get_subject(&state->scope, value));
        }
        if(lv_streq("bind_format", name)) {
            icon_text_set_bind_format(item, value);
        }
    }
}

void icon_text_register(void)
{
    lv_xml_register_widget("icon_text", icon_text_xml_create, icon_text_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */