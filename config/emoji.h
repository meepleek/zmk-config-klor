/*
 * Based on https://github.com/urob/zmk-helpers
 */

#pragma once

#include "macros.h"

#define UC_MACRO(name, unicode_bindings)                                                         \
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
                bindings = <&macro_tap &kp LS(LC(U))>, <&macro_tap unicode_bindings>, <&macro_tap &kp SPACE>; \
            };                                                                                   \
        };                                                                                       \
    };

#define ZMK_EMOJI_PAIR(name, L2, L3, L4, U2, U3, U4) \
    UC_MACRO(name##_lower, &kp CS_N1 &kp CS_F &kp CS_##L2 &kp CS_##L3 &kp CS_##L4)       \
    UC_MACRO(name##_upper, &kp CS_N1 &kp CS_F &kp CS_##U2 &kp CS_##U3 &kp CS_##U4)       \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)
