#include <AccelStepper.h>
#include <math.h>

#define limitSwitchZ 11   //z
#define limitSwitchY 10   //y
#define limitSwitchX 9    //x

// Define the stepper motors and the pins the will use
AccelStepper stepperX(1, 2, 5); // (Type:driver, STEP, DIR)
AccelStepper stepperY(1, 3, 6);
AccelStepper stepperZ(1, 4, 7);

double x = 500.0;
double y = 0.0;
double L1 = 250; // L1 = 250mm
double L2 = 250; // L2 = 250mm

int stepperXPosition = 0;
int stepperYPosition = 0;
int stepperZPosition = 0;

const float theta1AngleToSteps = -33.333333;
const float theta2AngleToSteps = 8.888888;
const float zDistanceToSteps = 400;

byte inputValue[5];
int k = 0;

String content = "";
int data[8];

int theta1Array[100];
int theta2Array[100];
int zArray[100];

int positionsCounter = 0;

void setup() {
  Serial.begin(115200);

  pinMode(limitSwitchZ, INPUT_PULLUP);
  pinMode(limitSwitchY, INPUT_PULLUP);
  pinMode(limitSwitchX, INPUT_PULLUP);

  // Stepper motors max speed
  stepperX.setMaxSpeed(4000);
  stepperX.setAcceleration(2000);
  stepperY.setMaxSpeed(4000);
  stepperY.setAcceleration(2000);
  stepperZ.setMaxSpeed(4000);
  stepperZ.setAcceleration(2000);

  //data[4] = 100;
  homing(); //************************************ NOTE *********************************//
}

void loop() {

  if (Serial.available())
  {
    content = Serial.readString(); // Read the incomding data from Processing
    // Extract the data from the string and put into separate integer variables (data[] array)
    for (int i = 0; i < 8; i++)
    {
      int index = content.indexOf(","); // locate the first ","
      data[i] = atol(content.substring(0, index).c_str()); //Extract the number from start to the ","
      content = content.substring(index + 1); //Remove the number from the string
    }
    /*
      data[0] - SAVE button status
      data[1] - RUN button status
      data[2] - Joint 1 angle
      data[3] - Joint 2 angle
      data[4] - Z position
      data[5] - Speed value
      data[6] - Acceleration value
    */
    // If SAVE button is pressed, store the data into the appropriate arrays
    if (data[0] == 1)
    {
      theta1Array[positionsCounter] = data[2] * theta1AngleToSteps; //store the values in steps = angles * angleToSteps variable
      theta2Array[positionsCounter] = data[3] * theta2AngleToSteps;
      zArray[positionsCounter] = data[4] * zDistanceToSteps;
      positionsCounter++;
    }
    // clear data
    if (data[0] == 2)
    {
      // Clear the array data to 0
      memset(theta1Array, 0, sizeof(theta1Array));
      memset(theta2Array, 0, sizeof(theta2Array));
      memset(zArray, 0, sizeof(zArray));
      positionsCounter = 0;
    }
  }     // het vong lap IF(Serial.available())
  
  // If RUN button is pressed
  while (data[1] == 1)
  {
    stepperX.setSpeed(data[5]);
    stepperY.setSpeed(data[5]);
    stepperZ.setSpeed(data[5]);
    stepperX.setAcceleration(data[6]);
    stepperY.setAcceleration(data[6]);
    stepperZ.setAcceleration(data[6]);

    // execute the stored steps
    for (int i = 0; i < positionsCounter; i++)
    {
      if (data[1] == 0)
      {
        break;
      }
      stepperX.moveTo(theta1Array[i]);
      stepperY.moveTo(theta2Array[i]);
      stepperZ.moveTo(zArray[i]);
      while (stepperX.currentPosition() != theta1Array[i] || stepperY.currentPosition() != theta2Array[i] || stepperZ.currentPosition() != zArray[i])
      {
        stepperX.run();
        stepperY.run();
        stepperZ.run();
      }

      //check for change in speed and acceleration or program stop
      if (Serial.available())
      {
        content = Serial.readString(); // Read the incomding data from Processing
        // Extract the data from the string and put into separate integer variables (data[] array)
        for (int i = 0; i < 8; i++)
        {
          int index = content.indexOf(","); // locate the first ","
          data[i] = atol(content.substring(0, index).c_str()); //Extract the number from start to the ","
          content = content.substring(index + 1); //Remove the number from the string
        }

        if (data[1] == 0)
        {
          break;
        }
        // change speed and acceleration while running the program
        stepperX.setSpeed(data[5]);
        stepperY.setSpeed(data[5]);
        stepperZ.setSpeed(data[5]);
        stepperX.setAcceleration(data[6]);
        stepperY.setAcceleration(data[6]);
        stepperZ.setAcceleration(data[6]);
      }
    }
    /*
      // execute the stored steps in reverse
      for (int i = positionsCounter - 2; i >= 0; i--) {
      if (data[1] == 0) {
        break;
      }
      stepperX.moveTo(theta1Array[i]);
      stepperY.moveTo(theta2Array[i]);
      stepperZ.moveTo(phiArray[i]);
      stepper4.moveTo(zArray[i]);
      while (stepperX.currentPosition() != theta1Array[i] || stepperY.currentPosition() != theta2Array[i] || stepperZ.currentPosition() != phiArray[i] || stepper4.currentPosition() != zArray[i]) {
        stepperX.run();
        stepperY.run();
        stepperZ.run();
        stepper4.run();
      }
      gripperServo.write(gripperArray[i]);

      if (Serial.available()) {
        content = Serial.readString(); // Read the incomding data from Processing
        // Extract the data from the string and put into separate integer variables (data[] array)
        for (int i = 0; i < 10; i++) {
          int index = content.indexOf(","); // locate the first ","
          data[i] = atol(content.substring(0, index).c_str()); //Extract the number from start to the ","
          content = content.substring(index + 1); //Remove the number from the string
        }
        if (data[1] == 0) {
          break;
        }
      }
      }
    */
  }     // het vong lap while RUN

  stepperXPosition = data[2] * theta1AngleToSteps;
  stepperYPosition = data[3] * theta2AngleToSteps;
  stepperZPosition = data[4] * zDistanceToSteps;

  stepperX.setSpeed(data[5]);
  stepperY.setSpeed(data[5]);
  stepperZ.setSpeed(data[5]);

  stepperX.setAcceleration(data[6]);
  stepperY.setAcceleration(data[6]);
  stepperZ.setAcceleration(data[6]);
  
  stepperX.moveTo(stepperXPosition);
  stepperY.moveTo(stepperYPosition);
  stepperZ.moveTo(stepperZPosition);
  while (stepperX.currentPosition() != stepperXPosition || stepperY.currentPosition() != stepperYPosition || stepperZ.currentPosition() != stepperZPosition)
  {
    stepperX.run();
    stepperY.run();
    stepperZ.run();
  }
  //delay(200);                   //************************** NOTE *************************//
}

void serialFlush() {
  while (Serial.available() > 0) {  //while there are characters in the serial buffer, because Serial.available is >0
    Serial.read();         // get one character
  }
}

void homing() {
  // Homing StepperZ
  while (digitalRead(limitSwitchZ) != 0) {
    stepperZ.setSpeed(2000); //Negative is go down
    stepperZ.runSpeed();
    stepperZ.setCurrentPosition(0); // When limit switch pressed set position to 0 steps
  }
  delay(20);

  // Homing StepperX
  while (digitalRead(limitSwitchX) != 0) {
    stepperX.setSpeed(700);
    stepperX.runSpeed();
    stepperX.setCurrentPosition(0); // When limit switch pressed set position to 0 steps
  }
  delay(20);
  stepperX.moveTo(-1160);    // Neg is CCW
  while (stepperX.currentPosition() != -1160) {
    stepperX.run();
  }
  stepperX.setCurrentPosition(0); 
  delay(100);

  // Homing StepperY
  while (digitalRead(limitSwitchY) != 0) {
    
    stepperY.setSpeed(-500);    // Negative is CW
    stepperY.runSpeed();
    stepperY.setCurrentPosition(0); 
  }
  delay(20);
  int homeY = 1410;
  stepperY.moveTo(homeY);     // Pos is CCW 1410
  while (stepperY.currentPosition() != homeY) {
    stepperY.run();
  }
  stepperY.setCurrentPosition(0);     //home tai vi tri duoi thang

}
