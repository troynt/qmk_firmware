#!/usr/bin/env bash

set -ex

make system76/launch_3:troy

FIRMWARE="$(realpath .build/system76_launch_3_default.elf)"
./openocd.sh -c "program ${FIRMWARE} verify reset exit"
