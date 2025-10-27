/**
 * @file analog_hand.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "analog_hand_private_gen.h"
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
static void subject_observer_cb(lv_observer_t *observer, lv_subject_t *subject);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void analog_hand_constructor_hook(lv_obj_t * obj)
{
    analog_hand_t * widget = (analog_hand_t *)obj;
    widget->offset = 0;

}

void analog_hand_destructor_hook(lv_obj_t * obj)
{

}

void analog_hand_event_hook(lv_event_t * e)
{

}

void analog_hand_bind_rotation(lv_obj_t * analog_hand, lv_subject_t * bind_rotation)
{
    analog_hand_t * widget = (analog_hand_t *)analog_hand;
    widget->bind_rotation = bind_rotation;
    lv_subject_add_observer_obj(widget->bind_rotation, subject_observer_cb, analog_hand, widget);
}

void analog_hand_set_src(lv_obj_t * analog_hand, const void * src)
{
    analog_hand_t * widget = (analog_hand_t *)analog_hand;
    widget->src = src;
    lv_image_set_src(analog_hand, src);
}

void analog_hand_set_pivot_x(lv_obj_t * analog_hand, int32_t pivot_x)
{
    analog_hand_t * widget = (analog_hand_t *)analog_hand;
    widget->pivot_x = pivot_x;
    lv_obj_set_style_transform_pivot_x(analog_hand, widget->pivot_x, 0);
}

void analog_hand_set_pivot_y(lv_obj_t * analog_hand, int32_t pivot_y)
{
    analog_hand_t * widget = (analog_hand_t *)analog_hand;
    widget->pivot_y = pivot_y;
    lv_obj_set_style_transform_pivot_y(analog_hand, widget->pivot_y, 0);
}

void analog_hand_set_offset(lv_obj_t * analog_hand, int32_t offset)
{
    analog_hand_t * widget = (analog_hand_t *)analog_hand;
    widget->offset = offset;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void subject_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    analog_hand_t * widget = (analog_hand_t *)lv_observer_get_user_data(observer);
    lv_obj_t * obj = (lv_obj_t *)widget;
    lv_obj_set_style_transform_rotation(obj, lv_subject_get_int(subject) + widget->offset, 0);
}
