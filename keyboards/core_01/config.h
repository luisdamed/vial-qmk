#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xEEEE
#define PRODUCT_ID      0x2023
#define DEVICE_VER		0x0001
#define MANUFACTURER    Luis Medina
#define PRODUCT         core_01

// /* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

/* key matrix pins */
#define MATRIX_ROW_PINS { F6, F5, F4}
#define MATRIX_COL_PINS { E6, D7, C6}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 0

#define VIAL_KEYBOARD_UID {0x36, 0x67, 0x27, 0xAE, 0x54, 0x94, 0x76, 0x0C}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 2 }

#define DEBUG_MATRIX_SCAN_RATE






