/*

  DIY MIDI controller using an ATmega32U4-based arduino and multiple CD74HC4067 multiplexers for up to 192 MIDI controls (if you use 12 multiplexers).
  
  Mike James
  
  06/25/2019 (V2.0)
  06/26/2019 (v2.0.1)
  06/27/2019 (v2.0.2)

*/

// MIDIUSB - Version: 1.0.4
#include <MIDIUSB.h>
#include <MIDIUSB_Defs.h>
#include <frequencyToNote.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

// CD74HC4067 - Version: Latest
#include <CD74HC4067.h>

// S{0,1,2,3} on the multiplexers connected to D{10,16,14,15} on the Pro Micro (you can change these to whatever pins you wish)
CD74HC4067 mux(10,16,14,15);

// Set number of multiplexers used
const int muxNum = 1;

// Set the number of analog inputs used on the multiplexer (really just here for testing purposes; will default to 16 when done)
const int analogInputs = 5;

// Setting a threshold for analog input to prevent minor fluctuations from changing values
const int threshold = 8;

// init values for analog reads
uint8_t oldValue[muxNum][analogInputs];
uint8_t newValue = 0;

void setup() {
  // Set the pins to read input 
  pinMode(A0, INPUT);
  //pinMode(A1, INPUT);
  //pinMode(A2, INPUT);
}

void loop() {
  for (int i = 0; i < muxNum; i++) {
    for (int j = 0; j < analogInputs; j++) {
      valueChange(i,j);
    }
  } 
}

void valueChange(int x, int y) {
  mux.channel(y);
  
  newValue = analogRead(x) >> 3; // bitshifting the 1024 values down to 128 for MIDI purposes
  
  int cc = (x * 16) + y; // setting the CC value based on MUX and channel 
  
  if (abs(newValue - oldValue[x][y]) > threshold) {
    sendMidi(cc,newValue);
    oldValue[x][y] = newValue;
  }
  
  delay(10);  
}

void sendMidi(int x, int y) {
  midiEventPacket_t midiCc = {0x0B, 0xB0, x, y};
  MidiUSB.sendMIDI(midiCc);
  MidiUSB.flush();
}
