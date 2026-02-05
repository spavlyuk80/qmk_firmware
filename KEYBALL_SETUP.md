# Keyball44 Firmware Setup

This repository contains QMK firmware configured for Keyball44 with Sea Picro (RP2040) controllers.

## Configuration

- **Keyboard:** Keyball44
- **Controller:** Sea Picro (RP2040)
- **Trackball:** Right side
- **USB:** Left side (master)

## Building Firmware

```bash
./build_keyball.sh
```

Or with a custom keymap:

```bash
./build_keyball.sh my_keymap
```

Output: `keyball_keyball44_default.uf2`

## Flashing

1. Disconnect TRRS cable between halves
2. Put left half in bootloader mode (double-tap reset button)
3. Copy firmware: `cp keyball_keyball44_default.uf2 /Volumes/RPI-RP2/`
4. Repeat for right half
5. Connect TRRS cable
6. Plug USB into left half

## Updating from Upstream QMK

### First-time setup (already done)

```bash
git remote add upstream https://github.com/qmk/qmk_firmware.git
```

### To sync with latest QMK

```bash
# Fetch latest from upstream
git fetch upstream

# Make sure you're on your branch
git checkout master  # or your working branch

# Merge upstream changes
git merge upstream/master

# Resolve any conflicts if needed, then:
git add .
git commit -m "Merge upstream QMK updates"

# Push to your fork
git push origin master
```

### If merge conflicts occur

The Keyball files in `keyboards/keyball/` are custom and may conflict with upstream changes. Common resolutions:

1. For files in `keyboards/keyball/` - keep your version (ours)
2. For QMK core files - typically accept upstream (theirs)

```bash
# Keep your version of a file
git checkout --ours keyboards/keyball/some_file.c

# Accept upstream version
git checkout --theirs quantum/some_file.c

# After resolving
git add .
git commit -m "Resolved merge conflicts"
```

## Pushing Your Changes

```bash
# Stage your changes
git add .

# Commit with a message
git commit -m "Description of changes"

# Push to your fork
git push origin master
```

## Creating a Custom Keymap

1. Copy the default keymap:
   ```bash
   cp -r keyboards/keyball/keyball44/keymaps/default keyboards/keyball/keyball44/keymaps/my_keymap
   ```

2. Edit `keyboards/keyball/keyball44/keymaps/my_keymap/keymap.c`

3. Build with your keymap:
   ```bash
   ./build_keyball.sh my_keymap
   ```

## Keymap Layers

- **Layer 0:** Default QWERTY
- **Layer 1:** Function keys, navigation, mouse buttons
- **Layer 2:** Numbers and symbols
- **Layer 3:** Trackball settings, CPI adjustment, QK_BOOT (bootloader)

### Entering Bootloader from Keymap

Hold Layer 3 key + press bottom-left key (or bottom-right on right half)

## Troubleshooting

### Trackball not working
- Ensure USB is connected to left half
- Ensure TRRS cable is properly connected
- Try re-flashing both halves

### Can't enter bootloader
- Double-tap reset button quickly (within 500ms)
- Or hold BOOT button while plugging in USB

### Keys not working on one half
- Check TRRS connection
- Re-flash both halves with TRRS disconnected
