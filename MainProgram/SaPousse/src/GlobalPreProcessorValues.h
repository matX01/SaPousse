#ifndef GlobalVar
#define GlobalVar

#include <Arduino.h>
#include "MainLibraries/Debugger.h"



//SDCard
#define NumberOfParametersLoaded 4

#define ParameterListX 10
#define ParameterListY 4
#define ParameterCharSize 5


#define FlightParametersDirectory "FP.SP"
#define CalibrationDataFile "SC.SP"

#define NumberOfArraysToLog 10

//SPIDev 
#define numberOfCumulatedExceptionInDefinedTimeOut 750
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
        #define AK8963_MODULE_ADDR 0x00
        #define UNDER_I2C_AK8963_ADRESS 0x00
        #define AK8963_MEASURE_OUT 0x03
        #define AK8963_CNTL_1 0x0A
        #define AK8963_CNTL_2 0x0B
        #define AK8963_SENS_ADJ 0x10
        

        #define NumberOfIterationForCalibration 100
        #define CompassCalibrationTime 60000

    
    
//SBUS Reciever
    #define NUMBER_OF_CHANNEL 16
    #define FAILSAFE_TOKEN 880
    #define SENTENCE_SIZE 25
    #define SENTENCE_ACCEPTATION_SIZE 22

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

//IMU

struct SensorGatParam{
    uint8_t StartByte;
    uint8_t BufferStartPosition;
    uint8_t BufferStopPosition;
    uint8_t SensorID;


};

struct Quaternion{

    float r;
    float i;
    float j;
    float k;

};

inline Quaternion MultiplyQaternion(Quaternion Q1 , Quaternion Q2){
    Quaternion ReturnValue;
    ReturnValue.r = (Q1.r*Q2.r)-(Q1.i*Q2.i)-(Q1.j*Q2.j)-(Q1.k*Q2.k);
    ReturnValue.i = (Q1.r*Q2.i)+(Q1.i*Q2.r)+(Q1.j*Q2.k)-(Q1.k*Q2.j);
    ReturnValue.j = (Q1.r*Q2.j)-(Q1.i*Q2.k)+(Q1.j*Q2.r)+(Q1.k*Q2.i);
    ReturnValue.k = (Q1.r*Q2.k)+(Q1.i*Q2.j)-(Q1.j*Q2.i)+(Q1.k*Q2.r );
    return ReturnValue;


}

inline Quaternion AddQaternion(Quaternion Q1 , Quaternion Q2){
    Quaternion ReturnValue;
    ReturnValue.r = Q1.r+Q2.r;
    ReturnValue.i = Q1.i+Q2.i;
    ReturnValue.j = Q1.j+Q2.j;
    ReturnValue.k = Q1.k+Q2.k;

    return ReturnValue;


}


inline SensorGatParam MergeSensor(SensorGatParam StartParam,SensorGatParam StopParam){
    
    SensorGatParam ReturnValue;
    ReturnValue.StartByte = StartParam.StartByte;
    ReturnValue.BufferStartPosition = StartParam.BufferStartPosition;
    ReturnValue.BufferStopPosition = StopParam.BufferStopPosition;
    ReturnValue.SensorID = StartParam.SensorID;
    
    return ReturnValue;

};

struct GPSOut{

    volatile char Sentence[80] = "";
    volatile bool DataReady = false;

};


struct RadioOut{
    
    volatile uint16_t Channel[NUMBER_OF_CHANNEL];
    volatile bool DataReady = false; 

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
const ErrorType FAILSAFE {

    5

};


//MPU
const SensorGatParam ACCEL {
    
    ACCEL_OUT,
    0,
    3,
    0

};
const SensorGatParam GYRO {
    
    GYRO_OUT,
    4,
    7,
    2

};
const SensorGatParam TEMP {
    TEMPERATURE_OUT,
    3,
    4,
    1

};

const SensorGatParam COMPAS {
    COMPAS_OUT,
    7,
    10,
    3

};
const SensorGatParam ALL {
    
    ACCEL_OUT,
    0,
    9,
    4
};


#endif