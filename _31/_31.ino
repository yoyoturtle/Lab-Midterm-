#include "SevSeg.h"
SevSeg sevseg;

void setup()
{
  Serial.begin(9600);
  Serial.print("31\n"); 
  Serial.print("03050273\n"); 
 Serial.println("03050592");
 
  byte numDigits = 4;
  byte digitPins[] = {13,10,9,2};
  byte segmentPins[] = {12, 8, 4, 6, 7, 11, 3, 5};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);


}
void loop()
{
  int val;
    if(Serial.available())
    {
      val = Serial.parseInt();
        
      if(val>=0 && val<10000)
      {
        sevseg.setNumber(val);
        Serial.println(val);  
          sevseg.refreshDisplay();
        }
      else
        Serial.println("range error");  
      
      
    }
    else
            sevseg.refreshDisplay();

    
}
