// Endgame is to be able to type with left hand and keep right on the mouse
// Features:
// - Swap Hands that mirrors layout
// - Auto Shift
// - Keys B, N, M moved to far right where they'd be on Miuni32
// - Shift + Backspace for Delete
// - IJKL navigation

#include QMK_KEYBOARD_H

#define PERMISSIVE_HOLD

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define _BASE         0
#define _SYMB         1
#define _NUMB         2
#define _TENKEY       3
#define _FUNCTION     4
#define _MOUSE        5

#define SYM____ MO(_SYMB)
#define NUM____ MO(_NUMB)
#define TENKEY_ MO(_TENKEY)
#define FUNC___ MO(_FUNCTION)
#define MOUSE__ MO(_MOUSE)

#define UNDO___ LCTL(KC_Z)
#define CUT____ LCTL(KC_X)
#define COPY___ LCTL(KC_C)
#define PASTE__ LCTL(KC_V)

#define SWP_SPC SH_T(KC_SPC)

#define SYM_SPC LT(_SYMB, KC_SPC)
#define SYM_BS_ LT(_SYMB, KC_BSPC)

#define NUM_SPC LT(_NUMB, KC_SPC)
#define NUM_ENT LT(_NUMB, KC_ENT)

#define SHF_A__ RSFT_T(KC_A)
#define SHF_F__ RSFT_T(KC_F)
#define SHF_J__ RSFT_T(KC_J)
#define SH_SCLN RSFT_T(KC_SCLN)

#define SHF_ENT RSFT_T(KC_ENT)
#define CTL_X__ LCTL_T(KC_X)
#define ALT_C__ LALT_T(KC_C)
#define GUI_V__ LGUI_T(KC_V)
#define GUI_B__ LGUI_T(KC_B)
#define ALT_N__ RALT_T(KC_N)

#define SHF_BS RSFT_T(KC_BSPC)

enum custom_keycodes
{
	KC_BSDL,  // Backspace and Delete on shift
	//M1,
	//M2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [_BASE] = LAYOUT_gergo(
	
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
		
        SHF_BS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_QUOT,                            KC_QUOT, KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, SHF_ENT,
		
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_PDOT, KC_COMM,   KC_LWIN,      KC_LWIN,   KC_COMM, KC_PDOT, KC_B,   KC_N,    KC_M,    KC_SLSH, KC_RCTL,
		
                                            NUM_SPC, SWP_SPC, SYM_SPC, NUM_ENT,          NUM_ENT, SYM_SPC, SYM_SPC, SYM_SPC
    ),
    [_SYMB] = LAYOUT_gergo(
/*               $        "        {        }        !                                                                                                          */
        KC_ESC,  KC_DLR,  KC_DQUO, KC_LCBR, KC_RCBR, KC_EXLM,                                             _______, KC_BSPC, KC_UP,   KC_DEL,  _______, _______,
/*               |        &        (        )        =        >                                                                                                 */
        _______, KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN, KC_EQL,  KC_RABK,                           _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
/*               @        _        [        ]        +        <          \|                                                                                     */
        _______, KC_AT,   KC_UNDS, KC_LBRC, KC_RBRC, KC_PLUS, KC_LABK,   KC_BSLS,     _______,   _______, _______, _______, _______, _______, _______, _______,
		
                                            _______, _______, _______, _______,         _______, _______, _______, _______
    ),
    [_NUMB] = LAYOUT_gergo(
/*               !        @        #        $        %                                                                                                          */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                _______, _______, _______, _______, _______, _______,
/*               ^        &        *        {        }        /?                                                                                                */
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SLSH,                           _______, _______, _______, _______, _______, _______, _______,
/*                                                   -                                                                                                          */
        FUNC___, UNDO___, CUT____, COPY___, PASTE__, KC_PMNS, _______,   _______,     _______,   _______, _______, _______, _______, _______, _______, _______,
		
                                            UNDO___, CUT____, COPY___, PASTE__,         _______, _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT_gergo(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                               _______, _______, _______, _______, _______, _______,
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,                           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,   _______,     _______,   _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______, _______,         _______, _______, _______, _______
    ),
//    [_MOUSE] = LAYOUT_gergo(
//        _______, _______, _______, _______, _______, _______,                                             _______, _______, KC_MS_U, _______, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______,                           _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
//                                            _______, _______, _______, _______,         _______, _______, KC_BTN1, KC_BTN2
//    ),
//    [_TENKEY] = LAYOUT_gergo(
//        _______, _______, _______, _______, _______, _______,                                             KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______,                           XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, _______, _______,
//        _______, _______, _______, _______, _______, _______, _______, _______,         KC_NLCK, XXXXXXX, KC_KP_3, KC_KP_2, KC_KP_1, XXXXXXX, _______, _______,
//                                            _______, _______, _______, _______,         _______, XXXXXXX, KC_KP_0, KC_PDOT
//    ),
};


//static bool IsDisableMods = false;
//static uint8_t registeredBackspaceOrDelete = 0;
//static uint8_t unregisteredMods = 0;

//void DisableMods(void)
//{
//    unregisteredMods = unregisteredMods | get_mods();
//    clear_mods();

//    IsDisableMods = true;
//}

//void EnableMods(void)
//{
//    if (unregisteredMods != 0)
//    {
//        set_mods(unregisteredMods);
//        unregisteredMods = 0;
//    }

//    IsDisableMods = false;
//}

//void UpdateMods(uint16_t keycode, keyrecord_t* record)
//{
//    if (IS_MOD(keycode))
//    {
//        if (IsDisableMods)
//        {
//            if (record->event.pressed)
//			{
//                DisableMods(); // This will append new mods
//            }
//			else
//			{
//                // TODO: I'm not sure entirely if two mods could overlap e.g. LSFT_T(kc)
//                unregisteredMods = unregisteredMods & ~keycode;
//            }
//        }
//    }
//}

//bool IsShifted(void)
//{
//    uint8_t allMods = unregisteredMods | get_mods();

//    if ((allMods & KC_LSFT) != 0)
//        return true;

//    if ((allMods & KC_RSFT) != 0)
//        return true;

//    return false;
//}

//bool process_record_user(uint16_t keycode, keyrecord_t* record)
//{
//    switch (keycode)
//    {
//        case KC_BSDL: // Shift-BS = DEL
//            {
//                if (record->event.pressed)
//			{
//                    DisableMods();

//                    registeredBackspaceOrDelete = IsShifted() ? KC_DEL : KC_BSPC;
//                    register_code(registeredBackspaceOrDelete);
//                }
//			else
//			{
//                    if (registeredBackspaceOrDelete != 0)
//                    {
//                        unregister_code(registeredBackspaceOrDelete);
//                        registeredBackspaceOrDelete = 0;
//                    }

//                    EnableMods();
//                }

//                break;
//                //return false;
//            }
//        case M1: { if (record->event.pressed) SEND_STRING("=>"); break; }
//        case M2: { if (record->event.pressed) SEND_STRING(".Select(x => x)" SS_TAP(X_LEFT) "."); break; }
//        default:
//            {
//                UpdateMods(keycode, record);
//                break;
//            }
//    }

//    return true; // Process all other key codes normally
//}

//  [EMPTY] = LAYOUT_gergo
//  (
//      _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
//                                          _______, _______, _______, _______,         _______, _______, _______, _______,
//  ),
































