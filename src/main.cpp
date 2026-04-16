/*
   MIT License

  Copyright (c) 2025 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  ______________  _____
  ___  __/___  /_ ___(_)_____ _______ _______
  __  /_  __  __ \__  / _  _ \__  __ `/_  __ \
  _  __/  _  /_/ /_  /  /  __/_  /_/ / / /_/ /
  /_/     /_.___/ /_/   \___/ _\__, /  \____/
                                /____/

*/

#include "main.h"

ChronosESP32 watch;

StorageModule storage;
MotionModule motion;
HealthModule health(watch, storage);
ButtonModule buttons;
DeviceModule device(watch, storage, motion, health);
DisplayModule display(device, health);

void connectionCallback(bool state) {
  Timber.i("Connection state: %s", state ? "Connected" : "Disconnected");

  if (device.sleepTimerDuration() != TIMER_INFINITE) {
    device.sleepTimerStart(20); // 20 secs
  } else if (device.sleepTimerDuration() == TIMER_INFINITE && !state) {
    device.sleepTimerStart(20); // 20 secs
  }
}

void longPressCallback() {
  digitalWrite(MOTOR_PIN, HIGH);
  delay(20);
  digitalWrite(MOTOR_PIN, LOW);
}

void notificationCallback(Notification notification) {
  device.handleNotification(notification);
  digitalWrite(MOTOR_PIN, HIGH);
  delay(50);
  digitalWrite(MOTOR_PIN, LOW);
}

void configCallback(Config config, uint32_t a, uint32_t b) {
  switch (config) {
  case CF_TIME:
    device.setRTC();
    break;

  case CF_USER:
    health.setUserInfo(
        (uint8_t)((a >> 24) & 0xFF),                   // age
        (uint8_t)((a >> 16) & 0xFF),                   // height
        (uint8_t)((a >> 8) & 0xFF),                    // weight
        (uint8_t)((a >> 0) & 0xFF),                    // step length
        (uint32_t)((uint8_t)((b >> 16) & 0xFF) * 1000) // target steps
    );
    break;
  }

  device.handleConfigs(config, a, b);
}

void healthRequestCallback(HealthRequest request, bool state) {
  switch (request) {
  case HR_STEPS_RECORDS: {
    device.setSyncData(true);
    if (device.sleepTimerDuration() != TIMER_INFINITE) {
      device.sleepTimerStart(40); // 40 sec
    }
  } break;
  }
}

void bleDataCallback(uint8_t *data, int len) {
  if (data[0] >= 0xC0 && data[0] <= 0xCF) {
    storage.handleFileCommand(data, len);
    if (data[0] == 0xCE) {
      if (data[4] == 0xFF) {
        device.sleepTimerStart(TIMER_INFINITE);
      } else if (data[4] == 0x00) {
        device.sleepTimerStart(30);
      }
    }
  }
  if (data[0] == 0xCF) {
    uint8_t nameLen = data[4];
    String filename = String((char *)&data[5]).substring(0, nameLen);
    Timber.i("Set default face: " + filename);
    if (filename.startsWith("/lvgl/faces/") &&
        filename.endsWith("/info.json")) {
      display.loadFace(filename);
    } else {
      Timber.e("Invalid watchface info path: " + filename);
    }
  }
}

void sendDataBle(uint8_t *data, size_t len) { watch.sendCommand(data, len); }

void navigationIconCallback(uint8_t *data, bool icon) {
  display.navigationIconCallback(data, icon);
}

void navigationDataCallback(String text, String title, String directions,
                            bool icon) {
  display.navigationDataCallback(text, title, directions, icon);
}

void buttonHandler(ButtonEvent buttonEvent) {
  device.initBLE(); // if bluetooth not running, start it on any button press

  if (device.sleepTimerDuration() != TIMER_INFINITE) {
    device.sleepTimerStart(40); // 40 sec
  }

  if (buttonEvent.type == BT_MENU && buttonEvent.click == long_click) {
  }
  if (buttonEvent.type == BT_BACK && buttonEvent.click == long_click) {
  }

  Timber.i(buttons.getInfo(buttonEvent));

  display.handleButtons(buttonEvent);
}

void motionInterruptCallback(uint16_t irq) {
  if (device.sleepTimerDuration() != TIMER_INFINITE) {
    device.sleepTimerStart(40); // 40 sec
  }
  Timber.i(motion.getInterrupts(irq));

  display.handleMotionInterrupt(irq);
}

void logCallback(Level level, unsigned long time, String message) {
  Serial.print(message);
}

