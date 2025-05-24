/*
 * Based on https://github.com/urob/zmk-helpers
 */

#pragma once

#include "macros.h"

#define UNICODE_LEAD_LINUX &macro_tap &kp LS(LC(U))  // <- Linux compose sequence
#define UNICODE_TRAIL_LINUX &macro_tap &kp SPACE

#define UNICODE_LEAD_MAC &macro_press &kp LALT  // <- macOS compose sequence (must be activated in system preferences) // todo: is UNICODE input layout fine?
#define UNICODE_TRAIL_MAC &macro_release &kp LALT

#define UNICODE_LEAD_WIN &macro_tap &kp RALT &kp U  // <- WinCompose sequence
#define UNICODE_TRAIL_WIN &macro_tap &kp RET


#define UC_MACRO(name, lead_binding, tail_binding, unicode_bindings)                                                         \
    /                                                                                            \
    {                                                                                            \
        macros                                                                                   \
        {                                                                                        \
        name:                                                                                    \
            name                                                                                 \
            {                                                                                    \
                compatible = "zmk,behavior-macro";                                               \
                wait-ms = <0>;                                                                 \
                tap-ms = <0>;                                                                  \
                #binding-cells = <0>;                                                          \
                bindings = <lead_binding>, <&macro_tap unicode_bindings>, <tail_binding>; \
            };                                                                                   \
        };                                                                                       \
    };

#define OS_HINT_MACRO(name, c0, c1, c2)                                                         \
    /                                                                                            \
    {                                                                                            \
        macros                                                                                   \
        {                                                                                        \
        name##_os_hint:                                                                                    \
            name##_os_hint                                                                                \
            {                                                                                    \
                compatible = "zmk,behavior-macro";                                               \
                wait-ms = <0>;                                                                 \
                tap-ms = <0>;                                                                  \
                #binding-cells = <0>;                                                          \
                bindings = <&kp c0 &kp c1 &kp c2>; \
            };                                                                                   \
        };                                                                                       \
    };


#define EMOJI_PAIR_OS(name, leading_binding, trailing_binding, L2, L3, L4, U2, U3, U4) \
    UC_MACRO(name##_lower, leading_binding, trailing_binding, &kp N1 &kp F &kp L2 &kp L3 &kp L4)       \
    UC_MACRO(name##_upper, leading_binding, trailing_binding, &kp N1 &kp F &kp U2 &kp U3 &kp U4)       \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)

#define CZECH_PAIR_OS(name, leading_binding, trailing_binding, L1, L2, L3, U1, U2, U3) \
    UC_MACRO(name##_lower, leading_binding, trailing_binding, &kp N0 &kp L1 &kp L2 &kp L3)       \
    UC_MACRO(name##_upper, leading_binding, trailing_binding, &kp N0 &kp U1 &kp U2 &kp U3)       \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)

#define EMOJI_PAIR(name, L2, L3, L4, U2, U3, U4) \
    EMOJI_PAIR_OS(l_##name, UNICODE_LEAD_LINUX, UNICODE_TRAIL_LINUX, L2, L3, L4, U2, U3, U4)   \
    EMOJI_PAIR_OS(m_##name, UNICODE_LEAD_MAC, UNICODE_TRAIL_MAC, L2, L3, L4, U2, U3, U4)       \
    EMOJI_PAIR_OS(w_##name, UNICODE_LEAD_WIN, UNICODE_TRAIL_WIN, L2, L3, L4, U2, U3, U4)

#define CZECH_PAIR(name, L1, L2, L3, U1, U2, U3) \
    CZECH_PAIR_OS(l_##name, UNICODE_LEAD_LINUX, UNICODE_TRAIL_LINUX, L1, L2, L3, U1, U2, U3)   \
    CZECH_PAIR_OS(m_##name, UNICODE_LEAD_MAC, UNICODE_TRAIL_MAC, L1, L2, L3, U1, U2, U3)       \
    CZECH_PAIR_OS(w_##name, UNICODE_LEAD_WIN, UNICODE_TRAIL_WIN, L1, L2, L3, U1, U2, U3)

#define UNICODE_CHAR(name, keybinding) \
    UC_MACRO(l_##name, UNICODE_LEAD_LINUX, UNICODE_TRAIL_LINUX, keybinding)   \
    UC_MACRO(m_##name, UNICODE_LEAD_MAC, UNICODE_TRAIL_MAC, keybinding)       \
    UC_MACRO(w_##name, UNICODE_LEAD_WIN, UNICODE_TRAIL_WIN, keybinding)

#define UNICODE_LAYER(prefix) \
         &prefix##os_hint       &none        &prefix##degree       &prefix##euro       &bootloader     \
         &prefix##u_acu   &prefix##u_ring   &prefix##d_car   &prefix##n_car   &prefix##t_car     \
     \
 &none       &prefix##a_acu  &prefix##r_car   &prefix##s_car   &prefix##z_car   &none     \
 &prefix##c_car    &prefix##e_car  &prefix##e_acu   &prefix##i_acu   &prefix##y_acu  &prefix##o_acu     \
     \
 &none   &kp LALT   &kp LCTRL     &kp LSHFT   &kp LWIN   &none        &none     \
 &none   &none      &prefix##emj_tongue   &kp RSHFT   &prefix##emj_vomit &prefix##emj_thumb   &prefix##emj_innocent     \
     \
                                       &none   &none           &none               &none     \
                                       &none   &prefix##emj_sad   &prefix##emj_grin   &prefix##emj_smile 