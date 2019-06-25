/*******************************************************************
* 
*    This is Leonardo_1.
*    It will control VCOs, VCFs (1,3,5,7) and ADRs (VCO/VCF 1,3,5,7)
*    
********************************************************************/
#include <MIDIUSB.h>
#include <frequencyToNote.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

// Initializing those variables
int led[] = {5,7,11,13}; // digital pins for LEDs
int bank = 0;
int oldBank = -1; // seting oldBank to a value that is impossible to hit so as to initialize the controller
int cc = 0; // more initialization

void setup() {
  Serial.begin(9600);
  while(!Serial) {
    ;
  }
  
  // toggles for bank selection
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  
  // outputs for LEDs
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
}

void ledValue(int bank);
void midi(int cc);

void loop() {
  int pin2 = digitalRead(2);  // 0 or 1
  int pin3 = digitalRead(3) << 1;  // 0 or 2
  
  bank = (pin2 + pin3); // yup, binary! 0,1,2,3
  cc = bank; // This sets CC as a multiplier (each bank has 12 values for CC, this gives us all 48)
  midi(cc);
  
  if (oldBank != bank) { // will not be equal on init
    ledValue(bank); // setting the correct LEDs for the active bank
    oldBank = bank; // Set these equal. If no changes, no need to run through all the loops.
  }
}

void ledValue(int bank) {
  for (int i=0; i<5; i++) {
    if (bank == i) {
      digitalWrite(led[i], HIGH); // Lighting the LED that corresponds with the active bank
    }
    else {
      digitalWrite(led[i], LOW); // Turning off LEDs that do not correspond to active bank
    }
  }
}

void midi(int cc) {
  uint8_t oldAnalogValue = 0;
  uint8_t newAnalogValue = 0;
  cc *= 12;
  
  for (int i=0; i<12; i++) {                    // Checking all 12 analog inputs (0 through 11)
    uint16_t analogValue = analogRead(i);
    uint8_t newAnalogValue = analogValue >> 3;
    cc += (i + 1); // Our CC multiplier * 12 (for the 12 analog values) bank0: 0-11, bank1: 12-23, bank2: 24-35, bank3: 36-47
  
    if( newAnalogValue != oldAnalogValue ) // if nothing's changed, skip it
    {   
      midiEventPacket_t midiCc = { 0x0B, 0xB0, cc, newAnalogValue }; // {midi type: CC, MIDI channel 1, CC#, CC value}
      MidiUSB.sendMIDI(midiCc); // send above packet
      MidiUSB.flush(); // flush it all down
      oldAnalogValue = newAnalogValue; // set equal so if nothing changes, skip the loops
    }
  }
}