void setup() {

  Serial.begin(115200);
  Timber.setLogCallback(logCallback);

  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause(); // get wake up reason

  bool full_refresh = true;

  switch (wakeup_reason) {
  case ESP_SLEEP_WAKEUP_TIMER:
    Timber.i("Wakeup caused by timer");
    full_refresh = false;
    break;
  case ESP_SLEEP_WAKEUP_EXT0:
    Timber.i("Wakeup caused by RTC alarm");
    full_refresh = true;
    break;
  case ESP_SLEEP_WAKEUP_EXT1:
    Timber.i("Wakeup caused by Button press");
    full_refresh = false;
    break;
  case ESP_SLEEP_WAKEUP_UNDEFINED:
    Timber.i("Wakeup was not caused by deep sleep");
    break;
  default:
    Timber.i("Wakeup was not caused by deep sleep: %d", wakeup_reason);
    break;
  }

  pinMode(MOTOR_PIN, OUTPUT);
  device.updateBattery();

  int bat = device.getBattery();

  if (full_refresh && bat >= 30) {
    digitalWrite(MOTOR_PIN, HIGH);
    delay(50);
  }
  digitalWrite(MOTOR_PIN, LOW);

  display.begin(full_refresh);

  if (full_refresh) {
    display.drawImage(((const lv_image_dsc_t *)ic_chronos_watchy)->data + 8, 0,
                      0, 200, 200);
    delay(2000);
  }

  Wire.begin(I2C_SDA, I2C_SCL);

  motion.begin();
  storage.begin();
  health.begin();
  buttons.begin();
  device.begin();

  display.configure();
  device.checkHourlyData();

  buttons.setButtonCallback(buttonHandler);
  buttons.setLongPressCallback(longPressCallback);
  device.setNavigationDataCallback(navigationDataCallback);
  device.setNavigationIconCallback(navigationIconCallback);
  watch.setConnectionCallback(connectionCallback);
  watch.setHealthRequestCallback(healthRequestCallback);
  watch.setConfigurationCallback(configCallback);
  watch.setNotificationCallback(notificationCallback);
  motion.setInterruptCallback(motionInterruptCallback);
  watch.setRawDataCallback(bleDataCallback);
  storage.setTransferCallback(sendDataBle);

  if (watch.getMinute() % device.getBLEInterval() == 0 || full_refresh ||
      device.shouldSyncData()) {
    device.sleepTimerStart(MINUTE_TO_S(1)); // 1 minute
  } else if (wakeup_reason == ESP_SLEEP_WAKEUP_EXT1) {
    device.sleepTimerStart(30); // 30 sec
  } else {
    device.sleepTimerStart(0);
  }

  if (device.sleepTimerDuration() > 0) {
    device.initBLE(); // run bluetooth
  }
  Timber.i("Setup done");

  buttons.handleWakeup();

  if (bat < 30) {
    watchy_shutdown(true);
  }
}

void loop() {
  watch.loop();
  buttons.update();
  motion.update();
  device.update();
  display.update();
  storage.update();

  if (device.sleepTimerEnded()) {
    Timber.i("Going to sleep, saving data");
    device.saveSettings();
    device.saveWeather();
    device.saveNotifications();
    device.saveContacts();
    device.saveQR();

    bool sleep = device.isSettingActive(ST_SLEEP);
    SettingTime time = device.getSettings(ST_SLEEP);
    DateTime wakeup;
    wakeup.hour = time.endHour;
    wakeup.minute = time.endMinute;

    if (sleep) {
      device.setRTCAlarm(wakeup);
      display.sleepMode(wakeup.hour, wakeup.minute);
    } else {
      display.timeout();
    }
    delay(50);
    display.hibernate();

    buttons.configureWakeup();

    if (sleep) {
      esp_sleep_enable_ext0_wakeup(
          (gpio_num_t)RTC_INT_PIN,
          0); // enable deep sleep wake on RTC interrupt
    } else {
      esp_sleep_enable_timer_wakeup((60 - watch.getSecond()) * uS_TO_S_FACTOR);
    }
    esp_deep_sleep_start();
  }
}

void watchy_shutdown(bool low) {
  Timber.i("Shutting down");
  device.saveSettings();
  device.saveWeather();
  device.saveNotifications();
  device.saveContacts();
  device.saveQR();
  if (low) {
    display.lowBatteryMode();
  } else {
    display.shutdownMode();
  }
  display.hibernate();
  buttons.configureWakeup();
  esp_deep_sleep_start();
}