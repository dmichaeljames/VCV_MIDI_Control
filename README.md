# VCV MIDI Control (VMC)

This project is for creating an Arduino-based MIDI controller for use with VCVrack.

VMC makes use of the following hardware:

* Arduino Pro Micro (or any ATmega32u4-based controller)
* CD74HC4067 multiplexers
* 10K linear potentiometers (16 / multiplexer)

Additionally, this project makes use of Waspinator's CD74HC4067 library (https://github.com/waspinator/CD74HC4067) to interface with the multiplexers. You could do it all by hand, but why reinvent the wheel?

Go make some music!
