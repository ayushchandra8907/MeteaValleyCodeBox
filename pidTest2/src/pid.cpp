#include "pid.h"


double kP = 0.08;
double kI = 0;
double kD = 0;


//helper
double getPIDpos(){
  double r = rightTrack.position(degrees);
  double l = leftTrack.position(degrees);

  return r/1.0;
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
  double integral = 0;
  double derivative = 0;
  double prevError = error;

  double motPow = 0;


  while(true){

    //p for porn
    error = target - getPIDpos();


    //i for intercourse
    if (error <= 0)
      integral = 0;
    integral += error;

    //d for dick
    derivative = error-prevError;
    prevError = error;



    motPow = error*kP + integral*kI + error*kD;




    Brain.Screen.printAt(20, 40, "Right Track %3f", rightTrack.position(degrees));
    
    powerMotors(motPow);

    wait(20, msec);
  }




  
}