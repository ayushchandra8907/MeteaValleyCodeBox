#include "pid.h"


double kP = 1;
double kI = 0;
double kD = 0;


//helper
double getPIDpos(){
  double r = rightTrack.position(degrees);
  double l = leftTrack.position(degrees);

  return r/2.0;
}

void powerMotors(double p){
  RFM.spin(forward, p, volt);
  RBM.spin(forward, p, volt);
  LFM.spin(forward, p, volt);
  LBM.spin(forward, p, volt);
}

//methods
void pidTranslate(double target){
  double error = target - getPIDpos();
  double motPow = error*kP;


  while(true){
    error = target - getPIDpos();
    motPow = error*kP;

    powerMotors(motPow);
  }




  
}