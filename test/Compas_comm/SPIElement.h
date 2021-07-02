#ifndef SPIHandler
#define SPIHandler

#include <SPI.h>
#include <Arduino.h>
#include "GlobalPreProcessorValues.h"


#define MISOPIN_SPI0 12
#define MOSIPIN_SPI0 11
#define SCKPIN_SPI0 13

#define MISOPIN_SPI1 1
#define MOSIPIN_SPI1 26
#define SCKPIN_SPI1 27

#define MISOPIN_SPI2 14
#define MOSIPIN_SPI2 2
#define SCKPIN_SPI2 3

#define READ_TOKEN 0x80

class SPIDev {
   
    uint8_t UseSpiNumber;
    uint8_t CSPin;
    bool DummyRead = false;
    SPISettings DeviceBusSettings;
    
    public :
    SPIDev();
    void SPIInitParam(uint8_t CSPinForModule,uint8_t SpiUsedForTheCommunication,SPISettings SettingsForSPIComm);
    void begin();
    void beginTransaction();
    void endTransaction();
    uint8_t getRegister(uint8_t RegisterToRead);
    void setRegister(uint8_t Register,uint8_t Message);
    
    
    

};


class GeneralSPI{
    public :

    static void beginAllSPI(int NumberOfUsedSPI);
    static int NumberOfDefinedSPI;

};

extern GeneralSPI GeneralSPIConfiguration;

#endif