/**
 * @file icon_text_private_gen.h
 *
 */

#ifndef ICON_TEXT_PRIVATE_H
#define ICON_TEXT_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "icon_text.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    const void * icon;
    lv_subject_t * bind_text;
    const char * bind_format;
    lv_obj_t * img_icon;
    lv_obj_t * lv_label_0;
} icon_text_t;

extern const lv_obj_class_t icon_text_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void icon_text_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ICON_TEXT_PRIVATE_H*/