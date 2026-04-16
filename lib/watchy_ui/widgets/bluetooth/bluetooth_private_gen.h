/**
 * @file bluetooth_private_gen.h
 *
 */

#ifndef BLUETOOTH_PRIVATE_H
#define BLUETOOTH_PRIVATE_H

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
#include "bluetooth.h"

/*********************
 *      DEFINES
 *********************/

#ifndef BLUETOOTH_USER_DATA
#define BLUETOOTH_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_obj_t * lv_image_0;
    lv_obj_t * lv_image_1;
    BLUETOOTH_USER_DATA
} bluetooth_t;

extern const lv_obj_class_t bluetooth_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void bluetooth_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*BLUETOOTH_PRIVATE_H*/