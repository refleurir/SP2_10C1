/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/faq/how-to-control-speed-of-servo-motor
 */

#include <Servo.h>

#define PIN_SERVO 10

Servo myServo;
unsigned long MOVING_TIME = 3000; // moving time is 3 seconds
unsigned long moveStartTime;
int startAngle = 30; // 30°
int stopAngle  = 90; // 90°

void setup() {
  myServo.attach(PIN_SERVO);
  moveStartTime = millis(); // start moving

  myServo.write(startAngle); // Set position
  delay(500);
}

void loop() {
  unsigned long progress = millis() - moveStartTime;

  if (progress <= MOVING_TIME) {
    float t = (float)progress / MOVING_TIME;
    float sigmoid = 1 / (1 + exp(-11.0 * (t - 0.5)));
    long angle = startAngle + sigmoid*(stopAngle - startAngle);
    
    myServo.write(angle); 
  }
}
