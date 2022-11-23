// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RFM                  motor         15              
// RBM                  motor         13              
// LFM                  motor         3               
// LBM                  motor         10              
// Controller1          controller                    
// rightTrack           encoder       E, F            
// centTrack            encoder       C, D            
// leftTrack            encoder       A, B            
// intake               motor         20              
// indexer              motor         18              
// fly1                 motor         19              
// fly2                 motor         1               
// endgame              motor         9               
// inert1               inertial      11              
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
void buttonHold(motor m, bool fwd, bool rev, int pow, vex::brakeType b){
  if(fwd){
      m.spin(forward, pow, percent);
  } else if (rev){
      m.spin(reverse, pow, percent);
  } else {
      m.stop(b);
  }
}

void buttonHold(motor m, bool fwd, int pow, vex::brakeType b){
  if(fwd){
      m.spin(forward, pow, percent);
  } else {
      m.stop(b);
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
//drivetrain
double rPow;
double lPow;
double fwdD = 1;

void switchDir(){
  fwdD *= -1;
}



//flywheel
double flyPow = 12;
void flySpeed1(){flyPow = 12;}
void flySpeed2(){flyPow = 9;}
void flySpeed3(){flyPow = 6;}

//TESTING AUTONOMOUS
void testAut(){
  translate(5, turns, 12);
  rotate(90, 5);
  translate(-5, turns, 12);
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
  Controller1.ButtonLeft.pressed(switchDir);

  //flywheel settings
  Controller1.ButtonUp.pressed(flySpeed1);
  Controller1.ButtonRight.pressed(flySpeed2);
  Controller1.ButtonDown.pressed(flySpeed3);
  
  
  //driver control loop
  while(true){
    //driver control - tank drive
    rPow = fwdD*(RFM.velocity(percent) + (Controller1.Axis2.position() - RFM.velocity(percent))*0.3);
    lPow = fwdD*(LFM.velocity(percent) + (Controller1.Axis3.position() - LFM.velocity(percent))*0.3);

    if(fabs(rPow) <= 10){rPow = 0;}
    if(fabs(lPow) <= 10){lPow = 0;}


    RFM.spin(vex::forward, rPow, vex::percent);
    RBM.spin(vex::forward, rPow, vex::percent);
    LFM.spin(vex::forward, lPow, vex::percent);
    LBM.spin(vex::forward, lPow, vex::percent);


    //encoders
    if(Controller1.ButtonX.pressing()){
      Brain.Screen.printAt(20, 40, "Right Track %3f", rightTrack.position(degrees));
      Brain.Screen.printAt(20, 60, "Cent Track %3f", centTrack.position(degrees));
      Brain.Screen.printAt(20, 80, "Left Track %3f", leftTrack.position(degrees));
    } else {
      Brain.Screen.clearScreen();
    }

    //buttons--------------
    //indexer

    if(Controller1.ButtonR2.pressing()){
      indexer.spin(forward, 75, percent);
    } else {
      indexer.stop(hold);
    }

    //intake
    buttonHold(intake, Controller1.ButtonL2.pressing(), Controller1.ButtonL1.pressing(), 100, coast);

    //flywheel
    buttonHoldVolt(fly1, Controller1.ButtonR1.pressing(), flyPow);
    buttonHoldVolt(fly2, Controller1.ButtonR1.pressing(), flyPow);

    //endgame
    buttonHold(endgame, Controller1.ButtonY.pressing(), Controller1.ButtonB.pressing(), 100, hold);


    // while(getTrackPos(degrees) <= 100){
    //   RFM.spin(forward, 12, volt);
    //   RBM.spin(forward, 12, volt);
    //   LFM.spin(forward, 12, volt);
    //   LBM.spin(forward, 12, volt);

    //   Brain.Screen.printAt(20, 80, "Avg Pos %3f", getTrackPos(degrees));
    // }

    wait(20, msec);
  }
}
