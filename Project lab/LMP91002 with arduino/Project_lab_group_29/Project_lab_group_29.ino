#include <Wire.h>
#define LMP91002 0x48
#define LMP91002_STATUS_REG 0x00
#define LMP91002_LOCK_REG 0x01
#define LMP91002_UNLOCK_REG 0x00
#define LMP91002_TIACN_REG 0x10
#define LMP91002_RTIACN_def_REG 0x00
#define LMP91002_RTIACN_2P75K_REG 0x07
#define LMP91002_RTIACN_3P5K_REG 0x0B
#define LMP91002_RTIACN_7K_REG 0x0F
#define LMP91002_RTIACN_14K_REG 0x13
#define LMP91002_RTIACN_35K_REG 0x17
#define LMP91002_RTIACN_120K_REG 0x1B
#define LMP91002_RTIACN_350K_REG 0x1F
#define LMP91002_REFCN_REG 0x11
#define LMP91002_DIAGN_0PTG_20PTG_INT_REG 0x00
#define LMP91002_DIAGN_0PTG_50PTG_INT_REG 0x20
#define LMP91002_DIAGN_0PTG_67PTG_INT_REG 0x40
#define LMP91002_DIAGN_1PTG_20PTG_INT_REG 0x01
#define LMP91002_DIAGN_1PTG_50PTG_INT_REG 0x21
#define LMP91002_DIAGN_1PTG_67PTG_INT_REG 0x41
#define LMP91002_DIAGN_0PTG_20PTG_EXT_REG 0x80
#define LMP91002_DIAGN_0PTG_50PTG_EXT_REG 0xA0
#define LMP91002_DIAGN_0PTG_67PTG_EXT_REG 0xC0
#define LMP91002_DIAGN_1PTG_20PTG_EXT_REG 0x81
#define LMP91002_DIAGN_1PTG_50PTG_EXT_REG 0xA1
#define LMP91002_DIAGN_1PTG_67PTG_EXT_REG 0xC1
#define LMP91002_MODECN_REG 0x12
#define LMP91002_MODECN_DEEPSLEEP_REG 0x00
#define LMP91002_MODECN_STANDBY_REG 0x02
#define LMP91002_MODECN_3LEADAMPCELL_REG 0x03

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\n LMP91002 data");
}

void loop() {
  uint8_t Status,Lock,Unlock,TIACN,REFCN,MODECN;

    //STATUS
    Wire.beginTransmission(LMP91002);
    Wire.write(LMP91002_STATUS_REG);  
    Wire.endTransmission(true);
    Wire.requestFrom(LMP91002,1);
    while(Wire.available()){
      Status = Wire.read(); 
      Serial.print("STATUS = ");
      Serial.println(Status,BIN);
      delay(1000);
      }
   
    //LOCK
    Wire.beginTransmission(LMP91002);  
    Wire.write(LMP91002_LOCK_REG);
    Wire.write(LMP91002_UNLOCK_REG);
    Wire.endTransmission(true);
    Wire.requestFrom(LMP91002,1);
    while(Wire.available()){
      Lock   = Wire.read();
      Serial.print("LOCK = ");
      Serial.println(Lock,HEX); 
      delay(1000);     
      }  

    //TIACN
    Wire.beginTransmission(LMP91002);
    Wire.write(LMP91002_TIACN_REG);
    Wire.write(LMP91002_RTIACN_14K_REG);
    Wire.endTransmission(true);
    Wire.requestFrom(LMP91002,1);
    while(Wire.available()){
      TIACN  = Wire.read();
      Serial.print("TIACN = ");
      Serial.println(TIACN,BIN);
      delay(1000);
      }

    //REFCN
    Wire.beginTransmission(LMP91002);
    Wire.write(LMP91002_REFCN_REG);
    Wire.write(LMP91002_DIAGN_1PTG_67PTG_EXT_REG);
    Wire.endTransmission(true);
    Wire.requestFrom(LMP91002,1);
    while(Wire.available()){
      REFCN  = Wire.read();
      Serial.print("REFCN = ");
      Serial.println(REFCN,BIN);
      delay(1000);
      }

    //MODECN
    Wire.beginTransmission(LMP91002);
    Wire.write(LMP91002_MODECN_REG);
    Wire.write(LMP91002_MODECN_3LEADAMPCELL_REG);
    Wire.endTransmission(true);
    Wire.requestFrom(LMP91002,1);
    while(Wire.available()){
      MODECN  = Wire.read();
      Serial.print("MODECN = ");
      Serial.println(MODECN,BIN);
      delay(1000);
      }
}
