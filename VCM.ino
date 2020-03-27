/*

  DIY MIDI controller using an Arduino Leonardo and multiple CD74HC4067 multiplexers for up to 192 MIDI controls (if you use 12 multiplexers).
  Mike James
  06/25/2019 (V2.0)
  06/26/2019 (v2.0.1)
  06/27/2019 (v2.0.2)
  03/27/2020 (2.1)

*/

// MIDIUSB - Version: 1.0.4
#include <MIDIUSB.h>
#include <MIDIUSB_Defs.h>
#include <frequencyToNote.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>
#include <CD74HC4067.h>

CD74HC4067 mux(0,1,2,3); // Outputs to S0-S3 on the multiplexers

const int analogInputs = 1;
const int threshold = 0;

// init values for analog reads
uint8_t oldValue[analogInputs][16]; 
uint8_t newValue = 0;

void setup() {}

void loop() {
  for (int i = 0; i < analogInputs; i++) {
    for (int pin = 0; pin < 15; pin++) {
      mux.channel(pin);
      analogRead(i);
      newValue = analogRead(i) >> 3; 
      delay(10);
  
      // setting the CC value based on the analog input and MUX channel
      int cc = (i * 16) + pin;  
      
      // If the new value from the potentiometers is larger than the threshold, send the new MIDI value
      if (abs(newValue - oldValue[i][pin]) > threshold) { 
        midiEventPacket_t midiCc = {0x0B, 0xB0, cc, newValue};
        MidiUSB.sendMIDI(midiCc);
        MidiUSB.flush();
        oldValue[i][pin] = newValue;
      }
    }  
  }  
}
