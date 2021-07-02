#ifndef SDCardHandler
#define SDCardHandler

#include "GlobalPreProcessorValuessorValues.h"

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

class SDCard {
    
    public :
        
        SDCard();
        static void begin(int SDCSPin);
        static void ReadFlightParameters();
        static void ReadCalibrationData();
        static FlightParameter* getParameters(int ParameterID);
    
    private :
        
        static void RecordParameter(int FPID,int X,int Y,float ValueToRecord);
        static int CSPin;
        static float b;
        static FlightParameter FP[NumberOfParametersLoaded];
        static

};


extern SDCard SDCardReader;

#endif