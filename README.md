# Autonomous Robot with Obstacle Avoidance

This Arduino code implements a simple autonomous robot capable of avoiding obstacles using ultrasonic sensors. The robot uses a combination of a servo motor and ultrasonic sensor to detect obstacles and maneuver around them. It consists of motor control, sensor reading, and decision-making functions.

## Components Used
- AFMotor library for controlling DC motors.
- NewPing library for interfacing with the ultrasonic sensor.
- Servo library for controlling the servo motor.

## Hardware Setup
- **Ultrasonic Sensor**: Connected to the Arduino analog pins `A0` (TRIG) and `A1` (ECHO).
- **DC Motors**: Utilizes AFMotor library for controlling the motors connected to pins 1-4.
- **Servo Motor**: Connected to pin 10 for sweeping to detect obstacles.

## Constants
- `TRIG_PIN` and `ECHO_PIN`: Pins for ultrasonic sensor.
- `MAX_DISTANCE`: Maximum distance to measure in centimeters.
- `MAX_SPEED`: Maximum speed of the motors.
- `SERVO_CENTER`, `SERVO_RIGHT`, `SERVO_LEFT`: Servo motor positions.
- `DISTANCE_THRESHOLD`: Threshold distance for obstacle detection.
- `RESPONSE_DELAY`: Delay for response to sensor readings.
- `PING_INTERVAL`: Interval between ultrasonic sensor readings.
- `MOTOR_STOP_DELAY`: Delay for stopping motors.
- `TURN_DELAY`, `LOOK_DELAY`: Delay for turning and looking functions.
- `MAX_DISTANCE_READING`: Maximum distance reading for sensor.

## Functions
- `setup()`: Initializes the servo motor and reads initial distance.
- `loop()`: Main loop calling `checkObstaclesAndNavigate()`.
- `checkObstaclesAndNavigate()`: Checks for obstacles and navigates accordingly.
- `performAvoidanceManeuver()`: Performs avoidance maneuver by stopping, moving backward, looking, and turning.
- `lookInDirection()`: Sweeps the servo motor to look for obstacles.
- `readPing()`: Reads distance from ultrasonic sensor.
- `moveForward()`, `moveBackward()`: Moves the robot forward and backward.
- `turnRight()`, `turnLeft()`: Turns the robot right and left.
- `setMotorDirection()`: Sets the direction of DC motors.
- `stopMotors()`: Stops all motors.
- `rampUpSpeed()`: Ramps up motor speed gradually.

## Usage
1. Connect the components as described in the hardware setup.
2. Upload the code to your Arduino board.
3. Power up the robot and observe its autonomous obstacle avoidance behavior.

## Notes
- Adjust constants and delays as needed for your specific robot and environment.
- Ensure proper calibration of the servo motor and ultrasonic sensor for accurate obstacle detection.
