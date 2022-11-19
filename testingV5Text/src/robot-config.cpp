#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RFM = motor(PORT15, ratio18_1, false);
motor RBM = motor(PORT13, ratio18_1, false);
motor LFM = motor(PORT3, ratio18_1, true);
motor LBM = motor(PORT10, ratio18_1, true);
controller Controller1 = controller(primary);
encoder rightTrack = encoder(Brain.ThreeWirePort.E);
encoder centTrack = encoder(Brain.ThreeWirePort.C);
encoder leftTrack = encoder(Brain.ThreeWirePort.A);
motor intake = motor(PORT20, ratio18_1, true);
motor indexer = motor(PORT18, ratio18_1, true);
motor fly1 = motor(PORT19, ratio6_1, false);
motor fly2 = motor(PORT1, ratio6_1, true);
motor endgame = motor(PORT9, ratio18_1, false);
inertial inert1 = inertial(PORT11);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}