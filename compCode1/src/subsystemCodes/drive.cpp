#include "subsystemHeaders/drive.h"
#include "globals.h"
#include "main.h"
#include "pros/misc.h"

//drive functions==============================================================
void setDriveMotors() {
    double leftJoy = Controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    double rightJoy = Controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    setDrive(leftJoy, rightJoy);
}

//auton functions==============================================================
void translateIME(double units, double voltage){
    //get direction
    int dir = fabs(units)/units;

    //reset encoders
    clearDriveMotors();

    //go forward
    while(fabs(getMotorPosition()) < fabs(units)){
        setDrive(dir * voltage, dir * voltage);
        pros::delay(20);
    }

    //end
    setDrive(dir * -10, dir * -10);
    pros::delay(50);

    setDrive(0, 0);
}


//helper functions==============================================================
void setDrive(double left, double right){
    RFM = right;
    RBM = right;
    LFM = left;
    LBM = left;
}

void clearDriveMotors(){
    RFM.tare_position();
    RBM.tare_position();
    LFM.tare_position();
    LBM.tare_position();
}

void clearTrackingWheels(){
    rightTrack.reset();
    centTrack.reset();
    leftTrack.reset();
}

double getMotorPosition(){
    double sumPos = RFM.get_position() + RBM.get_position() + LFM.get_position() + LBM.get_position();

    return sumPos/4.0;
    
}

//Button functions===============================================================
void BUTTON_MACROS(){

    //resets encoders
    if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
        clearTrackingWheels();
    }


    //prints encoder values
    if(Controller1.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
        pros::lcd::print(0, "Rigt Tracking Wheel: %5.4f", rightTrack.get_value());
        pros::lcd::print(1, "Cent Tracking Wheel: %5.4f", centTrack.get_value());
        pros::lcd::print(2, "Left Tracking Wheel: %5.4f", leftTrack.get_value());
    }
}


