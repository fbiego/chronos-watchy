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

#include "lvgl_private.h"
#include "bluetooth.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_obj_t * lv_image_0;
    lv_obj_t * lv_image_1;
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