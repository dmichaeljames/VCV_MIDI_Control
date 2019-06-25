# VCV_MIDI_Control

Arduino code for creating a custom MIDI controller for use with VCVrack (or anything else, really).

This is specifically aimed at the Arduino Leonardo R3 as it can be used as a USB midi controller. There are other Arduinos that have the ATmega32u4 chipset, but the Leonardo gives you 12 analog inputs, allowing for up to 192 MIDI controls (and they're cheap online).

This project makes use of CD74HC4067 multiplexer/demultiplexers along with Waspinator's CD74HC4067 library (https://github.com/waspinator/CD74HC4067).

Have fun.
