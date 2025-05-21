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
