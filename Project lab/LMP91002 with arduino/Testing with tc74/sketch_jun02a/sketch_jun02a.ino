/* source of code:
http://www.electroschematics.com/9798/reading-temperatures-i2c-arduino/ */
#include <Wire.h>
int address1 = 72;  //decimal address of sensor 1
//int address2 = 73;  //decimal address of sensor 2
//int address3 = 74;  //decimal address of sensor 3
 
void setup() {
  Serial.begin(9600);
  Wire.begin();     // create a wire object
}
 
void loop() {
  //start the communication with IC with the address xx
  Wire.beginTransmission(address1); 
  //send a bit and ask for register zero
  Wire.write(0);
  //end transmission
  Wire.endTransmission();
  //request 1 byte from address xx
  Wire.requestFrom(address1, 1);
  //wait for response
  while(Wire.available() == 0);
  Serial.println(Wire.read());
  //put the temperature in variable c
  //int c = Wire.read();   
  //return c;
 // int c1 = read_temp(address1);
 // int c2 = read_temp(address2);
 // int c3 = read_temp(address3);  
 // Serial.print("Sensor 1: ");
  //Serial.print(c1);
  //Serial.print("C | ");
 // Serial.print("Sensor 2: ");
//  Serial.print(c2);
 // Serial.print("C | ");
 // Serial.print("Sensor 3: ");
  //Serial.print(c3);   
 // Serial.println("C");
  delay(1000);  
}
 
//int read_temp(int address) {
  /*//start the communication with IC with the address xx
  Wire.beginTransmission(address); 
  //send a bit and ask for register zero
  Wire.write(0);
  //end transmission
  Wire.endTransmission();
  //request 1 byte from address xx
  Wire.requestFrom(address, 1);
  //wait for response
  while(Wire.available() == 0);
  //put the temperature in variable c
  int c = Wire.read();   
  return c;*/
//}
