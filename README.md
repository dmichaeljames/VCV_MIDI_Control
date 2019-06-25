# VCV_MIDI_Control (VMC)

This project is for creating an Arduino-based MIDI controller for use with VCVrack.

VMC makes use of the following hardware:

* Arduino Leonardo R3
* Up to 12 CD74HC4067 multiplexers
* Up to 192 linear potentiometers (16 / multiplexer)

I chose the Leonardo R3 as they can be used natively as USB MIDI devices; that being said, any Arduino with the ATmega32u4 chipset can be used.

Additionally, this project makes use of Waspinator's CD74HC4067 library (https://github.com/waspinator/CD74HC4067) to interface with the multiplexers. You could do it all by hand, but why reinvent the wheel?

Go make some music!
