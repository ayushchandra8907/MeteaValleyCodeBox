using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LBM;
extern motor LMM;
extern motor LFM;
extern motor RBM;
extern motor RMM;
extern motor RFM;
extern controller Controller1;
extern motor intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );