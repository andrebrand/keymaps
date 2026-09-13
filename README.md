# How to edit the key mapping

## Find the files

The qmk_firmware fold is saved in the user directory. Inside you'll find `keyboard > crkbd > keymaps`.

## Configre the files

Inside my custom keymap `andiibrandii` the `keymap.c` file I have configured 8 Layers.
Layer 0 - 3 are configured to be used for windows, 4 - 7 are more or less the same as 0 - 3 but for mac os.

- Layer 0 - basic latin alphabet qwerty-ish + ß and home row mods
- Layer 1 - Navigation (right) and numpad (left)
- Layer 2 - Special characters
- Layer 3 - Switch layer to manually switch between Operating Systems. This is not really needed anymore because when the keyboard is first connected the OS is detected and automaticly switches layer to mac (or not). F1-F12 is also on this layer
- Layer 4 - same as Layer 0 but for mac
- Layer 5 - same as Layer 1 but for mac
- Layer 6 - same as Layer 2 but for mac
- Layer 7 - same as Layer 3 but for mac

## Compile the firmware

Start the `QMK MSYS` Command Tool and run `qmk compile`, maybe add the parameter for keybaord and the custom keymap when it's not set as default anymore.

The generated firmware file is located at the root of the qmk_firmware folder.

## Flash the firmware

Start the `QMK Toolbox` and selected the firmware file, connect the keyboard, and flash.
