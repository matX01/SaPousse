  #include "GlobalPreProcessorValues.h"

int GlobalExceptionHandler::ExceptionCount = 0;
unsigned long GlobalExceptionHandler::LastExceptionCountTime =0;

GlobalExceptionHandler::GlobalExceptionHandler(){

}

void GlobalExceptionHandler::begin(){
    
    pinMode(13,OUTPUT);
    digitalWrite(13,LOW);

}

void GlobalExceptionHandler::Error(uint8_t ExceptionID,ErrorType Err){
    
    switch(Err.ErrorTypeID){
        case 0:
            DebugTool.DisplayError(ExceptionID);
             while(true){
                
                digitalWrite(13,HIGH);
                delay(100);
                digitalWrite(13,LOW);
                delay(100);
    
            }

        break;
        case 1:

            DebugTool.DisplayError(ExceptionID);
             while(true){
                
                digitalWrite(13,HIGH);
                delay(100);
                digitalWrite(13,LOW);
                delay(100);
    
            }

        break;




        case 2:



        break;
        case 3:




        break;
        case 4:
           

            if(LastExceptionCountTime+TimeUnitForExceptionTimeOut < millis()){
                
                ExceptionCount = 0;

            } 
            else if(ExceptionCount >= numberOfCumulatedExceptionInDefinedTimeOut){

                Error(0x05,FATALERROR);
             }

            LastExceptionCountTime = millis();
            ExceptionCount++;

            break;
    }

    DebugTool.DisplayError(ExceptionID);
    
   

}






