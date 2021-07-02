#ifndef IMUClass
#define IMUClass

#include "SPIElement.h"
#include <Arduino.h>
#include "GlobalPreProcessorValues.h"


#define IMUSPISpeed 1000000
#define IMUSPIMode SPI_MODE3
#define IMUSPIBit MSBFIRST

struct DataStructure {
    
    volatile float OutputFloat[10];
    volatile short OutputShort[10];
    
};
struct SensorGatParam{
    uint8_t StartByte;
    uint8_t BufferStartPosition;
    uint8_t BufferStopPosition;


};


class IMU9250 {
    public :
    
    IMU9250();
    static void SetBus(uint8_t SPINumberUsedForComm,uint8_t CSPin);
    static void begin();
    
    static uint8_t readAK8963(uint8_t Register);
    static void writeAK8963(uint8_t Register,uint8_t Message);
    static void setAK8963ToBrigeMode();
    
    static void calibrateCompas(int NumberOfCalibrationIteration);
    
    
    static void readSensor();
    static DataStructure *GetValues();
    


    private :
    
    static SPIDev IMUSPI;
    static DataStructure OutputValue;
    static short Offsets[3];
    static float Linearity[3];
    static float ConversionValue[3];
    static uint8_t Ranges[4];

};

extern IMU9250 MPU9250;

const SensorGatParam ACCEL {
    
    ACCEL_OUT,
    0,
    3

};
const SensorGatParam GYRO {
    
    GYRO_OUT,
    3,
    6

};
const SensorGatParam TEMP {
    TEMPERATURE_OUT,
    6,
    7

};

const SensorGatParam COMPAS {
    COMPAS_OUT,
    7,
    10

};
const SensorGatParam ALL {
    
    ACCEL_OUT,
    0,
    9
};


#endif