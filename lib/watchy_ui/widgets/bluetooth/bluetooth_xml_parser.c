/**
 * @file bluetooth_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "bluetooth_gen.h"
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

void * bluetooth_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = bluetooth_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create bluetooth");
        return NULL;
    }

    return item;
}

void bluetooth_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
    }
}

void bluetooth_register(void)
{
    lv_xml_register_widget("bluetooth", bluetooth_xml_create, bluetooth_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */