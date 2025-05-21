/*
 * Based on https://github.com/urob/zmk-helpers
 */

#pragma once

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

#define UC_MODMORPH(name, uc_binding, shifted_uc_binding)      \
    /                                                          \
    {                                                          \
        behaviors                                              \
        {                                                      \
        name:                                                  \
            name                                               \
            {                                                  \
                compatible = "zmk,behavior-mod-morph";         \
                #binding-cells = <0>;                        \
                bindings = <uc_binding>, <shifted_uc_binding>; \
                mods = <(MOD_LSFT | MOD_RSFT)>;                \
            };                                                 \
        };                                                     \
    };

#define ZMK_EMOJI_PAIR(name, L2, L3, L4, U2, U3, U4) \
    UC_MACRO(name##_lower, &kp CS_N1 &kp CS_F &kp CS_##L2 &kp CS_##L3 &kp CS_##L4)       \
    UC_MACRO(name##_upper, &kp CS_N1 &kp CS_F &kp CS_##U2 &kp CS_##U3 &kp CS_##U4)       \
    UC_MODMORPH(name, &name##_lower, &name##_upper)
