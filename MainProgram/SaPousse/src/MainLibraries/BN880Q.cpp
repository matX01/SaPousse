#include "BN880Q.h"


GPSOut GPSHandler::GPSReading;


namespace GPSHandling {

    char GPSSentence[80] = "";


}



GPSHandler::GPSHandler(){




}

void GPSHandler::begin(){

    Serial5.begin(115200);

} 
GPSOut* GPSHandler::GetValues(){

    return &GPSReading;

}

void serialEvent5(){

    char ReadedChar = Serial5.read();
    

    switch(ReadedChar){
        case '\n':

            (*GPSDev.GetValues()).DataReady = true;
            
        break;
        case '$' :
            
            strcpy(GPSHandling::GPSSentence,"");

        break;
        
        default :

            sprintf(GPSHandling::GPSSentence,"%s%c",GPSHandling::GPSSentence,ReadedChar);


        break;




    }
    
    
    
}







