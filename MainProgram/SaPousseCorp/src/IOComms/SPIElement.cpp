#include "SPIElement.h"




SPIDev::SPIDev(){


}

void SPIDev::SPIInitParam(uint8_t CSPinForModule,uint8_t SpiUsedForTheCommunication,SPISettings SettingsForSPIComm){
    
    DeviceBusSettings = SettingsForSPIComm;
    CSPin = CSPinForModule;
    UseSpiNumber = SpiUsedForTheCommunication;
    
}

void SPIDev::begin(){
    
    pinMode(CSPin,OUTPUT);
    digitalWrite(CSPin,HIGH);
    
    if(UseSpiNumber > GeneralSPIConfiguration.NumberOfDefinedSPI){
       Serial.println(GeneralSPIConfiguration.NumberOfDefinedSPI);
        ExceptionHandler.Error(0x08,INITERROR);

    }

}

void SPIDev::beginTransaction(){
    if(UseSpiNumber == 1){

        SPI.beginTransaction(DeviceBusSettings);

    }
    else if(UseSpiNumber == 2){

        SPI1.beginTransaction(DeviceBusSettings);

    }
    else {

        SPI2.beginTransaction(DeviceBusSettings);

    }
    digitalWrite(CSPin,LOW);
}

void SPIDev::endTransaction(){
    digitalWrite(CSPin,HIGH);

    if(UseSpiNumber == 1){

        SPI.endTransaction();
      
    }
    else if(UseSpiNumber == 2){

        SPI1.endTransaction();

    }
    else{

           SPI2.endTransaction();

    }

    DummyRead = false;

}
uint8_t SPIDev::getRegister(uint8_t RegisterToRead){
 
    if(!DummyRead){

        DummyRead = true;

        if(UseSpiNumber == 1){

            SPI.transfer(RegisterToRead | READ_TOKEN);
                
           return SPI.transfer(0x00);
        
        }
        else if(UseSpiNumber == 2){

            SPI1.transfer(RegisterToRead | READ_TOKEN);
            
            return SPI1.transfer(0x00);

        }
        else {
                
            SPI2.transfer(RegisterToRead | READ_TOKEN);
            
            return SPI2.transfer(0x00);

        }
    }
    else{
        if(UseSpiNumber == 1){

            return SPI.transfer(0x00);

        }
        else if(UseSpiNumber == 2){

            return SPI1.transfer(0x00);

        }
        else{

            return SPI2.transfer(0x00);

        }

    }

}
void SPIDev::setRegister(uint8_t Register,uint8_t Message){
    if(UseSpiNumber == 1){

        SPI.transfer(Register);
        SPI.transfer(Message);
        
    }
    else if(UseSpiNumber == 2){

        SPI1.transfer(Register);
        SPI1.transfer(Message);

    }
    else {
              
        SPI2.transfer(Register);
        SPI2.transfer(Message);

    }
}

int GeneralSPI::NumberOfDefinedSPI = 0;

void GeneralSPI::beginAllSPI(int NumberOfUsedSPI){

    NumberOfDefinedSPI = NumberOfUsedSPI;

    for(int i = 1;i < NumberOfUsedSPI;i ++){

        switch (i){
        case 1:
          
            SPI.begin();

            SPI.setMISO(MISOPIN_SPI0);
            SPI.setMOSI(MOSIPIN_SPI0);
            SPI.setSCK(SCKPIN_SPI0);

            break;
        case 2:
          
            SPI1.begin();

            SPI1.setMISO(MISOPIN_SPI1);
            SPI1.setMOSI(MOSIPIN_SPI1);
            SPI1.setSCK(SCKPIN_SPI1);

            break;
        case 3:
          
            SPI2.begin();

            SPI2.setMISO(MISOPIN_SPI2);
            SPI2.setMOSI(MOSIPIN_SPI2);
            SPI2.setSCK(SCKPIN_SPI2);

            break;
        default:

            ExceptionHandler.Error(0x07,INITERROR);

        break;
        
        }

    }
    
}

