/**
 * @file icon_text_gen.h
 *
 */

#ifndef ICON_TEXT_GEN_H
#define ICON_TEXT_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "src/core/lv_obj_class_private.h"
#else
    #include "lvgl.h"
    #include "src/core/lv_obj_class_private.h"
#endif

#include "../../watchy_ui_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a icon_text object
 * @param parent pointer to an object, it will be the parent of the new icon_text
 * @return pointer to the created icon_text
 */
lv_obj_t * icon_text_create(lv_obj_t * parent);
/**
 * icon_text icon
 * @param obj   pointer to a icon_text
 * @param icon  icon
 */
void icon_text_set_icon(lv_obj_t * icon_text, const void * icon);

/**
 * icon_text bind_text
 * @param obj   pointer to a icon_text
 * @param bind_text  bind_text
 */
void icon_text_bind_text(lv_obj_t * icon_text, lv_subject_t * bind_text);

/**
 * icon_text bind_format
 * @param obj   pointer to a icon_text
 * @param bind_format  bind_format
 */
void icon_text_set_bind_format(lv_obj_t * icon_text, const char * bind_format);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ICON_TEXT_GEN_H*/