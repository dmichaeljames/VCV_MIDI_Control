# VCV MIDI Control (VMC)

This project is for creating an Arduino-based MIDI controller for use with VCVrack.

VMC makes use of the following hardware:

* Arduino Pro Micro (or any ATmega32u4-based controller)
* CD74HC4067 multiplexers
* 10K linear potentiometers (16 / multiplexer)

Additionally, this project makes use of Waspinator's CD74HC4067 library (https://github.com/waspinator/CD74HC4067) to interface with the multiplexers. You could do it all by hand, but why reinvent the wheel?

### PCB Layouts

For the hardware side of things, you can do whatever you want, but if you're interested, I've included some printable PCB layouts (and the Fritzing file if you want to edit things). These are for printing, transferring and etching your own boards. I'm sure they can be sent off to have the boards made professionally, but I make ZERO guarantees.
