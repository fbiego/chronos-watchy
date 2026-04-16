/**
 * @file analog_hand_gen.h
 *
 */

#ifndef ANALOG_HAND_GEN_H
#define ANALOG_HAND_GEN_H

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
 * Create a analog_hand object
 * @param parent pointer to an object, it will be the parent of the new analog_hand
 * @return pointer to the created analog_hand
 */
lv_obj_t * analog_hand_create(lv_obj_t * parent);
/**
 * The subject to bind the image rotation
 * @param obj   pointer to a analog_hand
 * @param bind_rotation  The subject to bind the image rotation
 */
void analog_hand_bind_rotation(lv_obj_t * analog_hand, lv_subject_t * bind_rotation);

/**
 * The image src
 * @param obj   pointer to a analog_hand
 * @param src  The image src
 */
void analog_hand_set_src(lv_obj_t * analog_hand, const void * src);

/**
 * The x pivot point of the image
 * @param obj   pointer to a analog_hand
 * @param pivot_x  The x pivot point of the image
 */
void analog_hand_set_pivot_x(lv_obj_t * analog_hand, int32_t pivot_x);

/**
 * The y pivot point of the image
 * @param obj   pointer to a analog_hand
 * @param pivot_y  The y pivot point of the image
 */
void analog_hand_set_pivot_y(lv_obj_t * analog_hand, int32_t pivot_y);

/**
 * The offset of the rotation
 * @param obj   pointer to a analog_hand
 * @param offset  The offset of the rotation
 */
void analog_hand_set_offset(lv_obj_t * analog_hand, int32_t offset);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ANALOG_HAND_GEN_H*/