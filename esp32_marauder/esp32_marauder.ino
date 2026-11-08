#include "configs.h"

#ifndef HAS_SCREEN
  #define MenuFunctions_h
  #define Display_h
#endif

#include <stdio.h>

#ifdef HAS_GPS
  #include "GpsInterface.h"
#endif

#include "Assets.h"
#include "WiFiScan.h"
#ifdef HAS_SD
  #include "SDInterface.h"
#endif
#include "Buffer.h"

#ifdef HAS_FLIPPER_LED
  #include "flipperLED.h"
#elif defined(XIAO_ESP32_S3) || defined(XIAO_ESP32_C5)
  #include "xiaoLED.h"
#elif defined(MARAUDER_M5STICKC) || defined(MARAUDER_M5STICKCP2)
  #include "stickcLED.h"
#elif defined(HAS_NEOPIXEL_LED) || defined(HAS_T_DONGLE_LED)
  #include "LedInterface.h"
#endif

#include "settings.h"
#include "CommandLine.h"
#include "ReconMission.h"
#if defined(HAS_CSI_MOTION)
  #include "CsiMotionMonitor.h"
#endif
#include "lang_var.h"

#ifdef HAS_T_DONGLE_DISPLAY
  #include "TDongleDisplay.h"
#endif

#ifdef HAS_BATTERY
  #include "BatteryInterface.h"
#endif

#ifdef HAS_SCREEN
  #include "Display.h"
  #include "MenuFunctions.h"
#endif

#ifdef HAS_BUTTONS
  #include "Switches.h"
  
  #if (U_BTN >= 0)
    Switches u_btn = Switches(U_BTN, 1000, U_PULL);
  #endif
  #if (D_BTN >= 0)
    Switches d_btn = Switches(D_BTN, 1000, D_PULL);
  #endif
  #if (L_BTN >= 0)
    Switches l_btn = Switches(L_BTN, 1000, L_PULL);
  #endif
  #if (R_BTN >= 0)
    Switches r_btn = Switches(R_BTN, 1000, R_PULL);
  #endif
  #if (C_BTN >= 0)
    Switches c_btn = Switches(C_BTN, 1000, C_PULL);
  #endif
  
  // === YOUR CUSTOM BUTTONS ===
  #ifdef B_BTN
    #if (B_BTN >= 0)
      Switches b_btn = Switches(B_BTN, 1000, B_PULL);
    #endif
  #endif
  #ifdef S_BTN
    #if (S_BTN >= 0)
      Switches s_btn = Switches(S_BTN, 1000, true);
    #endif
  #endif
  #ifdef X_BTN
    #if (X_BTN >= 0)
      Switches x_btn = Switches(X_BTN, 1000, true);
    #endif
  #endif
  // ===========================

#endif

WiFiScan wifi_scan_obj;
EvilPortal evil_portal_obj;
Buffer buffer_obj;
Settings settings_obj;
CommandLine cli_obj;
ReconMission recon_obj;
#if defined(HAS_CSI_MOTION)
  CsiMotionMonitor csi_motion_obj;
#endif

#ifdef HAS_T_DONGLE_DISPLAY
  TDongleDisplay t_dongle_display;
#endif

#ifdef HAS_GPS
  GpsInterface gps_obj;
#endif

#ifdef HAS_BATTERY
  BatteryInterface battery_obj;
#endif

#ifdef HAS_SCREEN
  Display display_obj;
  MenuFunctions menu_function_obj;
#endif

#if defined(HAS_SD) && !defined(HAS_C5_SD)
  SDInterface sd_obj;
#endif

#ifdef HAS_FLIPPER_LED
  flipperLED flipper_led;
#elif defined(XIAO_ESP32_S3) || defined(XIAO_ESP32_C5)
  xiaoLED xiao_led;
#elif defined(MARAUDER_M5STICKC) || defined(MARAUDER_M5STICKCP2)
  stickcLED stickc_led;
#elif defined(HAS_NEOPIXEL_LED) || defined(HAS_T_DONGLE_LED)
  LedInterface led_obj;
#endif

const String PROGMEM version_number = MARAUDER_VERSION;

