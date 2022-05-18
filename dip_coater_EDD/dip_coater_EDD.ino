#include <Stepper.h>

#define BUTTON 2

const float mmpersteps = -0.04;  // change this to fit the number of steps for your motor

// initialize the stepper library on pins 8 through 11:
Stepper stepper(200, 8, 9, 10, 11);

int motorSpeed;
int cycles;
int moveDist;
int current;

void setup() {
  // nothing to do inside the setup
  current = 0;
  motorSpeed = 0;
  cycles = 0;
  moveDist = 0;
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
}

void waitForButton() {
   while(digitalRead(2)) {
    delay(10);
   }
   while(!digitalRead(2)) {
       delay(10);
   }
   Serial.println("BUTTON PRESSED");
}

void setSpeedMotor() {
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  motorSpeed = map(sensorReading, 0, 1023, 0, 250);
  // set the motor speed:
  stepper.setSpeed(motorSpeed);
  Serial.print("Speed: ");
  Serial.println(motorSpeed);
  // step 1/100 of a revolution:
}

void goToPosition() {
  int pos = analogRead(A0);
  pos = map(pos, 0, 1023, 0, 100);
  int moveDist = current-pos;
  Serial.println(moveDist);
  Serial.print("steppin: ");
  Serial.println((int)(-moveDist/mmpersteps));
  delay(100);
  if(moveDist<0) {
    
    stepper.step((int)(moveDist/mmpersteps));
    current = current + pos;
    delay(2000);
    stepper.step((int)(-moveDist/mmpersteps));
    current = current - pos;
  }
  else {
    stepper.step((int)(-moveDist/mmpersteps));
    current = current - pos;
    delay(2000);
    stepper.step((int)(moveDist/mmpersteps));
    current = current + pos;
  }
  

}

int setCycles(int cycles) {
  cycles = analogRead(1);
  return cycles;
}

void loop() {
  waitForButton();
  setSpeedMotor();
  waitForButton();
  delay(10);
  goToPosition();
  /*
  cycles = setCycles();
  for (int x = 0; x < cycles; x++) {
    goToPosition();
    delay(5000);
    stepper.step(-moveDist);
    delay(5000);
  }
  */
}
