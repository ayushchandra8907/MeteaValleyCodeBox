using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RBM;
extern motor RFM;
extern motor LFM;
extern motor LBM;
extern encoder rightTrack;
extern encoder centTrack;
extern encoder leftTrack;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );