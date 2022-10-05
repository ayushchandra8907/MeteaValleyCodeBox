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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  //driver control loop
  while(true){
    //driver control - tank drive
    RFM.spin(vex::forward, Controller1.Axis2.position(), vex::percent);
    RBM.spin(vex::forward, Controller1.Axis2.position(), vex::percent);
    LFM.spin(vex::forward, Controller1.Axis3.position(), vex::percent);
    LBM.spin(vex::forward, Controller1.Axis3.position(), vex::percent);



    wait(20, msec);
  }
}
