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
long avgReading;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  // capsense args [channel mask, autoscan sequence, deglitch value]
  boolean fdc0 = capsense0.begin(0xF, 0x6, 0x5, false);
  boolean fdc1 = capsense1.begin(0x1, 0x1, 0x5, false);
 
  delay(500);
  for (int i = 0; i < 16; i++) {
    avgReading += capsense1.getReading28(0);
  }
  avgReading /= 16;
}

void loop() {
  long capa = capsense1.getReading28(0);
  Serial.println(capa-avgReading);
}
