
#include "BN880Q.h"



void setup(){
    
    Serial.begin(115200);
    GPSDev.begin();


    

}

void loop(){

    
    Serial.println(({1,2,3,4,5})[3]);


}