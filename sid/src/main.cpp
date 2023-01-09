/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Ayush                                            */
/*    Created:      Sat Jan 07 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LBM                  motor         1               
// LMM                  motor         2               
// LFM                  motor         3               
// RBM                  motor         4               
// RMM                  motor         5               
// RFM                  motor         6               
// Controller1          controller                    
// intake               motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(true){
    LBM.spin(forward, Controller1.Axis3.position(), percent);
    LMM.spin(forward, Controller1.Axis3.position(), percent);
    LFM.spin(forward, Controller1.Axis3.position(), percent);
    RBM.spin(forward, Controller1.Axis2.position(), percent);
    RMM.spin(forward, Controller1.Axis2.position(), percent);
    RFM.spin(forward, Controller1.Axis2.position(), percent);

    if(Controller1.ButtonR2.pressing()){
      intake.spin(forward, 100, percent);
    } else if(Controller1.ButtonL2.pressing()){
      intake.spin(reverse, 100, percent);
    } else {
      intake.stop(coast);
    }


    wait(20, msec);
  }
  
}
