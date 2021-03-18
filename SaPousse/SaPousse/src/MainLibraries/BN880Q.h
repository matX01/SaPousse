#ifndef GPSHANDLER
#define GPSHANDLER

#include "Arduino.h"
#include "../GlobalVariables.h"
#include "Debugger.h"


class GPSHandler {
    
    public :
    GPSHandler();
    static void begin();
    static void ProcessGPS();
    static bool dataReady;
    private :
    




};

extern GPSHandler GPSDev;

#endif