/*****************************************************************************
* 
*    This is Leonardo_2.
*    It will control VCOs (2,4,6,8), VCFs (2,4,6,8) and ADRs (VCO/VCF 2,4,6,8)
*    
\****************************************************************************/
#include <MIDIUSB.h>
#include <frequencyToNote.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

// Initializing those variables
int bank = 0;

void setup() {
  Serial.begin(9600);
  while(!Serial) {
    ;
  }
}

void midi(int cc);

void loop() {
  bank = Serial.read(); // Getting the bank info from Leonardo_1 to sync VCO (etc) values
  int cc = (bank + 4); // This sets CC as a multiplier (each bank has 12 values for CC, this gives us all 48 (0-47 are in Leo_1, this sets the next 48 to 48-95)
  midi(cc);
}
  
void midi(int cc) {
  uint8_t oldAnalogValue = 0;
  uint8_t newAnalogValue = 0;
  cc *= 12;
  
  for (int i=0; i<12;i++){                    // Checking all 12 analog inputs (0 through 11)
    uint16_t analogValue = analogRead(i);
    uint8_t newAnalogValue = analogValue >> 3;
    cc = (i + 1); // Our CC multiplier * 12 (for the 12 analog values) bank0: 48-59, bank1: 60-71, bank2: 72-83, bank3: 84-95
  
    if( newAnalogValue != oldAnalogValue ) // if nothing's changed, skip it
    {   
      midiEventPacket_t midiCc = { 0x0B, 0xB0, cc, newAnalogValue }; // {midi type: CC, MIDI channel 1, CC#, CC value}
      MidiUSB.sendMIDI(midiCc); // send above packet
      MidiUSB.flush(); // flush it all down
      oldAnalogValue = newAnalogValue; // set equal so if nothing changes, skip the loops
    }
  }
}
