#include "subsystemHeaders/indexer.h"
#include "pros/misc.h"
#include "pros/motors.h"

//main function
void indexDiscs(){
    if(Controller1.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        indexer = 100;
    } else {
        indexer.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        indexer = 0;
    }
}