#include "subsystemHeaders/intake.h"
#include "main.h"
#include "globals.h"

void setIntakeMotors(){
    //forward & reverse
    if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        intake = 100;
    } else if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intake = -100;
    } else {
        intake = 0;
    }
}