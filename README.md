# ReimageVideo
![proto_image](https://github.com/LogoiLab/ReimageVideo/blob/204df1f184ed52cb22cb57da85f1f4edf1acc1d6/res/proto_image.jpg)

Open source firmware for the ImageVideo RDU 1502 "Tally System".

Compile using [SDCC](http://sdcc.sourceforge.net/)

You will need an intel 8051 compatible MCU in the PLCC44 package style. This project uses the [Atmel at89s8253](http://ww1.microchip.com/downloads/en/DeviceDoc/doc3286.pdf)

## Goals

- [x] Display text
- [x] Display bars
- [x] Color
- [x] Segment inversion
- [x] Per-column inversion
- [x] Serial communication
- [x] Serial command processing

## Command reference

Communication with the device is done over RS232 serial at 14400 baud.

Due to the design of the device, the 8051 chip can only receive data and cannot transmit. Instead, error messages are printed directly to the screen.

Use `p` for percentage fill, `t` for text, and `c` for clear.

color values are `r` for red, `g` for green, and `y` for yellow.

The `p` command takes a percentage as a value from 0.0 to 1.0 (leading zero and decimal point is required).

Values are persistent until changed. Percentage fills can be overlaid on text. When `c` is called both percentage and text are cleared.

Command structure is:
`<command> <color> <value>`

Some examples:

- `t r I'm Open Source!` Displays the text "I'm Open Source!" in the color red.
- `c` Clears the screen.
- `p g 0.25` Percentage fills to 25% in the color green.
- `t g Overlay` Displays the text "Overlay" in green (overlaying the percentage in previous command).
- `p y 0.50` Changes display color to yellow and changes the percentage fill to 50%, keeping the previous text value (assuming one exists).
