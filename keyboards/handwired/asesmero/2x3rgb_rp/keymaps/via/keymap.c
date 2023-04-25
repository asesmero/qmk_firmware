/*
Copyright 2023 Antonio Sesmero

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    LAYER_0,
	LAYER_1,
	LAYER_2,
	LAYER_3
	};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_0] = LAYOUT_ortho_2x3(
		MEH(KC_A), MEH(KC_B), MEH(KC_C), 
		MEH(KC_D), MEH(KC_E), MEH(KC_F)), 
	};
	
	[LAYER_1] = LAYOUT_ortho_2x3(
		MEH(KC_A), MEH(KC_B), MEH(KC_C), 
		MEH(KC_D), MEH(KC_E), MEH(KC_F)), 
    };
	
	[LAYER_2] = LAYOUT_ortho_2x3(
		MEH(KC_A), MEH(KC_B), MEH(KC_C), 
		MEH(KC_D), MEH(KC_E), MEH(KC_F)), 
    };

	[LAYER_3] = LAYOUT_ortho_2x3(
		MEH(KC_A), MEH(KC_B), MEH(KC_C), 
		MEH(KC_D), MEH(KC_E), MEH(KC_F)), 
    };
	
	
const rgblight_segment_t PROGMEM rgb_layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_PURPLE} 
);

const rgblight_segment_t PROGMEM rgb_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer0,
    rgb_layer1,
    rgb_layer2,
    rgb_layer3
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_PURPLE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, LAYER_0));
	rgblight_set_layer_state(1, layer_state_cmp(state, LAYER_1));
	rgblight_set_layer_state(2, layer_state_cmp(state, LAYER_2));
	rgblight_set_layer_state(3, layer_state_cmp(state, LAYER_3));
    return state;