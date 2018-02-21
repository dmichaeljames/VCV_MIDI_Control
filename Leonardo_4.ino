/*******************************************************************
* 
*    This is Leonardo_4.
*    It will control VCAs 1-8
*    
\*******************************************************************
#include <MIDIUSB.h>
#include <frequencyToNote.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

// Initializing those variables
uint8_t oldAnalogValue = 0;
uint8_t newAnalogValue = 0;

void setup() {
}

void loop() {
  for (int i=0; i<9;i++) { // Checking all 8 analog inputs (0 through 7)
    int cc = 120; // VCAs start on CC 120 (0-119 used previously) and run through 127
    uint16_t analogValue = analogRead(i);
    uint8_t newAnalogValue = analogValue >> 3;
    cc += i;
      
    if( newAnalogValue != oldAnalogValue ) // if nothing's changed, skip it
    {   
      midiEventPacket_t midiCc = { 0x0B, 0xB0, cc, newAnalogValue }; // {midi type: CC, MIDI channel 1, CC#, CC value}
      MidiUSB.sendMIDI(midiCc); // send above packet
      MidiUSB.flush(); // flush it all down
      oldAnalogValue = newAnalogValue; // set equal so if nothing changes, skip the loops
    }
  }
}
