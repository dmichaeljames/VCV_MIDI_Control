# VCV_MIDI_Control (VMC)

This project is for creating an Arduino-based MIDI controller for use with VCVrack.

VMC makes use of the following hardware:

* Arduino Leonardo R3 (or any ATmega32u4-based controller)
* Up to 12 CD74HC4067 multiplexers
* Up to 192 linear potentiometers (16 / multiplexer)

Additionally, this project makes use of Waspinator's CD74HC4067 library (https://github.com/waspinator/CD74HC4067) to interface with the multiplexers. You could do it all by hand, but why reinvent the wheel?

Go make some music!
