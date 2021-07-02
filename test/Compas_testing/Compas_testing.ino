
#include "Debugger.h"
#include "GlobalPreProcessorValues.h"
#include "IMU9250.h"

short maxV[] = {-32765,-32765,-32765};
short minV[] = {32765,32765,32765};
short maxV2[] = {-32765,-32765,-32765};
short minV2[] = {32765,32765,32765};
//short value[] = {-383,-444,285};
//short value[] = {-271,-401,219};
short value[] = {0,0,0};
float coef[] = {1,1,1};
float hah[3];
void setup() {
  pinMode(23,OUTPUT);
  GeneralSPIConfiguration.beginAllSPI(3);
  MPU9250.SetBus(1,10);
  MPU9250.begin();
  //calibration();


}
float xFlat;
float yFlat;
float hding;


void loop() {

  MPU9250.readSensor();

  DataStructure dtr = *MPU9250.GetValues();

  dtr.OutputShort[0] = (dtr.OutputShort[0]+value[0])*coef[0];
  dtr.OutputShort[1] = (dtr.OutputShort[1]+value[1])*coef[1];
  dtr.OutputShort[2] = (dtr.OutputShort[2]+value[2])*coef[2];
  /*hah[0] = (atan(((float)dtr.OutputShort[0])/((float)dtr.OutputShort[2]))*180.0/PI);
  hah[1] = (atan(((float)dtr.OutputShort[1])/((float)dtr.OutputShort[2]))*180.0/PI);
  hah[2] = (atan(((float)dtr.OutputShort[0])/((float)dtr.OutputShort[1]))*180.0/PI);*/
  
  hah[0] = (atan2((float)dtr.OutputShort[0],(float)dtr.OutputShort[2])*180.0/PI);
  hah[1] = (atan2((float)dtr.OutputShort[1],(float)dtr.OutputShort[2])*180.0/PI);
  hah[2] = (atan2((float)dtr.OutputShort[0],(float)dtr.OutputShort[1])*180.0/PI);
  /*xFlat = (((float)dtr.OutputShort[2]+value[2])/(cos(hah[0])));
  yFlat = (((float)dtr.OutputShort[2]+value[2])/(cos(hah[1])));
  hding = (atan((xFlat)/(yFlat))*180.0/PI);*/
  //Serial.println(hding);
  for(int i = 0;i < 3;i ++){
    
    /*if(i == 0){
      Serial.print(xFlat);
      Serial.print(",");
      continue;
    } 
       if(i == 1){
      Serial.print(yFlat);
      Serial.print(",");
      continue;
    } */
      /*if(dtr.OutputShort[i] > maxV2[i]){
        maxV2[i] = dtr.OutputShort[i];
        Disp();
      }
      if(dtr.OutputShort[i] < minV2[i]){
        minV2[i] = dtr.OutputShort[i];
        Disp();
      }*/
    Serial.print(dtr.OutputShort[i]);
    //Serial.print(hah[i]);
    Serial.print(",");
   
  }
  Serial.println();
delay(13);
if(digitalRead(23)){
  for(int i = 0;i < 3;i ++){
    maxV2[i] = -32765;
    minV2[i] = 32765;


  }
  Serial.println("\n reset");


}
}

void Disp(){
  Serial.print("\n\n max : ");
  for(int i = 0;i < 3;i ++){
    Serial.print(maxV2[i]);
    Serial.print(" ");
  }
    Serial.print("\n min : ");
  for(int i = 0;i < 3;i ++){
    Serial.print(minV2[i]);
    Serial.print(" ");
  }



}

void calibration(){
  unsigned long stopTime = millis() + 90 * 1000;

    delay(1000);
  while(millis() < stopTime){
  MPU9250.readSensor();
  DataStructure dtr = *MPU9250.GetValues();
  for(int i = 0;i < 3;i ++){
      if(dtr.OutputShort[i] > maxV[i]){
        maxV[i] = dtr.OutputShort[i];
      }
      if(dtr.OutputShort[i] < minV[i]){
        minV[i] = dtr.OutputShort[i];
      }







  
    
    Serial.print(dtr.OutputShort[i]);
    Serial.print(",");
   
  }
  Serial.println();
  delay(100);
  }
  maxV[0] = 427;
  maxV[1] = 651;
  maxV[2] = -29;
  
  minV[0] = -68;
  minV[1] = 146;
  minV[2] = -490;


/*
 max : 427 651 -29 
 min : -68 146 -490 
 offset : -179 -398 259 

486.00
 coef : 0.98 0.96 1.05 

*/
  Serial.print(" max : ");
  for(int i = 0;i < 3; i ++){
    Serial.print(maxV[i]);
    Serial.print(" ");
    


  }
  Serial.print("\n min : ");
  for(int i = 0;i < 3; i ++){

    
    
    Serial.print(minV[i]);
    Serial.print(" ");
    


  }
  Serial.print("\n offset : ");
  float moyenne = 0;
    for(int i = 0;i < 3; i ++){
        value[i] = (-((maxV[i]+minV[i])/2));
        moyenne += (float)(abs(maxV[i]-minV[i])/3);

    
    Serial.print(value[i]);
    Serial.print(" ");
    


  }
  Serial.println();
  Serial.print(moyenne);
  Serial.print("\n coef : ");
  for(int i = 0;i < 3;i ++){
    coef[i] = moyenne/(float)abs(maxV[i]-minV[i]);

    Serial.print(coef[i]);
  
    Serial.print(" ");

  }
  
  Serial.println("\n");
}
