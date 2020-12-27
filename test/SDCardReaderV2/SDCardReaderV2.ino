//#include<Arduino.h>



void setup(){
Serial.begin(115200);

float *value = (float*)malloc(4*4);
/**value = 4;
*(value)[1] = 5;
float val = *value;
Serial.print(val);
float val2 = *(value+1);*/
float val[] = *value;

Serial.print(val[0]);


}

void loop(){



}
