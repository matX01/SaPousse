#ifndef GPSHANDLER
#define GPSHANDLER

#include "Arduino.h"


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