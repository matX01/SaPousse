#ifndef GlobalVar
#define GlobalVar
#include <Arduino.h>
#include "Debugger.h"



//SDCard
#define NumberOfParametersLoaded 4
#define ParameterListX 10
#define ParameterListY 4
#define ParameterCharSize 5
#define FlightParametersDirectory "FP.SP"

//SPIDev 
#define numberOfCumulatedExceptionInDefinedTimeOut 10000
#define TimeUnitForExceptionTimeOut 1000

//MPU9250
    //TableMap
    
        #define GYRO_OUT 0x43
        #define ACCEL_OUT 0x3B
        #define TEMPERATURE_OUT 0x41
        #define COMPAS_OUT 0x49
        #define IMU_ADRESS 0x75

        #define UNDER_I2C_SETUP 0x6A
        #define UNDER_I2C_MASTERMODE 0x20

        #define UNDER_I2C_CLKSETUP 0x24
        #define UNDER_I2C_400KCLK 0x0D

        #define PWR_MANAGEMENT_1 0x6B
        #define PWR_MANAGEMENT_2 0x6C
        #define RESET_I2C 0x02
        #define RESET_IMU 0x80
        #define CLK_20MHZ 0x00

        #define I2C_SLV0_ADDRSEL 0x25
        #define SLV0_REGISTERTOOP 0x26
        #define SLV0_CTRL 0x27
        #define SLV0_REGISTER_OUTPUT 0x63
        #define SLV_READ_MODE 0x80
        #define SLV_ENABLE 0x80
        #define SLV_DATAOUT 0x49
        #define SLV0_DO 0x63
    //AK8963
        #define AK8963_ADDR 0x0C
    
        #define UNDER_I2C_AK8963_ADRESS 0x00
        #define AK8963 MEASURE_OUT 0x03
        #define AK8963_CNTL_1 0x0A
        #define AK8963_CNTL_2 0x0B
        #define AK8963_SENS_ADJ 0x10


#define IMUFIFOSize 40

//SampleRateDivider

#define NumberOfDifferentExecutionRate 4;






struct FlightParameter{
    
    float FlightParam[ParameterListY][ParameterListX];

};


struct ErrorType {
   
    uint8_t ErrorTypeID;

};

class GlobalExceptionHandler {
    public :
    
    GlobalExceptionHandler();
    static void begin();
    static void FailedToInitialise(uint8_t ExceptionID);
    static void SpiCommErr();
    static void FatalError(uint8_t ExceptionID);
    static void Error(uint8_t ExceptionID,ErrorType Err);
    private :
    
    static int ExceptionCount;
    static unsigned long LastExceptionCountTime;


};

extern GlobalExceptionHandler ExceptionHandler;

const ErrorType INITERROR{
    0
};
const ErrorType FATALERROR{
    1
};
const ErrorType SAMPLINGERROR{
    2
};
const ErrorType SMALLERROR{
    3
};
const ErrorType SPIERROR {
    4
};




#endif
/*


#include <SPI.h>
#include "GlobalPreProcessorValuessorValues.h"
#include "SPIElement.h"
#include "Debugger.h"
/*
const int CSPin = 10;
int x = 0;
SPISettings SPIDev(1000000,MSBFIRST,SPI_MODE3);*/



/*
void setup() {
  Serial.begin(115200);
  pinMode(CSPin,OUTPUT);
  digitalWrite(CSPin,HIGH);
  SPI.begin();
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x6B);
  SPI.transfer(0x80);
  digitalWrite(CSPin,HIGH);
  SPI.endTransaction();
  delay(100);
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x6A);
  SPI.transfer(0x20);
  digitalWrite(CSPin,HIGH);
  SPI.endTransaction();
  delay(1);
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x24);
  SPI.transfer(0x1D);
  digitalWrite(CSPin,HIGH);
  SPI.endTransaction();
  delay(1);
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x25);
  SPI.transfer(0x0C | 0x80);
  digitalWrite(CSPin,HIGH);
  SPI.endTransaction();
  delay(1);
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x26);
  SPI.transfer(0x00);
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



}

void loop() {
  SPI.beginTransaction(SPIDev);
  digitalWrite(CSPin,LOW);
  SPI.transfer(0x49 | 0x80);
  for(int i = 0;i < 10; i ++){
    Serial.print(SPI.transfer(0x00),HEX);
    Serial.print(" ");
  }
  Serial.println();
  digitalWrite(CSPin,HIGH);
  SPI.endTransaction();
  delay(1000);

}





SPIDev MPU;

void setup(){
  /*
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
    
  }*/

/*
0x6B 10000000 -> 0x80
0x6A 00100000 -> 0x20
0x24 00001101 -> 0x0D
0x25 10001100 -> 0x8C
0x26 00000000 -> 0x00
0x27 10000001 - > 0x81


*/
/*
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6A);
 SPI.transfer(0x00);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(100);
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6A | 0x80);
 Serial.println(SPI.transfer(0x00),HEX);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(100);
 */
/*
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6A);
 SPI.transfer(0x02);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(100);  
 SPI.beginTransaction(SPIDev);
 digitalWrite(CSPin,LOW);
 SPI.transfer(0x6A | 0x80);
 Serial.println(SPI.transfer(0x00),HEX);
 digitalWrite(CSPin,HIGH);
 SPI.endTransaction();
 delay(100);


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
MPU.setRegister(0x6B,0x00);
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
Serial.println(MPU.getRegister(0x6B),HEX);
MPU.endTransaction();
delay(1);



MPU.beginTransaction();
MPU.setRegister(0x6A,0x20);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
 Serial.print("0x6A : ");
Serial.println(MPU.getRegister(0x6B),HEX);
MPU.endTransaction();
delay(1);



MPU.beginTransaction();
MPU.setRegister(0x24,0x0D);
MPU.endTransaction();
delay(1);
MPU.beginTransaction();
 Serial.print("0x24 : ");
Serial.println(MPU.getRegister(0x6B),HEX);
MPU.endTransaction();
delay(1);



/*SPI.beginTransaction(SPIDev);
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
}*/