/*
 * you need to select the board as NodeMCU 1.0(ESP12E Module). for this syou can watch our other tutorials in our channel. 
 * you can also take the help from this link. and also select the COM port to uplaod the program. 
 */
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL6in09eemr"
#define BLYNK_DEVICE_NAME "Servo control"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"
#include<Servo.h>
Servo servo;

BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo.write(s0);
  Blynk.virtualWrite(V1, s0);
}

void setup()
{
  Serial.begin(9600);
  servo.attach(D2);
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{
  BlynkEdgent.run();
}
