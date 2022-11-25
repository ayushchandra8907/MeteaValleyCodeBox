#include "main.h"
int auton = -1;

using namespace vex;
brain Brain;
controller Controller1;
competition Competition;

//Add motor definitions here:
motor rightFrontMotor (vex::PORT11, vex::gearSetting::ratio18_1, true); //Change the port number to change the port
motor rightRearMotor (vex::PORT12, vex::gearSetting::ratio18_1, true); //Change the port number to change the port
motor leftRearMotor (vex::PORT19, vex::gearSetting::ratio18_1, false); //Change the port number to change the port
motor leftFrontMotor (vex::PORT20, vex::gearSetting::ratio18_1, false); //Change the port number to change the port
motor placeHolderMotor1 (vex::PORT1, vex::gearSetting::ratio18_1); //Change the port number to change the port
motor placeHolderMotor2 (vex::PORT2, vex::gearSetting::ratio18_1); //Change the port number to change the port
motor placeHolderMotor3 (vex::PORT3, vex::gearSetting::ratio18_1); //Change the port number to change the port
motor placeHolderMotor4 (vex::PORT3, vex::gearSetting::ratio18_1); //Change the port number to change the port
//motor placeHolderTorqueMotor (vex::PORT3, vex::gearSetting::ratio36_1); //Just change the gearsetting on 
//                                                            the motor that has a changed insert to match these demo motors
//motor placeHolderSpeedMotor (vex::PORT3, vex::gearSetting::ratio6_1);

//Add sensor definitions here:
inertial Inertial(vex::PORT20); //Change the number to change the port
pot Potentiometer(Brain.ThreeWirePort.A); //Change the letter to change the port
limit LimitSwitch(Brain.ThreeWirePort.H); //Change the letter to change the port

//Add motor_group/drivetrain definitions here:
motor_group leftGroup(leftFrontMotor, leftRearMotor);
motor_group rightGroup(rightFrontMotor, rightRearMotor);
drivetrain driveTrain(leftGroup, rightGroup);
smartdrive smartDrive(leftGroup, rightGroup, Inertial, 12.56, 16, 16, distanceUnits::in);//Change the numbers according to the 
//                                                                                        size of your base as needed

void drive(double distanceInches, int speed) // Speed ranges from 0 to 100
//                     if you put in a negative number for distance then you will move backwards
{
  driveTrain.driveFor(directionType::fwd, distanceInches, distanceUnits::in, speed, velocityUnits::pct);
}

//turn method that turns to a target rotation
void pTurn(double degrees) //P loop turn code (better than the smartdrive methods once kP is tuned properly)
{
  if(Inertial.installed())
  {
    int dt = 20; // Recommended wait time in milliseconds
    double target = degrees; // In revolutions
    double error = target - Inertial.rotation();
    double kP = .6;
    while (std::abs(error) > 1) // Allows +- 1 degree variance, don't reduce unless you know what you are doing
    {
      error = target - Inertial.rotation();
      double percent = kP * error + 20 * error / std::abs(error);
      leftGroup.spin(directionType::fwd, percent, pct);
      rightGroup.spin(directionType::rev, percent, pct);
      vex::task::sleep(dt);
    }
    leftGroup.stop();
    rightGroup.stop();
  }
  else
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono40);
    Brain.Screen.setFillColor(red);
    Brain.Screen.print("No Inertial Sensor Installed");
  }
}

void pdTurn(double degrees) //PD loop turn code (better than the smartdrive and P loop methods once kP and kD are tuned properly)
{
  if(Inertial.installed())
  {
    int dt = 20;  // Recommended wait time in milliseconds
    double target = degrees; // In revolutions
    double error = target - Inertial.rotation();
    double kP = .7;
    double kD = .1;
    double prevError = error;
    while (std::abs(error) > 1) // Allows +- 1 degree variance, don't reduce unless you know what you are doing
    {
      error = target - Inertial.rotation();
      double derivative = (error - prevError)/dt;
      double percent = kP * error + kD * derivative;
      leftGroup.spin(directionType::fwd, percent, pct);
      rightGroup.spin(directionType::rev, percent, pct);
      vex::task::sleep(dt);
      prevError = error;
    }
    leftGroup.stop();
    rightGroup.stop();
  }
  else
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono40);
    Brain.Screen.setFillColor(red);
    Brain.Screen.print("Inertial Sensor Not Detected");
  }
}

void X_Button_Macro()
{

}

void Y_Button_Macro()
{
  
}

void Left_Button_Macro()
{
  
}

void Right_Button_Macro()
{
  
}

void drive_Tank() {
  leftGroup.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
  rightGroup.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
}

