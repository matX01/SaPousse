#ifndef IMUClass
#define IMUClass

#include "../IOComms/SPIElement.h"
#include <Arduino.h>
#include "../GlobalPreProcessorValues.h"
#include "../IOComms/SDCard.h"

#define IMUSPISpeed 16000000
#define IMUSPIMode SPI_MODE3
#define IMUSPIBit MSBFIRST


namespace IMUData{

    extern volatile float OutputFloat[10];
    extern volatile short OutputShort[10];
    extern volatile bool DataReady;



}



class IMU9250 {
    public :
    
    IMU9250();
    static void SetBus(uint8_t SPINumberUsedForComm,uint8_t CSPin);
    static void begin(FlightParameter *IMUBeginParameters,FlightParameter *CompasBeginParameters);
    

    static void setAK8963ToBrigeMode();
    static uint8_t GetCalibrationValue(SensorGatParam Sensor);
    static void calibrateSensor(SensorGatParam SensorToCalibrate,int NumberOfCalibrationIteration);

    static void readSensor(SensorGatParam Param);
    

    private :
    static uint8_t readAK8963(uint8_t Register);
    static void writeAK8963(uint8_t Register,uint8_t Message);
    static uint8_t Calibration[4];
    static SPIDev IMUSPI;
    static short Offsets[10];
    static float Linearity[10];
    static float ConversionValue[10];
    static uint8_t Ranges[4];

};

extern IMU9250 MPU9250;



#endif