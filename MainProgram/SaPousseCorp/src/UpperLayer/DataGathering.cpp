#include "DataGathering.h"

int DataGathering::SchedulingFrequency;
IntervalTimer DataGathering::mainTimer;








DataGathering::DataGathering(){




}

ScheduledGatheringObject::ScheduledGatheringObject(){



}





void DataGathering::begin(FlightParameter* DataGatheringParameter){
 
SchedulingFrequency = (int)(*DataGatheringParameter).FlightParam[0][0];   
mainTimer.priority(0);

}

void DataGathering::Scheduling(bool State){
    if(State){
    
        mainTimer.begin(ScheduledGathering,SchedulingFrequency);

    }
    else {

        mainTimer.end();

    }

}

void DataGathering::ChangeSchedulingFrequency(int NewSchedulingFrequency){

    SchedulingFrequency = NewSchedulingFrequency;
    mainTimer.update(NewSchedulingFrequency);

}
















void ScheduledGatheringObject::begin(uint8_t Div){

    Divider = Div;

}

bool ScheduledGatheringObject::IsExecuted(){
    if(counter == Divider){

        counter = 1;
        return true;
    }
    else {

        counter ++;
        return false;

    }

}

