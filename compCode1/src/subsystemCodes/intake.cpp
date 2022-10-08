#include "subsystemHeaders/intake.h"
#include "main.h"
#include "globals.h"
#include "pros/misc.h"
#include "pros/motors.h"

//basic button movement
void setIntakeMotors(){
    //forward
    if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        intake = 100;
    }  
    
    //reverse
    if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intake = -100;
    } 
}