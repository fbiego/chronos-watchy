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

#include <Arduino.h>
#include <ChronosESP32.h>
#include <Timber.h>
#include <Wire.h>

#include "watchy_ui.h"

#include "ButtonModule.h"
#include "DeviceModule.h"
#include "DisplayModule.h"
#include "HealthModule.h"
#include "MotionModule.h"
#include "StorageModule.h"

#define I2C_SDA 21
#define I2C_SCL 22

#define RTC_INT_PIN 27
#define MOTOR_PIN 13

#define uS_TO_S_FACTOR                                                         \
  1000000ULL // Conversion factor for micro seconds to seconds

void watchy_shutdown(bool low);
