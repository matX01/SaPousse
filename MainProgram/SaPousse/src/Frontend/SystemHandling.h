#ifndef SystemHandlerClass
#define SystemHandlerClass

#include "Arduino.h"

#include "../MainLibraries/Debugger.h"
#include "../IOComms/SDCard.h"
#include "../GlobalPreProcessorValues.h"
#include "../IOComms/SPIElement.h"
#include "../MainLibraries/IMU9250.h"
#include "../UpperLayer/DataGathering.h"
#include "../MainLibraries/BN880Q.h"
#include "../MainLibraries/SBUS.h"



class SystemHandling{
    public :
    SystemHandling();
    static void CalibrateSensor(int SensorID);

    static void StartStabilisation();
    static void SetStabilisationLevel(uint8_t StabilisationLevel,uint8_t StabilisationPower);
    static void StartGathering();  
    static void StopGathering();
    static void RadioFailsafe(bool failsafeValue);







};

extern SystemHandling SystemHandler;



#endif