#ifdef HAS_NEOPIXEL_LED
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(Pixels, PIN, NEO_GRB + NEO_KHZ800);
#endif

uint32_t currentTime  = 0;

// PWM Brightness Control
#ifdef HAS_SCREEN
  #include <Preferences.h>
  #define BL_CHANNEL 0
  #define BL_FREQ 5000
  #define BL_RESOLUTION 8
  const uint8_t BL_LEVELS[] = {26, 51, 77, 102, 128, 153, 179, 204, 230, 255};
  const uint8_t BL_NUM_LEVELS = 10;
  uint8_t bl_level_idx = 9;
  Preferences bl_prefs;
#endif

#ifdef HAS_SCREEN
  #ifndef HAS_MINI_SCREEN
    #if ESP_ARDUINO_VERSION_MAJOR >= 3
      #define BL_SETUP()       ledcAttach(TFT_BL, BL_FREQ, BL_RESOLUTION)
      #define BL_SET(duty)     ledcWrite(TFT_BL, (duty))
    #else
      #define BL_SETUP()       do { ledcSetup(BL_CHANNEL, BL_FREQ, BL_RESOLUTION); ledcAttachPin(TFT_BL, BL_CHANNEL); } while(0)
      #define BL_SET(duty)     ledcWrite(BL_CHANNEL, (duty))
    #endif
  #endif
#endif

#ifndef HAS_MINI_SCREEN
  void brightnessInit() {
    #ifdef HAS_SCREEN
      bl_prefs.begin("backlight", false);
      bl_level_idx = bl_prefs.getUChar("level", 9);
      if (bl_level_idx >= BL_NUM_LEVELS) bl_level_idx = 9;
      BL_SETUP();
      BL_SET(BL_LEVELS[bl_level_idx]);
    #endif
  }

  void brightnessCycle() {
    #ifdef HAS_SCREEN
      bl_level_idx = (bl_level_idx + 1) % BL_NUM_LEVELS;
      BL_SET(BL_LEVELS[bl_level_idx]);
      bl_prefs.putUChar("level", bl_level_idx);
    #endif
  }

  uint8_t getBrightnessLevel() {
    #ifdef HAS_SCREEN
      return bl_level_idx;
    #else
      return 0;
    #endif
  }

  void brightnessSave(uint8_t level) {
    #ifdef HAS_SCREEN
      if (level >= BL_NUM_LEVELS) level = BL_NUM_LEVELS - 1;
      bl_level_idx = level;
      BL_SET(BL_LEVELS[bl_level_idx]);
      bl_prefs.putUChar("level", bl_level_idx);
    #endif
  }

  void backlightOn() {
    #ifdef HAS_SCREEN
      BL_SETUP();
      BL_SET(BL_LEVELS[bl_level_idx]);
    #endif
  }

  void backlightOff() {
    #ifdef HAS_SCREEN
      BL_SET(0);
    #endif
  }
#else
  void backlightOn() {
    #ifdef HAS_SCREEN
      #if defined(MARAUDER_MINI) || defined(MARAUDER_MINI_V3)
        digitalWrite(TFT_BL, LOW);
      #elif !defined(MARAUDER_POOM)
        digitalWrite(TFT_BL, HIGH);
      #endif
    #endif
  }

  void backlightOff() {
    #ifdef HAS_SCREEN
      #if defined(MARAUDER_MINI) || defined(MARAUDER_MINI_V3)
        digitalWrite(TFT_BL, HIGH);
      #elif !defined(MARAUDER_POOM)
        digitalWrite(TFT_BL, LOW);
      #endif
    #endif
  }
#endif

