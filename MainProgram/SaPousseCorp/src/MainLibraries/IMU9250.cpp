#include "IMU9250.h"

SPIDev IMU9250::IMUSPI;
DataStructure IMU9250::OutputValue;

float IMU9250::ConversionValue[10];
short IMU9250::Offsets[10];
float IMU9250::Linearity[10];
uint8_t IMU9250::Ranges[4];
uint8_t IMU9250::Calibration[4];

IMU9250::IMU9250(){

   

}

void IMU9250::SetBus(uint8_t SPINumberUsedForComm,uint8_t CSPin){

    IMUSPI.SPIInitParam(CSPin,SPINumberUsedForComm,SPISettings(IMUSPISpeed,IMUSPIMode,IMUSPIBit));
    SDCardReader.SetCalibrationPointer((uint8_t *)&Offsets,sizeof(Offsets));
    SDCardReader.SetCalibrationPointer((uint8_t *)&Linearity,sizeof(Linearity));
    for(int i = 0;i < 10; i ++){

        Linearity[i] = 1;

    }

}



void IMU9250::begin(FlightParameter *IMUBeginParameters,FlightParameter *CompasBeginParameters){
    
    IMUSPI.begin();

    IMUSPI.beginTransaction();
    if(IMUSPI.getRegister(IMU_ADRESS) != 0x71){

        ExceptionHandler.Error(0x0A,INITERROR);

    }
    IMUSPI.endTransaction();

    delay(1);

    IMUSPI.beginTransaction();
    IMUSPI.setRegister(PWR_MANAGEMENT_1,RESET_IMU);
    IMUSPI.endTransaction();

    delay(1);

    IMUSPI.beginTransaction();
    IMUSPI.setRegister(UNDER_I2C_SETUP,RESET_I2C);
    IMUSPI.endTransaction();
    
    delay(1);

    writeAK8963(0x0B,0x01);

    delay(1);

    //transfering Setup of IMU
    for(int i = 0;i < ParameterListX;i ++){
        
        if((*IMUBeginParameters).FlightParam[1][i] != 255){
            
            IMUSPI.beginTransaction();
            IMUSPI.setRegister((uint8_t)(*IMUBeginParameters).FlightParam[1][i],(uint8_t)(*IMUBeginParameters).FlightParam[2][i]);
            IMUSPI.endTransaction();
            
            delay(1);

            IMUSPI.beginTransaction();
            if(IMUSPI.getRegister((uint8_t)(*IMUBeginParameters).FlightParam[1][i]) != (uint8_t)(*IMUBeginParameters).FlightParam[2][i]){

               ExceptionHandler.Error(0x09,INITERROR);

            }
       
            IMUSPI.endTransaction(); 
            delay(1);

        }

    }
    if(readAK8963(AK8963_MODULE_ADDR) != 0x48){

        ExceptionHandler.Error(0x0B,INITERROR);

    }


    for(int i = 0;i<ParameterListX;i ++){
        //Serial.println((uint8_t)(*CompasBeginParameters).FlightParam[1][i],HEX);
        if((*CompasBeginParameters).FlightParam[1][i] != 255){
            
            writeAK8963((uint8_t)(*CompasBeginParameters).FlightParam[0][i],(uint8_t)(*CompasBeginParameters).FlightParam[1][i]);
            
            delay(1);

            if(readAK8963((uint8_t)(*CompasBeginParameters).FlightParam[0][i]) != (uint8_t)(*CompasBeginParameters).FlightParam[1][i]){

               ExceptionHandler.Error(0x09,INITERROR);

            }

            delay(1);

        }


    }
 
    delay(1);

       
    for(int i = 0;i < 10;i ++){
            //Linearity[i] = 1;
            
        if(i < 3){

            ConversionValue[i] = 0.000598f*pow(2,((*IMUBeginParameters).FlightParam[0][0]));

            int CalibrationValue = 0;
            for(int j = 0;j < 3;j ++){

                if(Offsets[j] != 0){

                    CalibrationValue ++;

                }

            }
            if(CalibrationValue == 3){

                Calibration[0] = 1;

            }
        } 
        else if(i == 3){

            ConversionValue[i] = 1*pow(2,((*IMUBeginParameters).FlightParam[0][1]));               //TROUVER LES VALEURS DE CONVERSION TEMPERATURE

            if(Offsets[3] != 0){

                Calibration[1] = 1;

            }
        

        }
        else if(i >= 4 && i < 7){

            ConversionValue[i] = 0.00762962f*pow(2,((*IMUBeginParameters).FlightParam[0][2]));
            
            int CalibrationValue = 0;
            for(int j = 0;j < 3;j ++){

                if(Offsets[j+4] != 0){

                    CalibrationValue ++;

                }

            }
            if(CalibrationValue == 3){

                Calibration[2] = 1;

            }           


        }
        else {

            ConversionValue[i] = 1*pow(2,((*IMUBeginParameters).FlightParam[0][3]));                 //TROUVER LES VALEURS DE CONVERSION COMPAS

            int CalibrationValue = 0;
            for(int j = 0;j < 3;j ++){

                if(Offsets[j+7] != 0){

                    CalibrationValue ++;

                }

            }
            if(CalibrationValue == 3){

                Calibration[3] = 1;

            }           

        }
    }
  
    //Set ranges of the IMU
    for(int i = 0;i < 4;i ++){

        Ranges[i] = (uint8_t)(*IMUBeginParameters).FlightParam[0][i];
        
    } 

    setAK8963ToBrigeMode();

}

