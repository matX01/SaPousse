#include "BN880Q.h"


bool GPSHandler::dataReady = false;




GPSHandler::GPSHandler(){




}

void GPSHandler::begin(){

    Serial5.begin(115200);

} 



namespace GPSHandling {
    
    char GPSSentence[20] = "";

}



void serialEvent5(){

    char ReadedChar = Serial5.read();
    
    switch(ReadedChar){
        case '\n':

        break;
        case '$' :

        break;
        
        default :




        break;




    }
    
    
    
}







