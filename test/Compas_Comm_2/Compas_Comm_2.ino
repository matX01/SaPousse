/*#include <SPI.h>


const int CSPin = 10;
int x = 0;
SPISettings SPIDev(1000000,MSBFIRST,SPI_MODE3);




void setup(){
  pinMode(CSPin,OUTPUT);
  digitalWrite(CSPin,HIGH);
  SPI.begin();
  Serial.begin(115200);
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x75 | 0x80);
  uint8_t out = SPI.transfer(0x00);
  digitalWrite(CSPin,HIGH);
  SPI.endTransaction();
  if(out != 0x71){
    
    Serial.println("Not Connected !");
    while(true);
    
  }

/*
0x6B 10000000 -> 0x80
0x6A 00100000 -> 0x20
0x24 00001101 -> 0x0D
0x25 10001100 -> 0x8C
0x26 00000000 -> 0x00
0x27 10000001 -> 0x81*/
/*
SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6B);
 SPI.transfer(0x80);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6B | 0x80);
 Serial.print("0x6B : ");
 Serial.println(SPI.transfer(0x00),HEX);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);//Fait

SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6B);
 SPI.transfer(0x00);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6B | 0x80);
 Serial.print("0x6B : ");
 Serial.println(SPI.transfer(0x00),HEX);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);//Fait

 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6A);
 SPI.transfer(0x02);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6A | 0x80);
 Serial.print("0x6A : ");
 Serial.println(SPI.transfer(0x00),HEX);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);


 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6A);
 SPI.transfer(0x20);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6A | 0x80);
 Serial.print("0x6A : ");
 Serial.println(SPI.transfer(0x00),HEX);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);

 
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x24);
 SPI.transfer(0x0D);      //Possibilité d'erreur
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);
  SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 Serial.print("0x24 : ");
 SPI.transfer(0x24 | 0x80);
 Serial.println(SPI.transfer(0x00),HEX);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(1);


Serial.println(" ");
writeReg(0x0A,0x16);

  
}
void loop(){

/*Serial.println();
for(int i = 0;i < 18;i ++){
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x26);
  SPI.transfer(i);      
  digitalWrite(CSPin,HIGH);
  SPI.endTransaction();
  delay(1);
  Serial.print(i, HEX);
  Serial.print(" : ");
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x49 | 0x80);
  Serial.print(SPI.transfer(0x00),HEX);
  digitalWrite(CSPin,HIGH);
  SPI.endTransaction();
  delay(1);
  Serial.println();

 } 
 Serial.println();
 

for(uint8_t i = 0;i < 18; i ++){
  Serial.print(i,HEX);
  Serial.print(" : ");
  Serial.println(ReadReg(i),HEX);
  delay(1);

}
delay(1000);
Serial.println();

  
}

uint8_t ReadReg(uint8_t Reg){


delay(1);

SPI.beginTransaction(SPIDev);
digitalWrite(CSPin,LOW);
SPI.transfer(0x25);
SPI.transfer(0x8C);
digitalWrite(CSPin,HIGH);
SPI.endTransaction();
delay(1);

SPI.beginTransaction(SPIDev);
digitalWrite(CSPin,LOW);
SPI.transfer(0x26);
SPI.transfer(Reg);
digitalWrite(CSPin,HIGH);
SPI.endTransaction();
delay(1);

SPI.beginTransaction(SPIDev);
digitalWrite(CSPin,LOW);
SPI.transfer(0x27);
SPI.transfer(0x81);
digitalWrite(CSPin,HIGH);
SPI.endTransaction();
delay(1);

SPI.beginTransaction(SPIDev);
digitalWrite(CSPin,LOW);
SPI.transfer(0x49 | 0x80);
uint8_t returnValue = SPI.transfer(0x00);
digitalWrite(CSPin,HIGH);
SPI.endTransaction();
delay(1);

return returnValue;

}
void writeReg(uint8_t reg,uint8_t mess){

delay(1);
SPI.beginTransaction(SPIDev);
digitalWrite(CSPin,LOW);
SPI.transfer(0x25);
SPI.transfer(0x0C);
digitalWrite(CSPin,HIGH);
SPI.endTransaction();
delay(1);

SPI.beginTransaction(SPIDev);
digitalWrite(CSPin,LOW);
SPI.transfer(0x26);
SPI.transfer(reg);
digitalWrite(CSPin,HIGH);
SPI.endTransaction();
delay(1);

SPI.beginTransaction(SPIDev);
digitalWrite(CSPin,LOW);
SPI.transfer(0x63);
SPI.transfer(mess);
digitalWrite(CSPin,HIGH);
SPI.endTransaction();
delay(1);

SPI.beginTransaction(SPIDev);
digitalWrite(CSPin,LOW);
SPI.transfer(0x27);
SPI.transfer(0x81);
digitalWrite(CSPin,HIGH);
SPI.endTransaction();
delay(1);

}*/



