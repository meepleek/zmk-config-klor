#pragma once

// #include <dt-bindings/zmk/hid_usage.h>
// #include <dt-bindings/zmk/hid_usage_pages.h>
// #include <dt-bindings/zmk/modifiers.h>
#include <dt-bindings/zmk/keys.h>
#include "macros.h"

#define CS_SEMICOLON GRAVE
#define CS_PLUS N1
#define CS_EQUAL MINUS

#define CS_ACUTE EQUAL
#define CS_CARON LS(CS_ACUTE)
#define CS_RING LS(CS_SEMICOLON)

#define CS_Q Q
#define CS_W W
#define CS_E E
#define CS_R R
#define CS_T T
#define CS_Z Y
#define CS_U U
#define CS_I I
#define CS_O O
#define CS_P P
#define CS_U_ACU LEFT_BRACKET
#define CS_RPAR RIGHT_BRACKET

#define CS_A A
#define CS_S S
#define CS_D D
#define CS_F F
#define CS_G G
#define CS_H H
#define CS_J J
#define CS_K K
#define CS_L L
#define CS_SECT SINGLE_QUOTE
#define CS_BACKSLASH NON_US_BACKSLASH

#define CS_Y Z
#define CS_X X
#define CS_C C
#define CS_V V
#define CS_B B
#define CS_N N
#define CS_M M
#define CS_COMMA COMMA
#define CS_DOT DOT
#define CS_MINUS SLASH

#define CS_E_CAR N2
#define CS_S_CAR N3
#define CS_C_CAR N4
#define CS_R_CAR N5
#define CS_Z_CAR N6
#define CS_Y_ACU N7
#define CS_A_ACU N8
#define CS_I_ACU N9
#define CS_E_ACU N0
#define CS_U_ACU LEFT_BRACKET
#define CS_U_RING SEMICOLON

#define CS_N1 LS(N1)
#define CS_N2 LS(N2)
#define CS_N3 LS(N3)
#define CS_N4 LS(N4)
#define CS_N5 LS(N5)
#define CS_N6 LS(N6)
#define CS_N7 LS(N7)
#define CS_N8 LS(N8)
#define CS_N9 LS(N9)
#define CS_N0 LS(N0)
#define CS_PERCENT LS(CS_EQUAL)
#define CS_SLASH LS(LEFT_BRACKET)
#define CS_LPAR LS(CS_RPAR)
#define CS_DOUBLE_QUOTES LS(CS_U_RING)
#define CS_EXCL LS(CS_SECT)
#define CS_SINGLE_QUOTE LS(CS_E_ACU)
#define CS_PIPE LS(CS_BACKSLASH)
#define CS_QMARK LS(CS_COMMA)
#define CS_COLON LS(CS_DOT)
#define CS_UNDERSCORE LS(CS_MINUS)

#define CS_TILDE RA(N1)
#define CS_CARET RA(N2)
#define CS_GRAVE RA(N7)
#define CS_EURO RA(CS_E)
#define CS_LEFT_BRACKET RA(CS_F)
#define CS_RIGHT_BRACKET RA(CS_G)
#define CS_DOLLAR RA(CS_U_RING)
#define CS_HASH RA(CS_X)
#define CS_AMPERSAND RA(CS_C)
#define CS_AT RA(CS_V)
#define CS_LEFT_BRACE RA(CS_B)
#define CS_RIGHT_BRACE RA(CS_N)
#define CS_LT RA(CS_COMMA)
#define CS_GT RA(CS_DOT)
#define CS_ASTERISK RA(SLASH)

#define CS_CHAR_MACRO(name, key_binding)                                                     \
/                                                                                            \
{                                                                                            \
    macros                                                                                   \
    {                                                                                        \
        name##_lower: name##_lower {                                                         \
            compatible = "zmk,behavior-macro";                                               \
            wait-ms = <0>;                                                                   \
            tap-ms = <0>;                                                                    \
            #binding-cells = <0>;                                                            \
            bindings = <key_binding>;                                                        \
        };                                                                                   \
        name##_upper: name##_upper {                                                         \
            compatible = "zmk,behavior-macro";                                               \
            wait-ms = <20>;                                                                  \
            tap-ms = <20>;                                                                   \
            #binding-cells = <0>;                                                            \
            bindings =                                                                       \
                <&kp CAPS>,                                                                  \
                <key_binding>,                                                               \
                <&kp CAPS>                                                                   \
            ;                                                                                \
        };                                                                                   \
    };                                                                                       \
};

#define CS_KEY_PAIR(name, key)                           \
    CS_CHAR_MACRO(name, &kp key)                         \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)

#define CS_DIAC_CHAR_MACRO(name, key_binding, diacritic_binding)                             \
/                                                                                            \
{                                                                                            \
    macros                                                                                   \
    {                                                                                        \
        name##_lower: name##_lower {                                                         \
            compatible = "zmk,behavior-macro";                                               \
            wait-ms = <20>;                                                                  \
            tap-ms = <20>;                                                                   \
            #binding-cells = <0>;                                                            \
            bindings =                                                                       \
                <diacritic_binding>,                                                         \
                <key_binding>;                                                               \
        };                                                                                   \
        name##_upper: name##_upper {                                                         \
            compatible = "zmk,behavior-macro";                                               \
            wait-ms = <20>;                                                                  \
            tap-ms = <20>;                                                                   \
            #binding-cells = <0>;                                                            \
            bindings =                                                                       \
                <diacritic_binding>,                                                         \
                <&kp CAPS>,                                                                  \
                <key_binding>,                                                               \
                <&kp CAPS>;                                                                  \
        };                                                                                   \
    };                                                                                       \
};

#define CS_DIAC_KEY_PAIR(name, key, diacritic)                           \
    CS_DIAC_CHAR_MACRO(name, &kp key, &kp diacritic)                          \
    SHIFTED_MODMORPH(name, &name##_lower, &name##_upper)