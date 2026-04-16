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

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl_private.h"
#else
    #include "lvgl_private.h"
#endif
#include "icon_text.h"

/*********************
 *      DEFINES
 *********************/

#ifndef ICON_TEXT_USER_DATA
#define ICON_TEXT_USER_DATA
#endif

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
    ICON_TEXT_USER_DATA
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