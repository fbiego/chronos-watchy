/**
 * @file watchy_ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "watchy_ui_gen.h"

#if LV_USE_XML
#include "widgets/analog_hand/analog_hand_private_gen.h"
#include "widgets/bluetooth/bluetooth_private_gen.h"
#include "widgets/icon_text/icon_text_private_gen.h"
#include "widgets/weather_icon/weather_icon_private_gen.h"
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * NS_Regular_16;
extern lv_font_t NS_Regular_16_data;
lv_font_t * NS_Regular_20;
extern lv_font_t NS_Regular_20_data;
lv_font_t * NS_Regular_30;
extern lv_font_t NS_Regular_30_data;
lv_font_t * NS_Bold_20;
extern lv_font_t NS_Bold_20_data;
lv_font_t * NS_Bold_30;
extern lv_font_t NS_Bold_30_data;
lv_font_t * NS_Bold_40;
extern lv_font_t NS_Bold_40_data;

/*----------------
 * Images
 *----------------*/

const void * ic_telegram;
extern const void * ic_telegram_data;
const void * ic_next;
extern const void * ic_next_data;
const void * ic_twitter;
extern const void * ic_twitter_data;
const void * ic_mute;
extern const void * ic_mute_data;
const void * ic_chronos_100;
extern const void * ic_chronos_100_data;
const void * ic_volume_down;
extern const void * ic_volume_down_data;
const void * ic_line;
extern const void * ic_line_data;
const void * ic_storage;
extern const void * ic_storage_data;
const void * ic_volume_up;
extern const void * ic_volume_up_data;
const void * ic_sos;
extern const void * ic_sos_data;
const void * ic_search;
extern const void * ic_search_data;
const void * ic_pairing;
extern const void * ic_pairing_data;
const void * ic_kakao_talk;
extern const void * ic_kakao_talk_data;
const void * ic_settings;
extern const void * ic_settings_data;
const void * ic_rainy;
extern const void * ic_rainy_data;
const void * ic_instagram;
extern const void * ic_instagram_data;
const void * ic_cloud;
extern const void * ic_cloud_data;
const void * ic_message;
extern const void * ic_message_data;
const void * ic_phone;
extern const void * ic_phone_data;
const void * ic_file_xml;
extern const void * ic_file_xml_data;
const void * ic_file_dir;
extern const void * ic_file_dir_data;
const void * ic_skype;
extern const void * ic_skype_data;
const void * ic_pause;
extern const void * ic_pause_data;
const void * ic_sunny;
extern const void * ic_sunny_data;
const void * ic_sync;
extern const void * ic_sync_data;
const void * ic_distance;
extern const void * ic_distance_data;
const void * ic_bluetooth;
extern const void * ic_bluetooth_data;
const void * ic_qr_codes;
extern const void * ic_qr_codes_data;
const void * ic_file_unknown;
extern const void * ic_file_unknown_data;
const void * ic_wechat;
extern const void * ic_wechat_data;
const void * ic_file_bin;
extern const void * ic_file_bin_data;
const void * ic_haze;
extern const void * ic_haze_data;
const void * ic_sun_cloud;
extern const void * ic_sun_cloud_data;
const void * ic_timeout;
extern const void * ic_timeout_data;
const void * watchface_default;
extern const void * watchface_default_data;
const void * ic_no_weather;
extern const void * ic_no_weather_data;
const void * ic_chronos_40;
extern const void * ic_chronos_40_data;
const void * ic_calories;
extern const void * ic_calories_data;
const void * ic_snow;
extern const void * ic_snow_data;
const void * ic_xml;
extern const void * ic_xml_data;
const void * ic_battery;
extern const void * ic_battery_data;
const void * ic_vkontakte;
extern const void * ic_vkontakte_data;
const void * ic_viber;
extern const void * ic_viber_data;
const void * ic_weibo;
extern const void * ic_weibo_data;
const void * ic_music;
extern const void * ic_music_data;
const void * ic_wind;
extern const void * ic_wind_data;
const void * ic_camera;
extern const void * ic_camera_data;
const void * ic_file_back;
extern const void * ic_file_back_data;
const void * ic_activity;
extern const void * ic_activity_data;
const void * ic_steps;
extern const void * ic_steps_data;
const void * ic_weather;
extern const void * ic_weather_data;
const void * ic_sleep_mode;
extern const void * ic_sleep_mode_data;
const void * ic_contacts;
extern const void * ic_contacts_data;
const void * ic_notifications;
extern const void * ic_notifications_data;
const void * ic_whatsapp;
extern const void * ic_whatsapp_data;
const void * ic_info;
extern const void * ic_info_data;
const void * ic_controls;
extern const void * ic_controls_data;
const void * ic_bt_con;
extern const void * ic_bt_con_data;
const void * ic_bt_on;
extern const void * ic_bt_on_data;
const void * ic_configs;
extern const void * ic_configs_data;
const void * ic_navigation;
extern const void * ic_navigation_data;
const void * ic_mail;
extern const void * ic_mail_data;
const void * ic_messenger;
extern const void * ic_messenger_data;
const void * ic_watch;
extern const void * ic_watch_data;
const void * ic_nav;
extern const void * ic_nav_data;
const void * ic_tornado;
extern const void * ic_tornado_data;
const void * ic_chronos_watchy;
extern const void * ic_chronos_watchy_data;
const void * ic_facebook;
extern const void * ic_facebook_data;
const void * ic_previous;
extern const void * ic_previous_data;
const void * ic_low_battery;
extern const void * ic_low_battery_data;
const void * ic_shutdown;
extern const void * ic_shutdown_data;
const void * ic_shutdown_mode;
extern const void * ic_shutdown_mode_data;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_time;
lv_subject_t subject_date;
lv_subject_t subject_hour;
lv_subject_t subject_minute;
lv_subject_t subject_hour_analog;
lv_subject_t subject_minute_analog;
lv_subject_t subject_am_pm;
lv_subject_t subject_day;
lv_subject_t subject_month;
lv_subject_t subject_year;
lv_subject_t subject_month_short;
lv_subject_t subject_month_long;
lv_subject_t subject_weekday;
lv_subject_t subject_weekday_short;
lv_subject_t subject_weekday_long;
lv_subject_t subject_power_off;
lv_subject_t subject_bluetooth;
lv_subject_t subject_camera;
lv_subject_t subject_bluetooth_state;
lv_subject_t subject_voltage;
lv_subject_t subject_battery;
lv_subject_t subject_phone_battery;
lv_subject_t subject_steps;
lv_subject_t subject_calories;
lv_subject_t subject_temperature;
lv_subject_t subject_weather_icon;
lv_subject_t subject_distance;
lv_subject_t subject_distance_unit;
lv_subject_t subject_temp_unit;
lv_subject_t subject_last_sync;
lv_subject_t subject_navigation;
lv_subject_t subject_address;
lv_subject_t subject_ble_name;
lv_subject_t subject_settings_index;
lv_subject_t subject_settings_view;
lv_subject_t subject_music_view;
lv_subject_t subject_camera_state;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void watchy_ui_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* get font 'NS_Regular_16' from a C array */
    NS_Regular_16 = &NS_Regular_16_data;
    /* get font 'NS_Regular_20' from a C array */
    NS_Regular_20 = &NS_Regular_20_data;
    /* get font 'NS_Regular_30' from a C array */
    NS_Regular_30 = &NS_Regular_30_data;
    /* get font 'NS_Bold_20' from a C array */
    NS_Bold_20 = &NS_Bold_20_data;
    /* get font 'NS_Bold_30' from a C array */
    NS_Bold_30 = &NS_Bold_30_data;
    /* get font 'NS_Bold_40' from a C array */
    NS_Bold_40 = &NS_Bold_40_data;


    /*----------------
     * Images
     *----------------*/
    ic_telegram = &ic_telegram_data;
    ic_next = &ic_next_data;
    ic_twitter = &ic_twitter_data;
    ic_mute = &ic_mute_data;
    ic_chronos_100 = &ic_chronos_100_data;
    ic_volume_down = &ic_volume_down_data;
    ic_line = &ic_line_data;
    ic_storage = &ic_storage_data;
    ic_volume_up = &ic_volume_up_data;
    ic_sos = &ic_sos_data;
    ic_search = &ic_search_data;
    ic_pairing = &ic_pairing_data;
    ic_kakao_talk = &ic_kakao_talk_data;
    ic_settings = &ic_settings_data;
    ic_rainy = &ic_rainy_data;
    ic_instagram = &ic_instagram_data;
    ic_cloud = &ic_cloud_data;
    ic_message = &ic_message_data;
    ic_phone = &ic_phone_data;
    ic_file_xml = &ic_file_xml_data;
    ic_file_dir = &ic_file_dir_data;
    ic_skype = &ic_skype_data;
    ic_pause = &ic_pause_data;
    ic_sunny = &ic_sunny_data;
    ic_sync = &ic_sync_data;
    ic_distance = &ic_distance_data;
    ic_bluetooth = &ic_bluetooth_data;
    ic_qr_codes = &ic_qr_codes_data;
    ic_file_unknown = &ic_file_unknown_data;
    ic_wechat = &ic_wechat_data;
    ic_file_bin = &ic_file_bin_data;
    ic_haze = &ic_haze_data;
    ic_sun_cloud = &ic_sun_cloud_data;
    ic_timeout = &ic_timeout_data;
    watchface_default = &watchface_default_data;
    ic_no_weather = &ic_no_weather_data;
    ic_chronos_40 = &ic_chronos_40_data;
    ic_calories = &ic_calories_data;
    ic_snow = &ic_snow_data;
    ic_xml = &ic_xml_data;
    ic_battery = &ic_battery_data;
    ic_vkontakte = &ic_vkontakte_data;
    ic_viber = &ic_viber_data;
    ic_weibo = &ic_weibo_data;
    ic_music = &ic_music_data;
    ic_wind = &ic_wind_data;
    ic_camera = &ic_camera_data;
    ic_file_back = &ic_file_back_data;
    ic_activity = &ic_activity_data;
    ic_steps = &ic_steps_data;
    ic_weather = &ic_weather_data;
    ic_sleep_mode = &ic_sleep_mode_data;
    ic_contacts = &ic_contacts_data;
    ic_notifications = &ic_notifications_data;
    ic_whatsapp = &ic_whatsapp_data;
    ic_info = &ic_info_data;
    ic_controls = &ic_controls_data;
    ic_bt_con = &ic_bt_con_data;
    ic_bt_on = &ic_bt_on_data;
    ic_configs = &ic_configs_data;
    ic_navigation = &ic_navigation_data;
    ic_mail = &ic_mail_data;
    ic_messenger = &ic_messenger_data;
    ic_watch = &ic_watch_data;
    ic_nav = &ic_nav_data;
    ic_tornado = &ic_tornado_data;
    ic_chronos_watchy = &ic_chronos_watchy_data;
    ic_facebook = &ic_facebook_data;
    ic_previous = &ic_previous_data;
    ic_low_battery = &ic_low_battery_data;
    ic_shutdown = &ic_shutdown_data;
    ic_shutdown_mode = &ic_shutdown_mode_data;

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    static char subject_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_time,
                           subject_time_buf,
                           subject_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "12:45"
                          );
    static char subject_date_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_date_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_date,
                           subject_date_buf,
                           subject_date_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Sun 5 Oct"
                          );
    lv_subject_init_int(&subject_hour, 12);
    lv_subject_init_int(&subject_minute, 45);
    lv_subject_init_int(&subject_hour_analog, 3150);
    lv_subject_init_int(&subject_minute_analog, 450);
    static char subject_am_pm_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_am_pm_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_am_pm,
                           subject_am_pm_buf,
                           subject_am_pm_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "AM"
                          );
    lv_subject_init_int(&subject_day, 5);
    lv_subject_init_int(&subject_month, 10);
    lv_subject_init_int(&subject_year, 2025);
    static char subject_month_short_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_month_short_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_month_short,
                           subject_month_short_buf,
                           subject_month_short_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Oct"
                          );
    static char subject_month_long_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_month_long_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_month_long,
                           subject_month_long_buf,
                           subject_month_long_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "October"
                          );
    lv_subject_init_int(&subject_weekday, 0);
    static char subject_weekday_short_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_weekday_short_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_weekday_short,
                           subject_weekday_short_buf,
                           subject_weekday_short_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Sun"
                          );
    static char subject_weekday_long_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_weekday_long_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_weekday_long,
                           subject_weekday_long_buf,
                           subject_weekday_long_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Sunday"
                          );
    static char subject_power_off_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_power_off_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_power_off,
                           subject_power_off_buf,
                           subject_power_off_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "12"
                          );
    lv_subject_init_int(&subject_bluetooth, 1);
    lv_subject_init_int(&subject_camera, 0);
    static char subject_bluetooth_state_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_bluetooth_state_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_bluetooth_state,
                           subject_bluetooth_state_buf,
                           subject_bluetooth_state_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Connected"
                          );
    lv_subject_init_int(&subject_voltage, 3869);
    lv_subject_init_int(&subject_battery, 83);
    lv_subject_init_int(&subject_phone_battery, 53);
    lv_subject_init_int(&subject_steps, 1234);
    lv_subject_init_int(&subject_calories, 324);
    lv_subject_init_int(&subject_temperature, 24);
    lv_subject_init_int(&subject_weather_icon, 0);
    lv_subject_set_min_value_int(&subject_weather_icon, -1);
    lv_subject_set_max_value_int(&subject_weather_icon, 7);
    static char subject_distance_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_distance_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_distance,
                           subject_distance_buf,
                           subject_distance_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "1.3"
                          );
    static char subject_distance_unit_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_distance_unit_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_distance_unit,
                           subject_distance_unit_buf,
                           subject_distance_unit_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "km"
                          );
    static char subject_temp_unit_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_temp_unit_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_temp_unit,
                           subject_temp_unit_buf,
                           subject_temp_unit_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "°C"
                          );
    static char subject_last_sync_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_last_sync_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_last_sync,
                           subject_last_sync_buf,
                           subject_last_sync_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "36m"
                          );
    lv_subject_init_int(&subject_navigation, 1);
    static char subject_address_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_address_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_address,
                           subject_address_buf,
                           subject_address_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "AA:45:45:24:35:DC"
                          );
    static char subject_ble_name_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_ble_name_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_ble_name,
                           subject_ble_name_buf,
                           subject_ble_name_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Watchy"
                          );
    lv_subject_init_int(&subject_settings_index, 0);
    lv_subject_set_min_value_int(&subject_settings_index, 0);
    lv_subject_set_max_value_int(&subject_settings_index, 5);
    lv_subject_init_int(&subject_settings_view, 0);
    lv_subject_init_int(&subject_music_view, 0);
    lv_subject_set_min_value_int(&subject_music_view, 0);
    lv_subject_set_max_value_int(&subject_music_view, 1);
    static char subject_camera_state_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_camera_state_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_camera_state,
                           subject_camera_state_buf,
                           subject_camera_state_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Ready"
                          );

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */
    analog_hand_register();
    bluetooth_register();
    icon_text_register();
    weather_icon_register();

    /* Register fonts */
    lv_xml_register_font(NULL, "NS_Regular_16", NS_Regular_16);
    lv_xml_register_font(NULL, "NS_Regular_20", NS_Regular_20);
    lv_xml_register_font(NULL, "NS_Regular_30", NS_Regular_30);
    lv_xml_register_font(NULL, "NS_Bold_20", NS_Bold_20);
    lv_xml_register_font(NULL, "NS_Bold_30", NS_Bold_30);
    lv_xml_register_font(NULL, "NS_Bold_40", NS_Bold_40);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_time", &subject_time);
    lv_xml_register_subject(NULL, "subject_date", &subject_date);
    lv_xml_register_subject(NULL, "subject_hour", &subject_hour);
    lv_xml_register_subject(NULL, "subject_minute", &subject_minute);
    lv_xml_register_subject(NULL, "subject_hour_analog", &subject_hour_analog);
    lv_xml_register_subject(NULL, "subject_minute_analog", &subject_minute_analog);
    lv_xml_register_subject(NULL, "subject_am_pm", &subject_am_pm);
    lv_xml_register_subject(NULL, "subject_day", &subject_day);
    lv_xml_register_subject(NULL, "subject_month", &subject_month);
    lv_xml_register_subject(NULL, "subject_year", &subject_year);
    lv_xml_register_subject(NULL, "subject_month_short", &subject_month_short);
    lv_xml_register_subject(NULL, "subject_month_long", &subject_month_long);
    lv_xml_register_subject(NULL, "subject_weekday", &subject_weekday);
    lv_xml_register_subject(NULL, "subject_weekday_short", &subject_weekday_short);
    lv_xml_register_subject(NULL, "subject_weekday_long", &subject_weekday_long);
    lv_xml_register_subject(NULL, "subject_power_off", &subject_power_off);
    lv_xml_register_subject(NULL, "subject_bluetooth", &subject_bluetooth);
    lv_xml_register_subject(NULL, "subject_camera", &subject_camera);
    lv_xml_register_subject(NULL, "subject_bluetooth_state", &subject_bluetooth_state);
    lv_xml_register_subject(NULL, "subject_voltage", &subject_voltage);
    lv_xml_register_subject(NULL, "subject_battery", &subject_battery);
    lv_xml_register_subject(NULL, "subject_phone_battery", &subject_phone_battery);
    lv_xml_register_subject(NULL, "subject_steps", &subject_steps);
    lv_xml_register_subject(NULL, "subject_calories", &subject_calories);
    lv_xml_register_subject(NULL, "subject_temperature", &subject_temperature);
    lv_xml_register_subject(NULL, "subject_weather_icon", &subject_weather_icon);
    lv_xml_register_subject(NULL, "subject_distance", &subject_distance);
    lv_xml_register_subject(NULL, "subject_distance_unit", &subject_distance_unit);
    lv_xml_register_subject(NULL, "subject_temp_unit", &subject_temp_unit);
    lv_xml_register_subject(NULL, "subject_last_sync", &subject_last_sync);
    lv_xml_register_subject(NULL, "subject_navigation", &subject_navigation);
    lv_xml_register_subject(NULL, "subject_address", &subject_address);
    lv_xml_register_subject(NULL, "subject_ble_name", &subject_ble_name);
    lv_xml_register_subject(NULL, "subject_settings_index", &subject_settings_index);
    lv_xml_register_subject(NULL, "subject_settings_view", &subject_settings_view);
    lv_xml_register_subject(NULL, "subject_music_view", &subject_music_view);
    lv_xml_register_subject(NULL, "subject_camera_state", &subject_camera_state);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "ic_telegram", ic_telegram);
    lv_xml_register_image(NULL, "ic_next", ic_next);
    lv_xml_register_image(NULL, "ic_twitter", ic_twitter);
    lv_xml_register_image(NULL, "ic_mute", ic_mute);
    lv_xml_register_image(NULL, "ic_chronos_100", ic_chronos_100);
    lv_xml_register_image(NULL, "ic_volume_down", ic_volume_down);
    lv_xml_register_image(NULL, "ic_line", ic_line);
    lv_xml_register_image(NULL, "ic_storage", ic_storage);
    lv_xml_register_image(NULL, "ic_volume_up", ic_volume_up);
    lv_xml_register_image(NULL, "ic_sos", ic_sos);
    lv_xml_register_image(NULL, "ic_search", ic_search);
    lv_xml_register_image(NULL, "ic_pairing", ic_pairing);
    lv_xml_register_image(NULL, "ic_kakao_talk", ic_kakao_talk);
    lv_xml_register_image(NULL, "ic_settings", ic_settings);
    lv_xml_register_image(NULL, "ic_rainy", ic_rainy);
    lv_xml_register_image(NULL, "ic_instagram", ic_instagram);
    lv_xml_register_image(NULL, "ic_cloud", ic_cloud);
    lv_xml_register_image(NULL, "ic_message", ic_message);
    lv_xml_register_image(NULL, "ic_phone", ic_phone);
    lv_xml_register_image(NULL, "ic_file_xml", ic_file_xml);
    lv_xml_register_image(NULL, "ic_file_dir", ic_file_dir);
    lv_xml_register_image(NULL, "ic_skype", ic_skype);
    lv_xml_register_image(NULL, "ic_pause", ic_pause);
    lv_xml_register_image(NULL, "ic_sunny", ic_sunny);
    lv_xml_register_image(NULL, "ic_sync", ic_sync);
    lv_xml_register_image(NULL, "ic_distance", ic_distance);
    lv_xml_register_image(NULL, "ic_bluetooth", ic_bluetooth);
    lv_xml_register_image(NULL, "ic_qr_codes", ic_qr_codes);
    lv_xml_register_image(NULL, "ic_file_unknown", ic_file_unknown);
    lv_xml_register_image(NULL, "ic_wechat", ic_wechat);
    lv_xml_register_image(NULL, "ic_file_bin", ic_file_bin);
    lv_xml_register_image(NULL, "ic_haze", ic_haze);
    lv_xml_register_image(NULL, "ic_sun_cloud", ic_sun_cloud);
    lv_xml_register_image(NULL, "ic_timeout", ic_timeout);
    lv_xml_register_image(NULL, "watchface_default", watchface_default);
    lv_xml_register_image(NULL, "ic_no_weather", ic_no_weather);
    lv_xml_register_image(NULL, "ic_chronos_40", ic_chronos_40);
    lv_xml_register_image(NULL, "ic_calories", ic_calories);
    lv_xml_register_image(NULL, "ic_snow", ic_snow);
    lv_xml_register_image(NULL, "ic_xml", ic_xml);
    lv_xml_register_image(NULL, "ic_battery", ic_battery);
    lv_xml_register_image(NULL, "ic_vkontakte", ic_vkontakte);
    lv_xml_register_image(NULL, "ic_viber", ic_viber);
    lv_xml_register_image(NULL, "ic_weibo", ic_weibo);
    lv_xml_register_image(NULL, "ic_music", ic_music);
    lv_xml_register_image(NULL, "ic_wind", ic_wind);
    lv_xml_register_image(NULL, "ic_camera", ic_camera);
    lv_xml_register_image(NULL, "ic_file_back", ic_file_back);
    lv_xml_register_image(NULL, "ic_activity", ic_activity);
    lv_xml_register_image(NULL, "ic_steps", ic_steps);
    lv_xml_register_image(NULL, "ic_weather", ic_weather);
    lv_xml_register_image(NULL, "ic_sleep_mode", ic_sleep_mode);
    lv_xml_register_image(NULL, "ic_contacts", ic_contacts);
    lv_xml_register_image(NULL, "ic_notifications", ic_notifications);
    lv_xml_register_image(NULL, "ic_whatsapp", ic_whatsapp);
    lv_xml_register_image(NULL, "ic_info", ic_info);
    lv_xml_register_image(NULL, "ic_controls", ic_controls);
    lv_xml_register_image(NULL, "ic_bt_con", ic_bt_con);
    lv_xml_register_image(NULL, "ic_bt_on", ic_bt_on);
    lv_xml_register_image(NULL, "ic_configs", ic_configs);
    lv_xml_register_image(NULL, "ic_navigation", ic_navigation);
    lv_xml_register_image(NULL, "ic_mail", ic_mail);
    lv_xml_register_image(NULL, "ic_messenger", ic_messenger);
    lv_xml_register_image(NULL, "ic_watch", ic_watch);
    lv_xml_register_image(NULL, "ic_nav", ic_nav);
    lv_xml_register_image(NULL, "ic_tornado", ic_tornado);
    lv_xml_register_image(NULL, "ic_chronos_watchy", ic_chronos_watchy);
    lv_xml_register_image(NULL, "ic_facebook", ic_facebook);
    lv_xml_register_image(NULL, "ic_previous", ic_previous);
    lv_xml_register_image(NULL, "ic_low_battery", ic_low_battery);
    lv_xml_register_image(NULL, "ic_shutdown", ic_shutdown);
    lv_xml_register_image(NULL, "ic_shutdown_mode", ic_shutdown_mode);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/