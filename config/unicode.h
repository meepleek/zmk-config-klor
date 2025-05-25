/*
 * Based on https://github.com/urob/zmk-helpers
 */

#pragma once

#include "macros.h"

#define UNICODE_LEAD_LINUX &macro_tap &kp LS(LC(U))  // <- Linux compose sequence
#define UNICODE_TRAIL_LINUX &macro_tap &kp SPACE

#define UNICODE_LEAD_MAC &macro_press &kp LALT  // <- macOS compose sequence (unicode hex input)
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


#define EMOJI_PAIR_UTF32(name, leading_binding, trailing_binding, L2, L3, L4, U2, U3, U4) \
    UC_MACRO(name##_lower, leading_binding, trailing_binding, &kp N1 &kp F &kp L2 &kp L3 &kp L4)       \
    UC_MACRO(name##_upper, leading_binding, trailing_binding, &kp N1 &kp F &kp U2 &kp U3 &kp U4)       \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)

#define EMOJI_PAIR_UTF16(name, leading_binding, trailing_binding, L3, L5, L6, L7, U3, U5, U6, U7) \
    UC_MACRO(name##_lower, leading_binding, trailing_binding, &kp D &kp N8 &kp N3 &kp L3 &kp D &kp L5 &kp L6 &kp L7)       \
    UC_MACRO(name##_upper, leading_binding, trailing_binding, &kp D &kp N8 &kp N3 &kp U3 &kp D &kp U5 &kp U6 &kp U7)       \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)

#define EMOJI_PAIR(name, L2, L3, L4, U2, U3, U4, ML3, ML5, MU3, MU5) \
    EMOJI_PAIR_UTF32(l_##name, UNICODE_LEAD_LINUX, UNICODE_TRAIL_LINUX, L2, L3, L4, U2, U3, U4)   \
    EMOJI_PAIR_UTF32(w_##name, UNICODE_LEAD_WIN, UNICODE_TRAIL_WIN, L2, L3, L4, U2, U3, U4)     \    
    EMOJI_PAIR_UTF16(m_##name, UNICODE_LEAD_MAC, UNICODE_TRAIL_MAC, ML3, ML5, L3, L4, MU3, MU5, U3, U4) 

#define CZECH_PAIR_OS(name, leading_binding, trailing_binding, L1, L2, L3, U1, U2, U3) \
    UC_MACRO(name##_lower, leading_binding, trailing_binding, &kp N0 &kp L1 &kp L2 &kp L3)       \
    UC_MACRO(name##_upper, leading_binding, trailing_binding, &kp N0 &kp U1 &kp U2 &kp U3)       \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)

#define CZECH_PAIR(name, L1, L2, L3, U1, U2, U3) \
    CZECH_PAIR_OS(l_##name, UNICODE_LEAD_LINUX, UNICODE_TRAIL_LINUX, L1, L2, L3, U1, U2, U3)   \
    CZECH_PAIR_OS(m_##name, UNICODE_LEAD_MAC, UNICODE_TRAIL_MAC, L1, L2, L3, U1, U2, U3)       \
    CZECH_PAIR_OS(w_##name, UNICODE_LEAD_WIN, UNICODE_TRAIL_WIN, L1, L2, L3, U1, U2, U3)

#define UNICODE_CHAR(name, keybinding_utf32, keybinding_utf16) \
    UC_MACRO(l_##name, UNICODE_LEAD_LINUX, UNICODE_TRAIL_LINUX, keybinding_utf32)   \    
    UC_MACRO(w_##name, UNICODE_LEAD_WIN, UNICODE_TRAIL_WIN, keybinding_utf32)       \    
    UC_MACRO(m_##name, UNICODE_LEAD_MAC, UNICODE_TRAIL_MAC, keybinding_utf16)      

#define UNICODE_LAYER(prefix) \
         &prefix##os_hint       &none        &prefix##degree       &prefix##euro       &bootloader     \
         &prefix##u_acu   &prefix##u_ring   &prefix##d_car   &prefix##n_car   &prefix##t_car     \
     \
 &prefix##crab       &prefix##a_acu  &prefix##r_car   &prefix##s_car   &prefix##z_car   &none     \
 &prefix##c_car    &prefix##e_car  &prefix##e_acu   &prefix##i_acu   &prefix##y_acu  &prefix##o_acu     \
     \
 &none   &kp LALT   &kp LCTRL     &kp LSHFT   &kp LWIN   &none        &none     \
 &none   &none      &prefix##emj_tongue   &kp RSHFT   &prefix##emj_vomit &prefix##emj_thumb   &prefix##emj_innocent     \
     \
                                       &none   &none           &none               &none     \
                                       &none   &prefix##emj_sad   &prefix##emj_grin   &prefix##emj_smile 


#define BASE_OS_LAYER()  \
                     &trans      &trans     &trans      &trans      &trans \
                     &trans   &trans   &trans   &trans   &trans \
 \
             &trans  &trans   &trans   &trans   &trans   &trans \
             &trans  &trans      &trans    &trans    &trans   &trans \
 \
             &trans  &trans   &trans       &trans       &trans        &trans         &trans \
             &trans  &trans     &trans   &trans   &trans   &trans   &trans \
 \
                                                   &trans  &trans          &trans              &trans \
                                                   &trans  &trans   &trans   &trans                                     