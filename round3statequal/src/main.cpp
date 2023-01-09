// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RFM                  motor         16              
// RBM                  motor         13              
// LFM                  motor         3               
// LBM                  motor         10              
// sideTrack            encoder       E, F            
// centTrack            encoder       C, D            
// intake               motor         20              
// indexer              motor         14              
// fly1                 motor         8               
// fly2                 motor         9               
// Inertial             inertial      11              
// autonSwitch          bumper        G               
// ---- END VEXCODE CONFIGURED DEVICES ----



#include "vex.h"
#include "helpers.h"
#include "autonMovers.h"
#include "autonRoutines.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
  Inertial.calibrate();

  sideTrack.setPosition(0, degrees);
  centTrack.setPosition(0, degrees);

  autonSwitch.pressed(switchAut);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // switch(currentAut) {
  //   case 0:
  //     autonRoute0();
  //     Brain.Screen.printAt(20, 40, "Selected Auton:", currentAut);
  //     break;

  //   case 1:
  //     autonRoute1();
  //     Brain.Screen.printAt(20, 40, "Selected Auton:", currentAut);
  //     break;

  //   case 2:
  //     autonRoute2();
  //     Brain.Screen.printAt(20, 40, "Selected Auton:", currentAut);
  //     break;
  // }
  
  waitUntil(Inertial.isCalibrating() == false);
  
  //pidTurn(90);

  double inches = 31.0;

  autTranslate(360 * (inches/4/3.14), degrees, 20); //360 degrees at 10 percent
  pidTurn(-90); //left 90 degrees

  //intake shit shit shit code after sleep shit code


  pidTurn(-90 - 45);
  inches = 101;
  autTranslate(360 * (inches/4/3.14), degrees, 50);

  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  sideTrack.setPosition(0, degrees);
  centTrack.setPosition(0, degrees);


  Controller1.ButtonA.pressed(clearTrackingWheels);

  //flywheel settings
  Controller1.ButtonUp.pressed(flyPowIncrease);
  Controller1.ButtonDown.pressed(flyPowDecrease);

  //endgame
  Controller1.ButtonY.pressed(endgameTrigger);

  while (1) {
    //DEBUGGING-----------------------------------
      // if(Controller1.ButtonX.pressing()){
      //   //Brain.Screen.printAt(20, 40, "Inertial %3f", Inertial.rotation());
      //   Controller1.Screen.setCursor(1, 1);
      //   Controller1.Screen.print("flypow = %f", flyPow);
      // } else {
      //   //Brain.Screen.clearScreen();
      // }


    //driver control - tank drive============================================    
    rPow = (pow(Controller1.Axis2.position(), 3))*(pow(0.01, 2));
    lPow = (pow(Controller1.Axis3.position(), 3))*(pow(0.01, 2));

    RFM.spin(vex::forward, rPow, vex::percent);
    RBM.spin(vex::forward, rPow, vex::percent);
    LFM.spin(vex::forward, lPow, vex::percent);
    LBM.spin(vex::forward, lPow, vex::percent);


    //buttons---------------------------------------------------------------------------------------------
    //intake, roller, indexer
    buttonHold(intake, Controller1.ButtonL1.pressing(), Controller1.ButtonR1.pressing(), 100, coast);

    //flywheel
    buttonHoldVolt(fly1, Controller1.ButtonL2.pressing(), flyPow);
    buttonHoldVolt(fly2, Controller1.ButtonL2.pressing(), flyPow);

    //endgame
    buttonHoldVolt(endgame, Controller1.ButtonRight.pressing(), 12);


    wait(20, msec); 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
