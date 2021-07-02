#ifndef GPSHANDLER
#define GPSHANDLER

#include "Arduino.h"
#include "../GlobalPreProcessorValues.h"
#include "Debugger.h"



class GPSHandler {
    
    public : 
    GPSHandler();
    static void begin();
    static void ProcessGPS();
    static GPSOut* GetValues();
    
    private :
    static GPSOut GPSReading;




};

extern GPSHandler GPSDev;




namespace GPSHandling{


    extern char GPSSentence[80];


}





#endif