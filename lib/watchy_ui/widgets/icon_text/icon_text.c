/**
 * @file icon_text.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "icon_text_private_gen.h"
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

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void icon_text_constructor_hook(lv_obj_t * obj)
{

}

void icon_text_destructor_hook(lv_obj_t * obj)
{

}

void icon_text_event_hook(lv_event_t * e)
{

}

void icon_text_set_icon(lv_obj_t * icon_text, const void * icon)
{
    icon_text_t * widget = (icon_text_t *)icon_text;
    widget->icon = icon;
    lv_image_set_src(widget->img_icon, widget->icon);
}

void icon_text_bind_text(lv_obj_t * icon_text, lv_subject_t * bind_text)
{
    icon_text_t * widget = (icon_text_t *)icon_text;
    widget->bind_text = bind_text;
    lv_label_bind_text(widget->lv_label_0, widget->bind_text, widget->bind_format);
}

void icon_text_set_bind_format(lv_obj_t * icon_text, const char * bind_format)
{
    icon_text_t * widget = (icon_text_t *)icon_text;
    widget->bind_format = bind_format;
    if (widget->bind_text)
    {
        lv_label_bind_text(widget->lv_label_0, widget->bind_text, widget->bind_format);
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/