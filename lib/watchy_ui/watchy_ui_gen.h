/**
 * @file watchy_ui_gen.h
 */

#ifndef WATCHY_UI_GEN_H
#define WATCHY_UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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
    #include "lvgl/lvgl.h"
    #include "lvgl/src/core/lv_obj_class_private.h"
#endif



/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * NS_Regular_16;

extern lv_font_t * NS_Regular_20;

extern lv_font_t * NS_Regular_30;

extern lv_font_t * NS_Bold_20;

extern lv_font_t * NS_Bold_30;

extern lv_font_t * NS_Bold_40;

extern lv_font_t * NS_Regular_ru_16;

extern lv_font_t * NS_Regular_ru_20;

extern lv_font_t * NS_Regular_ru_30;

extern lv_font_t * NS_Bold_ru_20;

extern lv_font_t * NS_Bold_ru_30;

extern lv_font_t * NS_Bold_ru_40;

/*----------------
 * Images
 *----------------*/

extern const void * ic_telegram;
extern const void * ic_next;
extern const void * ic_twitter;
extern const void * ic_mute;
extern const void * ic_chronos_100;
extern const void * ic_volume_down;
extern const void * ic_line;
extern const void * ic_storage;
extern const void * ic_volume_up;
extern const void * ic_sos;
extern const void * ic_search;
extern const void * ic_pairing;
extern const void * ic_kakao_talk;
extern const void * ic_settings;
extern const void * ic_rainy;
extern const void * ic_instagram;
extern const void * ic_cloud;
extern const void * ic_message;
extern const void * ic_phone;
extern const void * ic_file_xml;
extern const void * ic_file_dir;
extern const void * ic_skype;
extern const void * ic_pause;
extern const void * ic_sunny;
extern const void * ic_sync;
extern const void * ic_distance;
extern const void * ic_bluetooth;
extern const void * ic_qr_codes;
extern const void * ic_file_unknown;
extern const void * ic_wechat;
extern const void * ic_file_bin;
extern const void * ic_haze;
extern const void * ic_sun_cloud;
extern const void * ic_timeout;
extern const void * img_watchface_default;
extern const void * ic_no_weather;
extern const void * ic_chronos_40;
extern const void * ic_calories;
extern const void * ic_snow;
extern const void * ic_xml;
extern const void * ic_battery;
extern const void * ic_vkontakte;
extern const void * ic_viber;
extern const void * ic_weibo;
extern const void * ic_music;
extern const void * ic_wind;
extern const void * ic_camera;
extern const void * ic_file_back;
extern const void * ic_activity;
extern const void * ic_steps;
extern const void * ic_weather;
extern const void * ic_sleep_mode;
extern const void * ic_contacts;
extern const void * ic_notifications;
extern const void * ic_whatsapp;
extern const void * ic_info;
extern const void * ic_controls;
extern const void * ic_bt_con;
extern const void * ic_bt_on;
extern const void * ic_configs;
extern const void * ic_navigation;
extern const void * ic_mail;
extern const void * ic_messenger;
extern const void * ic_watch;
extern const void * ic_nav;
extern const void * ic_tornado;
extern const void * ic_chronos_watchy;
extern const void * ic_facebook;
extern const void * ic_previous;
extern const void * ic_low_battery;
extern const void * ic_shutdown;
extern const void * ic_shutdown_mode;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_time;
extern lv_subject_t subject_date;
extern lv_subject_t subject_hour;
extern lv_subject_t subject_minute;
extern lv_subject_t subject_hour_analog;
extern lv_subject_t subject_minute_analog;
extern lv_subject_t subject_am_pm;
extern lv_subject_t subject_day;
extern lv_subject_t subject_month;
extern lv_subject_t subject_year;
extern lv_subject_t subject_month_short;
extern lv_subject_t subject_month_long;
extern lv_subject_t subject_weekday;
extern lv_subject_t subject_weekday_short;
extern lv_subject_t subject_weekday_long;
extern lv_subject_t subject_power_off;
extern lv_subject_t subject_bluetooth;
extern lv_subject_t subject_camera;
extern lv_subject_t subject_bluetooth_state;
extern lv_subject_t subject_voltage;
extern lv_subject_t subject_battery;
extern lv_subject_t subject_phone_battery;
extern lv_subject_t subject_steps;
extern lv_subject_t subject_calories;
extern lv_subject_t subject_temperature;
extern lv_subject_t subject_weather_icon;
extern lv_subject_t subject_distance;
extern lv_subject_t subject_distance_unit;
extern lv_subject_t subject_temp_unit;
extern lv_subject_t subject_last_sync;
extern lv_subject_t subject_navigation;
extern lv_subject_t subject_address;
extern lv_subject_t subject_ble_name;
extern lv_subject_t subject_settings_index;
extern lv_subject_t subject_settings_view;
extern lv_subject_t subject_music_view;
extern lv_subject_t subject_camera_state;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void watchy_ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/contact_item/contact_item_gen.h"
#include "components/face_item/face_item_gen.h"
#include "components/file_item/file_item_gen.h"
#include "components/forecast/forecast_gen.h"
#include "components/list_item/list_item_gen.h"
#include "components/status_bar/status_bar_gen.h"
#include "screens/activity_gen.h"
#include "screens/contacts_gen.h"
#include "screens/control_gen.h"
#include "screens/home_gen.h"
#include "screens/info_gen.h"
#include "screens/loader_gen.h"
#include "screens/menu_gen.h"
#include "screens/music_gen.h"
#include "screens/navigation_gen.h"
#include "screens/notification_gen.h"
#include "screens/pairing_gen.h"
#include "screens/qr_gen.h"
#include "screens/selector_gen.h"
#include "screens/settings_gen.h"
#include "screens/weather_gen.h"
#include "widgets/analog_hand/analog_hand_gen.h"
#include "widgets/bluetooth/bluetooth_gen.h"
#include "widgets/icon_text/icon_text_gen.h"
#include "widgets/weather_icon/weather_icon_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WATCHY_UI_GEN_H*/