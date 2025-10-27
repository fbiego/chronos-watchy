/**
 * @file bluetooth_gen.h
 *
 */

#ifndef BLUETOOTH_GEN_H
#define BLUETOOTH_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl.h"
#endif

#include "watchy_ui_gen.h"

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
 * Create a bluetooth object
 * @param parent pointer to an object, it will be the parent of the new bluetooth
 * @return pointer to the created bluetooth
 */
lv_obj_t * bluetooth_create(lv_obj_t * parent);
;

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*BLUETOOTH_GEN_H*/