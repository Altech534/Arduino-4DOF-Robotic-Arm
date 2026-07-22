#include <Servo.h>

// -------- Servo Objects --------
Servo joystickServo;
Servo encoderServo;
Servo joystickServo2;
Servo clawServo;

// -------- Servo Pins --------
const int joystickServoPin = 12;
const int encoderServoPin = 11;
const int joystickServo2Pin = 10;
const int clawServoPin = 9;

// -------- Joystick --------
const int joystickX = A0;  // Left/right
const int joystickY = A1;  // Up/down
const int joystickButton = 13; // Joystick press

int joystickAngle = 90;
int joystick2Angle = 90;

// -------- Claw --------
int clawOpen = 0;
int clawClosed = 30;

// -------- Rotary Encoder --------
const int clkPin = 3;
const int dtPin = 4;
const int swPin = 2;

int encoderAngle = 90;
int lastCLK;

void setup() {

  Serial.begin(9600);

  // Attach servos
  joystickServo.attach(joystickServoPin);
  encoderServo.attach(encoderServoPin);
  joystickServo2.attach(joystickServo2Pin);
  clawServo.attach(clawServoPin);

  // Starting positions
  joystickServo.write(joystickAngle);
  encoderServo.write(encoderAngle);
  joystickServo2.write(joystick2Angle);
  clawServo.write(clawOpen);

  // Buttons
  pinMode(joystickButton, INPUT_PULLUP);
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);

  lastCLK = digitalRead(clkPin);
}


void loop() {

  // =========================
  // JOYSTICK UP/DOWN SERVO (Pin 12)
  // =========================

  int joystickYValue = analogRead(joystickY);

  if (joystickYValue > 600) {
    joystickAngle++;
  }
  else if (joystickYValue < 400) {
    joystickAngle--;
  }

  joystickAngle = constrain(joystickAngle, 0, 180);
  joystickServo.write(joystickAngle);



  // =========================
  // JOYSTICK LEFT/RIGHT SERVO (Pin 10)
  // =========================

  int joystickXValue = analogRead(joystickX);

  if (joystickXValue > 600) {
    joystick2Angle++;
  }
  else if (joystickXValue < 400) {
    joystick2Angle--;
  }

  joystick2Angle = constrain(joystick2Angle, 0, 180);
  joystickServo2.write(joystick2Angle);



  // =========================
  // ROTARY ENCODER SERVO (Pin 11)
  // =========================

  int currentCLK = digitalRead(clkPin);

  if (currentCLK != lastCLK && currentCLK == HIGH) {

    if (digitalRead(dtPin) != currentCLK) {
      encoderAngle += 10;
    }
    else {
      encoderAngle -= 10;
    }

    encoderAngle = constrain(encoderAngle, 0, 180);

    encoderServo.write(encoderAngle);
  }

  lastCLK = currentCLK;



  // =========================
  // CLAW CONTROL (Pin 9)
  // =========================

  if (digitalRead(joystickButton) == LOW) {

    clawServo.write(clawClosed);  // Close claw

  }
  else {

    clawServo.write(clawOpen);    // Open claw

  }



  // Encoder button resets encoder servo
  if (digitalRead(swPin) == LOW) {

    encoderAngle = 180;
    encoderServo.write(encoderAngle);

    delay(200);
  }


  delay(15);
}