void setup()
{
  randomSeed(esp_random());
  
  #ifndef DEVELOPER
    esp_log_level_set("*", ESP_LOG_NONE);
  #endif
  
  Serial.begin(115200);

  #if defined(HAS_SCREEN) && !defined(MARAUDER_POOM)
    pinMode(TFT_BL, OUTPUT);
  #endif
  
  backlightOff();
  
  #if defined(HAS_SCREEN) && !defined(MARAUDER_POOM)
    digitalWrite(TFT_CS, HIGH);
  #endif
  
  #if defined(HAS_SD) && !defined(HAS_C5_SD)
    pinMode(SD_CS, OUTPUT);
    delay(10);
    digitalWrite(SD_CS, HIGH);
    delay(10);
  #endif

  Serial.println("ESP-IDF version is: " + String(esp_get_idf_version()));

  #ifdef HAS_PSRAM
    if (!psramInit()) {
      Serial.println(F("PSRAM not available"));
    }
  #endif

  #ifdef HAS_SCREEN
    display_obj.RunSetup();
    display_obj.tft.setTextColor(TFT_WHITE, TFT_BLACK);
  #endif

  #ifndef HAS_MINI_SCREEN
    brightnessInit();
    backlightOff();
  #endif

  #ifdef HAS_SCREEN
    display_obj.drawBootSplash();
  #endif

  backlightOn();

  #ifdef HAS_SCREEN
    #if defined(HAS_BUTTONS) && (C_BTN >= 0)
      if (c_btn.justPressed()) {
        display_obj.headless_mode = true;
        backlightOff();
      }
    #endif
  #endif

  settings_obj.begin();

  const char* type = settings_obj.getSettingType("wu");
  if (type == nullptr || type[0] == '\0') {
    settings_obj.createDefaultSettings(SPIFFS);
  }

  #if defined(HAS_SD)
    if(!sd_obj.initSD())
      Serial.println(F("SD Card NOT Supported"));
  #endif

  wifi_scan_obj.RunSetup();

  #ifdef HAS_T_DONGLE_DISPLAY
    t_dongle_display.begin();
  #endif

  evil_portal_obj.setup();

  #ifdef HAS_BATTERY
    battery_obj.RunSetup();
    battery_obj.battery_level = battery_obj.getBatteryLevel();
  #endif

  #ifdef HAS_FLIPPER_LED
    flipper_led.RunSetup();
  #elif defined(HAS_NEOPIXEL_LED) || defined(HAS_T_DONGLE_LED)
    led_obj.RunSetup();
  #endif

  #ifdef HAS_GPS
    gps_obj.begin();
  #endif

  #ifdef HAS_SCREEN  
    display_obj.tft.setTextColor(TFT_WHITE, TFT_BLACK);
    menu_function_obj.RunSetup();
  #endif

  wifi_scan_obj.StartScan(WIFI_SCAN_OFF);
  cli_obj.RunSetup();
}

void loop()
{
  currentTime = millis();
  bool mini = false;

  #ifdef SCREEN_BUFFER
    #ifndef HAS_ILI9341
      mini = true;
    #endif
  #endif

  #if (defined(HAS_ILI9341) && !defined(MARAUDER_CYD_2USB))
    #if defined(HAS_BUTTONS) && (C_BTN >= 0)
      if (c_btn.isHeld()) {
        if (menu_function_obj.disable_touch)
          menu_function_obj.disable_touch = false;
        else
          menu_function_obj.disable_touch = true;
        menu_function_obj.updateStatusBar();
        while (!c_btn.justReleased())
          delay(1);
      }
    #endif
  #endif

  cli_obj.main(currentTime);
  wifi_scan_obj.main(currentTime);
  recon_obj.main(currentTime);
  #if defined(HAS_CSI_MOTION)
    csi_motion_obj.main(currentTime);
  #endif

  #ifdef HAS_T_DONGLE_DISPLAY
    t_dongle_display.update(currentTime, wifi_scan_obj);
  #endif

  #ifdef HAS_GPS
    gps_obj.main();
  #endif

  buffer_obj.save();

  #ifdef HAS_BATTERY
    battery_obj.main(currentTime);
  #endif

  if ((wifi_scan_obj.currentScanMode != WIFI_PACKET_MONITOR) || (mini)) {
    #ifdef HAS_SCREEN
      menu_function_obj.main(currentTime);
    #endif
  }
  
  #ifdef HAS_FLIPPER_LED
    flipper_led.main();
  #elif defined(HAS_NEOPIXEL_LED)
    led_obj.main(currentTime);
  #endif

  #ifdef HAS_SCREEN
    delay(1);
  #else
    delay(50);
  #endif
}
