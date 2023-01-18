#include "gui.h"
//dimensions: 480x272

//AUTON
void autonGUI(){

}

//DRIVER CONTROL
void displayPatriotism(){
  clearBrain();

  //blue box
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(blue);
  Brain.Screen.drawRectangle(0, 0, 240, 120);

  //stripes
  double rect = 0; 
  int start = 240;
  int len = 240;

  for(int i = 0; i<13; i++){
    if(i%2 == 0){
      Brain.Screen.setFillColor(red);
      Brain.Screen.setPenColor(red);
      Brain.Screen.drawRectangle(start, rect, len, 20);
      rect += 20;
    } else {
      Brain.Screen.setFillColor(white);
      Brain.Screen.setPenColor(white);
      Brain.Screen.drawRectangle(start, rect, len, 20);
      rect += 20;
    }
    if(i == 5){
      start = 0;
      len = 480;
    }
  }
}

void displayBrazilia(){
  //green background
  clearBrain();

  Brain.Screen.setFillColor(green);
  Brain.Screen.setPenColor(green);
  Brain.Screen.drawRectangle(0, 0, 480, 272);

  //diamond
  //right triangle
  Brain.Screen.setPenColor(yellow);

  int size = 140;
  int index = 240;
  int y = 50;
  while(size > 0){
    Brain.Screen.drawLine(index, y, index, y+size);
    index++;
    y +=0.5;
    size -= 2;
  }
}

void displayIndia(){
  clearBrain();
  
  //orange
  Brain.Screen.setFillColor(orange);
  Brain.Screen.setPenColor(orange);
  Brain.Screen.drawRectangle(0, 0, 480, 80);
  //white
  Brain.Screen.setFillColor(white);
  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(0, 80, 480, 80);
  //green
  Brain.Screen.setFillColor(green);
  Brain.Screen.setPenColor(green);
  Brain.Screen.drawRectangle(0, 160, 480, 80);
  //blue center circle
  Brain.Screen.setFillColor(blue);
  Brain.Screen.setPenColor(blue);
  Brain.Screen.drawCircle(240, 120, 40);
}


void displayVelocityLogo(){
  clearBrain();

  Brain.Screen.setPenWidth(20);

  Brain.Screen.drawLine(50, 50, 200, 200);
}


void clearBrain(){
  Brain.Screen.clearScreen();
}