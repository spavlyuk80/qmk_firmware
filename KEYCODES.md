# QMK Keycodes Reference

## Basic Keys

### Letters
`KC_A` through `KC_Z`

### Numbers
`KC_1` through `KC_0`

### Function Keys
`KC_F1` through `KC_F24`

### Modifiers
| Keycode | Description |
|---------|-------------|
| `KC_LCTL` | Left Control |
| `KC_LSFT` | Left Shift |
| `KC_LALT` | Left Alt |
| `KC_LGUI` | Left GUI (Cmd/Win) |
| `KC_RCTL` | Right Control |
| `KC_RSFT` | Right Shift |
| `KC_RALT` | Right Alt (AltGr) |
| `KC_RGUI` | Right GUI |

### Navigation
| Keycode | Description |
|---------|-------------|
| `KC_ENT` | Enter |
| `KC_ESC` | Escape |
| `KC_BSPC` | Backspace |
| `KC_TAB` | Tab |
| `KC_SPC` | Space |
| `KC_INS` | Insert |
| `KC_DEL` | Delete |
| `KC_HOME` | Home |
| `KC_END` | End |
| `KC_PGUP` | Page Up |
| `KC_PGDN` | Page Down |
| `KC_UP` | Up Arrow |
| `KC_DOWN` | Down Arrow |
| `KC_LEFT` | Left Arrow |
| `KC_RGHT` | Right Arrow |

