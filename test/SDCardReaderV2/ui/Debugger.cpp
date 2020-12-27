#include "Debugger.h"


boolean Debugger::DebuggingToolActivated;
uint8_t DisplayMenu;
uint8_t DisplayElement;
VariableLogger Variables[32];


void serialEvent(){
    
    while(Serial.available()){
        
        Serial.println(Serial.read());

    }

}

Debugger::Debugger(){



}

void Debugger::begin(bool DebuggingActivated){

    DebuggingToolActivated = DebuggingActivated;
    if(DebuggingActivated){
        while(!Serial);
        Serial.begin(115200);
        
        Serial.println("Y X Z");  
        //Serial.println("Serial port connected , Passing in debug mode");
        //Serial.println("\nDebugging Tool Loading\n\n===\n");
        
        //DisplayMainMenu();
    
    
    
    }

}

void Debugger::DisplayMainMenu(){
    
    
    Serial.print("=1 display Frequency\n=2 display variables\n=3 interrupt system\n===\n");


}

void Debugger::Display(char DisplayedText[]){
  


}

void Debugger::AddVariableLog(int* VariablePos,char DisplayName){
    


}

void Debugger::DisplayError(uint8_t ErrorID){

    Serial.print("\n\n########## Error : An Error Has Occurred ErrorID : ");
    Serial.println(ErrorID,HEX);

}

