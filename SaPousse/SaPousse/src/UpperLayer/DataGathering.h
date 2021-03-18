#ifndef GatheringHandler
#define GatheringHandler

#include "../GlobalVariables.h"





class DataGathering {

    public:
    DataGathering();
    static void begin(FlightParameter* DataGatheringParameter);
    static void Scheduling(bool State);
    static void ChangeSchedulingFrequency(int NewSchedulingFrequency);

    private:
    static int SchedulingFrequency;
    static IntervalTimer mainTimer;




};

class ScheduledGatheringObject {

    public:
    ScheduledGatheringObject();
    void begin(uint8_t Div);
    bool IsExecuted();
    private:
    uint8_t Divider;
    uint8_t counter = 0;

};


extern DataGathering ScheduledGatherer;
extern void ScheduledGathering();


#endif