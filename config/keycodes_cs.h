// keycodes_cs.h
// Czech QWERTZ aliases for an ANSI US‑physical keyboard in ZMK
#pragma once

#include <dt-bindings/zmk/keys.h>

/* Row 1 (digits & symbols) */
#define CS_SCLN GRV   // ;  (on US) → ` (grave)
#define CS_PLUS N1    // +  → 1
#define CS_ECAR N2    // ě  → 2
#define CS_SCAR N3    // š  → 3
#define CS_CCAR N4    // č  → 4
#define CS_RCAR N5    // ř  → 5
#define CS_ZCAR N6    // ž  → 6
#define CS_YACU N7    // ý  → 7
#define CS_AACU N8    // á  → 8
#define CS_IACU N9    // í  → 9
#define CS_EACU N0    // é  → 0
#define CS_EQL MINS   // =  → -
#define CS_ACUT EQUAL // ´  (dead)

/* Row 2 (QWERTY → QWERTZ) */
#define CS_Q Q
#define CS_W W
#define CS_E E
#define CS_R R
#define CS_T T
#define CS_Z Y // Czech Z is at US Y
#define CS_U U
#define CS_I I
#define CS_O O
#define CS_P P
#define CS_UACU LBKT // ú  → [
#define CS_RPAR RBKT // )  → ]

/* Row 3 */
#define CS_A A
#define CS_S S
#define CS_D D
#define CS_F F
#define CS_G G
#define CS_H H
#define CS_J J
#define CS_K K
#define CS_L L
#define CS_URNG SCLN // ů  → ;
#define CS_SECT QUOT // §  → '
#define CS_DIAE NUHS // ¨  → non‑US hash
#define CS_BSLS NUBS // \  → non‑US backslash

/* Row 4 */
#define CS_Y Z // Czech Y is at US Z
#define CS_X X
#define CS_C C
#define CS_V V
#define CS_B B
#define CS_N N
#define CS_M M
#define CS_COMMA COMMA // ,
#define CS_DOT DOT     // .
#define CS_MINS SLSH   // -  → /

/* Shifted symbols & dead‑keys */
#define CS_RNGA S(CS_SCLN)   // ° (dead)
#define CS_1 S(CS_PLUS)      // !
#define CS_2 S(CS_ECAR)      // "
#define CS_3 S(CS_SCAR)      // §
#define CS_4 S(CS_CCAR)      // $
#define CS_5 S(CS_RCAR)      // %
#define CS_6 S(CS_ZCAR)      // &
#define CS_7 S(CS_YACU)      // /
#define CS_8 S(CS_AACU)      // (
#define CS_9 S(CS_IACU)      // )
#define CS_0 S(CS_EACU)      // =
#define CS_PERC S(CS_EQL)    // %
#define CS_CARN S(CS_ACUT)   // ˇ (dead)
#define CS_SLSH S(CS_UACU)   // /
#define CS_LPAR S(CS_RPAR)   // (
#define CS_DQUO S(CS_URNG)   // "
#define CS_EXLM S(CS_SECT)   // !
#define CS_QUOT S(CS_DIAE)   // '
#define CS_PIPE S(CS_BSLS)   // |
#define CS_QMARK S(CS_COMMA) // ?
#define CS_COLN S(CS_DOT)    // :
#define CS_UNDS S(CS_MINS)   // _

/* AltGr (Right‑Alt) layer */
#define CS_TILD RA(CS_PLUS)  // ~
#define CS_CIRC RA(CS_SCAR)  // ^ (dead)
#define CS_BREV RA(CS_CCAR)  // ˘ (dead)
#define CS_OGON RA(CS_ZCAR)  // ˛ (dead)
#define CS_GRV RA(CS_YACU)   // ` (dead)
#define CS_DOTA RA(CS_AACU)  // ˙ (dead)
#define CS_DACU RA(CS_EACU)  // ˝ (dead)
#define CS_CEDL RA(CS_ACUT)  // ¸ (dead)
#define CS_EURO RA(CS_E)     // €
#define CS_DIV RA(CS_UACU)   // ÷
#define CS_MUL RA(CS_RPAR)   // ×
#define CS_LDST RA(CS_S)     // đ
#define CS_CDST RA(CS_D)     // Đ
#define CS_LBRC RA(CS_F)     // [
#define CS_RBRC RA(CS_G)     // ]
#define CS_LLST RA(CS_K)     // ł
#define CS_CLST RA(CS_L)     // Ł
#define CS_DLR RA(CS_URNG)   // $
#define CS_SS RA(CS_SECT)    // ß
#define CS_CURR RA(CS_DIAE)  // ¤
#define CS_HASH RA(CS_X)     // #
#define CS_AMPR RA(CS_C)     // &
#define CS_AT RA(CS_V)       // @
#define CS_LCBR RA(CS_B)     // {
#define CS_RCBR RA(CS_N)     // }
#define CS_LABK RA(CS_COMMA) // <
#define CS_RABK RA(CS_DOT)   // >
#define CS_ASTR RA(CS_MINS)  // *