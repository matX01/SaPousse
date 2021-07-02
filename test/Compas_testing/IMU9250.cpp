#include "IMU9250.h"

SPIDev IMU9250::IMUSPI;
DataStructure IMU9250::OutputValue;

float IMU9250::ConversionValue[3];
short IMU9250::Offsets[3];
float IMU9250::Linearity[3];
uint8_t IMU9250::Ranges[4];





IMU9250::IMU9250(){

   

}

void IMU9250::SetBus(uint8_t SPINumberUsedForComm,uint8_t CSPin){

    IMUSPI.SPIInitParam(CSPin,SPINumberUsedForComm,SPISettings(IMUSPISpeed,IMUSPIMode,IMUSPIBit));

}



void IMU9250::begin(){
    
    IMUSPI.begin();

    IMUSPI.beginTransaction();
    if(IMUSPI.getRegister(IMU_ADRESS) != 0x71){

        ExceptionHandler.Error(0x0A,INITERROR);

    }
    IMUSPI.endTransaction();

    delay(1);

    IMUSPI.beginTransaction();
    IMUSPI.setRegister(PWR_MANAGEMENT_1,RESET_IMU);
    IMUSPI.endTransaction();

    delay(1);

    IMUSPI.beginTransaction();
    IMUSPI.setRegister(UNDER_I2C_SETUP,RESET_I2C);
    IMUSPI.endTransaction();
    
    delay(1);

    
    IMUSPI.beginTransaction();
    IMUSPI.setRegister(0x6B,0x00);
    IMUSPI.endTransaction();

    delay(1);

    IMUSPI.beginTransaction();
    IMUSPI.setRegister(0x6A,0x20);
    IMUSPI.endTransaction();
    
    delay(1);

    
    IMUSPI.beginTransaction();
    IMUSPI.setRegister(0x24,0x0D);
    IMUSPI.endTransaction();
 
    delay(1);

       
        for(int i = 0;i < 3;i ++){
            Linearity[i] = 1;
           

            ConversionValue[i] = 1;

      

        }
  
    //Set ranges of the IMU
    for(int i = 0;i < 4;i ++){

        Ranges[i] = 1;
        
    } 
    if(readAK8963(0x00) != 0x48)
    {


        Serial.println(" hahhah00");

    }
    writeAK8963(0x0B,0x01);
    //writeAK8963(0x0A,0x16);
    //writeAK8963(0x0C,0b01000000);
    writeAK8963(0x0A,0x16);
    setAK8963ToBrigeMode();

}








void IMU9250::calibrateCompas(int NumberOfCalibrationIteration){

    /*Rotate the IMU on all axis to find the min and max points of all*/



}

void IMU9250::readSensor(){

    IMUSPI.beginTransaction();
    uint8_t buff[2];
    
    for(int i = 0;i < 3;i ++){

        buff[1] = IMUSPI.getRegister(0x49);    
        buff[0] = IMUSPI.getRegister(0x00);

      
        OutputValue.OutputShort[i] = (((short)(((buff[0] << 8) | (buff[1]))+Offsets[i]))*Linearity[i]);
        OutputValue.OutputFloat[i] =  OutputValue.OutputShort[i]*ConversionValue[i];
        
    }
    uint8_t OVF = (IMUSPI.getRegister(0x49) & 0b00001000);
    if(OVF == 0b00001000){

        Serial.println("OVF!!!!!");

    }  
    IMUSPI.endTransaction();


}

uint8_t IMU9250::readAK8963(uint8_t Register){
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(I2C_SLV0_ADDRSEL,AK8963_ADDR | 0x80);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_REGISTERTOOP,Register);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_CTRL,SLV_ENABLE | 0x01);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
uint8_t returnValue = IMUSPI.getRegister(0x49);
IMUSPI.endTransaction();
delay(1);

    return returnValue;
}

void IMU9250::writeAK8963(uint8_t Register,uint8_t Message){

delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(I2C_SLV0_ADDRSEL,AK8963_ADDR);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_REGISTERTOOP,Register);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_DO,Message);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_CTRL,SLV_ENABLE | 0x01);
IMUSPI.endTransaction();
delay(1);
}

void IMU9250::setAK8963ToBrigeMode(){
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(I2C_SLV0_ADDRSEL,AK8963_ADDR | 0x80);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_REGISTERTOOP,AK8963_MEASURE_OUT);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_CTRL,SLV_ENABLE | 0x07);
IMUSPI.endTransaction();
delay(1);





}



DataStructure *IMU9250::GetValues(){
    
    return &OutputValue;
    /*FIFOReadingPosition ++;
    if(FIFORecordPosition == IMUFIFOSize){

        FIFOReadingPosition = 0;

    }
    
    return ReturnStructurePointer;*/

}



/*

Il faut détécter si le FIFO est plein/si le FIFO est vide

    Si il est plein :
        ERREUR , réduire de 100Hz le Sampling;
    Si il est vide :
        Disable la gestion de données puisqu'on est en flux tendu

    L'objectif est de maintenir la latence la plus basse possible , si l'acquisition , le traitement et l'envoi se font en flux tendu alors c'est parfait
    */