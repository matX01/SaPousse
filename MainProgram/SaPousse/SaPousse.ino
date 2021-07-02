
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
    //ScheduledGatherer.begin(50);
    
    
    GPSDev.begin();
    SBUSDev.begin(); 



    //SystemHandler.StartGathering();



}
Quaternion quat;
void loop() {
    DebugTool.actualise();
    
    /*if(IMUData::DataReady){
        
        Quaternion quat2 = {
            (IMUData::OutputFloat[4])*0.1f,
            1,
            0,
            0,
            
        };
        //Quaternion quat2=AddQaternion(quat,quat1);

        char charBuff[50] = "";
        sprintf(charBuff,"%i,%i,%i,\n",IMUData::OutputShort[0],IMUData::OutputShort[1],IMUData::OutputShort[2]);
        Serial.print(charBuff);






        delay(100);
        IMUData::DataReady = false;
    }*/
    

    
    
    
    
    
    
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
    IMUData::DataReady = true;

}



