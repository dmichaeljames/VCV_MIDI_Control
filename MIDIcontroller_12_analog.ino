/************************************************************************************************************************************************* 
*
*  Arduino Leonardo-based MIDI controller sketch made for controlling VCVrack, but can be used for anything MIDI-based
*  
*  02/15/2018
*
**************************************************************************************************************************************************/
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
  // Quick explaination of what's going on here: analogRead(A0) is grabbing the value from the arduino (0 - 1023); this is then being bitshifted ( >> 3) to convert the 1024 levels from the analog input to the 128 levels that MIDI uses
  uint16_t analogValue = analogRead(A0);
  uint8_t newAnalogValue = analogValue >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {  
    // Here we have the arduino sending a MIDICC packet with a CC message (0x0B), on channel 1 (0xB0), with a CC number (1), and the bitshifted value from the analog pin. Then, the current value is saved to oldAnalogValue and
    // the arduino ignores this input until a change is made.
    //
    // My setup uses four arduinos all set to the same channel (0xB0), so I need to make sure that the CC channels are different for all four devices.
    // adding commented out lines for the other boards.
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 1, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 13, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 25, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 37, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }

  uint16_t analogValue1 = analogRead(A1);
  uint8_t newAnalogValue1 = analogValue1 >> 3;
  
  if( newAnalogValue1 != oldAnalogValue1 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 2, newAnalogValue1 };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 14, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 26, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 38, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue1 = newAnalogValue1;
    }
  
  uint16_t analogValue2 = analogRead(A2);
  uint8_t newAnalogValue2 = analogValue2 >> 3;
  
  if( newAnalogValue2 != oldAnalogValue2 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 3, newAnalogValue2 };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 15, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 27, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 39, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue2 = newAnalogValue2;
    }
    
  uint16_t analogValue3 = analogRead(A3);
  uint8_t newAnalogValue3 = analogValue3 >> 3;
  
  if( newAnalogValue3 != oldAnalogValue3 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 4, newAnalogValue3 };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 16, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 28, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 40, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue3 = newAnalogValue3;
    }

  uint16_t analogValue4 = analogRead(A4);
  uint8_t newAnalogValue4 = analogValue4 >> 3;
  

  if( newAnalogValue4 != oldAnalogValue4 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 5, newAnalogValue4 };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 17, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 29, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 41, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue4 = newAnalogValue4;
    }
  uint16_t analogValue5 = analogRead(A5);
  uint8_t newAnalogValue5 = analogValue5 >> 3;
  
  if( newAnalogValue5 != oldAnalogValue5 )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 6, newAnalogValue5 };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 18, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 30, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 42, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue5 = newAnalogValue5;
    }  

  uint16_t analogValue6 = analogRead(A6);
  uint8_t newAnalogValue6 = analogValue6 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 7, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 19, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 31, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 43, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
  
  uint16_t analogValue7 = analogRead(A7);
  uint8_t newAnalogValue7 = analogValue7 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 8, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 20, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 32, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 44, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
    
  uint16_t analogValue8 = analogRead(A8);
  uint8_t newAnalogValue8 = analogValue8 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 9, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 21, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 33, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 45, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
    
  uint16_t analogValue9 = analogRead(A9);
  uint8_t newAnalogValue9 = analogValue9 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 10, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 22, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 34, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 46, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
  
  uint16_t analogValue10 = analogRead(A10);
  uint8_t newAnalogValue10 = analogValue10 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 11, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 23, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 35, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 47, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
  
  uint16_t analogValue11 = analogRead(A11);
  uint8_t newAnalogValue11 = analogValue11 >> 3;
  
  if( newAnalogValue != oldAnalogValue )
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 12, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 24, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 36, newAnalogValue };
    //midiEventPacket_t midiCc = { 0x0B, 0xB0, 48, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
    }
}