### Symbols
| Keycode | Description |
|---------|-------------|
| `KC_MINS` | `-` and `_` |
| `KC_EQL` | `=` and `+` |
| `KC_LBRC` | `[` and `{` |
| `KC_RBRC` | `]` and `}` |
| `KC_BSLS` | `\` and `|` |
| `KC_SCLN` | `;` and `:` |
| `KC_QUOT` | `'` and `"` |
| `KC_GRV` | `` ` `` and `~` |
| `KC_COMM` | `,` and `<` |
| `KC_DOT` | `.` and `>` |
| `KC_SLSH` | `/` and `?` |

### Special Keys
| Keycode | Description |
|---------|-------------|
| `KC_CAPS` | Caps Lock |
| `KC_PSCR` | Print Screen |
| `KC_SCRL` | Scroll Lock |
| `KC_PAUS` | Pause |
| `KC_APP` | Application/Menu key |
| `_______` | Transparent (use lower layer) |
| `XXXXXXX` | No operation |

---

## Layer Switching

### Hold to Activate
| Keycode | Description |
|---------|-------------|
| `MO(layer)` | Momentary - hold to activate layer |
| `LT(layer, kc)` | Layer-Tap - hold for layer, tap for keycode |

### Tap to Activate
| Keycode | Description |
|---------|-------------|
| `TG(layer)` | Toggle - tap to toggle layer on/off |
| `TO(layer)` | Turn On - switch to layer exclusively |
| `OSL(layer)` | One-Shot Layer - next keypress on layer, then return |
| `DF(layer)` | Default - change base layer permanently |

### Tri-Layer
| Keycode | Description |
|---------|-------------|
| `TT(layer)` | Tap-Toggle - tap to toggle, hold for momentary |

---

## Modifier Combinations

### Mod + Key (on press)
| Format | Example | Description |
|--------|---------|-------------|
| `S(kc)` | `S(KC_A)` | Shift + A (types "A") |
| `C(kc)` | `C(KC_C)` | Ctrl + C |
| `A(kc)` | `A(KC_TAB)` | Alt + Tab |
| `G(kc)` | `G(KC_L)` | GUI + L |
| `LCTL(kc)` | `LCTL(KC_Z)` | Left Ctrl + key |
| `LSFT(kc)` | `LSFT(KC_1)` | Shift + 1 (types "!") |
| `LALT(kc)` | `LALT(KC_F4)` | Alt + F4 |
| `LGUI(kc)` | `LGUI(KC_SPC)` | Cmd + Space |

### Mod-Tap (hold for mod, tap for key)
| Keycode | Description |
|---------|-------------|
| `MT(mod, kc)` | Generic mod-tap |
| `LCTL_T(kc)` | Hold: Left Ctrl, Tap: kc |
| `LSFT_T(kc)` | Hold: Left Shift, Tap: kc |
| `LALT_T(kc)` | Hold: Left Alt, Tap: kc |
| `LGUI_T(kc)` | Hold: Left GUI, Tap: kc |
| `RCTL_T(kc)` | Hold: Right Ctrl, Tap: kc |
| `RSFT_T(kc)` | Hold: Right Shift, Tap: kc |
| `RALT_T(kc)` | Hold: Right Alt, Tap: kc |
| `RGUI_T(kc)` | Hold: Right GUI, Tap: kc |

---

## One-Shot (Sticky) Keys

### One-Shot Modifiers
| Keycode | Description |
|---------|-------------|
| `OSM(MOD_LSFT)` | Sticky Left Shift |
| `OSM(MOD_LCTL)` | Sticky Left Control |
| `OSM(MOD_LALT)` | Sticky Left Alt |
| `OSM(MOD_LGUI)` | Sticky Left GUI |
| `OSM(MOD_RSFT)` | Sticky Right Shift |
| `OSM(MOD_RCTL)` | Sticky Right Control |
| `OSM(MOD_RALT)` | Sticky Right Alt |
| `OSM(MOD_RGUI)` | Sticky Right GUI |

### One-Shot Layers
| Keycode | Description |
|---------|-------------|
| `OSL(layer)` | Next keypress on layer, then return |

---

## Mouse Keys

| Keycode | Description |
|---------|-------------|
| `MS_BTN1` | Mouse Button 1 (Left click) |
| `MS_BTN2` | Mouse Button 2 (Right click) |
| `MS_BTN3` | Mouse Button 3 (Middle click) |
| `MS_BTN4` | Mouse Button 4 |
| `MS_BTN5` | Mouse Button 5 |
| `MS_UP` | Mouse Up |
| `MS_DOWN` | Mouse Down |
| `MS_LEFT` | Mouse Left |
| `MS_RGHT` | Mouse Right |
| `MS_WHLU` | Scroll Wheel Up |
| `MS_WHLD` | Scroll Wheel Down |
| `MS_WHLL` | Scroll Wheel Left |
| `MS_WHLR` | Scroll Wheel Right |
| `MS_ACL0` | Mouse Acceleration 0 (slow) |
| `MS_ACL1` | Mouse Acceleration 1 (medium) |
| `MS_ACL2` | Mouse Acceleration 2 (fast) |

---

## Media Keys

| Keycode | Description |
|---------|-------------|
| `KC_MUTE` | Mute |
| `KC_VOLU` | Volume Up |
| `KC_VOLD` | Volume Down |
| `KC_MNXT` | Next Track |
| `KC_MPRV` | Previous Track |
| `KC_MSTP` | Stop |
| `KC_MPLY` | Play/Pause |
| `KC_MSEL` | Media Select |
| `KC_EJCT` | Eject |

---

## System Keys

| Keycode | Description |
|---------|-------------|
| `KC_PWR` | System Power |
| `KC_SLEP` | System Sleep |
| `KC_WAKE` | System Wake |

---

## QMK Special

| Keycode | Description |
|---------|-------------|
| `QK_BOOT` | Enter bootloader (flash mode) |
| `QK_RBT` | Reboot keyboard |
| `DB_TOGG` | Toggle debug mode |
| `EE_CLR` | Clear EEPROM |

---

## Keyball-Specific Keycodes

| Keycode | Description |
|---------|-------------|
| `CPI_I100` | Increase trackball CPI by 100 |
| `CPI_D100` | Decrease trackball CPI by 100 |
| `CPI_I1K` | Increase trackball CPI by 1000 |
| `CPI_D1K` | Decrease trackball CPI by 1000 |
| `SCRL_DVI` | Increase scroll divider |
| `SCRL_DVD` | Decrease scroll divider |
| `SCRL_TO` | Toggle scroll mode |
| `SCRL_MO` | Momentary scroll mode |
| `KBC_RST` | Reset Keyball config to defaults |
| `KBC_SAVE` | Save current CPI/scroll settings |
| `AML_TO` | Toggle auto mouse layer |
| `AML_I50` | Increase auto mouse timeout by 50ms |
| `AML_D50` | Decrease auto mouse timeout by 50ms |
| `SSNP_VRT` | Scroll snap: vertical only |
| `SSNP_HOR` | Scroll snap: horizontal only |
| `SSNP_FRE` | Scroll snap: free movement |

---

## RGB Lighting (if enabled)

| Keycode | Description |
|---------|-------------|
| `RGB_TOG` | Toggle RGB on/off |
| `RGB_MOD` | Next RGB mode |
| `RGB_RMOD` | Previous RGB mode |
| `RGB_HUI` | Increase hue |
| `RGB_HUD` | Decrease hue |
| `RGB_SAI` | Increase saturation |
| `RGB_SAD` | Decrease saturation |
| `RGB_VAI` | Increase brightness |
| `RGB_VAD` | Decrease brightness |

---

## Examples

### Layer-Tap: Space on tap, Layer 1 on hold
```c
LT(1, KC_SPC)
```

### Mod-Tap: Escape on tap, Control on hold
```c
LCTL_T(KC_ESC)
```

### Toggle Layer 2
```c
TG(2)
```

### One-shot Shift (sticky shift for next key)
```c
OSM(MOD_LSFT)
```

### Ctrl+Shift+Esc (Task Manager)
```c
LCTL(LSFT(KC_ESC))
```

---

## Full Documentation

https://docs.qmk.fm/keycodes
