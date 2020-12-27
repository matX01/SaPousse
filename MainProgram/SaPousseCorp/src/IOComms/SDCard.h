#ifndef SDCardHandler
#define SDCardHandler

#include "../GlobalVariables.h"

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
        static FlightParameter* getParameters(int ParameterID);
        static void SetCalibrationPointer(uint8_t *VariablePointer,size_t Size);
    private :
        
        static void RecordParameter(int FPID,int X,int Y,float ValueToRecord);
        static int CSPin;
        static FlightParameter FP[NumberOfParametersLoaded];
        static SensorPointer SS[10];
        static int RecordPointerPosition;
        
};


extern SDCard SDCardReader; 

#endif