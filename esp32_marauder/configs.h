#pragma once

#ifndef configs_h
  #define configs_h

  #define POLISH_POTATO

  //// BOARD TARGETS
  //#define MARAUDER_M5STICKC
  //#define MARAUDER_M5STICKCP2
  //#define MARAUDER_M5STACK_CORE2_AWS
  //#define MARAUDER_MINI
  //#define MARAUDER_V4
  //#define MARAUDER_V6
  //#define MARAUDER_V6_1
  //#define MARAUDER_V7
  //#define MARAUDER_V7_1
  //#define MARAUDER_KIT
  //#define GENERIC_ESP32
  //#define MARAUDER_FLIPPER
  //#define MARAUDER_MULTIBOARD_S3
  //#define ESP32_LDDB
  //#define MARAUDER_DEV_BOARD_PRO
  //#define XIAO_ESP32_S3
  //#define XIAO_ESP32_C5
  //#define MARAUDER_REV_FEATHER
  //#define MARAUDER_CYD_MICRO // 2432S028
  //#define MARAUDER_CYD_2USB // Another 2432S028 but it has tWo UsBs OoOoOoO
  //#define MARAUDER_CYD_GUITION // ESP32-2432S024 GUITION
  //#define MARAUDER_CYD_3_5_INCH
  //#define MARAUDER_C5
  //#define MARAUDER_T_DONGLE_C5
  //#define MARAUDER_CARDPUTER
  //#define MARAUDER_CARDPUTER_ADV
  //#define MARAUDER_V8
  //#define MARAUDER_PANCAKE
  //#define MARAUDER_MINI_V3
  //#define MARAUDER_M5_NANO_C6
  //#define DUAL_MINI_C5
  //#define MARAUDER_POOM
  #define ESP32_S3_MINI
  //// END BOARD TARGETS

  #define MARAUDER_VERSION "v1.20.0"
  #define GRAPH_REFRESH   100
  #define TRACK_EVICT_SEC 90
  #define DUAL_BAND_CHANNELS 51
  #define DISPLAY_BUFFER_LIMIT 20
  #define MODE_OFF 0
  #define MODE_RAINBOW 1
  #define MODE_ATTACK 2
  #define MODE_SNIFF 3
  #define MODE_CUSTOM 4

  //// HARDWARE NAMES
  #ifdef ESP32_S3_MINI
    #define HARDWARE_NAME "ESP32-S3 N16R8 + ST7735"
  #elif defined(MARAUDER_M5STICKC)
    #define HARDWARE_NAME "M5Stick-C Plus"
  // ... (other boards omitted for brevity, they remain in the full file)
  #else
    #define HARDWARE_NAME "ESP32"
  #endif

  //// BOARD FEATURES
  #ifdef ESP32_S3_MINI
    #define HAS_BT
    #define HAS_BUTTONS
    #define HAS_NEOPIXEL_LED
    #define HAS_SCREEN
    #define USE_FFAT
    #define HAS_SD
    #define USE_SD
    #define HAS_PSRAM
    #define HAS_GPS
    #define HAS_DIRECT_UPLOAD
    #define HAS_NIMBLE_2
    #define HAS_IDF_3
    #define HAS_C5_SD // Forces SD sharing SPI with TFT
  #endif
  // ... (other boards omitted for brevity)

  //// BUTTON DEFINITIONS
  #ifdef HAS_BUTTONS
    #ifdef ESP32_S3_MINI
      #define U_BTN 38
      #define D_BTN 39
      #define L_BTN 4
      #define R_BTN 5
      #define C_BTN 15
      #define B_BTN 16
      #define S_BTN 47
      #define X_BTN 48

      #define HAS_U
      #define HAS_D
      #define HAS_L
      #define HAS_R
      #define HAS_C
      #define HAS_B

      #define U_PULL true
      #define D_PULL true
      #define L_PULL true
      #define R_PULL true
      #define C_PULL true
      #define B_PULL true
    #endif
    // ... (other boards omitted)
  #endif
  //// END BUTTON DEFINITIONS

  //// DISPLAY DEFINITIONS
  #ifdef HAS_SCREEN
    #ifdef ESP32_S3_MINI
      #define CHAN_PER_PAGE 7
      #define SCREEN_CHAR_WIDTH 40
      #define BANNER_TEXT_SIZE 1

      #ifndef TFT_WIDTH
        #define TFT_WIDTH 128
      #endif
      #ifndef TFT_HEIGHT
        #define TFT_HEIGHT 160
      #endif

      #define SCREEN_ORIENTATION 3
      
      #define SCREEN_BUFFER
      #define MAX_SCREEN_BUFFER 9
      #define GRAPH_VERT_LIM TFT_HEIGHT/2 - 1
      #define EXT_BUTTON_WIDTH 0
      #define CHAR_WIDTH 6
      #define SCREEN_WIDTH TFT_HEIGHT
      #define SCREEN_HEIGHT TFT_WIDTH
      #define HEIGHT_1 TFT_WIDTH
      #define WIDTH_1 TFT_HEIGHT
      #define STANDARD_FONT_CHAR_LIMIT (SCREEN_WIDTH/6)
      #define TEXT_HEIGHT 12
      #define BOT_FIXED_AREA 0
      #define TOP_FIXED_AREA 32
      #define YMAX SCREEN_HEIGHT
      #define minimum(a,b)     (((a) < (b)) ? (a) : (b))
      #define MENU_FONT &FreeMono9pt7b
      #define BUTTON_SCREEN_LIMIT 5
      #define BUTTON_ARRAY_LEN BUTTON_SCREEN_LIMIT
      #define STATUS_BAR_WIDTH 8
      #define LVGL_TICK_PERIOD 6

      #define FRAME_X 20
      #define FRAME_Y 40
      #define FRAME_W 120
      #define FRAME_H 50
      #define REDBUTTON_X FRAME_X
      #define REDBUTTON_Y FRAME_Y
      #define REDBUTTON_W (FRAME_W/2)
      #define REDBUTTON_H FRAME_H
      #define GREENBUTTON_X (REDBUTTON_X + REDBUTTON_W)
      #define GREENBUTTON_Y FRAME_Y
      #define GREENBUTTON_W (FRAME_W/2)
      #define GREENBUTTON_H FRAME_H
      #define STATUSBAR_COLOR 0x4A49
    #endif
    // ... (other boards omitted)
  #endif
  //// END DISPLAY DEFINITIONS

  //// MENU DEFINITIONS
  #ifdef ESP32_S3_MINI
    #define BANNER_TIME 100
    #define COMMAND_PREFIX "!"
    #define KEY_X (SCREEN_WIDTH/2)
    #define KEY_Y 28
    #define KEY_W SCREEN_WIDTH
    #define KEY_H 18
    #define KEY_SPACING_X 0
    #define KEY_SPACING_Y 1
    #define KEY_TEXTSIZE 1
    #define ICON_W 18
    #define ICON_H 18
    #define BUTTON_PADDING 16
  #endif
  //// END MENU DEFINITIONS

  //// SD DEFINITIONS
  #if defined(USE_SD)
    #ifdef ESP32_S3_MINI
      #define SD_CS 1
      #define SD_SCK 40
      #define SD_MISO 41
      #define SD_MOSI 42
    #endif
    // ... (other boards omitted)
  #endif
  //// END SD DEFINITIONS

  //// GPS STUFF
  #ifdef HAS_GPS
    #ifdef ESP32_S3_MINI
      #define GPS_SERIAL_INDEX 2
      #define GPS_TX 6
      #define GPS_RX 7
      #define mac_history_len 500
    #endif
  #endif
  //// END GPS STUFF

  //// NEOPIXEL STUFF  
  #ifdef HAS_NEOPIXEL_LED
    #ifdef ESP32_S3_MINI
      #define PIN 12
    #else
      #define PIN 25
    #endif
  #endif
  //// END NEOPIXEL STUFF

  //// MARAUDER TITLE STUFF
  #define MARAUDER_TITLE_BYTES 13578
  //// END MARAUDER TITLE STUFF

#endif
