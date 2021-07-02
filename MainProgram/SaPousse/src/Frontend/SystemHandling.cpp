#include "SystemHandling.h"



SystemHandling::SystemHandling(){



}




void SystemHandling::CalibrateSensor(int SensorID){

    switch (SensorID){
    case 0 :
        DebugTool.Display("Calibrating Accel\n");
        MPU9250.calibrateSensor(ACCEL,NumberOfIterationForCalibration);
    break;
    case 1 :
        DebugTool.Display("Calibrating Temperature\n");
        MPU9250.calibrateSensor(TEMP,NumberOfIterationForCalibration);
    break;
    case 2 :
        DebugTool.Display("Calibrating Gyroscope\n");
        MPU9250.calibrateSensor(GYRO,NumberOfIterationForCalibration);
    break;
    case 3 :
        DebugTool.Display("Calibrating Compass\n");
        MPU9250.calibrateSensor(COMPAS,NumberOfIterationForCalibration);
    break;
    case 4 :
        DebugTool.Display("Calibrating all\n");
        MPU9250.calibrateSensor(ALL,NumberOfIterationForCalibration);
    break;
    

    }
}

void SystemHandling::StartStabilisation(){
    
    ScheduledGatherer.Scheduling(true);

}

void SystemHandling::SetStabilisationLevel(uint8_t SetStabilisationLevel,uint8_t StabilisationPower){



}
void SystemHandling::StartGathering(){

    ScheduledGatherer.Scheduling(true);

}
void SystemHandling::StopGathering(){

    ScheduledGatherer.Scheduling(false);

}

void SystemHandling::RadioFailsafe(bool failsafeValue){

    if(failsafeValue){

        ExceptionHandler.Error(0x0C,FAILSAFE);
         
    }

}