void drive_Arcade() {
  leftGroup.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  rightGroup.spin(vex::directionType::fwd, Controller1.Axis3.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
}

void controls()
{
        // ------------------------Drive

        drive_Arcade();
        // drive_Tank(); - Switch between the 2 and find what you/your driver wants to use

        // -----------------------------Add Button Commands Here:
        
        /* 
        
        -Not all of these if statements need code in them.
            You just need to code the buttons you want to use with the commands that you want the button press to complete.
        -Basically, all of these if statements sense if the button is pressing on the controller 
            and if that is true does all of the commands enclosed in the brackets {} of the statement.
        
        */
        if(Controller1.ButtonA.pressing())
        {
          //add commands here to complete when button is pressing
          //Demo code:
          placeHolderMotor1.spin(forward, 100, percentUnits::pct);
        }
        else if(Controller1.ButtonB.pressing())
        {
          //add commands here to complete when button is pressing
          //Demo code:
          placeHolderMotor1.spin(reverse, 100, percentUnits::pct);
        }
        else
        {
          //usually the motor stop command goes here
          //Demo code:
          placeHolderMotor1.stop(brakeType::brake); 
          //You can change the type of brake to better suit the type of system
          //For example,  use brake type hold for lift/arm mechanisms
        }

        if(Controller1.ButtonUp.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else if(Controller1.ButtonDown.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else
        {
          //usually the motor stop command goes here
        }

        if(Controller1.ButtonR1.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else if(Controller1.ButtonR2.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else
        {
          //usually the motor stop command goes here
        }

        if(Controller1.ButtonL1.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else if(Controller1.ButtonL2.pressing())
        {
          //add commands here to complete when button is pressing
        }
        else
        {
          //usually the motor stop command goes here
        }
}

// GUI initialization code, don't change unless you know what you are doing
void askPosition() 
{ 
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(prop30);
  Brain.Screen.setPenColor(color(180, 180, 180));
  Brain.Screen.printAt(0, 30, "Battery Percentage: %d%%", Brain.Battery.capacity());
  Brain.Screen.setFont(prop20);
  Brain.Screen.drawLine(300, 0, 300, 40);
  Brain.Screen.setPenColor(color(0, 150, 0));
  Brain.Screen.drawRectangle(305, 0, 170, 40, color(0, 150, 0));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(365, 25, false, "Skills");
  Brain.Screen.setPenColor(color(180, 180, 180));
  Brain.Screen.setFont(prop30);
  Brain.Screen.drawLine(0, 40, 480, 40);
  Brain.Screen.setPenColor(color(180, 0, 0));
  Brain.Screen.drawRectangle(10, 50, 220, 85, color(180, 0, 0));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(95, 100, false, "RFS");
  Brain.Screen.setPenColor(color(0, 0, 180));
  Brain.Screen.drawRectangle(250, 50, 220, 85, color(0, 0, 180));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(335, 100, false, "BFS");
  Brain.Screen.setPenColor(color(180, 0, 0));
  Brain.Screen.drawRectangle(10, 145, 220, 85, color(180, 0, 0));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(95, 195, false, "RBS");
  Brain.Screen.setPenColor(color(0, 0, 180));
  Brain.Screen.drawRectangle(250, 145, 220, 85, color(0, 0, 180));
  Brain.Screen.setPenColor(black);
  Brain.Screen.printAt(335, 195, false, "BBS");
  Brain.Screen.setPenColor(color(180, 180, 180));
}

//Auton recorder, do not change at all unless you know what you are doing (except for save file name if needed) 
void auton_recorder()
{
    uint8_t data[3000];
    Controller1.Screen.clearScreen();
    for(int count = 5; count > 0; count--)
    {
      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1, 1);
      Controller1.Screen.print(count);
      vex::task::sleep(1000);
    }
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Recording");
    for (int i = 0; i < 3000; i+= 5) 
    {
        controls();

        data[i] = (uint8_t) (leftGroup.velocity(vex::velocityUnits::pct) + 100);
        data[i + 1] = (uint8_t) (rightGroup.velocity(vex::velocityUnits::pct) + 100);
        data[i + 2] = (uint8_t) (placeHolderMotor1.velocity(vex::velocityUnits::pct) + 100);
        data[i + 3] = (uint8_t) (placeHolderMotor3.velocity(vex::velocityUnits::pct) + 100);
        data[i + 4] = (uint8_t) (placeHolderMotor4.velocity(vex::velocityUnits::pct) + 100);
        vex::task::sleep(20);
    }
    //Changing "data.txt" will change the savefile name, this will allow multiple recordings 
    Brain.SDcard.savefile("data.txt", data, 3000);
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Complete!");  
}

void pre_auton() 
{
  
  if(Inertial.installed())
  {
    Inertial.calibrate(2000);
    vex::task::sleep(2000);
    Brain.Screen.clearScreen();
    Brain.Screen.setFont(fontType::mono40);
    Brain.Screen.setFillColor(red);
    Brain.Screen.print("Inertial Sensor Calibrating");
  }

  int xLastTouch = Brain.Screen.xPosition();
  int yLastTouch = Brain.Screen.yPosition();
  askPosition();
  while (Brain.Screen.xPosition() == xLastTouch && Brain.Screen.yPosition() == yLastTouch) {
    vex::task::sleep(20);
  }
  bool k = true;
  while (k) {
    if ((Brain.Screen.xPosition() >= 10 && Brain.Screen.xPosition() <= 230) && (Brain.Screen.yPosition() >= 50 && Brain.Screen.yPosition() <= 135)) {
      auton = 0;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 250 && Brain.Screen.xPosition() <= 470) && (Brain.Screen.yPosition() >= 50 && Brain.Screen.yPosition() <= 135)) {
      auton = 1;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 10 && Brain.Screen.xPosition() <= 230) && (Brain.Screen.yPosition() >= 145 && Brain.Screen.yPosition() <= 230)) {
      auton = 2;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 250 && Brain.Screen.xPosition() <= 470) && (Brain.Screen.yPosition() >= 145 && Brain.Screen.yPosition() <= 230)) {
      auton = 3;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 305 && Brain.Screen.xPosition() <= 475) && (Brain.Screen.yPosition() >= 0 && Brain.Screen.yPosition() <= 40)) {
      auton = 4;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 15 && Brain.Screen.xPosition() <= 135) && (Brain.Screen.yPosition() >= 0 && Brain.Screen.yPosition() <= 40)) {
      auton = 5;
      k = false;
    } else if ((Brain.Screen.xPosition() >= 150 && Brain.Screen.xPosition() <= 290) && (Brain.Screen.yPosition() >= 0 && Brain.Screen.yPosition() <= 40)) {
      auton = 6;
      k = false;
    }
  }

  if (auton == 0) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("RFS Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("RFS Selected");
  } else if (auton == 1) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("BFS Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("BFS Selected");
  } else if (auton == 2) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("RBS Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("RBS Selected");
  } else if (auton == 3) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("BBS Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("BBS Selected");
  } else if (auton == 4) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Skills Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("Skills Selected");
  } else if (auton == 5) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Recorder Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("Recorder Selected");
  } else if (auton == 6) {
    Brain.Screen.clearScreen();
    Brain.Screen.print("Playback Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("Playback Selected");
  } else {
    Brain.Screen.clearScreen();
    Brain.Screen.print("No Auton Selected");
    Controller1.Screen.clearScreen();
    Controller1.Screen.print("No Auton Selected");
  }
}

