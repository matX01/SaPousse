// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       test1.ino
    Created:	01/06/2020 15:52:23
    Author:     DESKTOP-OLPR60S\mathi
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
void setup()
{
    pinMode(13, OUTPUT);

}

// Add the main program code into the continuous loop() function
void loop()
{
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);

}
