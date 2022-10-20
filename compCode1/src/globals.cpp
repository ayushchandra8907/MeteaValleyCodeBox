#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

//controller
pros::Controller Controller1(pros::E_CONTROLLER_MASTER);

//motors
pros::Motor RFM(1, pros::E_MOTOR_GEARSET_18, false);
pros::Motor RBM(2, pros::E_MOTOR_GEARSET_18, false);
pros::Motor LFM(3, pros::E_MOTOR_GEARSET_18, true);
pros::Motor LBM(4, pros::E_MOTOR_GEARSET_18, true);

pros::Motor intake(5, pros::E_MOTOR_GEARSET_18, false);
pros::Motor indexer(6, pros::E_MOTOR_GEARSET_18, false);

//sensors
pros::ADIEncoder rightTrack('A', 'B', false);
pros::ADIEncoder centTrack('C', 'D', false);
pros::ADIEncoder leftTrack('E', 'F', false);


