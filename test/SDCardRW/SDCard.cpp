#include "SDCard.h"


int SDCard::CSPin;
FlightParameter SDCard::FP[];
SensorPointer SDCard::SS[10];
int SDCard::RecordPointerPosition = 0;
SDCard::SDCard(){

}

void SDCard::begin(int SDCSPin){
    SS[0].SizeOfElement = sizeof(ui);
    SS[0].VariablePointer = (uint8_t * )&ui;
    CSPin = SDCSPin;
    pinMode(CSPin,OUTPUT);
    
    if(!SD.begin(CSPin)){

        ExceptionHandler.Error(0x01,INITERROR);

    }
    for(int i = 0;i < NumberOfParametersLoaded;i ++){
        for(int j = 0;j < ParameterListY;j ++){
            for(int k = 0; k < ParameterListX;k ++){

                FP[i].FlightParam[j][k] = 255;

            }

        }

    }



    
}

void SDCard::ReadCalibrationData(){
    File CalibrationData = SD.open(CalibrationDataFile,FILE_READ);

    if(CalibrationData){
        
        for(int i = 0;i < RecordPointerPosition;i ++){

            CalibrationData.read(SS[i].VariablePointer,SS[i].SizeOfElement);

        }

    }

}
void SDCard::WriteCalibrationData(){

    SD.remove(CalibrationDataFile);
    ExceptionHandler.Display("SDCard : Saving ...\n");
    File CalibrationData = SD.open(CalibrationDataFile,FILE_WRITE);
    
    if(CalibrationData){

        for(int i = 0;i < RecordPointerPosition;i ++){

            CalibrationData.write((const uint8_t *)SS[i].VariablePointer,SS[i].SizeOfElement);

        }

        ExceptionHandler.Display("SDCard : Saved\n");
    
    }

}


void SDCard::GetCalibrationPointer(uint8_t *VariablePointer,size_t Size){
    if(RecordPointerPosition >)

    SS[RecordPointerPosition].SizeOfElement = Size;
    SS[RecordPointerPosition].VariablePointer = VariablePointer;
    RecordPointerPosition ++;


}

void SDCard::ReadFlightParameters(){    // 7% de mémoire consomé ici.

    File FlightParameterFile = SD.open(FlightParametersDirectory,FILE_READ);
    if(FlightParameterFile){
        bool PassLine = false;
        int ParameterReaded = 0;
        
        int ParameterCoordinate[2] = {0,0};
        char CharBuffer[ParameterCharSize] = "";

        while(FlightParameterFile.available()){
            
            char ReadedCharacter = FlightParameterFile.read();
            
            if(ReadedCharacter == '#'){

                PassLine = true;
                continue;
            }
            else if(ReadedCharacter == '\r'){

                continue;

            }
            else if(ReadedCharacter == '\n'){
                
                if(!PassLine){
                
                    FP[ParameterReaded].FlightParam[ParameterCoordinate[1]][ParameterCoordinate[0]] = atof(CharBuffer);
                
                

                    strcpy(CharBuffer,"");

                    
                    ParameterReaded ++;
                    ParameterCoordinate[0] = 0;
                    ParameterCoordinate[1] = 0;
                }

                PassLine = false;
              
                continue;
            }
            else if(!PassLine){
               
                if(ReadedCharacter == ','){

                    FP[ParameterReaded].FlightParam[ParameterCoordinate[1]][ParameterCoordinate[0]] = atof(CharBuffer);
                    
                    
                    strcpy(CharBuffer,"");

                    ParameterCoordinate[0] ++;
                    if(ParameterCoordinate[0] >= ParameterListX){

                        ExceptionHandler.Error(0x03,INITERROR);
                        
                    }
                    continue;

                }
                else if(ReadedCharacter == '/'){
                   
                    FP[ParameterReaded].FlightParam[ParameterCoordinate[1]][ParameterCoordinate[0]] = atof(CharBuffer);

                    strcpy(CharBuffer,"");

                    ParameterCoordinate[1] ++;
                    ParameterCoordinate[0] = 0;
                    if(ParameterCoordinate[1] >= ParameterListY){

                        ExceptionHandler.Error(0x03,INITERROR);

                    }
                    continue;

                }
                else{
                  
                    sprintf(CharBuffer,"%s%c",CharBuffer,ReadedCharacter);
                    
                }
           
            }
       
        }
        FlightParameterFile.close();

    }
    else{

        ExceptionHandler.Error(0x02,INITERROR);

    }

}


FlightParameter* SDCard::getParameters(int ParameterID){
 
return &FP[ParameterID];

}