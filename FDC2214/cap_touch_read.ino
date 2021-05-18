// Capacitive Touch Sensing PCB Verification
// FDC2214 TI Capacitive Sensing Chip
// Target board Arduino Uno
// A4 = SDA Black
// A5 = SCL Orange
// 3.3V = Blue
// GND = White

#include  <Wire.h>
#include "FDC2214.h"

FDC2214 capsense0(FDC2214_I2C_ADDR_0);
FDC2214 capsense1(FDC2214_I2C_ADDR_1);

int READ_BYTES = 2;
unsigned long byteArray0[4] = {0, 0, 0, 0};
unsigned long byteArray1[4] = {0, 0, 0, 0};

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Hello World");
  boolean fdc0 = capsense0.begin(0xF, 0x6, 0x5);
//  boolean fdc1 = capsense1.begin(0xF, 0x6, 0x5);
  boolean fdc1 = capsense1.begin(0x1, 0x1, 0x5);
  //boolean capOk = capsense.begin(0x3, 0x4, 0x5);
  Serial.println("Finished Setup");
  if (fdc0) Serial.println("Sensor 0 OK");
  else Serial.println("Sensor 0 Fail");
  if (fdc1) Serial.println("Sensor 1 OK");
  else Serial.println("Sensor 1 Fail");
  delay(500);
}

void loop() {
  unsigned long capa = capsense1.getReading28(0);
  Serial.println(capa);
//  for (int i = 0; i < 4; i++) {
//    byteArray0[i] = capsense0.getReading28(i); 
//    Serial.print(byteArray0[i]);  
//    if (i < 3) Serial.print(", ");
//    else Serial.println(""); 
//    byteArray1[i] = capsense1.getReading28(i);
//    if (i == 0) 
//    {
//      Serial.println(byteArray1[i] - 14800000);
//    }
//    if (i < 3) Serial.print(", ");
//    else Serial.println(""); 
//  }
}
