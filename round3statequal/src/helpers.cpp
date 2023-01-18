#include "helpers.h"
//#include "pid.h"

//GENERAL USE========================================================
void buttonHold(motor m, bool fwd, bool rev, int pow, vex::brakeType b){
  if(fwd){
      m.spin(forward, pow, percent);
  } else if (rev){
      m.spin(reverse, pow, percent);
  } else {
      m.stop(b);
  }
}

void buttonHold(motor m, bool fwd, int pow, vex::brakeType b){
  if(fwd){
      m.spin(forward, pow, percent);
  } else {
      m.stop(b);
  }
}

void buttonHoldVolt(motor m, bool fwd, int pow){
  if(fwd){
      m.spin(forward, pow, volt);
  } else {
      m.stop(coast);
  }
}

//DRIVE===============================================================
double rPow;
double lPow;


//FLYWHEEL============================================================
double flyPow = 9; //default flywheel power
void flyPowIncrease(){
  if(!(flyPow >= 12)){
    flyPow += .1;
  } 
}
void flyPowDecrease(){
  if(!(flyPow <= 0)){
    flyPow -= .1;
  } 
}

//ENDGAME=============================================================
void endgameTrigger(){
  Brain.Screen.print("BRAZILIA");
  Controller1.Screen.print("BRAZILA");
}