void autoRFS()
{
    //Code Red Front Side auton here:
}

void autoBFS()
{
    //Code Blue Front Side auton here:
}

void autoRBS()
{
    //Code Red Back Side auton here:
}

void autoBBS()
{
    //Code Blue Back Side auton here:
}

void autoSkills()
{
    //Code Skills auton here:
}

void autonomous()
{
    if(auton == 0)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running RFS");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoRFS();
    }
    else if(auton == 1)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running BFS");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoBFS();
    }
    else if(auton == 2)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running RBS");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoRBS();
    }
    else if(auton == 3)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running BBS");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoBBS();
    }
    else if(auton == 4)
    {
        Controller1.Screen.clearScreen();
        Controller1.Screen.print("Running Skills");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
        autoSkills();
    }
    else if(auton == 6)
    {
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("Running Playback");
      Controller1.Screen.newLine();
      Controller1.Screen.print("Team 8995_");
      uint8_t buf[3000];
      Brain.SDcard.loadfile("data.txt", buf, 3000); //Change "data.txt" if needed to load from a different file 
    
      for (int i = 0; i < 3000; i+= 5) 
      {    
          leftGroup.spin(vex::directionType::fwd, buf[i] - 100, vex::velocityUnits::pct);
          rightGroup.spin(vex::directionType::fwd, buf[i + 1] - 100, vex::velocityUnits::pct);
          placeHolderMotor1.spin(vex::directionType::fwd, buf[i + 2] - 100, vex::velocityUnits::pct);
          placeHolderMotor2.spin(vex::directionType::fwd, buf[i + 2] - 100, vex::velocityUnits::pct);
          placeHolderMotor3.spin(vex::directionType::fwd, buf[i + 3] - 100, vex::velocityUnits::pct);
          placeHolderMotor4.spin(vex::directionType::fwd, buf[i + 4] - 100, vex::velocityUnits::pct);
          vex::task::sleep(20);
      }
    }
    else
    {
        //Doesn't run Auton
        Controller1.Screen.clearScreen();
        Controller1.Screen.print(":( i sleep");
        Controller1.Screen.newLine();
        Controller1.Screen.print("Team 8995_");
    }
}

void usercontrol()
{
    if(auton == 5) 
    {
      Controller1.Screen.clearScreen();
      Controller1.Screen.print("Running Recorder");
      Controller1.Screen.newLine();
      Controller1.Screen.print("Team 8995_");
    }

    Controller1.ButtonX.pressed(X_Button_Macro);
    Controller1.ButtonY.pressed(Y_Button_Macro);
    Controller1.ButtonLeft.pressed(Left_Button_Macro);
    Controller1.ButtonRight.pressed(Right_Button_Macro);

    while(1)
    {
      if(auton == 5) 
      {
        auton_recorder();
      } else 
      {
        controls();
      }
    }
}

int main() {

    //Run the pre-autonomous function.
    pre_auton();

    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.
    while(1)
    {
      vex::task::sleep(20);//Sleep the task for a short amount of time to prevent wasted resources.
    }
}
