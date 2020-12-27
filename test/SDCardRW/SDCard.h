#ifndef SDCardHandler
#define SDCardHandler

#include "GlobalVariables.h"

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

class SDCard {
    
    public :
        
        SDCard();
        static void begin(int SDCSPin);
        static void ReadFlightParameters();
        static void ReadCalibrationData();
        static void WriteCalibrationData();
        static void GetCalibrationPointer(uint8_t *VariablePointer,size_t Size);
        static FlightParameter* getParameters(int ParameterID);
    
    private :
        
        static void RecordParameter(int FPID,int X,int Y,float ValueToRecord);
        static int CSPin;
        static FlightParameter FP[NumberOfParametersLoaded];
        static SensorPointer SS[10];
        static int RecordPointerPosition;

        
};


extern SDCard SDCardReader; 

#endif