#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

// Constants
#define TRIG_PIN A0
#define ECHO_PIN A1
#define MAX_DISTANCE 200
#define MAX_SPEED 190
#define MOTOR_SPEED_INCREMENT 2
#define SERVO_CENTER 115
#define SERVO_RIGHT 50
#define SERVO_LEFT 170
#define DISTANCE_THRESHOLD 15
#define RESPONSE_DELAY 100
#define PING_INTERVAL 70
#define MOTOR_STOP_DELAY 5
#define TURN_DELAY 500
#define LOOK_DELAY 500
#define MAX_DISTANCE_READING 250

// Sensor and motor setup
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
AF_DCMotor motors[4] = {
  {1, MOTOR12_1KHZ},
  {2, MOTOR12_1KHZ},
  {3, MOTOR34_1KHZ},
  {4, MOTOR34_1KHZ}
};
Servo myservo;

// Globals
boolean isMovingForward = false;
int currentDistance = 100;

void setup() {
  myservo.attach(10);
  myservo.write(SERVO_CENTER);
  delay(2000);
  currentDistance = readPing();
}

void loop() {
  checkObstaclesAndNavigate();
}

void checkObstaclesAndNavigate() {
  int distanceRight, distanceLeft;

  delay(RESPONSE_DELAY);
  if (currentDistance <= DISTANCE_THRESHOLD) {
    performAvoidanceManeuver(distanceRight, distanceLeft);
  } else {
    moveForward();
  }
  currentDistance = readPing();
}

void performAvoidanceManeuver(int &distanceRight, int &distanceLeft) {
  stopMotors();
  moveBackward();
  delay(RESPONSE_DELAY);
  stopMotors();
  delay(RESPONSE_DELAY);
  
  distanceRight = lookInDirection(SERVO_RIGHT);
  distanceLeft = lookInDirection(SERVO_LEFT);

  if (distanceRight >= distanceLeft) {
    turnRight();
  } else {
    turnLeft();
  }
  stopMotors();
}

int lookInDirection(int angle) {
  myservo.write(angle);
  delay(LOOK_DELAY);
  int distance = readPing();
  myservo.write(SERVO_CENTER);
  delay(RESPONSE_DELAY);
  return distance;
}

int readPing() {
  delay(PING_INTERVAL);
  int cm = sonar.ping_cm();
  return cm == 0 ? MAX_DISTANCE_READING : cm;
}
