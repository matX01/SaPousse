#include<SD.h>
#include<SPI.h>
#include<String.h>

char FolderDir[3][8] = {"FP.SP","/DTL/","/EVL/"};
int SDSpiPin = 0;

File Test;


void FlightParameters(){
    if(!SD.begin(SDSpiPin)){

        Serial.println("init Failed");

    }
    else{

        Serial.println("Init Done ... ");
        Serial.println(strcat(FolderDir[1],FolderDir[0]));
        Test = SD.open(strcat(FolderDir[1],FolderDir[0]),FILE_READ);
        if(Test){
        while(Test.available()){

            Serial.write(Test.read());


        }
        Test.close();
        }
        else{
          Serial.println("FileNotFound");


          
        }


    }




}


int Begin(int SDCSPin){
    Serial.begin(115200);
    SDSpiPin = SDCSPin;
    pinMode(SDCSPin,OUTPUT);
    Serial.println("Test Reading SD Card");



}




void setup(){
Begin(48);
FlightParameters();


}
void loop(){


}


/*
 
#include <SPI.h>
#include <SD.h>

File myFile;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(48, OUTPUT);
   
  if (!SD.begin(48)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("FP.SP", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
  // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  // re-open the file for reading:
  myFile = SD.open("FP.SP");
  if (myFile) {
    Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop()
{
  // nothing happens after setup
}*/
