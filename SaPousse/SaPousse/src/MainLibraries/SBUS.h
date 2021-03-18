#ifndef SBUSHANDLER
#define SBUSHANDLER

#include "Arduino.h"
#include "../GlobalVariables.h"
#include "../Frontend/SystemHandling.h"
class SBUSHandler {
    
    public :
    SBUSHandler();
    static void begin();
    static RadioOut ChannelOutput;
    static uint8_t InputByte[2];
    static uint8_t Sentence[SENTENCE_SIZE];
    static volatile bool FailsafeToken;
    static uint8_t NumberOfRecordedBytes;
    static bool getFailsafeValue();
    static volatile RadioOut* GetRadioChannel();
    





};

extern SBUSHandler SBUSDev;

#endif