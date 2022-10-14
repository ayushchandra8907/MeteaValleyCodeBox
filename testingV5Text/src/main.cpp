/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Ayush                                            */
/*    Created:      Tue Oct 04 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RFM                  motor         1               
// RBM                  motor         2               
// LFM                  motor         3               
// LBM                  motor         4               
// Controller1          controller                    
// rightTrack           encoder       A, B            
// centTrack            encoder       C, D            
// leftTrack            encoder       E, F            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  rightTrack.setPosition(0, degrees);
  centTrack.setPosition(0, degrees);
  leftTrack.setPosition(0, degrees);
  
  //driver control loop
  while(true){
    //driver control - tank drive
    RFM.spin(vex::forward, Controller1.Axis2.position(), vex::percent);
    RBM.spin(vex::forward, Controller1.Axis2.position(), vex::percent);
    LFM.spin(vex::forward, Controller1.Axis3.position(), vex::percent);
    LBM.spin(vex::forward, Controller1.Axis3.position(), vex::percent);


    Brain.Screen.printAt(20, 40, "Right Track %f", rightTrack.position(degrees));
    Brain.Screen.printAt(20, 60, "Cent Track %f", centTrack.position(degrees));
    Brain.Screen.printAt(20, 80, "Left Track %f", leftTrack.position(degrees));



    wait(20, msec);
  }
}
