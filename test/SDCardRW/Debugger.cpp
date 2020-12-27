#include "Debugger.h"


boolean Debugger::DebuggingToolActivated;
uint8_t DisplayMenu;
uint8_t DisplayElement;
VariableLogger Variables[1];
int MenuID = 0;
char buffer[3] = "";
void serialEvent(){
    
    while(Serial.available()){
        char ReadedChar = Serial.read();

        if(ReadedChar == '\n'){
            if(MenuID <= 0){

                MenuID = atof(buffer);

            }
            else{
                
                MenuID = (MenuID*10)+atof(buffer);
            
            }

            strcpy(buffer,"");

            DebugTool.DisplayMenu();
             
        }
        else{

        sprintf(buffer,"%s%c",buffer,ReadedChar);

        }
        

    }

}

Debugger::Debugger(){



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
       
            Display("=1 MPU9250\n= BN880Q\n=3 XM+ \n=4 PITOT Probe\n=5 Telemetry Emitter");
        
        break;
        case 11:
            
            Display("=1 Calibration values\n2= Calibrate\n3= Raw values\n4= calibrate");

        break;
        case 111:


        break;
        case 112:

        break;
        case 113:

        break;
        case 114:

        break;





        case 2:

            
        break;
        case 3:

        break;

        case 4:

        break;
        case 5:

        break;
        default:
            MenuID = 0;
            Display("=1 Peripheral Management\n=2 display variables\n=3 interrupt system\n=4 Display Frequency");

        break;
    
    
    }
    Serial.print("\n=====\n");

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

