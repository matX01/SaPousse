#include "tst.h"  



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  tester.test();
  // put your main code here, to run repeatedly:
  delay(1000);
  
}

void testFunc(){
  
  Serial.println("ah");
  
}
