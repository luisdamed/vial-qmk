#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "quantum.h"

#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_h(
       	KC_F13 , KC_F14 , KC_F15,
        KC_F16 , KC_F17 , KC_F18,
        KC_F19 , KC_F20 , KC_F21
    ),

    [1] = LAYOUT_h(
        ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),

    [2] = LAYOUT_h(
        ____, ____, ____, ____, ____, ____, ____, ____, ____
    ),

    [3] = LAYOUT_h(
        ____, ____, ____, ____, ____, ____, ____, ____, ____ 
    ),

};


enum layer_names {
    _LY0,
    _LY1,
    _LY2,
    _LY3,
};

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    if(data[0] == 0xFC){
        switch (data[1]) {
            case 0x01:{
                // move to layer
                data[1] = 0xFD;
                layer_move(data[2]);
                break;
            }
            case 0x02:{
                // turn on layer
                data[1] = 0xFD;
                layer_on(data[2]);
                break;
            }
            case 0x03:{
                // turn off layer
                data[1] = 0xFD;
                layer_off(data[2]);
                break;
            }
        }
    }
    raw_hid_send(data, length);
}





// layer_state_t layer_state_set_user(layer_state_t state) {
//   writePin(B1, get_highest_layer(state) > 0);
//   return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//   // Use `static` variable to remember the previous status.
//   static bool layer0_on = false;

//   if (layer0_on != IS_LAYER_ON_STATE(state, _LY0)) {
//     layer0_on = !layer0_on;
//     if (layer0_on) {  // Just entered the _LY0 layer.
//        writePin(B1, 1);
//        writePin(B3, 0);
//     } else if (IS_LAYER_ON_STATE(state, _LY1)){          // Just exited the _LY0 layer.
//       writePin(B1, 0);
//       writePin(B3, 1);
//     }
//   }

//   return state;
// }


layer_state_t layer_state_set_user(layer_state_t state) {
  // Use `static` variable to remember the previous status.
  static bool layer0_on = false;
  static bool layer1_on = false;


  if (layer0_on != IS_LAYER_ON_STATE(state, _LY0)) {
    layer0_on = !layer0_on;
    if (layer0_on) {  // Just entered the _LY0 layer.
       writePin(B1, 1);
    } else{          // Just exited the _LY0 layer.
      writePin(B1, 0);
    }
  }

  if (layer1_on != IS_LAYER_ON_STATE(state, _LY1)) {
    layer1_on = !layer1_on;
    if (layer1_on) {  // Just entered the _LY1 layer.
       writePin(B3, 1);
    } else{          // Just exited the _LY1 layer.
      writePin(B3, 0);
    }
  }

  return state;
}


