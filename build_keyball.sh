#!/bin/bash
# Build script for Keyball44 firmware

set -e

KEYBOARD="keyball/keyball44"
KEYMAP="${1:-default}"

echo "Building Keyball44 firmware with keymap: $KEYMAP"

qmk compile -kb "$KEYBOARD" -km "$KEYMAP"

FIRMWARE="keyball_keyball44_${KEYMAP}.uf2"

if [ -f "$FIRMWARE" ]; then
    echo ""
    echo "Build successful: $FIRMWARE"
    echo ""
    echo "To flash:"
    echo "  1. Put keyboard half in bootloader mode (double-tap reset)"
    echo "  2. Run: cp $FIRMWARE /Volumes/RPI-RP2/"
    echo "  3. Repeat for other half"
else
    echo "Build failed!"
    exit 1
fi
