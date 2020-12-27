# SaPousse

SaPousse is an airplane flight controller software built from scratch .


SaPousse is **Open Source** so completly free to use, modify and share.


It is developped to improve my knowledge about control systems and mecanism , and i want to share it in order to help other peoples that are blocked on a problem that i already had and already solved.


WARNING : SaPousse is actually in an early beta version and cannot be used on a model airplane.
 
 
 ## Hardware Requirement :
 _SaPousse is built on a precise Hardware set, there is no waranties that other hardware will work without any modifications of the code._
 
 1. The main board is a Teensy 4.1
 2. The IMU is a MPU9250
 3. The barometer is a BMP280
 3. The GPS is a BN880Q
 4. The Radio reciever is a XM+
 
 ## Software Requirement :
 1. SaPousse is based on the teensyduino lib(witch is Arduino lib)
 2. SaPousse needs to be compiled into the Arduino soft , that's why the main file is a .ino file

 ## Features that will be implemented :
 
 ### Flight modes :
  1. Manual
  2. Auto Throttle 
  3. mode 2 + Pitch and roll stabilisation
  4. mode 3 + Yaw stabilisation 
  5. mode 4 + waypoint following (Fully autonomus mode)
 
 ### Avionics features :
   _Complete telemetry stream with a ground station._
   
   
## Features that are implemented :
  1. Config file on an SD card
  2. Complete calibration of the IMU
  3. Calibration save mecanism
  4. data sampling at a certain speed
  5. SBUS decoder to get data from the radiocommand
  
  

  
  
  

  
