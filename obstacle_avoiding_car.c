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