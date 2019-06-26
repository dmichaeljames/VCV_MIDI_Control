/*

  DIY MIDI controller using an Arduino Leonardo and multiple CD74HC4067 multiplexers for up to 192 MIDI controls (if you use 12 multiplexers).
  Mike James
  06/25/2019

*/

// MIDIUSB - Version: 1.0.4
#include <MIDIUSB.h>
#include <MIDIUSB_Defs.h>
#include <frequencyToNote.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

// CD74HC4067 - Version: Latest
#include <CD74HC4067.h>

// S{0,1,2,3} on the multiplexers connected to D{8,9,10,11} on the Leonardo
CD74HC4067 mux(8, 9, 10, 11);

// Set number of multiplexers used
const int muxNum = 3;

// init values for analog reads
uint8_t oldValue = 0;
uint8_t newValue = 0;

// Set the MIDI channel you wish to use (0-15)
const int channel = 0;

void setup() {
  // Set the analog pins to read input
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  // Start taking readings from the multiplexers
  for (int i; i < muxNum; i++) {
    for (int j; j < 16; j++) { // takes input from each of the 16 channels on the multiplexers
      mux.channel(j);
      newValue = analogRead(i) >> 3; // bitshifting the 1024 values down to 128 for MIDI purposes
      
      int cc = (i * 16) + (j + 1); // setting the CC value based on MUX and channel 
      
      if (newValue != oldValue) {
        midiEventPacket_t midiCc = {0x0B, 0xB0 | channel, cc, newValue};
        MidiUSB.sendMIDI(midiCc);
        MidiUSB.flush();
        oldValue = newValue;
      }
      
      delay(50);
    }
  } 
}
