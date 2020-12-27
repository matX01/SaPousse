#include "Arduino.h"

char Record[2000] = {0x00};
bool ReadToken = false;
int k = 0;

//char List[9] = {0xB5,0x62,0x06,0x08,0x0E,0x30,0x0A,0x00,0x00};//0x56,0xD2};
char List[] = {0xB5,0x62,0x06,0x8,0x06,0x03,0x02,0x02,0x00,0x00}; // Checksum
//{0xB5,0x62,0x06,0x08,0x06,0xE8,0x03,0x02,0x02,0x03,0x3F,0xB5,0x62,0x06,0x08,0x0E,0x30,0x0A};//,0x00,0x00,0x00,0x00,0x00};

#define DEBUG
//B5 62 6 8 6 E8 3 2 2 3 3F B5 62 6 8 E 30 A 0 0 0 0 0

//B5 62 6 8 6 E8 3 2 2 3 3F B5 62 6 8 E 30 A 0 0 0 0 0 �b�?�b0



//B5 62 6 8 E 30 A 0 0 
//CheckSum : 63 A4
//B5 62 6 32 38 AE A 
//B5 62 6 8 E 30

void setup(){
    
    uint8_t CK_A = 0;
    uint8_t CK_B = 0;
    //Serial.println(sizeof(List)-2);
    for(int i = 2;i < sizeof(List)-2; i ++){
        CK_A += (uint8_t)List[i];
        CK_B += CK_A;
        /*CK_A = CK_A & 0xFF;
        CK_B = CK_B & 0xFF;*/
    }
    //CK_B += ;
    List[sizeof(List)-1] = (char)CK_B;
    List[sizeof(List)-2] = (char)CK_A;

    Serial.begin(115200);
    Serial5.begin(115200);
    
    delay(1000);
    
    //Serial5.print("!UBX CFG-RATE 1000 1 1\r\n");
    

 

}

void loop(){
#ifdef DEBUG
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

//00000011 11101000
//11101000 11000000
//00010111 11000000


void serialEvent(){
    //Serial.print("Work");
    char inChar = Serial.read();
 #ifdef DEBUG
    if(inChar == ')'){
        ReadToken = true;
        

    }
    else if(inChar == '='){

        SCB_AIRCR = 0x05FA0004;
    
    }
    else if(inChar == '!'){

        
        for(int i = 0;i < sizeof(List); i ++){
            Serial5.write(List[i]);
            Serial.print(List[i],HEX);
            Serial.print(" ");

        }
    Serial.println();
   

    }
    else if(inChar != 0x0A){
        k ++;
        sprintf(Record,"%s%c",Record,inChar);
#endif
        Serial5.write(inChar);
#ifdef DEBUG
    }
#endif
 

}

bool Rd = false;
void serialEvent5(){
    //Serial.print("Work");
    char InByte = Serial5.read();
    #ifdef DEBUG
    if(InByte == '$'){

        Rd = true;

    }
    if(!ReadToken && Rd){
        
        Serial.write(InByte);
    
    }

    if(!Rd){

        Serial.print(InByte,HEX);
        Serial.print(" ");



    }
    if(InByte == '\n'){

        Rd = false;

    }
    #endif
    #ifndef DEBUG
     Serial.write(InByte);
     #endif

}
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
21:59:57  R -> NMEA GNGSA,  Size  52,  'GNSS DOP and Active Satellites'


          0030  37 37 0D 0A                                      77
          
22:04:21  0000  B5 62 06 08 06 00 10 27 02 00 02 00 4F E3        µb'Oã
          
22:04:21  0000  B5 62 05 01 02 00 06 08 16 3F    

B5 62 6 8 6 E8 3 2 2 3 3F B5 62 6 8 E 30 A 0 0 0 0 0
*/