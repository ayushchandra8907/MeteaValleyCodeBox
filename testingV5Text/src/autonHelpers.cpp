#include "autonHelpers.h"

//setter
void setDrive(double left, double right){
  RFM.spin(forward, right, percent);
  RBM.spin(forward, right, percent);
  LFM.spin(forward, left, percent);
  LBM.spin(forward, left, percent);
}

//tracking wheels
void clearTrackingWheels(){
  rightTrack.setPosition(0, degrees);
  centTrack.setPosition(0, degrees);
  leftTrack.setPosition(0, degrees);
}

double getTrackPos(vex::rotationUnits u){
  double r = rightTrack.position(u);
  double l = leftTrack.position(u);

  return (r+l)/2.0;
}


//move forward and backwards
void translate(double d, vex::rotationUnits units, double speed){
    //get direction
    int dir = fabs(d)/d;

    //reset encoders
    clearTrackingWheels();

    //go forward
    while(fabs(getTrackPos(units)) < fabs(d)){
        RFM.spin(forward, speed, volt);
        LFM.spin(forward, speed, volt);
        RBM.spin(forward, speed, volt);
        LBM.spin(forward, speed, volt);
        
    }

    //end
    //setDrive(dir * -10, dir * -10);
    wait(20, msec);

    //setDrive(0, 0);
}

//turn left or right
void rotate(double deg, double voltage){
    //get direction
    int dir = fabs(deg)/deg;

    //reset encoders
    inert1.setHeading(0, degrees);

    //go forward
    while(fabs(inert1.heading(degrees)) < fabs(deg)){
        setDrive(-1 * dir * voltage, dir * voltage);
    }

    //end
    setDrive(dir * 10, dir * -10);
    wait(20, msec);    
}