#include <SPI.h>
#include "GlobalVariables.h"
#include "SPIElement.h"
#include "Debugger.h"

SPIDev MPU;

void setup(){

/*
0x6B 10000000 -> 0x80
0x6A 00100000 -> 0x20
0x24 00001101 -> 0x0D
0x25 10001100 -> 0x8C
0x26 00000000 -> 0x00
0x27 10000001 - > 0x81
*/
GeneralSPIConfiguration.beginAllSPI(3);
MPU.SPIInitParam(10,1,SPISettings(1000000,MSBFIRST,SPI_MODE3));
MPU.begin();

MPU.beginTransaction();
MPU.setRegister(0x6B,0x80);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
 Serial.print("0x6B : ");
Serial.println(MPU.getRegister(0x6B),HEX);
MPU.endTransaction();
delay(1);


MPU.beginTransaction();
MPU.setRegister(0x6A,0x02);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
 Serial.print("0x6A : ");
Serial.println(MPU.getRegister(0x6A),HEX);
MPU.endTransaction();
delay(1);


MPU.beginTransaction();
MPU.setRegister(0x6B,0x00);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
 Serial.print("0x6B : ");
Serial.println(MPU.getRegister(0x6B),HEX);
MPU.endTransaction();
delay(1);

MPU.beginTransaction();
MPU.setRegister(0x6A,0x20);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
 Serial.print("0x6A : ");
Serial.println(MPU.getRegister(0x6A),HEX);
MPU.endTransaction();
delay(1);


MPU.beginTransaction();
MPU.setRegister(0x24,0x0D);
MPU.endTransaction();
delay(10);
MPU.beginTransaction();
Serial.print("0x24 : ");
Serial.println(MPU.getRegister(0x24),HEX);
MPU.endTransaction();
delay(1);

Serial.println(" ");

WriteReg(0x0B,0x01);
WriteReg(0x0A,0x0F);

for(uint8_t i = 0x10;i <= 0x12;i ++){
  
  Serial.println(ReadReg(i),HEX);

}
WriteReg(0x0B,0x01);
WriteReg(0x0A,0x16);

  
}
void loop(){
/*MPU.beginTransaction();
Serial.println(MPU.getRegister(0x75),HEX);
MPU.endTransaction();
delay(1000);

}*/

for(uint8_t i = 0;i < 19; i ++){
  Serial.print(i,HEX);
  Serial.print(" : ");
  Serial.println(ReadReg(i),HEX);
  delay(1);

}
delay(1000);
Serial.println();

  
}

uint8_t ReadReg(uint8_t Reg){

delay(1);
MPU.beginTransaction();
MPU.setRegister(0x25,0x8C);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
MPU.setRegister(0x26,Reg);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
MPU.setRegister(0x27,0x81);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
uint8_t returnValue = MPU.getRegister(0x49);
MPU.endTransaction();
delay(1);

return returnValue;

}
void WriteReg(uint8_t reg,uint8_t mess){

delay(1);
MPU.beginTransaction();
MPU.setRegister(0x25,0x0C);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
MPU.setRegister(0x26,reg);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
MPU.setRegister(0x63,mess);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
MPU.setRegister(0x27,0x81);
MPU.endTransaction();
delay(1);
}

/*uint8_t brdg(){

delay(1);
MPU.beginTransaction();
MPU.setRegister(0x25,0x8C);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
MPU.setRegister(0x26,Reg);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
MPU.setRegister(0x27,0x81);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
uint8_t returnValue = MPU.getRegister(0x49);
MPU.endTransaction();
delay(1);

return returnValue;

}*/