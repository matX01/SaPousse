#ifndef GlobalVar
#define GlobalVar
#include <Arduino.h>
#include "Debugger.h"



//SDCard
#define NumberOfParametersLoaded 4

#define ParameterListX 10
#define ParameterListY 4
#define ParameterCharSize 5
#define CalibrationFileCharSize 7

#define FlightParametersDirectory "FP.SP"
#define CalibrationDataFile "BONJ"

#define SystemSettingsX 3
#define SystemSettingsY 9

//SPIDev 
#define numberOfCumulatedExceptionInDefinedTimeOut 10000
#define TimeUnitForExceptionTimeOut 1000

//MPU9250
    //TableMap
    
        #define GYRO_OUT 0x43
        #define ACCEL_OUT 0x3B
        #define TEMPERATURE_OUT 0x41
        #define COMPAS_OUT 0x49
        #define IMU_ADRESS 0x75

        #define UNDER_I2C_SETUP 0x6A
        #define UNDER_I2C_MASTERMODE 0x20

        #define UNDER_I2C_CLKSETUP 0x24
        #define UNDER_I2C_400KCLK 0x0D

        #define PWR_MANAGEMENT_1 0x6B
        #define PWR_MANAGEMENT_2 0x6C
        #define RESET_I2C 0x02
        #define RESET_IMU 0x80
        #define CLK_20MHZ 0x00

        #define I2C_SLV0_ADDRSEL 0x25
        #define SLV0_REGISTERTOOP 0x26
        #define SLV0_CTRL 0x27
        #define SLV0_REGISTER_OUTPUT 0x63
        #define SLV_READ_MODE 0x80
        #define SLV_ENABLE 0x80
        #define SLV_DATAOUT 0x49
        #define SLV0_DO 0x63

    //AK8963
        #define AK8963_ADDR 0x0C
    
        #define UNDER_I2C_AK8963_ADRESS 0x00
        #define AK8963_MEASURE_OUT 0x03
        #define AK8963_CNTL_1 0x0A
        #define AK8963_CNTL_2 0x0B
        #define AK8963_SENS_ADJ 0x10

        #define NumberOfIterationForCalibration 100

#define IMUFIFOSize 40

//SampleRateDivider

#define NumberOfDifferentExecutionRate 4;






struct FlightParameter{
    
    float FlightParam[ParameterListY][ParameterListX];

};
struct SensorPointer{

    uint8_t * VariablePointer;
    size_t SizeOfElement;

};

struct ErrorType {
   
    uint8_t ErrorTypeID;

};

class GlobalExceptionHandler {
    public :
    
    GlobalExceptionHandler();
    static void begin();
    static void FailedToInitialise(uint8_t ExceptionID);
    static void SpiCommErr();
    static void FatalError(uint8_t ExceptionID);
    static void Error(uint8_t ExceptionID,ErrorType Err);
    private :
    
    static int ExceptionCount;
    static unsigned long LastExceptionCountTime;


};

extern GlobalExceptionHandler ExceptionHandler;

const ErrorType INITERROR{
    0
};
const ErrorType FATALERROR{
    1 
};
const ErrorType SAMPLINGERROR{
    2
};
const ErrorType SMALLERROR{
    3
};
const ErrorType SPIERROR {
    4
};




#endif