#ifndef GLOBALS_H
#define GLOBALS_H

#include "main.h"
#include "pros/adi.hpp"

//controller
extern pros::Controller Controller1;

//motors
extern pros::Motor RFM;
extern pros::Motor RBM;
extern pros::Motor LFM;
extern pros::Motor LBM;

extern pros::Motor intake;


//sensors
extern pros::ADIEncoder rightTrack;
extern pros::ADIEncoder centTrack;
extern pros::ADIEncoder leftTrack;

#endif