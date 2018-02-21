
/************************************************************************************************************************************************* 
*
*  Arduino Leonardo-based MIDI controller sketch made for controlling VCVrack, but can be used for anything MIDI-based
*  
*  02/21/2018
*
**************************************************************************************************************************************************/
#include <MIDIUSB.h>
#include <frequencyToNote.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

uint8_t oldAnalogValue = -1;
uint8_t newAnalogValue = -1;

void setup() {
}
 
void loop()
{  
  for (int i = 0; i < 12; i++) {
    uint16_t analogValue = analogRead(i);
    uint8_t newAnalogValue = analogValue >> 3;
    int cc = (i + 1);
  
    if( newAnalogValue != oldAnalogValue )
    {  
      midiEventPacket_t midiCc = { 0x0B, 0xB0, cc, newAnalogValue };
      MidiUSB.sendMIDI(midiCc);
      MidiUSB.flush();
      oldAnalogValue = newAnalogValue;
    }
  }
}
