
#include "src/Frontend/SystemHandling.h"

volatile bool DataAvailable = false;


ScheduledGatheringObject AccelGathering;
ScheduledGatheringObject CompasGathering;



void setup() {
    
    DebugTool.begin(true);
    ExceptionHandler.begin();
	
    GeneralSPIConfiguration.beginAllSPI(3);
    
    MPU9250.SetBus(1,10);
    
    SDCardReader.begin(BUILTIN_SDCARD);
    SDCardReader.ReadFlightParameters();
    SDCardReader.ReadCalibrationData();

    AccelGathering.begin((uint8_t)(*SDCardReader.getParameters(0)).FlightParam[0][1]);
    CompasGathering.begin((uint8_t)(*SDCardReader.getParameters(0)).FlightParam[0][2]);    

    MPU9250.begin(SDCardReader.getParameters(1),SDCardReader.getParameters(2));

    

    ScheduledGatherer.begin(SDCardReader.getParameters(0));
    
    
    GPSDev.begin();
    SBUSDev.begin(); 



    //SystemHandler.StartGathering();



}
unsigned long i = 0;
int k = 0;
float PitchAxisCos = 0;
float PitchAxisSin = 0;
float RollAxis = 0;
Quaternion Quat = {0,0,0,0};
void loop() {
    DebugTool.actualise();
    /*if(micros() >= i){
        i = i + 1000000;
        Serial.println(k);
        k = 0;

    }
    k ++;
    /*if((*MPU9250.GetPointerOfVariable()).DataReady){
         
        Quaternion Quat1 = {0,((float)(*MPU9250.GetPointerOfVariable()).OutputFloat[4]*(float)PI/180)*0.01f,((float)(*MPU9250.GetPointerOfVariable()).OutputFloat[5]*(float)PI/180)*0.01f,((float)(*MPU9250.GetPointerOfVariable()).OutputFloat[6]*(float)PI/180)*0.01f};
        Quaternion Quat = AddQaternion(Quat,Quat1);
            
            
            
            Serial.print(Quat.r,8);
            Serial.print(",");
            Serial.print(Quat.i,8);
            Serial.print(",");
            Serial.print(Quat.j,8);
            Serial.print(",");
            Serial.println(Quat.k,8);


        





        delay(10);
        (*MPU9250.GetPointerOfVariable()).DataReady = false;
    }
    
    //delay(1);
    
    
    
    
    
    
    /*unsigned long time = micros();
    if(i <= time){

        i = time+ 1000000;
        Serial.println(k);
        k = 0;

    }

    k++;
    */
}








void ScheduledGathering(){
    
    //if(!(*MPU0250.GetPointerOfVariable()).DataReady) ExceptionHandler.Error(0x08,SAMPLINGERROR);

    SensorGatParam StartParam = GYRO;
    SensorGatParam StopParam = GYRO;
   
    if(AccelGathering.IsExecuted()){

        StartParam = ACCEL;
  

    }

    if(CompasGathering.IsExecuted()){
        StopParam = COMPAS;
    
    }
 

    MPU9250.readSensor(MergeSensor(StartParam,StopParam));
    (*MPU9250.GetPointerOfVariable()).DataReady = true;

}



