#ifndef DRIVE_H
#define DRIVE_H

#include "main.h"
#include "globals.h"

//drive functions
void setDriveMotors(); //joystick input to motor output

//auton functions
void translateIME(double units, double voltage); //moves robot autonomously forward or backward


//helper functions
void setDrive(double left, double right); //sends powers to left and right side motors
void clearTrackingWheels(); //resets tracking wheels
void clearDriveMotors(); //resets IMEs
double getMotorPosition(); //returns position from IMEs

//button functions
void BUTTON_MACROS();


#endif