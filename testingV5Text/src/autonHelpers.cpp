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

double getPos(){
  double r = rightTrack.position(turns);
  double l = leftTrack.position(turns);

  return (r+l)/2.0;
}


//move forward and backwards
void translate(double turns, double voltage){
    //get direction
    int dir = fabs(turns)/turns;

    //reset encoders
    clearTrackingWheels();

    //go forward
    while(fabs(getPos()) < fabs(turns)){
        setDrive(dir * voltage, dir * voltage);
        
    }

    //end
    setDrive(dir * -10, dir * -10);
    wait(20, msec);

    setDrive(0, 0);
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
