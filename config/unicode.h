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


#define EMOJI_PAIR_OS(name, leading_binding, trailing_binding, L2, L3, L4, U2, U3, U4) \
    UC_MACRO(name##_lower, leading_binding, trailing_binding, &kp N1 &kp F &kp L2 &kp L3 &kp L4)       \
    UC_MACRO(name##_upper, leading_binding, trailing_binding, &kp N1 &kp F &kp U2 &kp U3 &kp U4)       \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)

#define CZECH_PAIR_OS(name, leading_binding, trailing_binding, L1, L2, L3, U1, U2, U3) \
    UC_MACRO(name##_lower, leading_binding, trailing_binding, &kp N0 &kp L1 &kp L2 &kp L3)       \
    UC_MACRO(name##_upper, leading_binding, trailing_binding, &kp N0 &kp U1 &kp U2 &kp U3)       \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)

#define EMOJI_PAIR(name, L2, L3, L4, U2, U3, U4) \
    EMOJI_PAIR_OS(name, UNICODE_LEAD_LINUX, UNICODE_TRAIL_LINUX, L2, L3, L4, U2, U3, U4)   \
    EMOJI_PAIR_OS(m_##name, UNICODE_LEAD_MAC, UNICODE_TRAIL_MAC, L2, L3, L4, U2, U3, U4)       \
    EMOJI_PAIR_OS(w_##name, UNICODE_LEAD_WIN, UNICODE_TRAIL_WIN, L2, L3, L4, U2, U3, U4)

#define CZECH_PAIR(name, L1, L2, L3, U1, U2, U3) \
    CZECH_PAIR_OS(name, UNICODE_LEAD_LINUX, UNICODE_TRAIL_LINUX, L1, L2, L3, U1, U2, U3)   \
    CZECH_PAIR_OS(m_##name, UNICODE_LEAD_MAC, UNICODE_TRAIL_MAC, L1, L2, L3, U1, U2, U3)       \
    CZECH_PAIR_OS(w_##name, UNICODE_LEAD_WIN, UNICODE_TRAIL_WIN, L1, L2, L3, U1, U2, U3)
