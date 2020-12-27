/*
  MPU9250.h
  Brian R Taylor
  brian.taylor@bolderflight.com

  Copyright (c) 2017 Bolder Flight Systems

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef MPU9250_h
#define MPU9250_h

#include "Arduino.h"
#include "Wire.h"    // I2C library
#include "SPI.h"     // SPI library

class MPU9250{
  public:
    enum GyroRange
    {
      GYRO_RANGE_250DPS,
      GYRO_RANGE_500DPS,
      GYRO_RANGE_1000DPS,
      GYRO_RANGE_2000DPS
    };
    enum AccelRange
    {
      ACCEL_RANGE_2G,
      ACCEL_RANGE_4G,
      ACCEL_RANGE_8G,
      ACCEL_RANGE_16G    
    };
    enum DlpfBandwidth
    {
      DLPF_BANDWIDTH_184HZ,
      DLPF_BANDWIDTH_92HZ,
      DLPF_BANDWIDTH_41HZ,
      DLPF_BANDWIDTH_20HZ,
      DLPF_BANDWIDTH_10HZ,
      DLPF_BANDWIDTH_5HZ
    };
    enum LpAccelOdr
    {
      LP_ACCEL_ODR_0_24HZ = 0,
      LP_ACCEL_ODR_0_49HZ = 1,
      LP_ACCEL_ODR_0_98HZ = 2,
      LP_ACCEL_ODR_1_95HZ = 3,
      LP_ACCEL_ODR_3_91HZ = 4,
      LP_ACCEL_ODR_7_81HZ = 5,
      LP_ACCEL_ODR_15_63HZ = 6,
      LP_ACCEL_ODR_31_25HZ = 7,
      LP_ACCEL_ODR_62_50HZ = 8,
      LP_ACCEL_ODR_125HZ = 9,
      LP_ACCEL_ODR_250HZ = 10,
      LP_ACCEL_ODR_500HZ = 11
    };
    MPU9250(TwoWire &bus,uint8_t address);
    MPU9250(SPIClass &bus,uint8_t csPin);
    int begin();
    int setAccelRange(AccelRange range);
    int setGyroRange(GyroRange range);
    int setDlpfBandwidth(DlpfBandwidth bandwidth);
    int setSrd(uint8_t srd);
    int enableDataReadyInterrupt();
    int disableDataReadyInterrupt();
    int enableWakeOnMotion(float womThresh_mg,LpAccelOdr odr);
    int readSensor();
    float getAccelX_mss();
    float getAccelY_mss();
    float getAccelZ_mss();
    float getGyroX_rads();
    float getGyroY_rads();
    float getGyroZ_rads();
    float getMagX_uT();
    float getMagY_uT();
    float getMagZ_uT();
    float getTemperature_C();
    
    int calibrateGyro();
    float getGyroBiasX_rads();
    float getGyroBiasY_rads();
    float getGyroBiasZ_rads();
    void setGyroBiasX_rads(float bias);
    void setGyroBiasY_rads(float bias);
    void setGyroBiasZ_rads(float bias);
    int calibrateAccel();
    float getAccelBiasX_mss();
    float getAccelScaleFactorX();
    float getAccelBiasY_mss();
    float getAccelScaleFactorY();
    float getAccelBiasZ_mss();
    float getAccelScaleFactorZ();
    void setAccelCalX(float bias,float scaleFactor);
    void setAccelCalY(float bias,float scaleFactor);
    void setAccelCalZ(float bias,float scaleFactor);
    int calibrateMag();
    float getMagBiasX_uT();
    float getMagScaleFactorX();
    float getMagBiasY_uT();
    float getMagScaleFactorY();
    float getMagBiasZ_uT();
    float getMagScaleFactorZ();
    void setMagCalX(float bias,float scaleFactor);
    void setMagCalY(float bias,float scaleFactor);
    void setMagCalZ(float bias,float scaleFactor);
  protected:
    // i2c
    uint8_t _address;
    TwoWire *_i2c;
    const uint32_t _i2cRate = 400000; // 400 kHz
    size_t _numBytes; // number of bytes received from I2C
    // spi
    SPIClass *_spi;
    uint8_t _csPin;
    bool _useSPI;
    bool _useSPIHS;
    const uint8_t SPI_READ = 0x80;
    const uint32_t SPI_LS_CLOCK = 1000000;  // 1 MHz
    const uint32_t SPI_HS_CLOCK = 15000000; // 15 MHz
    // track success of interacting with sensor
    int _status;
    // buffer for reading from sensor
    uint8_t _buffer[21];
    // data counts
    int16_t _axcounts,_aycounts,_azcounts;
    int16_t _gxcounts,_gycounts,_gzcounts;
    int16_t _hxcounts,_hycounts,_hzcounts;
    int16_t _tcounts;
    // data buffer
    float _ax, _ay, _az;
    float _gx, _gy, _gz;
    float _hx, _hy, _hz;
    float _t;
    // wake on motion
    uint8_t _womThreshold;
    // scale factors
    float _accelScale;
    float _gyroScale;
    float _magScaleX, _magScaleY, _magScaleZ;
    const float _tempScale = 333.87f;
    const float _tempOffset = 21.0f;
    // configuration
    AccelRange _accelRange;
    GyroRange _gyroRange;
    DlpfBandwidth _bandwidth;
    uint8_t _srd;
    // gyro bias estimation
    size_t _numSamples = 100;
    double _gxbD, _gybD, _gzbD;
    float _gxb, _gyb, _gzb;
    // accel bias and scale factor estimation
    double _axbD, _aybD, _azbD;
    float _axmax, _aymax, _azmax;
    float _axmin, _aymin, _azmin;
    float _axb, _ayb, _azb;
    float _axs = 1.0f;
    float _ays = 1.0f;
    float _azs = 1.0f;
    // magnetometer bias and scale factor estimation
    uint16_t _maxCounts = 1000;
    float _deltaThresh = 0.3f;
    uint8_t _coeff = 8;
    uint16_t _counter;
    float _framedelta, _delta;
    float _hxfilt, _hyfilt, _hzfilt;
    float _hxmax, _hymax, _hzmax;
    float _hxmin, _hymin, _hzmin;
    float _hxb, _hyb, _hzb;
    float _hxs = 1.0f;
    float _hys = 1.0f;
    float _hzs = 1.0f;
    float _avgs;
    // transformation matrix
    /* transform the accel and gyro axes to match the magnetometer axes */
    const int16_t tX[3] = {0,  1,  0}; 
    const int16_t tY[3] = {1,  0,  0};
    const int16_t tZ[3] = {0,  0, -1};
    // constants
    const float G = 9.807f;
    const float _d2r = 3.14159265359f/180.0f;
    // MPU9250 registers
    #define ACCEL_OUT  0x3B
    #define GYRO_OUT  0x43
    #define TEMP_OUT  0x41
    #define EXT_SENS_DATA_00  0x49
    #define ACCEL_CONFIG  0x1C
    #define ACCEL_FS_SEL_2G  0x00
    #define ACCEL_FS_SEL_4G  0x08
    #define ACCEL_FS_SEL_8G  0x10
    #define ACCEL_FS_SEL_16G  0x18
    #define GYRO_CONFIG  0x1B
    #define GYRO_FS_SEL_250DPS  0x00
    #define GYRO_FS_SEL_500DPS  0x08
    #define GYRO_FS_SEL_1000DPS  0x10
    #define GYRO_FS_SEL_2000DPS  0x18
    #define ACCEL_CONFIG2  0x1D
    #define ACCEL_DLPF_184  0x01
    #define ACCEL_DLPF_92  0x02
    #define ACCEL_DLPF_41  0x03
    #define ACCEL_DLPF_20  0x04
    #define ACCEL_DLPF_10  0x05
    #define ACCEL_DLPF_5  0x06
    #define CONFIG  0x1A
    #define GYRO_DLPF_184  0x01
    #define GYRO_DLPF_92  0x02
    #define GYRO_DLPF_41  0x03
    #define GYRO_DLPF_20  0x04
    #define GYRO_DLPF_10  0x05
    #define GYRO_DLPF_5  0x06
    #define SMPDIV  0x19
    #define INT_PIN_CFG  0x37
    #define INT_ENABLE  0x38
    #define INT_DISABLE  0x00
    #define INT_PULSE_50US  0x00
    #define INT_WOM_EN  0x40
    #define INT_RAW_RDY_EN  0x01
    #define PWR_MGMNT_1  0x6B
    #define PWR_CYCLE  0x20
    #define PWR_RESET  0x80
    #define CLOCK_SEL_PLL  0x01
    #define PWR_MGMNT_2  0x6C
    #define SEN_ENABLE  0x00
    #define DIS_GYRO  0x07
    #define USER_CTRL  0x6A
    #define I2C_MST_EN  0x20
    #define I2C_MST_CLK  0x0D
    #define I2C_MST_CTRL  0x24
    #define I2C_SLV0_ADDR  0x25
    #define I2C_SLV0_REG  0x26
    #define I2C_SLV0_DO  0x63
    #define I2C_SLV0_CTRL  0x27
    #define I2C_SLV0_EN  0x80
    #define I2C_READ_FLAG  0x80
    #define MOT_DETECT_CTRL  0x69
    #define ACCEL_INTEL_EN  0x80
    #define ACCEL_INTEL_MODE  0x40
    #define LP_ACCEL_ODR  0x1E
    #define WOM_THR  0x1F
    #define WHO_AM_I  0x75
    #define FIFO_EN  0x23
    #define FIFO_TEMP  0x80
    #define FIFO_GYRO  0x70
    #define FIFO_ACCEL  0x08
    #define FIFO_MAG  0x01
    #define FIFO_COUNT  0x72
    #define FIFO_READ  0x74
    // AK8963 registers
    #define AK8963_I2C_ADDR  0x0C
    #define AK8963_HXL  0x03 
    #define AK8963_CNTL1  0x0A
    #define AK8963_PWR_DOWN  0x00
    #define AK8963_CNT_MEAS1  0x12
    #define AK8963_CNT_MEAS2  0x16
    #define AK8963_FUSE_ROM  0x0F
    #define AK8963_CNTL2  0x0B
    #define AK8963_RESET  0x01
    #define AK8963_ASA  0x10
    #define AK8963_WHO_AM_I  0x00
    // private functions
    int writeRegister(uint8_t subAddress, uint8_t data);
    int readRegisters(uint8_t subAddress, uint8_t count, uint8_t* dest);
    int writeAK8963Register(uint8_t subAddress, uint8_t data);
    int readAK8963Registers(uint8_t subAddress, uint8_t count, uint8_t* dest);
    int whoAmI();
    int whoAmIAK8963();
};

