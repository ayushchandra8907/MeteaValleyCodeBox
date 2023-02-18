#include "autonRoutines.h"
#include "gui.h"

int currentAut = 3;

void switchAut(){
  currentAut++;
  
  if(currentAut == 4){
    currentAut = 0;
  }

  autonGUI();
}

//ROUTINES===========================================

//skills auton (0)
void skillsAut(){
  leftRoller();
  
  RFM.spin(forward);
  LFM.spin(forward);
  RBM.spin(forward);
  LBM.spin(forward);
  wait(3000, msec);
  RFM.stop(coast);
  LFM.stop(coast);
  RBM.stop(coast);
  LBM.stop(coast);

  pidTurn(90);

  RFM.spin(reverse);
  LFM.spin(reverse);
  RBM.spin(reverse);
  LBM.spin(reverse);
  wait(3500, msec);
  RFM.stop(coast);
  LFM.stop(coast);
  RBM.stop(coast);
  LBM.stop(coast);

  indexer.spinFor(reverse, 135, degrees);

  RFM.spin(forward);
  LFM.spin(forward);
  RBM.spin(forward);
  LBM.spin(forward);
  wait(3500, msec);
  RFM.stop(coast);
  LFM.stop(coast);
  RBM.stop(coast);
  LBM.stop(coast);

  pidTurn(45);

  RFM.spin(reverse);
  LFM.spin(reverse);
  RBM.spin(reverse);
  LBM.spin(reverse);
  wait(3000, msec);
  RFM.stop(coast);
  LFM.stop(coast);
  RBM.stop(coast);
  LBM.stop(coast);

  wait(2500, msec);

  pidTurn(45);

  endgame.spinFor(forward, 90, degrees);
  
}

//backupSkils auton (auton 1):
void nothingAut(){

}


//left side auton (auton 2):
void leftRoller(){


  RFM.setVelocity(20, percent);
  LFM.setVelocity(20, percent);
  RBM.setVelocity(20, percent);
  LBM.setVelocity(20, percent);

  RFM.spin(reverse);
  LFM.spin(reverse);
  RBM.spin(reverse);
  LBM.spin(reverse);

  wait(500, msec);

  RFM.stop(coast);
  LFM.stop(coast);
  RBM.stop(coast);
  LBM.stop(coast);

  indexer.spinFor(reverse, 60, degrees);

}

//right side auton (auton 3):
void leftAWP(){
  leftRoller();

  RFM.spin(forward);
  LFM.spin(forward);
  RBM.spin(forward);
  LBM.spin(forward);
  wait(500, msec);
  RFM.stop(coast);
  LFM.stop(coast);
  RBM.stop(coast);
  LBM.stop(coast);

  pidTurn(-17);

  //indexer.spinFor(forward, 50, degrees);

  fly1.spin(forward, 11.7, volt);
  wait(4000, msec);

  indexer.spinFor(reverse, 90, degrees);

  wait(4000, msec);

  indexer.spin(reverse);
  wait(5000, msec);

  indexer.stop();
  fly1.stop();


}


//RIGHT SIDE===================================================================
void rightRoller(){
  RFM.setVelocity(20, percent);
  LFM.setVelocity(20, percent);
  RBM.setVelocity(20, percent);
  LBM.setVelocity(20, percent);

  RFM.spin(forward);
  LFM.spin(forward);
  RBM.spin(forward);
  LBM.spin(forward);

  wait(3000, msec);

  pidTurn(-90);


  //going back
  RFM.spin(reverse);
  LFM.spin(reverse);
  RBM.spin(reverse);
  LBM.spin(reverse);

  wait(1500, msec);

  RFM.stop(coast);
  LFM.stop(coast);
  RBM.stop(coast);
  LBM.stop(coast);

  indexer.spinFor(reverse, 60, degrees);
}

