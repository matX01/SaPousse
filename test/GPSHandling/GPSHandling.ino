/*Copyright 2021 , Mathieu CUISSARD

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files of "SaPousse", to deal in the 
Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

this program is a test to understand how the ubx messages works

    -it contains a retro engeenering tool that allows to record ubx messages send to the gps by the u-center software on the computer
    -and a test message to pull data from the UBX-CFG-RATES register
    
    
enjoy :)


*/

#include "Arduino.h"

char Record[2000] = {0x00};
bool ReadToken = false;
int k = 0;
bool Rd = false;

//Token that allows reverse engeneering fonctionalities

#define DEBUG

    // ')' character displays the recorded bytes by the reverse engeneering system.
    // '=' reset the teensy (not the GPS)
    // '!' send the test message to the secondary port in byte that is written into the "List" array (and displays the list array in hex on the main serial port)



//char List[] = {0xB5,0x62,0x06,0x08,0x06,0x00,0xE8,0x03,0x02,0x00,0x01,0x00,0x00,0x00}; 
char List[] = {0xB5,0x62,0x06,0x08,0x00,0x00,0x00,0x00}; 


/*Messages sent by U-center while configuring the GPS Rates

    1000ms GPS sampling period
        B5 62 6 8 6 E8 3 2 2 3 3F B5 62 6 8 E 30 0 0 0 0 0 (There is an error into this line this is not the correct message)
    Pulling the sampling rate config
        B5 62 6 8 0 0 E 30 (this is a correct message)
    */

void setup(){
    
    //Checksum calculator implementation as shown into the ubx m8 documentation (refer to doc file in the root folder of the repo page 171 chapter 32.4)

    uint8_t CK_A = 0;
    uint8_t CK_B = 0;

    for(unsigned int i = 2;i < sizeof(List)-2; i ++){
        
        CK_A += (uint8_t)List[i];
        CK_B += CK_A;

    }

    //recording the checksum value at the end of the message
    List[sizeof(List)-1] = (char)CK_B;
    List[sizeof(List)-2] = (char)CK_A;

    //begin the serial ports
    Serial.begin(115200);                   //Main Serial port (connected to the Computer)
    Serial5.begin(115200);                  //Second Serial port (connected to the GPS)

}

void loop(){
#ifdef DEBUG
    //Displaying the recorded bytes sent to the main Serial port in hex
    while(ReadToken){
        
        Serial.print(Record);
        
        for(int i = 0;i < k; i ++){

            Serial.print(Record[i],HEX);
            Serial.print(" ");

        }
    
        Serial.println();
        
        delay(1000);

    }
#endif

}

//if data comes in the main serial port
void serialEvent(){

    char inChar = Serial.read();


 #ifdef DEBUG
    
    if(inChar == ')'){

        ReadToken = true;
    
    }
    else if(inChar == '='){

        SCB_AIRCR = 0x05FA0004;
    
    }
    else if(inChar == '!'){
        
        //send the List message on the secondary serial port and displays the List message in hex on the main serial port
        for(int i = 0;i < sizeof(List); i ++){
            
            Serial5.write(List[i]);
            
            Serial.print(List[i],HEX);
            Serial.print(" ");

        }
    
    Serial.println();
   

    }
    
    else if(inChar != 0x0A){
        
        //records the input data
        k ++;
        
        sprintf(Record,"%s%c",Record,inChar);

        //send the input to the gps as a simple bridge beetween the main and the secondary port
        Serial5.write(inChar);
    
    }
      
#endif
#ifndef DEBUG

    //send the input as a simple bridge beetween the main and the secondary port
    Serial5.write(inChar);

#endif

}

//if data comes in the secondary serial port
void serialEvent5(){

    char InByte = Serial5.read();

#ifdef DEBUG
    //if its an NMEA message , displays it as it comes
    
    if(InByte == '$'){

        Rd = true;

    }

    if(!ReadToken && Rd){
        
        //Serial.write(InByte);
    
    }

    if(!Rd){
        //and if it's not (so it's a UBX message) then displays it in hex on the main serial port
        Serial.print(InByte,HEX);
        Serial.print(" ");



    }

    if(InByte == '\n'){

        Rd = false;
        Serial.println("Readed ! ");
    }

#endif
#ifndef DEBUG
     //send the input as a simple bridge beetween the secondary and the main port
    Serial.write(InByte);

#endif

}


//U-center copy of packet console when a ubx config is sent to the gps
/*21:59:56  R -> NMEA GPGSV,  Size  64,  'GNSS Satellites in View'
21:59:56  R -> NMEA GPGSV,  Size  70,  'GNSS Satellites in View'
21:59:56  R -> NMEA GPGSV,  Size  57,  'GNSS Satellites in View'
21:59:56  R -> NMEA GLGSV,  Size  62,  'GNSS Satellites in View'
21:59:56  R -> NMEA GLGSV,  Size  66,  'GNSS Satellites in View'
21:59:56  R -> NMEA GLGSV,  Size  31,  'GNSS Satellites in View'
21:59:56  R -> NMEA GNGLL,  Size  52,  'Geographic Position - Latitude/Longitude'
21:59:56  R <- UBX CFG-RATE,  Size  14,  'Rates'
21:59:56  R <- UBX CFG,  Size   8,  'Config'
21:59:57  R -> NMEA GNRMC,  Size  68,  'Recommended Minimum Specific GNSS Data'
21:59:57  R -> NMEA GNVTG,  Size  35,  'Course Over Ground and Ground Speed'
21:59:57  R -> NMEA GNGGA,  Size  74,  'Global Positioning System Fix Data'
21:59:57  R -> NMEA GNGSA,  Size  52,  'GNSS DOP and Active Satellites'
21:59:57  R -> NMEA GNGSA,  Size  48,  'GNSS DOP and Active Satellites'
21:59:57  R -> NMEA GPGSV,  Size  64,  'GNSS Satellites in View'
21:59:57  R -> NMEA GPGSV,  Size  70,  'GNSS Satellites in View'
21:59:57  R -> NMEA GPGSV,  Size  57,  'GNSS Satellites in View'
21:59:57  R -> NMEA GLGSV,  Size  62,  'GNSS Satellites in View'
21:59:57  R -> NMEA GLGSV,  Size  66,  'GNSS Satellites in View'
21:59:57  R -> NMEA GLGSV,  Size  31,  'GNSS Satellites in View'
21:59:57  R -> NMEA GNGLL,  Size  52,  'Geographic Position - Latitude/Longitude'


                        21:59:57  R -> UBX ACK-ACK,  Size  10,  'Acknowledged'
                        21:59:57  R -> UBX CFG-RATE,  Size  14,  'Rates'
                        21:59:57  R -> UBX ACK-ACK,  Size  10,  'Acknowledged'


21:59:57  R -> NMEA GNRMC,  Size  68,  'Recommended Minimum Specific GNSS Data'
21:59:57  R -> NMEA GNVTG,  Size  35,  'Course Over Ground and Ground Speed'
21:59:57  R -> NMEA GNGGA,  Size  74,  'Global Positioning System Fix Data'
21:59:57  R -> NMEA GNGSA,  Size  52,  'GNSS DOP and Active Satellites'*/

