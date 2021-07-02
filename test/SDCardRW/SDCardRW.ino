#include "SDCard.h"
#include "GlobalPreProcessorValues.h"
#include "Debugger.h"


void setup(){

    SDCardReader.begin(BUILTIN_SDCARD);
    DebugTool.begin(true);
    ExceptionHandler.begin();
    SDCardReader.WriteCalibrationData();
    delay(100);
    SDCardReader.ReadCalibrationData();
    SDCardReader.ReadFlightParameters();
    //SDCardReader.WriteCalibrationData();
}

void loop(){

 /*
L'idée est de fournir a la fonction un pointer et une taille




 */
    






}