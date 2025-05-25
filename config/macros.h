#define SHIFTED_MODMORPH(name, regular_binding, shifted_binding)                                     \
/                                                                                            \
{                                                                                            \
    behaviors                                                                                \
    {                                                                                        \
        name: name {                                                                         \
            compatible = "zmk,behavior-mod-morph";                                           \
            #binding-cells = <0>;                                                            \
            bindings = <regular_binding>, <shifted_binding>;                                 \
            mods = <(MOD_LSFT | MOD_RSFT)>;                                                  \
        };                                                                                   \
    };                                                                                       \
};


#define HRM(name, flavour, tap_behaviour, hold_behaviour, hold_trigger_keys) \
      name: name { \
            compatible = "zmk,behavior-hold-tap"; \
            #binding-cells = <2>; \
            flavor = #flavour; \
            require-prior-idle-ms = <120>; \
            tapping-term-ms = <190>; \
            bindings = <&tap_behaviour>, <&hold_behaviour>; \
            hold-trigger-key-positions = <hold_trigger_keys>; \
            hold-trigger-on-release; \
        };