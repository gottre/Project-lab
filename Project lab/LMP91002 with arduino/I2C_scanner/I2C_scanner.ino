#include <Wire.h>
#define LMP91002_STATUS_REG 0x00

void setup()
{
  Wire.begin();

  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}

void I2C_scanner(){
  while(1){
  byte error, address;
  int nDevices;
  
  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 128; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(1000);           // wait for next scan
  }
}

void loop()
{
    byte address;
    Wire.write(LMP91002_STATUS_REG); // ask for status register 
    Wire.requestFrom(address,1);
    while(Wire.available()){
      int Status = Wire.read();
        if (Status == 1){
         Serial.println("LMP91002 is ready");
         delay(500);
        }
      else {
        Serial.println("LMP91002 is not ready");
        delay(500);
      }
    }
}



