#include "SBUS.h"


SBUSHandler::SBUSHandler(){




}

void SBUSHandler::begin(){

Serial4.begin(100000);

}

bool SBUSHandler::getFailsafeValue(){

    return FailsafeToken;

}

volatile RadioOut* SBUSHandler::GetRadioChannel(){

    return &ChannelOutput;

}



RadioOut SBUSHandler::ChannelOutput;
uint8_t SBUSHandler::InputByte[2];  
uint8_t SBUSHandler::Sentence[SENTENCE_SIZE];
volatile bool SBUSHandler::FailsafeToken = true;
uint8_t SBUSHandler::NumberOfRecordedBytes = 0;


void serialEvent4(){

    SBUSDev.InputByte[1] = SBUSDev.InputByte[0];
    SBUSDev.InputByte[0] = Serial4.read();

    if((SBUSDev.InputByte[1] == 0x00 && SBUSDev.InputByte[0] == 0x0F) && SBUSDev.NumberOfRecordedBytes >= SENTENCE_ACCEPTATION_SIZE){
        SBUSDev.NumberOfRecordedBytes = 0;

        int ByteToRead = 0;
        int overByte = 0;
        for(int i = 0;i < NUMBER_OF_CHANNEL;i ++){

            SBUSDev.ChannelOutput.Channel[i] = map((uint16_t)(((uint32_t)((SBUSDev.Sentence[ByteToRead]) | (SBUSDev.Sentence[ByteToRead+1] << 8) | (SBUSDev.Sentence[ByteToRead+2]) << 16 ) >> (uint8_t)overByte ) & 0x07FF),192,1792,1000,2000);

            if(SBUSDev.ChannelOutput.Channel[i] == FAILSAFE_TOKEN){
                
                if(!SBUSDev.FailsafeToken){

                    SystemHandler.RadioFailsafe(true);
                    SBUSDev.FailsafeToken = true;

                }
                
                break;
                    //Serial.println("la");
            }

            if(overByte != overByte%8){

                overByte = overByte%8;
                ByteToRead ++;

            }
        
            overByte += 3;
            ByteToRead ++;

             if(SBUSDev.FailsafeToken != false && i == 14){
                
                SBUSDev.FailsafeToken = false;
                SystemHandler.RadioFailsafe(false);

            }

        }
        SBUSDev.ChannelOutput.DataReady = true;
        
    }
    else{

        SBUSDev.Sentence[SBUSDev.NumberOfRecordedBytes] = SBUSDev.InputByte[0];
        SBUSDev.NumberOfRecordedBytes ++;


    }

}


