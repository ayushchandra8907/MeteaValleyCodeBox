#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RFM = motor(PORT1, ratio18_1, false);
motor RBM = motor(PORT2, ratio18_1, false);
motor LFM = motor(PORT3, ratio18_1, true);
motor LBM = motor(PORT4, ratio18_1, true);
controller Controller1 = controller(primary);
encoder rightTrack = encoder(Brain.ThreeWirePort.A);
encoder centTrack = encoder(Brain.ThreeWirePort.C);
encoder leftTrack = encoder(Brain.ThreeWirePort.E);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}