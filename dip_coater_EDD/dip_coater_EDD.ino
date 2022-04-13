#include <Stepper.h>

const int steps = 200;  // change this to fit the number of steps for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(steps, 8, 9, 10, 11);

int previous;
int motorSpeed;
int cycles;
int moveDist;

void setup() {
  // nothing to do inside the setup
  previous = 0; // the previous reading from the analog input
  motorSpeed = 0;
  cycles = 0;
  moveDist = 0;
}

int setSpeedMotor() {
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  myStepper.setSpeed(motorSpeed);
  // step 1/100 of a revolution:
  return motorSpeed
}

int goToPosition(int previous){
  int val = analogRead(0);
  moveDist = val-previous;
  stepper.step(moveDist);
  previous = val;
  return previous;
}

int setCycles(int cycles) {
  cycles = analogRead(1);
  return cycles
}

void loop(int moveDist) {
  motorSpeed = setSpeedMotor();
  cycles = setCycles();
  for (int x = 0; x < cycles; x++) {
    goToPosition();
    delay(5000);
    stepper.step(-moveDist);
    delay(5000);
  }
