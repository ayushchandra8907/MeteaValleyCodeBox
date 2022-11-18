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
// fly1                 motor         7               
// fly2                 motor         8               
// endgame              motor         9               
// inert1               inertial      20              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "autonHelpers.h"

using namespace vex;


//sensors
void resetEncoders(){
  rightTrack.setPosition(0, degrees);
  centTrack.setPosition(0, degrees);
  leftTrack.setPosition(0, degrees);
}


//helper functions
void buttonHold(motor m, bool fwd, bool rev, int pow){
  if(fwd){
      m.spin(forward, pow, percent);
  } else if (rev){
      m.spin(reverse, pow, percent);
  } else {
      m.stop(coast);
  }
}

void buttonHold(motor m, bool fwd, int pow){
  if(fwd){
      m.spin(forward, pow, percent);
  } else {
      m.stop(coast);
  }
}

void buttonHoldVolt(motor m, bool fwd, int pow){
  if(fwd){
      m.spin(forward, pow, volt);
  } else {
      m.stop(coast);
  }
}

//variables and others
double flyPow = 12;
void flySpeed1(){flyPow = 12;}
void flySpeed2(){flyPow = 9;}
void flySpeed3(){flyPow = 6;}
void flySpeed4(){flyPow = 3;}


void autonomous(){
  //put functions here
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  rightTrack.setPosition(0, degrees);
  centTrack.setPosition(0, degrees);
  leftTrack.setPosition(0, degrees);

  inert1.calibrate();
  inert1.setHeading(0, degrees);

  Controller1.ButtonA.pressed(resetEncoders);

  //flywheel settings
  Controller1.ButtonUp.pressed(flySpeed1);
  Controller1.ButtonRight.pressed(flySpeed2);
  Controller1.ButtonDown.pressed(flySpeed3);
  Controller1.ButtonLeft.pressed(flySpeed4);
  
  //driver control loop
  while(true){
    //driver control - tank drive
    RFM.spin(vex::forward, Controller1.Axis2.position(), vex::percent);
    RBM.spin(vex::forward, Controller1.Axis2.position(), vex::percent);
    LFM.spin(vex::forward, Controller1.Axis3.position(), vex::percent);
    LBM.spin(vex::forward, Controller1.Axis3.position(), vex::percent);

    if(Controller1.ButtonX.pressing()){
      Brain.Screen.printAt(20, 40, "Right Track %3f", rightTrack.position(degrees));
      Brain.Screen.printAt(20, 60, "Cent Track %3f", centTrack.position(degrees));
      Brain.Screen.printAt(20, 80, "Left Track %3f", leftTrack.position(degrees));
    }

    //buttons--------------
    //indexer
    buttonHold(indexer, Controller1.ButtonR2.pressing(), 75);

    //intake
    buttonHold(intake, Controller1.ButtonL2.pressing(), Controller1.ButtonL1.pressing(), 75);

    //flywheel
    buttonHoldVolt(fly1, Controller1.ButtonR1.pressing(), flyPow);
    buttonHoldVolt(fly1, Controller1.ButtonR1.pressing(), flyPow);

    //endgame
    buttonHold(endgame, Controller1.ButtonY.pressing(), Controller1.ButtonB.pressing(), 100);


    wait(20, msec);
  }
}
