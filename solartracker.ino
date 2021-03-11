#include <Servo.h>

Servo servoHorizontal;
int servoH = 0;
int servoHLimitHigh = 160;
int servoHLimitLow = 20;

Servo servoVertical; 
int servoV = 0; 
int servoVLimitHigh = 160;
int servoVLimitLow = 20;

int ldrtopl = 2; //top left LDR 
int ldrtopr = 1; //top right LDR 
int ldrbotl = 3; // bottom left LDR 
int ldrbotr = 0; // bottom right LDR 

 void setup () 
 {
  servoHorizontal.attach(11);  
  servoHorizontal.write(0);
  servoVertical.attach(9);   
  servoVertical.write(0);
  delay(500);
 }

void loop()
{
  servoH = servoHorizontal.read();
  servoV = servoVertical.read();
  
  //capturing analog values of each LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  
  // calculating average
  int avgtop = (topl + topr) / 2; //average of top LDRs
  int avgbot = (botl + botr) / 2; //average of bottom LDRs
  int avgleft = (topl + botl) / 2; //average of left LDRs
  int avgright = (topr + botr) / 2; //average of right LDRs

  if (avgtop < avgbot)
  {
    servoVertical.write(servoV +1);
    if (servoV > servoVLimitHigh) 
     { 
      servoV = servoVLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoVertical.write(servoV -1);
    if (servoV < servoVLimitLow)
  {
    servoV = servoVLimitLow;
  }
    delay(10);
  }
  else 
  {
    servoVertical.write(servoV);
  }
  
  if (avgleft > avgright)
  {
    servoHorizontal.write(servoH +1);
    if (servoH > servoHLimitHigh)
    {
    servoH = servoHLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servoHorizontal.write(servoH -1);
    if (servoH < servoHLimitLow)
     {
     servoH = servoHLimitLow;
     }
    delay(10);
  }
  else 
  {
    servoHorizontal.write(servoH);
  }
  delay(50);
}