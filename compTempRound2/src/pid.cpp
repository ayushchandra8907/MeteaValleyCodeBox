#include "vex.h"
#include "pid.h"

pid::pid(){
    // Copy to currGain to allow program to overwrite if neccessary
    this->currGain.kP = this->standard.kP;    
    this->currGain.kI = this->standard.kI;    
    this->currGain.kD = this->standard.kD;
}

pid::pid(double kP, double kI, double kD){
    this->currGain.kP = kP;    
    this->currGain.kI = kI;    
    this->currGain.kD = kD;
}

double pid::runPID(double target, double current)
{
    cError = target - current;

    cmpP = currGain.kP * cError;
    if(0==1) {integralValue += cError;} // integrator permently turned off
    cmpI = currGain.kI * integralValue;
    derivativeValue = cError - pError;
    cmpD = currGain.kD * derivativeValue;
    
    // Derivative Limiter //
    if(cmpD > DMAX)
        cmpD = DMAX;
    ////////////////////////
    
    change = cmpP + cmpI + cmpD;
    
    // Integrater Clamp //
    if(change > CMAX)   // Satuatation
        change = CMAX;  // Sets max command that is allowed // RPM //
    
    if((change > CMAX) && ((change >= 0 && cError >= 0) || (change < 0 && cError < 0))) // Windup Check
        integrate = false; // integrater is making things worse
    else
        integrate = true; // Integrater has a movement effective value
    //////////////////////
    return change;
}

void pid::autoTune()
{
    // auto tuner that uses previous data to account for gains factors
    /*
    So to work this out, this may involve using regression to find the factor that
    allows for the difference between wanted (mathamatical) and actual (physical model)
    */
}

void pid::resetPID()
{
    cError          = 0;
    pError          = 0;
    integrate       = true;
    cmpP            = 0;
    cmpI            = 0;
    integralValue   = 0;
    cmpD            = 0;
    derivativeValue = 0;
    change          = 0;
    mathValue       = 0;
}

void pid::set_kP    (double kP)      { this->currGain.kP = kP; }

void pid::set_kI    (double kI)      { this->currGain.kI = kI; }

void pid::set_kD    (double kD)      { this->currGain.kD = kD; }

void pid::set_gains (gains nGain)    { this->currGain = nGain; }
