/**
 * @file analog_hand_private_gen.h
 *
 */

#ifndef ANALOG_HAND_PRIVATE_H
#define ANALOG_HAND_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "analog_hand.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_image_t obj;  /* Base widget to extend */
    lv_subject_t * bind_rotation;
    const void * src;
    int32_t pivot_x;
    int32_t pivot_y;
    int32_t offset;
} analog_hand_t;

extern const lv_obj_class_t analog_hand_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void analog_hand_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ANALOG_HAND_PRIVATE_H*/