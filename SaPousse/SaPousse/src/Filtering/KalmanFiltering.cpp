




/*

Le croquis utilise 13152 octets (0%) de l'espace de stockage de programmes. Le maximum est de 8126464 octets.
Les variables globales utilisent 41660 octets (7%) de mémoire dynamique, ce qui laisse 482628 octets pour les variables locales. Le maximum est de 524288 octets.

Le croquis utilise 13152 octets (0%) de l'espace de stockage de programmes. Le maximum est de 8126464 octets.
Les variables globales utilisent 41660 octets (7%) de mémoire dynamique, ce qui laisse 482628 octets pour les variables locales. Le maximum est de 524288 octets.
*/
/*void IMU9250::calibrateAccel(int NumberOfCalibrationIteration){
   
    uint8_t NoCalibrate = 0;
    int MaxValue = 0;

    for(int i = 0;i < NumberOfCalibrationIteration;i ++){
        IMUSPI.beginTransaction();
        uint8_t buff[2];
        for(int j = 0;j < 3;j ++){
        
            buff[0] = IMUSPI.getRegister(ACCEL_OUT);    
            buff[1] = IMUSPI.getRegister(0x00);
            
            Offsets[j] += -((short)((buff[0] << 8) | (buff[1])))/NumberOfCalibrationIteration;
           
            if(Offsets[j] > MaxValue){

                MaxValue = Offsets[j];
                NoCalibrate = j;
            
            }
        
        }
        
        IMUSPI.endTransaction();
        delay(10);
    
    }

    Offsets[NoCalibrate] = 0;
    Linearity[NoCalibrate] = 16384.0f/(Ranges[0]*MaxValue);

    for(int i = 0;i < 3; i ++){

         //Linearity[i] = 16384.0f/(Ranges[0]*MaxValue);
         
        if(i == NoCalibrate){

            continue;

        }

        //Linearity[i] = 16384.0f/(Ranges[0]*MaxValue);
       
        Offsets[NoCalibrate] += Offsets[i]/2;


    }
    for(int i = 0;i < 3;i ++){

     
        Offsets[i] = Offsets[NoCalibrate];
        

    }
    Calibration[0] = 2;


}
void IMU9250::calibrateCompas(int NumberOfCalibrationIteration){

    //Rotate the IMU on all axis to find the min and max points of all
    Calibration[3] = 2;


}
void IMU9250::calibrateTemp(int NumberOfCalibrationIteration){

    Calibration[1] = 2;

}*/



