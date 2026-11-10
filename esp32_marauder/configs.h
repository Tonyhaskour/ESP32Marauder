#pragma once

#ifndef configs_h
  #define configs_h

  #define POLISH_POTATO

  //// BOARD TARGETS
  #define ESP32_S3_MINI
  //// END BOARD TARGETS

  #define JSON_SETTING_SIZE 6144
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
    #define HARDWARE_NAME "ESP32-S3 N16R8 ST7735"
  #else
    #define HARDWARE_NAME "ESP32"
  #endif
  //// END HARDWARE NAMES

  //// FCC MODULE IDENTIFIERS
  #define FCC_ID "See hardware label"
  //// END FCC MODULE IDENTIFIERS

  //// BOARD FEATURES
  #ifdef ESP32_S3_MINI
    #define HAS_PSRAM
    #define HAS_MINI_KB
    #define HAS_BT
    #define HAS_BUTTONS
    #define HAS_NEOPIXEL_LED
    #define HAS_SCREEN
    #define HAS_MINI_SCREEN
    #define HAS_SD
    #define USE_SD
  #endif

  //// BUTTON DEFINITIONS
  #ifdef HAS_BUTTONS
    #ifdef ESP32_S3_MINI
      #define U_BTN 38   // UP
      #define D_BTN 39   // DOWN
      #define L_BTN 4    // LEFT
      #define R_BTN 5    // RIGHT
      #define C_BTN 15   // A  (select / stop scan)
      #define B_BTN 16   // B  (back)
      #define S_BTN 47   // SELECT (same as A)
      #define X_BTN 48   // START (hold 3 s = restart)

      #define HAS_L
      #define HAS_R
      #define HAS_U
      #define HAS_D
      #define HAS_C
      #define HAS_B

      #define L_PULL true
      #define C_PULL true
      #define U_PULL true
      #define R_PULL true
      #define D_PULL true
      #define B_PULL true
      #define S_PULL true
      #define X_PULL true
    #endif
  #endif
  //// END BUTTON DEFINITIONS

  //// DISPLAY DEFINITIONS
  #ifdef HAS_SCREEN
    #ifdef ESP32_S3_MINI
      #define CHAN_PER_PAGE 7
      #define SCREEN_CHAR_WIDTH 40
      #ifndef TFT_MOSI
        #define TFT_MOSI 42
      #endif
      #ifndef TFT_SCLK
        #define TFT_SCLK 40
      #endif
      #ifndef TFT_MISO
        #define TFT_MISO 41
      #endif
      #ifndef TFT_CS
        #define TFT_CS 45
      #endif
      #ifndef TFT_DC
        #define TFT_DC 21
      #endif
      #ifndef TFT_RST
        #define TFT_RST 14
      #endif
      #ifndef TFT_BL
        #define TFT_BL 2
      #endif

      #define SCREEN_BUFFER
      #define MAX_SCREEN_BUFFER 9
      #define BANNER_TEXT_SIZE 1

      #ifndef TFT_WIDTH
        #define TFT_WIDTH 128
      #endif
      #ifndef TFT_HEIGHT
        #define TFT_HEIGHT 160
      #endif

      #define GRAPH_VERT_LIM (TFT_WIDTH / 2 - 1)
      #define EXT_BUTTON_WIDTH 0
      #define SCREEN_ORIENTATION 3
      #define CHAR_WIDTH 6
      #define SCREEN_WIDTH TFT_HEIGHT   // 160 (landscape)
      #define SCREEN_HEIGHT TFT_WIDTH   // 128 (landscape)
      #define HEIGHT_1 TFT_WIDTH
      #define WIDTH_1 TFT_HEIGHT
      #define STANDARD_FONT_CHAR_LIMIT (SCREEN_WIDTH/6)
      #define TEXT_HEIGHT 12
      #define BOT_FIXED_AREA 0
      #define TOP_FIXED_AREA 48
      #define YMAX SCREEN_HEIGHT
      #define minimum(a,b)     (((a) < (b)) ? (a) : (b))
      #define MENU_FONT &FreeMono9pt7b
      #define BUTTON_SCREEN_LIMIT 9
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

      // Packet monitor oscilloscope geometry
      #define PKT_HALF    (HEIGHT_1 / 2)
      #define PKT_AXIS_W  (WIDTH_1 - 10)
    #endif
  #endif
  //// END DISPLAY DEFINITIONS

  //// MENU DEFINITIONS
  #ifdef ESP32_S3_MINI
    #define BANNER_TIME 50
    #define COMMAND_PREFIX "!"
    #define KEY_X (SCREEN_WIDTH/2)
    #define KEY_Y (SCREEN_HEIGHT/4.5)
    #define KEY_W SCREEN_WIDTH
    #define KEY_H (SCREEN_HEIGHT/12.8)
    #define KEY_SPACING_X 0
    #define KEY_SPACING_Y 1
    #define KEY_TEXTSIZE 1
    #define ICON_W 22
    #define ICON_H 22
    #define BUTTON_PADDING 10
  #endif
  //// END MENU DEFINITIONS

  //// SD DEFINITIONS
  #if defined(USE_SD)
    #ifdef ESP32_S3_MINI
      #define SD_CS 1
    #endif
  #endif
  //// END SD DEFINITIONS

  //// SPACE SAVING COLORS
  #define TFTWHITE     1
  #define TFTCYAN      2
  #define TFTBLUE      3
  #define TFTRED       4
  #define TFTGREEN     5
  #define TFTGREY      6
  #define TFTGRAY      7
  #define TFTMAGENTA   8
  #define TFTVIOLET    9
  #define TFTORANGE    10
  #define TFTYELLOW    11
  #define TFTLIGHTGREY 12
  #define TFTPURPLE    13
  #define TFTNAVY      14
  #define TFTSILVER    15
  #define TFTDARKGREY  16
  #define TFTSKYBLUE   17
  #define TFTLIME      18
  //// END SPACE SAVING COLORS

  //// NEOPIXEL STUFF  
  #ifdef HAS_NEOPIXEL_LED
    #ifdef ESP32_S3_MINI
      #define PIN 12
    #endif
  #endif
  //// END NEOPIXEL STUFF

  //// EVIL PORTAL STUFF
  #ifdef HAS_PSRAM
    #define MAX_HTML_SIZE 30000
  #else
    #define MAX_HTML_SIZE 11400
  #endif
  //// END EVIL PORTAL STUFF

  //// GPS STUFF (Needed for MAC history even if GPS is disabled)
  #ifdef HAS_PSRAM
    #define mac_history_len 500
  #else
    #define mac_history_len 100
  #endif
  #define mac_history_len_half (mac_history_len / 2)
  //// END GPS STUFF

  //// WIFI STUFF
  #ifndef HAS_DUAL_BAND
    #define HOP_DELAY 1000
  #else
    #define HOP_DELAY 250
  #endif
  //// END WIFI STUFF

  //// PCAP BUFFER STUFF
  #ifdef HAS_PSRAM
    #define BUF_SIZE 8 * 1024
    #define SNAP_LEN 1 * 4096
  #elif defined(MARAUDER_NO_PSRAM_MEMORY_PROFILE)
    #define BUF_SIZE 2 * 1024
    #define SNAP_LEN 1514
  #else
    #define BUF_SIZE 3 * 1024
    #define SNAP_LEN 2324
  #endif
  //// END PCAP BUFFER STUFF

  //// MARAUDER TITLE STUFF
  #define MARAUDER_TITLE_BYTES 13578
  //// END MARAUDER TITLE STUFF

#endif