uint8_t IMU9250::GetCalibrationValue(SensorGatParam Sensor){
    /*Serial.println();
    for(int i = 0;i < 10;i ++){

        Serial.print(Offsets[i]);
        Serial.print(" ");


    }
    Serial.println();
    for(int i = 0;i < 10;i ++){

        Serial.print(Linearity[i],3);
        Serial.print(" ");


    }*/
    if(Sensor.SensorID == 4){
        uint8_t GlobalCalibration = 2;
        for(int i = 0;i < 4;i ++){

            if(Calibration[i] < GlobalCalibration){
                
                GlobalCalibration = Calibration[i];

                if(GlobalCalibration == 0){

                    return 0;

                }
            }

        }
        return GlobalCalibration;

    }
    else{
        
        return Calibration[Sensor.SensorID];

    }


}



void IMU9250::calibrateSensor(SensorGatParam SensorToCalibrate,int NumberOfCalibrationIteration){

    if(SensorToCalibrate.SensorID == 0){
        
        uint8_t NoCalibrate = 0;
        int MaxValue = 0;
        float TemporaryBuff[3] = {};
        for(int i = 0;i < NumberOfCalibrationIteration;i ++){
                
            IMUSPI.beginTransaction();
            uint8_t buff[2];
                
            for(int j = 0;j < 3;j ++){
        
                buff[0] = IMUSPI.getRegister(ACCEL_OUT);    
                buff[1] = IMUSPI.getRegister(0x00);
            
                //Offsets[j] += -((short)((buff[0] << 8) | (buff[1])))/NumberOfCalibrationIteration;
                TemporaryBuff[j] +=  -((short)((buff[0] << 8) | (buff[1])))/(float)NumberOfCalibrationIteration;

                if(TemporaryBuff[j] > MaxValue){

                    MaxValue = Offsets[j];
                    NoCalibrate = j;
            
                }
        
            }

            IMUSPI.endTransaction();
            delay(10);

        }
        
        TemporaryBuff[NoCalibrate] = 0;
        //Linearity[NoCalibrate] = 16384.0f/(Ranges[0]*MaxValue);

        for(int i = 0;i < 3; i ++){

                //Linearity[i] = 16384.0f/(Ranges[0]*MaxValue);
         
            if(i == NoCalibrate){

                continue;

            }

                //Linearity[i] = 16384.0f/(Ranges[0]*MaxValue);
       
            TemporaryBuff[NoCalibrate] += TemporaryBuff[i]/2;
            Offsets[i] = (short)TemporaryBuff[i];

        }
        
        Offsets[NoCalibrate] = (short)(TemporaryBuff[NoCalibrate]);

    }
    else if(SensorToCalibrate.SensorID == 1){



    }
    else if(SensorToCalibrate.SensorID == 2){
        float TemporaryBuff[3] = {};
        for(int i = 0;i < NumberOfCalibrationIteration;i ++){
            
            IMUSPI.beginTransaction();
            uint8_t buff[2];
            
            for(int j = 0;j < 3;j ++){
        
                buff[0] = IMUSPI.getRegister(GYRO_OUT);    
                buff[1] = IMUSPI.getRegister(0x00);
                
                TemporaryBuff[j] +=  -((short)((buff[0] << 8) | (buff[1])))/(float)NumberOfCalibrationIteration;
                //(float)(((short)((buff[0] << 8) | (buff[1])))/NumberOfCalibrationIteration);
                delay(1);
            }
        
            IMUSPI.endTransaction();
            delay(10);
            for(int i = 0;i < 3;i ++){

                Offsets[i+4] = (short)TemporaryBuff[i];

            }
        
        }
        
    }
    else if(SensorToCalibrate.SensorID == 3){
        short Extremums[2][3] = {
            {-32768,-32768,-32768},
            {32765,32765,32765}

        };
        uint8_t buff[2];
        unsigned long TimeElapsed = CompassCalibrationTime + millis();
        float moyenne = 0;
        short Measuredvalue;
        do{
            IMUSPI.beginTransaction();
            for(int i = 0;i < 3;i ++){
                buff[1] = IMUSPI.getRegister(COMPAS_OUT);    
                buff[0] = IMUSPI.getRegister(0x00);
                Measuredvalue = (short)((buff[0] << 8) | (buff[1]));
                if(Measuredvalue > Extremums[0][i]){

                    Extremums[0][i] = Measuredvalue;

                }
                if(Measuredvalue < Extremums[1][i]){

                    Extremums[1][i] = Measuredvalue;

                }

            }
            IMUSPI.endTransaction();
           delay(20); 
        }
        while(TimeElapsed > millis());
        Serial.println("max: ");
        for(int i = 0;i < 3;i ++){

            Serial.print(Extremums[0][i]);
            Serial.print(" ");

        }

        Serial.println("min: ");
        for(int i = 0;i < 3;i ++){

            Serial.print(Extremums[1][i]);
            Serial.print(" ");

        }
        for(int i = 0;i < 3;i ++){

            Offsets[i+7] = -((Extremums[0][i]+Extremums[1][i])/2);
            moyenne += (float)(abs(Extremums[0][i]-Extremums[1][i])/3);

        }
        
        for(int i = 0;i < 3;i ++){

            Linearity[i+7] = moyenne/(float)abs(Extremums[0][i]-Extremums[1][i]);

        }

    }
    else if(SensorToCalibrate.SensorID == 4){
        
        SensorGatParam Sns;        
        
        for(int i = 0;i < 4;i ++){
            
            Sns.SensorID = i;
            calibrateSensor(Sns,NumberOfCalibrationIteration);
            

        }

    }

    Calibration[SensorToCalibrate.SensorID] = 2;
    


}


