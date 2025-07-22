#!/bin/bash
set -euo pipefail

podman run -it --rm  \
    --security-opt label=disable \
    --workdir /workspaces/zmk/app \
    -v ../zmk:/workspaces/zmk \
    -v ./build:/workspaces/build \
    -v .:/workspaces/zmk-config \
    -p 3000:3000 \
    zmk \
    sh -c "west build -p -b nice_nano_v2 -d /workspaces/build/klor_left -- -DSHIELD=klor_left -DZMK_CONFIG=/workspaces/zmk-config/config && west build -p -b nice_nano_v2 -d /workspaces/build/klor_right -- -DSHIELD=klor_right -DZMK_CONFIG=/workspaces/zmk-config/config && find /workspaces -type f -name 'zmk.uf2' && cp /workspaces/build/klor_left/zephyr/zmk.uf2 /workspaces/build/klor_left.uf2 && cp /workspaces/build/klor_right/zephyr/zmk.uf2 /workspaces/build/klor_right.uf2 && rm -rf /workspaces/build/klor_right && rm -rf /workspaces/build/klor_left"
