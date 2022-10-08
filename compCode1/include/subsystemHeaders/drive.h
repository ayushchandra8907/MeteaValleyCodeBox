#ifndef DRIVE_H
#define DRIVE_H

#include "main.h"
#include "globals.h"

//drive functions
void setDriveMotors(); //joystick input to motor output

//auton functions
void translate(double units, double voltage); //moves robot autonomously forward or backward


//helper functions
void setDrive(double left, double right); //sends powers to left and right side motors
void clearDriveMotors(); //resets IMEs
double getMotorPosition(); //returns position from IMEs


#endif