using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RFM;
extern motor RBM;
extern motor LFM;
extern motor LBM;
extern controller Controller1;
extern encoder rightTrack;
extern encoder centTrack;
extern encoder leftTrack;
extern motor intake;
extern motor indexer;
extern motor fly1;
extern motor fly2;
extern motor endgame;
extern inertial inert1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );