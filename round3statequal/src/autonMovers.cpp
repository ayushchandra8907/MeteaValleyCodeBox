#include "autonMovers.h"


//HELPERS=============================================================================
//tracking wheels
void clearTrackingWheels(){
  straightTrack.setPosition(0, degrees);
}

double getPIDpos(){
  return straightTrack.position(degrees);;
}

//motors
void powerMotors(double p){
  RFM.spin(forward, p, volt);
  RBM.spin(forward, p, volt);
  LFM.spin(forward, p, volt);
  LBM.spin(forward, p, volt);
}

void turnMotors(double p){
  RFM.spin(reverse, p, volt);
  RBM.spin(reverse, p, volt);
  LFM.spin(forward, p, volt);
  LBM.spin(forward, p, volt);
}

void stopMotors(){
  RFM.stop();
  RBM.stop();
  LFM.stop();
  LBM.stop();
}


//REGULAR MOVEMENT=====================================================================
void autTranslate(double d, vex::rotationUnits units, double speed){
  RFM.setVelocity(speed, percent);
  RBM.setVelocity(speed, percent);
  LFM.setVelocity(speed, percent);
  LBM.setVelocity(speed, percent);

  RFM.spinFor(forward, d, units, false);
  RBM.spinFor(forward, d, units, false);
  LFM.spinFor(forward, d, units, false);
  LBM.spinFor(forward, d, units);

  RFM.setVelocity(100, percent);
  RBM.setVelocity(100, percent);
  LFM.setVelocity(100, percent);
  LBM.setVelocity(100, percent);
}


//PID MOVEMENT=========================================================================
void pidTranslate(double target){
  double kP = 0.25;
  double kI = 0;
  double kD = 0.1;

  double error = target - getPIDpos();
  double integral = 0;
  double derivative = 0;
  double prevError = error;

  double motPow = 0;

  double timeElap = 0;

  while(timeElap < 1500){

    //p for proportional
    error = target - getPIDpos();


    //i for intregral
    if (error <= 0)
      integral = 0;
    integral += error;

    //d for derivative
    derivative = error-prevError;
    prevError = error;


    motPow = error*kP + integral*kI + error*kD;
    //Brain.Screen.printAt(20, 40, "Right Track %3f", straightTrack.position(degrees));
    
    powerMotors(motPow);

    timeElap += 20;

    wait(20, msec);
  } 
}

void pidTurn(double degrees) {
  int dt = 20;  // Recommended wait time in milliseconds
  double target = degrees; // In revolutions
  double error = target - Inertial.rotation();
  double tP = .25; //.17
  double tD = 0.05; //.035
  double prevError = error;

  double timeElap = 0;

  while (timeElap < 2000) {
    error = target - Inertial.rotation();
    double derivative = (error - prevError)/dt;
    double percent = tP * error + tD * derivative;

    Brain.Screen.printAt(20, 40, "Inertial: %f", Inertial.rotation());

    turnMotors(percent);

    vex::task::sleep(dt);
    prevError = error;

    timeElap += dt;
  }
  
  stopMotors();

}
