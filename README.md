# SaPousse

SaPousse is an airplane flight controller software built from scratch .


SaPousse is **Open Source** so completly free to use, modify and share.

WARNING : SaPousse is actually in an early beta version and cannot be used on a model airplane.

It is developped to improve my knowledge about control systems and mecanism , and i want to share it in order to help other people that are blocked on a problem that i already had and already solved.

The code is a crap i'm working on improving it.

 ## Hardware Requirement :
 _SaPousse is built on a precise Hardware set, there is no warranties that other hardware will work without any modifications of the code._
 
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
   1. Ground EFIS System with Pseudo ILS configuration
   2. real time aviation map with waypoints placing.
   3. real time statistics of battery level , Link quality , etc.
   4. Config menu with Before flight Checklist, Nav parameters of the day (like ground pressure , max flight level etc.)
   5. Calibration menu to setup the sensors before the flight.
   

### Security features :
 _The wing that will serve as a test bench will weight around 1.5kg so the security features is a must and will be developped really carefully_
 
 __in any cases , if a failure appends , the airplane will give manual commands to the pilot if the radio is in range , in this degraded mode , the system will try as best as it can to give as mutch data as possible to the pilot by the ground station . if the radiocommand isn't in range , the motor will shut off automaticly and the plane will land on escape points that is configurated by the pilot before the flight.__
 
  1. in case of a sensor failure , the system will insure a measurement continuity by using other sensors to recreate the lost measurement.
  2. in case of a symetrical stall , the system will do a complete stall escape manuver.
  3. in case of an asymetrical stall , the system will stall the exterior wing in order to enter into a symetrical stall configuration.
   
## Features that are implemented :
  1. Config file on an SD card
  2. Complete calibration of the IMU
  3. Calibration save mecanism
  4. data sampling at a certain speed
  5. SBUS decoder to get data from the radiocommand
  
  

### Original Contributor : 
 Mathieu CUISSARD (matX01)
  
  
  

  
