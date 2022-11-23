#pragma once

class pid
{
  private:
  /**
    * Structure of gain valuse for multiple variations
    */
  struct gains
  {
      double kP;
      double kI;
      double kD;
  };

  /**
    * Default PID gain config for all PID controllers for robud
    */
  const gains standard = {0,0,0};
  const int CMAX = 200; // RPM
  const int DMAX = 5;   // Unknown Unit
  gains currGain;
  // gains auto_gen;
  double cError;
  double pError;
  bool integrate = true;

  // Components
  double cmpP;
  double cmpI;
  double integralValue;
  double cmpD;
  double derivativeValue;
  double change;
  double mathValue;

  public:
  pid();
  pid(double kP, double kI, double kD);
  double runPID(double target, double current);
  void autoTune();
  void set_kP(double kP);
  void set_kI(double kI);
  void set_kD(double kD);
  void set_gains(gains nGain);
  void resetPID();
};