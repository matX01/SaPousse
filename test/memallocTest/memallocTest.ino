#include "Arduino.h"



struct GPSSat {
    char Name;
    float heading;





};
int Menu = 0;

GPSSat* GPSSatArray;








int VariablesNumber = 0;
int* Test = NULL;

int i,j;
int* b = &i;


void setup(){

    Serial.begin(115200);
    i = 2;
    j = 8;


}


char CharBuffer[30] = "";
void loop(){

if(Serial.available() > 0){
    char ReadedCharacter = Serial.read();


    switch(ReadedCharacter){
        case '\n':
        Serial.println(CharBuffer);
            switch(Menu){
                case 1:
                    VariablesNumber ++;
                    Test = (int*) realloc(Test,VariablesNumber*sizeof(int));
                    Test[VariablesNumber-1] = (int)atof(CharBuffer);
                    Serial.println(*(Test+VariablesNumber-1));
                break;
                case 2:

                    for(int i = 0; i < 10;i ++){

                        Serial.print(" Variable Pos = ");
                        Serial.print(i);
                        Serial.print(" Value Number = ");
                        Serial.println(Test[i]);


                    }


                break;
                case 3:
                    free(Test);
                    Test = NULL;
                    VariablesNumber = 0;
        



                break;





            }
            Menu = 0;
            strcpy(CharBuffer,"");
            Serial.println("WEDIDIT");
            
        break;
        case 'A':
          
            Serial.print(" ADD VALUE = ");
            Menu = 1;

        break;
        case 'R':
          
            Serial.print("READ VALUE = ");
            Menu = 2;

        break;
        case 'D':
            
            Serial.print("REMOVE VALUE = ");
            Menu = 3;

        break;
        default:
            
            sprintf(CharBuffer,"%s%c",CharBuffer,ReadedCharacter);
            
        break;

    }


}





}
