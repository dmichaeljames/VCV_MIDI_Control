/* Arduino Leonardo-based MIDI controller sketch made for controlling VCVrack, but can be used for anything MIDI-based
*  
*  02/15/2018
*
 */
#include <MIDIUSB.h>

uint8_t oldAnalogValue = 0;
uint8_t newAnalogValue = 0;
uint8_t oldAnalogValue1 = 0;
uint8_t newAnalogValue1 = 0;
uint8_t oldAnalogValue2 = 0;
uint8_t newAnalogValue2 = 0;
uint8_t oldAnalogValue3 = 0;
uint8_t newAnalogValue3 = 0;
uint8_t oldAnalogValue4 = 0;
uint8_t newAnalogValue4 = 0;
uint8_t oldAnalogValue5 = 0;
uint8_t newAnalogValue5 = 0;
uint8_t oldAnalogValue6 = 0;
uint8_t newAnalogValue6 = 0;
uint8_t oldAnalogValue7 = 0;
uint8_t newAnalogValue7 = 0;
uint8_t oldAnalogValue8 = 0;
uint8_t newAnalogValue8 = 0;
uint8_t oldAnalogValue9 = 0;
uint8_t newAnalogValue9 = 0;
uint8_t oldAnalogValue10 = 0;
uint8_t newAnalogValue10 = 0;
uint8_t oldAnalogValue11 = 0;
uint8_t newAnalogValue11 = 0;

void setup()
{}
 
void loop()
{
  uint16_t analogValue = analogRead(A0);
  uint8_t newAnalogValue = analogValue >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 1, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }

  uint16_t analogValue1 = analogRead(A1);
  uint8_t newAnalogValue1 = analogValue1 >> 3;
  
  if( newAnalogValue1 != oldAnalogValue1 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 2, newAnalogValue1 };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue1 = newAnalogValue1;
    }
  uint16_t analogValue2 = analogRead(A2);
  uint8_t newAnalogValue2 = analogValue2 >> 3;
  
  if( newAnalogValue2 != oldAnalogValue2 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 3, newAnalogValue2 };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue2 = newAnalogValue2;
    }
    
  uint16_t analogValue3 = analogRead(A3);
  uint8_t newAnalogValue3 = analogValue3 >> 3;
  
  if( newAnalogValue3 != oldAnalogValue3 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 4, newAnalogValue3 };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue3 = newAnalogValue3;
    }

  uint16_t analogValue4 = analogRead(A4);
  uint8_t newAnalogValue4 = analogValue4 >> 3;
  

  if( newAnalogValue4 != oldAnalogValue4 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 5, newAnalogValue4 };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue4 = newAnalogValue4;
    }
  uint16_t analogValue5 = analogRead(A5);
  uint8_t newAnalogValue5 = analogValue5 >> 3;
  
  if( newAnalogValue5 != oldAnalogValue5 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 6, newAnalogValue5 };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue5 = newAnalogValue5;
    }  

  uint16_t analogValue6 = analogRead(A6);
  uint8_t newAnalogValue6 = analogValue6 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 7, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
  
  uint16_t analogValue7 = analogRead(A7);
  uint8_t newAnalogValue7 = analogValue7 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 8, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
    
  uint16_t analogValue8 = analogRead(A8);
  uint8_t newAnalogValue8 = analogValue8 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 9, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
    
  uint16_t analogValue9 = analogRead(A9);
  uint8_t newAnalogValue9 = analogValue9 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 10, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
  
  uint16_t analogValue10 = analogRead(A10);
  uint8_t newAnalogValue10 = analogValue10 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 11, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
  
  uint16_t analogValue11 = analogRead(A11);
  uint8_t newAnalogValue11 = analogValue11 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 12, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
}
