# Chronos Watchy

**Chronos-Watchy** is an **alternative firmware** for the **Watchy open-source e-ink smartwatch**, built with **LVGL** and designed to connect seamlessly with the [`Chronos App`](https://chronos.ke/), a modern companion app for smartwatch users.

> ⚠️ This firmware is currently compatible with **Watchy v2.0**.
> Tested successfully on an **AliExpress clone** with **USB Type-C**.

## Screen Previews

![screens_1](images/screens_1.png?raw=true "screens_1")

![screens_2](images/screens_2.png?raw=true "screens_2")

## Features

* 📱 **BLE Connectivity**: Syncs directly with the **Chronos App**
* 🕓 **Default Watchface**: Displays time, phone battery, and last sync time
* 🧭 **Navigation**: Turn-by-turn directions from Google Maps or OSMAnd
* 🔔 **Notifications**: Receive app notifications from your phone
* 👣 **Activity Tracking**: Steps with distance, and calorie estimation (+ historical data)
* 🌤️ **Weather Updates**: Synced from Chronos App
* 🌙 **Sleep Mode**: Controlled from the Chronos App; reduces power usage
* ⚙️ **Settings Menu**: Customize connection interval and view configs
* 📷 **Pairing via QR Code**: Quick setup with the Chronos App
* 🎶 **Controls**: Camera, Music, Find Phone controls (Only when connected)
* 🔗 **QR Code Links**: Save QR Code links on Watchy
* 📞 **Contacts**: Save contact info on Watchy
* 🕹️ **Multiple Watchface**: Installable at runtime via BLE, [`Watchy Faces`](https://github.com/fbiego/watchy_faces)

## Planned / To-Do

* ⚡ Non-blocking operations (BLE & storage handled in background tasks)
* ✋ Raise-to-wake gesture
* 👆 Double-tap to wake
* ⏰ Alarm and reminder system
* 🌍 Multi-language support


## Flashing the Firmware

### Option 1: Use Prebuilt Firmware (Recommended)

Prebuilt binaries are included in the `firmware/` directory, ready to flash, no build required.

You can use the **browser-based ESP flasher** provided by Espressif:

[**Flash Chronos Watchy via Web here**](https://espressif.github.io/esptool-js/)

1. Open the link above in **Chrome**
2. Connect your Watchy via USB
3. Click **Connect** under Program then select the correct serial port
4. Select the prebuilt `.bin` files from the `firmware/` folder, use the correct address as indicated in the file name
5. After flashing, your Watchy will automatically boot into Chronos-Watchy
> You may need to connect to the **Console**, then click **Reset**


### Option 2: Build Manually with PlatformIO

1. Install [PlatformIO](https://platformio.org/install)
2. Clone this repository:

   ```bash
   git clone https://github.com/fbiego/chronos-watchy.git
   cd chronos-watchy
   ```
3. Build the firmware:

   ```bash
   pio run
   ```
4. Flash to the watch:

   ```bash
   pio run -t upload
   ```

## App Setup Guide

<a href='https://chronos.ke/app?id=esp32'><img alt='Download Chronos' height="100px" src='https://chronos.ke/img/chronos.png'/></a>

[`Chronos App`](https://chronos.ke/)

### Connecting / Pairing

1. Open the **Chronos App → Watch tab → Watches → Pair new device**
2. On Watchy, open the **Pairing screen**
3. Choose the device from the app’s list (or tap **Search again**)
4. Alternatively, select **Manual** to enter the MAC address or **Scan QR code** displayed on Watchy


### Configuration

* **Time Format** -> 12h / 24h
* **Temperature** -> °C / °F
* **Units** -> Metric / Imperial

Under the **User** tab:

* Set your **age, height, and weight** (used for calorie and distance estimation)
* Configure **Sleep Time**, during which Watchy enters deep sleep until wakeup


### Weather Setup

1. Go to **Settings → Weather Update**
2. Tap the ⚙️ **gear icon**
3. Enable **weather updates**
4. Choose **Use GPS** or manually enter your city, then click **Check**
5. If successful, click **Save**


### Notifications

1. In the **Notifications tab**, enable access using **Notification Access**
2. Tap **Self Test** to verify Chronos can read notifications
3. Select **Apps** and choose which apps can send alerts to Watchy


### Navigation

1. In the **Watch tab**, scroll down to **ESP32 Manager**
2. Enable **Navigation** for your Watchy device
3. (Optional) Adjust **icon dither mode** and **threshold** for icon clarity
4. Open **Navigation screen** on Watchy
   * If BLE is disconnected, tap the rotating ⚙️ icon to restart
5. Open **Google Maps** or **OsmAnd** and start navigation
   * Directions will appear on your Watchy in real time

> ⚠️ Note: Navigation keeps BLE active continuously, which increases battery drain.

### Advanced Settings

* **App Sleep**: Prevents the app from trying to reconnect while Watchy is in sleep mode
* **Notification Buffer**: Stores and forwards notifications to Watchy when BLE reconnects


## Credits

* **Official Watchy Firmware**: Based on the open-source [Watchy project](https://watchy.sqfmi.com/) and its [firmware repository](https://github.com/sqfmi/Watchy)
* **Chronos ESP32 Library**: Provides seamless smartwatch connectivity with the Chronos app. [GitHub](https://github.com/fbiego/chronos-esp32)
* **Chronos App**: Companion app for smartwatch sync and notifications. [Website](https://chronos.ke/)
* **LVGL**: Powerful open-source embedded graphics library. [Website](https://lvgl.io/)
* **LVGL Pro**: Used for UI design and layout. [Website](https://pro.lvgl.io/)
* **Watchy Faces**: Watchfaces for the Chronos Watchy firmware. [Github](https://github.com/fbiego/watchy_faces)
