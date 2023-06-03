#include <AccelStepper.h>
#include <math.h>
#include "X_moving_or.h"
#include "O_moving_or.h"
#include <string.h>
#include <avr/pgmspace.h>

#define limitSwitchZ 11   //z
#define limitSwitchY 10   //y
#define limitSwitchX 9    //x
String data, d4;
char d1, d2;
char sh, num;
int d3;
// Define the stepper motors and the pins the will use
AccelStepper stepperX(1, 2, 5); // (Type:driver, STEP, DIR)
AccelStepper stepperY(1, 3, 6);
AccelStepper stepperZ(1, 4, 7);

//double x = 500.0;
//double y = 0.0;
//double L1 = 250; // L1 = 250mm
//double L2 = 250; // L2 = 250mm
//
//int stepperXPosition = 0;
//int stepperYPosition = 0;
//int stepperZPosition = 0;

//const float theta1AngleToSteps = -33.333333;
//const float theta2AngleToSteps = 8.888888;
//const float zDistanceToSteps = 400;

//byte inputValue[5];
//int k = 0;

//String content = "";
//int data[8];

//int theta1Array[41];
//int theta2Array[41];
//int zArray[100];

int low = 32000;
int high = 20000;
int i, a, b, c, d, q, w, e, r;
void setup() {
  Serial.begin(115200);

  pinMode(limitSwitchZ, INPUT_PULLUP);
  pinMode(limitSwitchY, INPUT_PULLUP);
  pinMode(limitSwitchX, INPUT_PULLUP);

  // Stepper motors max speed
  stepperX.setMaxSpeed(5000);
  stepperX.setAcceleration(2000);
  stepperY.setMaxSpeed(5000);
  stepperY.setAcceleration(2000);
  stepperZ.setMaxSpeed(5000);
  stepperZ.setAcceleration(2000);

  homing(); 
  delay(50);
  stepperX.setAcceleration(000);
  stepperY.setAcceleration(000);
  stepperZ.setAcceleration(2000);
}
//void hinhO()
//{
//  a = abs(O_moveToX_9[0]);
//  b = O_moveToY_9[0];
//  // di chuyển đến vị trí đầu tiên
//  stepperX.setSpeed(300);
//  stepperX.moveTo(a);
//
//  stepperY.setSpeed(300);
//  stepperY.moveTo(b);
//  while (stepperX.currentPosition() != a || stepperY.currentPosition() != b)
//  {
//    Serial.println("run");
//    stepperX.run();
//    stepperY.run();
//  }
//  // hạ trục Z
//  stepperZ.setSpeed(2000);
//  stepperZ.moveTo(low);
//  while (stepperZ.currentPosition() != low)
//  {
//    stepperZ.run();
//  }
//  // vẽ chữ O
//  for (i = 0; i < 211; i++)
//  {
//    q = O_speedX_9[i];
//    w = abs(O_moveToX_9[i]);
//    e = O_speedY_9[i];
//    r = O_moveToY_9[i];
//    Serial.println(i);
//    stepperX.setSpeed(q);
//    stepperX.moveTo(w);
//
//    stepperY.setSpeed(e);
//    stepperY.moveTo(r);
//
//    while (stepperX.currentPosition() != w || stepperY.currentPosition() != r)
//    {
//      stepperX.run();
//      stepperY.run();
//    }
//  }
//  // nâng trục Z
//  stepperZ.moveTo(high);
//  while (stepperZ.currentPosition() != high)
//  {
//    stepperZ.run();
//  }
//}
void hinhX(int movetox[], int movetoy[], float move_speedx[], float move_speedy[])
{
          a = abs(movetox[0]);
          b = movetoy[0];
          c = abs(movetox[101]);
          d = movetoy[101];
          
          stepperX.setSpeed(300);
          stepperX.moveTo(a);
        
          stepperY.setSpeed(300);
          stepperY.moveTo(b);
          while (stepperX.currentPosition() != a || stepperY.currentPosition() != b)
          {
            Serial.println("run");
            stepperX.run();
            stepperY.run();
          }
          // hạ trục Z
          stepperZ.setSpeed(2000);
          stepperZ.moveTo(low);
          while (stepperZ.currentPosition() != low)
          {
            stepperZ.run();
          }
          // vẽ "\"
          for (i = 1; i <= 100; i++)
          {
            q = movetox[i];
            w = abs(movetox[i]);
            e = move_speedx[i];
            r = movetoy[i];
        
            Serial.println(i);
            stepperX.setSpeed(q);
            stepperX.moveTo(w);
        
            stepperY.setSpeed(e);
            stepperY.moveTo(r);
        
            while (stepperX.currentPosition() != w || stepperY.currentPosition() != r)
            {
              stepperX.run();
              stepperY.run();
            }
          }
          // nâng trục Z
          stepperZ.moveTo(high);
          while (stepperZ.currentPosition() != high)
          {
            stepperZ.run();
          }
        
          // di chuyển đến vị trí 101
          stepperX.setSpeed(300);
          stepperX.moveTo(c);
        
          stepperY.setSpeed(300);
          stepperY.moveTo(d);
          while (stepperX.currentPosition() != c || stepperY.currentPosition() != d)
          {
            Serial.println("run");
            stepperX.run();
            stepperY.run();
          }
        
          // hạ trục Z
          stepperZ.moveTo(low);
          while (stepperZ.currentPosition() != low)
          {
            stepperZ.run();
          }
        
          // vẽ "/"
          for (i = 102; i < 202; i++)
          {
            q = movetox[i];
            w = abs(movetox[i]);
            e = movetoy[i];
            r = movetoy[i];
        
            Serial.println(i);
            stepperX.setSpeed(q);
            stepperX.moveTo(w);
        
            stepperY.setSpeed(e);
            stepperY.moveTo(r);
        
            while (stepperX.currentPosition() != w || stepperY.currentPosition() != r)
            {
              stepperX.run();
              stepperY.run();
            }
          }
        
          //nâng trục Z
          stepperZ.moveTo(high);
          while (stepperZ.currentPosition() != high)
          {
            stepperZ.run();
          }
  }

