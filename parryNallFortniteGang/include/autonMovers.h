#ifndef AUTONMOVERS_H
#define AUTONMOVERS_H

#include "vex.h"
#include "robot-config.h"


//HELPERS==================================================================
//tracking wheels
void clearTrackingWheels();
double getPIDpos();

//motors
void powerMotors(double p);
void turnMotors(double p);
void stopMotors();

//REGULAR MOVEMENT========================================================
void autTranslate(double d, vex::rotationUnits units, double voltage);


//PID MOVEMENT============================================================
void pidTranslate(double target);
void pidTurn(double deg);


#endif