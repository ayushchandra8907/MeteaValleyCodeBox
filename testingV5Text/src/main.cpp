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
// intake               motor         5               
// indexer              motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


void resetEncoders(){
  rightTrack.setPosition(0, degrees);
  centTrack.setPosition(0, degrees);
  leftTrack.setPosition(0, degrees);
}

void buttonHold(motor m, bool fwd, bool rev){
  if(fwd){
      m.spin(forward, 100, percent);
  } else if (rev){
      m.spin(reverse, 100, percent);
  } else {
      m.stop(coast);
  }
}

void buttonHold(motor m, bool fwd){
  if(fwd){
      m.spin(forward, 100, percent);
  } else {
      m.stop(coast);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  rightTrack.setPosition(0, degrees);
  centTrack.setPosition(0, degrees);
  leftTrack.setPosition(0, degrees);

  Controller1.ButtonUp.pressed(resetEncoders);
  
  //driver control loop
  while(true){
    //driver control - tank drive
    RFM.spin(vex::forward, Controller1.Axis2.position(), vex::percent);
    RBM.spin(vex::forward, Controller1.Axis2.position(), vex::percent);
    LFM.spin(vex::forward, Controller1.Axis3.position(), vex::percent);
    LBM.spin(vex::forward, Controller1.Axis3.position(), vex::percent);

    if(Controller1.ButtonDown.pressing()){
      Brain.Screen.printAt(20, 40, "Right Track %3f", rightTrack.position(degrees));
      Brain.Screen.printAt(20, 60, "Cent Track %3f", centTrack.position(degrees));
      Brain.Screen.printAt(20, 80, "Left Track %3f", leftTrack.position(degrees));
    }

    //buttons--------------
    //indexer
    buttonHold(indexer, Controller1.ButtonR2.pressing());

    //intake
    buttonHold(intake, Controller1.ButtonL2.pressing(), Controller1.ButtonL1.pressing());


    wait(20, msec);
  }
}
