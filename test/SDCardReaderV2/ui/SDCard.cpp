#include "SDCard.h"


int SDCard::CSPin;
FlightParameter SDCard::FP[];



SDCard::SDCard(){

}

void SDCard::begin(int SDCSPin){
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

void SDCard::ReadCalibrationsData(){


    
}


void SDCard::ReadFlightParameters(){    // 7% de mémoire consomé ici.

    File FlightParameterFile = SD.open(FlightParametersDirectory,FILE_READ);
    if(FlightParameterFile){
        



        while(FlightParameterFile.available()){

            char ReadedChar = FlightParameterFile.read();












        }
        
        
    }
    else{

        ExceptionHandler.Error(0x02,INITERROR);


    }
        
        
        
        
        
        
        
        /*bool PassLine = false;
        int ParameterReaded = 0;
        
        int ParameterCoordinate[2] = {0,0};
        int ArraySize[2] = {1,1};
        char CharBuffer[ParameterCharSize] = "";
        char LineBuffer[LineSize] = "";
        bool FirstLine = true;
        while(FlightParameterFile.available()){
            
            char ReadedCharacter = FlightParameterFile.read();
            //Serial.print(ReadedCharacter);
            /*if(ReadedCharacter == '#'){

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

    }*/

}



FlightParameter* SDCard::getParameters(int ParameterID){
 
return &FP[ParameterID];

}