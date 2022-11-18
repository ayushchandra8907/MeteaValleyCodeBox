#ifndef AUTONHELPERS_H
#define AUTONHELPERS_H

#include "vex.h"
#include "robot-config.h"


//setter
void setDrive(double left, double right);

//tracking wheels
void clearTrackingWheels();
void getPos();

//move forward and backwards
void translate(double turns, double voltage);

//turn left or right
void rotate(double deg, double voltage);


#endif