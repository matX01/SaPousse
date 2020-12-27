#include <SPI.h>

#define CSPin 10

#define MISOPin 12
#define MOSIPin 11
#define SCKPin 13

#define IMUSPISpeed 1000000
#define IMUSPIMode SPI_MODE3
#define IMUSPIBit MSBFIRST



SPISettings IMUSet = SPISettings(IMUSPISpeed,IMUSPIMode,IMUSPIBit);

void setup() {

  Serial.begin(115200);

  pinMode(CSPin,OUTPUT);
  digitalWrite(CSPin,HIGH);

  SPI.begin();
  SPI.setMISO(MISOPin);
  SPI.setMOSI(MOSIPin);
  SPI.setSCK(SCKPin);



}

void loop() {
  // put your main code here, to run repeatedly:

}

void serialEvent(){
    char ValueArray[6];

    char header = ' ';
    int valueinhex = 0;
    strcpy(ValueArray,"");
   
    while(Serial.available()){
        char val = Serial.read();
        switch(val){
        case '+':

           header = '+';
      
        /*SPI.beginTransaction(IMUSet);
        SPI.transfer(0x00);*/
      break;
      case '-':

       
        header = '-';

      break;
      case '\n' :


      break;
      default :

         sprintf(ValueArray,"%s%c",ValueArray,val);


      break;

    }
    }
   
    valueinhex = (int)strtol(ValueArray, NULL, 0);


    switch(header){
      case '+':

        Serial.print("set          Board -----> IMU value : ");
        Serial.println(valueinhex,HEX);

        SPI.beginTransaction(IMUSet);
        SPI.transfer(valueinhex);
        






      break;
      case '-':

        Serial.print("get          Board <----- IMU value : ");
        Serial.print(ValueArray);
        Serial.print(" returned : ");



      break;


    }
    Serial.println(ValueArray);
 
}