void loop() {

//  while (!Serial.available())
//  {
//    Serial.println("waiting");
//  }
//  Serial.println("main");
while(1)
{
  data = Serial.readString();
  d1 = data.charAt(0);
  d2 = data.charAt(1);
  //d3 = (int)d2;
  if(d1 == 'x')
  {
    switch(d2)
    {
      case '1':
      hinhX(X_moveToX_1, X_moveToY_1, X_speedX_1, X_speedY_1);
      break;
      case '4':
      hinhX(X_moveToX_4, X_moveToY_4, X_speedX_4, X_speedY_4);
      break;
    }
  }
//  if(dl = 'o')
//  {
//    hinhO(data);
//  }
  readyState();
}
//  while (1) {
//    Serial.println("WHILE TRUE");
//  }
}
void readyState()
{
  Serial.println("runing in readyState");
  stepperX.setSpeed(300);
  stepperX.moveTo(0);
  stepperY.setSpeed(300);
  stepperY.moveTo(0);
  while (stepperX.currentPosition() != 0 || stepperY.currentPosition() != 0)
  {
    stepperX.run();
    stepperY.run();
  }
  Serial.println("done readyState");
}
void homing2()
{
  stepperZ.setCurrentPosition(high);
  stepperY.setCurrentPosition(0);
  stepperX.setCurrentPosition(0);
  
}
void homing() {
  Serial.println("homing");
  // Homing StepperZ
  while (digitalRead(limitSwitchZ) != 0) {
    stepperZ.setSpeed(-2000); //Negative is go down
    stepperZ.runSpeed();
    stepperZ.setCurrentPosition(0); // When limit switch pressed set position to 0 steps
    stepperY.setCurrentPosition(0);
    stepperX.setCurrentPosition(0);
  }
  delay(20);

//  // Homing StepperX
//  while (digitalRead(limitSwitchX) != 0) {
//    stepperX.setSpeed(700);
//    stepperX.runSpeed();
//    stepperX.setCurrentPosition(0); // When limit switch pressed set position to 0 steps
//  }
//  delay(20);
//  stepperX.moveTo(-1160); // -4160 + 3000   // Neg is CCW
//  while (stepperX.currentPosition() != -1160)
//  {
//    stepperX.run();
//  }
//  stepperX.setCurrentPosition(0);
//  delay(100);
//
//  // Homing StepperY
//  while (digitalRead(limitSwitchY) != 0) {
//
//    stepperY.setSpeed(-500);    // Negative is CW
//    stepperY.runSpeed();
//    stepperY.setCurrentPosition(0);
//  }
//  delay(20);
//  int homeY = 1410;
//  stepperY.moveTo(homeY);     // Pos is CCW 1410
//  while (stepperY.currentPosition() != homeY) {
//    stepperY.run();
//  }
//  stepperY.setCurrentPosition(0);     //home tai vi tri duoi thang
//
//  Serial.println("homing done!");
//  stepperZ.moveTo(high);     // Pos is CCW 1410
//  while (stepperZ.currentPosition() != high) {
//    stepperZ.run();
//  }
}
