/*******************************************************************
 
    This is Leonardo_3.
    It will control LFOs 1-8.
    
\*******************************************************************/
#include <MIDIUSB.h>
#include <frequencyToNote.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

// Initializing those variables
int bank = -1; 

void setup() {
  // toggle for bank selection
  pinMode(2,INPUT);
}

void midi(int cc);

void loop() {
  int bank = digitalRead(2); // 0 or 1
  if (bank == 0) {
    midi(96); 
  }
  else {
    midi(108);
  }
}

void midi(int cc) {
  uint8_t oldAnalogValue = 0;
  uint8_t newAnalogValue = 0;
  
  for (int i=0; i<12;i++){                    // Checking all 12 analog inputs (0 through 11)
    uint16_t analogValue = analogRead(i);
    uint8_t newAnalogValue = analogValue >> 3;
    cc += i; // Our CC multiplier * 12 (for the 12 analog values) bank0: 0-11, bank1: 12-23, bank2: 24-35, bank3: 36-47
  
    if( newAnalogValue != oldAnalogValue ) // if nothing's changed, skip it
    {   
      midiEventPacket_t midiCc = { 0x0B, 0xB0, cc, newAnalogValue }; // {midi type: CC, MIDI channel 1, CC#, CC value}
      MidiUSB.sendMIDI(midiCc); // send above packet
      MidiUSB.flush(); // flush it all down
      oldAnalogValue = newAnalogValue; // set equal so if nothing changes, skip the loops
    }
  }
}