class MPU9250FIFO: public MPU9250 {
  public:
    using MPU9250::MPU9250;
    int enableFifo(bool accel,bool gyro,bool mag,bool temp);
    int readFifo();
    void getFifoAccelX_mss(size_t *size,float* data);
    void getFifoAccelY_mss(size_t *size,float* data);
    void getFifoAccelZ_mss(size_t *size,float* data);
    void getFifoGyroX_rads(size_t *size,float* data);
    void getFifoGyroY_rads(size_t *size,float* data);
    void getFifoGyroZ_rads(size_t *size,float* data);
    void getFifoMagX_uT(size_t *size,float* data);
    void getFifoMagY_uT(size_t *size,float* data);
    void getFifoMagZ_uT(size_t *size,float* data);
    void getFifoTemperature_C(size_t *size,float* data);
  protected:
    // fifo
    bool _enFifoAccel,_enFifoGyro,_enFifoMag,_enFifoTemp;
    size_t _fifoSize,_fifoFrameSize;
    float _axFifo[85], _ayFifo[85], _azFifo[85];
    size_t _aSize;
    float _gxFifo[85], _gyFifo[85], _gzFifo[85];
    size_t _gSize;
    float _hxFifo[73], _hyFifo[73], _hzFifo[73];
    size_t _hSize;
    float _tFifo[256];
    size_t _tSize;
};

#endif