void IMU9250::readSensor(SensorGatParam Param){
    uint8_t PotentialErrorCount = 0;
    IMUSPI.beginTransaction();
    uint8_t buff[2];
    
    for(int i = Param.BufferStartPosition;i < Param.BufferStopPosition;i ++){
        if(i > 6){

            buff[1] = IMUSPI.getRegister(Param.StartByte);    
            buff[0] = IMUSPI.getRegister(0x00);


        }else{

            buff[0] = IMUSPI.getRegister(Param.StartByte);    
            buff[1] = IMUSPI.getRegister(0x00);

        }
        short Out = ((short)(buff[0] << 8) | (buff[1]));
        OutputValue.OutputShort[i] = (short)((Out+(short)Offsets[i])*Linearity[i]);
        //OutputValue.OutputShort[i] = ((((short)(((buff[0] << 8) | (buff[1])))+Offsets[i]))*Linearity[i]);
        OutputValue.OutputFloat[i] =  OutputValue.OutputShort[i]*ConversionValue[i];
        
        
        if(Out == -1 || Out == 0){

            PotentialErrorCount ++;

        }

    }
    
    IMUSPI.endTransaction();

    if(PotentialErrorCount == (Param.BufferStopPosition-Param.BufferStartPosition)){

        ExceptionHandler.Error(0x05,SPIERROR);

    }
    /*else{

        FIFORecordPosition ++;
    
    }*/

}

uint8_t IMU9250::readAK8963(uint8_t Register){
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(I2C_SLV0_ADDRSEL,AK8963_ADDR | 0x80);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_REGISTERTOOP,Register);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_CTRL,SLV_ENABLE | 0x01);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
uint8_t returnValue = IMUSPI.getRegister(0x49);
IMUSPI.endTransaction();
delay(1);

    return returnValue;
}

void IMU9250::writeAK8963(uint8_t Register,uint8_t Message){

delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(I2C_SLV0_ADDRSEL,AK8963_ADDR);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_REGISTERTOOP,Register);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_DO,Message);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_CTRL,SLV_ENABLE | 0x01);
IMUSPI.endTransaction();
delay(1);
}

void IMU9250::setAK8963ToBrigeMode(){
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(I2C_SLV0_ADDRSEL,AK8963_ADDR | 0x80);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_REGISTERTOOP,AK8963_MEASURE_OUT);
IMUSPI.endTransaction();
delay(1);
IMUSPI.beginTransaction();
IMUSPI.setRegister(SLV0_CTRL,SLV_ENABLE | 0x07);
IMUSPI.endTransaction();
delay(1);





}



DataStructure *IMU9250::GetPointerOfVariable(){
    
    return &OutputValue;
    /*FIFOReadingPosition ++;
    if(FIFORecordPosition == IMUFIFOSize){

        FIFOReadingPosition = 0;

    }
    
    return ReturnStructurePointer;*/

}


/*

Il faut détécter si le FIFO est plein/si le FIFO est vide

    Si il est plein :
        ERREUR , réduire de 100Hz le Sampling;
    Si il est vide :
        Disable la gestion de données puisqu'on est en flux tendu

    L'objectif est de maintenir la latence la plus basse possible , si l'acquisition , le traitement et l'envoi se font en flux tendu alors c'est parfait
    */