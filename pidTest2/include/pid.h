#ifndef PID_H
#define PID_H



#include "vex.h"
#include "robot-config.h"


//helper
double getPIDpos();
void powerMotors(double p);

//methods
void pidTranslate(double target);


#endif