#include "Debugger.h"

#include "IMU9250.h"
#include "../GlobalVariables.h"
#include "../Frontend/SystemHandling.h"

bool Debugger::DebuggingToolActivated;
bool Debugger::DisplayerToken[3];
uint8_t DisplayMenu;
uint8_t DisplayElement;
VariableLogger Variables[1];
int MenuID = 0;
char buffer[3] = "";
void serialEvent(){
    
    //while(Serial.available()){
        char ReadedChar = Serial.read();
        Serial.print(ReadedChar);
        if(ReadedChar == '\n'){
            if(MenuID <= 0){

                MenuID = atof(buffer);

            }
            else{
                
                MenuID = (MenuID*10)+atof(buffer);
            
            }

            strcpy(buffer,"");
            Serial.println(MenuID);
            DebugTool.DisplayMenu();
             
        }
        else{

        sprintf(buffer,"%s%c",buffer,ReadedChar);

        }
        

    //}

}

Debugger::Debugger(){



}

void Debugger::GoBack(bool BackTwoMenu){

    if(BackTwoMenu){

        MenuID = MenuID/100;

    }
    else{
        
        MenuID = MenuID/10;
        
    }
    DisplayMenu();

}

void Debugger::begin(bool DebuggingActivated){

    DebuggingToolActivated = DebuggingActivated;
    if(DebuggingActivated){
        while(!Serial);
        Serial.begin(115200);
         
        Serial.println("Serial port connected , Passing in debug mode");
        Serial.println("\nDebugging Tool Loading\n");
        
        DisplayMenu();
    
    
    
    }

}

void Debugger::DisplayMenu(){
    Serial.print("\n=====\n");
    
    switch(MenuID){
        case 1:
       
            Display("=1 MPU9250\n=2 BN880Q\n=3 XM+ \n=4 PITOT Probe\n=5 Telemetry Emitter");
        
        break;
        case 11:
            
            Display("=1 Calibration values\n2= Calibrate\n3= Save values\n");

        break;
        case 111:
            Display("=Global : ");
            Display(MPU9250.GetCalibrationValue(ALL));
            Display("\n=Gyroscope : ");
            Display(MPU9250.GetCalibrationValue(GYRO));
            Display("\n=Temperature : ");
            Display(MPU9250.GetCalibrationValue(TEMP));
            Display("\n=Accelerometer : ");
            Display(MPU9250.GetCalibrationValue(ACCEL));
            Display("\n=COMPASS : ");
            Display(MPU9250.GetCalibrationValue(COMPAS));
            
            GoBack();
        
        break;
        case 112:

            Display("=1 Accelerometer\n=2 Temperature\n=3 Gyroscope\n=4 Compass\n=5 ALL");

        break;
        case 1121:
            
            SystemHandler.CalibrateSensor(0);
           
            GoBack(true);

        break;
        case 1122:
            
            SystemHandler.CalibrateSensor(1);
            
            GoBack(true);

        break;
        case 1123:
            
            SystemHandler.CalibrateSensor(2);
            
            GoBack(true);
        
        break;
        case 1124:
            
            SystemHandler.CalibrateSensor(3);
            
            GoBack(true);
        
        break;
        case 1125:
            
            SystemHandler.CalibrateSensor(4);
            
            GoBack(true);
        
        break;
        case 113:
            
            SDCardReader.WriteCalibrationData();
            GoBack();
        
        break;

        case 13:
        
            Display("FailsafeToken : ");
            Display(SBUSDev.getFailsafeValue());
            GoBack(true);
        
        break;
        case 131:

        break;
        
        case 2:

            Display("1= Display Raw MPU Data\n2= Display Raw Radio Channel Value");
            
        break;
        case 21:

            DisplayerToken[0] = !DisplayerToken[0];
            GoBack();

        break;
        case 22:

            DisplayerToken[1] = !DisplayerToken[1];
            GoBack();

        break;

        case 5:
            Display("=1 Start Gathering\n=2 Stop Gathering\n=3 Reset Board");
        break;
        case 51:
            SystemHandler.StartGathering();
            GoBack();
        break;
        case 52:
            SystemHandler.StopGathering();
            GoBack();

        break;
        case 53:
            
            SCB_AIRCR = 0x05FA0004;
        
        break;
        default:
            MenuID = 0;
            Display("=1 Peripheral Management\n=2 display variables\n=3 interrupt system\n=4 Display Frequency\n=5 System Control\n");

        break;
    
    
    }

}

void Debugger::Display(String DisplayedText){
  
    if(DebuggingToolActivated){

        Serial.print(DisplayedText);

    }

}

void Debugger::AddVariableLog(int* VariablePos,char DisplayName){
    


}

void Debugger::DisplayError(uint8_t ErrorID){

    Display("\n\n########## Error : An Error Has Occurred ErrorID : ");
    Display(ErrorID);

}

void Debugger::actualise(){
    
    if(DebuggingToolActivated){
    
        if(DisplayerToken[0]){
    
            if((*MPU9250.GetPointerOfVariable()).DataReady){
                
                for(int i = 0;i < 10;i ++){

                    Serial.print((*MPU9250.GetPointerOfVariable()).OutputFloat[i]);
                    Serial.print(",");


                }
                Serial.println();
                
                (*MPU9250.GetPointerOfVariable()).DataReady = false;

            }

        }
        if(DisplayerToken[1]){
            if((*SBUSDev.GetRadioChannel()).DataReady){

                 for(int i = 0;i < 16;i ++){
                    
                    Serial.print((*SBUSDev.GetRadioChannel()).Channel[i]);
                    Serial.print(" ");


                }
                Serial.println();

                (*SBUSDev.GetRadioChannel()).DataReady = false;
            
            }
  
        }

    }

}