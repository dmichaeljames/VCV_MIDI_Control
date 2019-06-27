/*

  DIY MIDI controller using an Arduino Leonardo and multiple CD74HC4067 multiplexers for up to 192 MIDI controls (if you use 12 multiplexers).
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

// S{0,1,2,3} on the multiplexers connected to D{8,9,10,11} on the Leonardo
CD74HC4067 mux(0,1,2,3);

// Set number of multiplexers used
const int muxNum = 1;
const int threshold = 4;

// init values for analog reads
uint8_t oldValue[muxNum][16];
uint8_t newValue = 0;

void setup() {
  pinMode(A0, INPUT);
  //pinMode(A1, INPUT);
  //pinMode(A2, INPUT);
}

void loop() {
  for (int i = 0; i < muxNum; i++) {
    for (int j = 0; j < 16; j++) {
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
