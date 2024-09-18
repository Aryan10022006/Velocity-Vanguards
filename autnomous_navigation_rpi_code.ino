#include <Arduino.h>

// Define motor control pins
const int ENA = 8;
const int ENB = 9;
const int IN1 = 10;
const int IN2 = 11;
const int IN3 = 12;
const int IN4 = 13;

// Ultrasonic sensor pins
const int TRIG_PIN = 15;  // Trigger pin for ultrasonic sensor
const int ECHO_PIN = 14;  // Echo pin for ultrasonic sensor

// Constants
const long minDistance = 20;        // Minimum distance to obstacle before stopping (cm)
const long checkInterval = 100;     // Time interval for checking distance (ms)
const int maxSpeed = 255;           // Maximum motor speed

// Function prototypes
long measureDistance();
void moveForward(int speed);
void moveBackward(int speed);
void stopMotors();
void turnLeft(int angle);
void turnRight(int angle);

// Setup function
void setup() {
  Serial.begin(115200);

  // Initialize motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Start by stopping the motors
  stopMotors();
}

// Main loop
void loop() {
  // Continuously move forward and check the distance every checkInterval ms
  unsigned long previousMillis = 0;

  while (true) {
    unsigned long currentMillis = millis();

    // If it's time to check the distance
    if (currentMillis - previousMillis >= checkInterval) {
      previousMillis = currentMillis;

      // Measure the distance in front of the bot
      long frontDistance = measureDistance();
      Serial.print("Front Distance: ");
      Serial.println(frontDistance);

      // If an obstacle is detected within the minimum distance, stop and avoid
      if (frontDistance < minDistance) {
        stopMotors();
        delay(100);  // Short pause before deciding

        // Check all directions
        turnRight(45);
        long right45Distance = measureDistance();
        Serial.print("45 Right Distance: ");
        Serial.println(right45Distance);

        turnLeft(90);  // Move back to center and turn left 45
        long left45Distance = measureDistance();
        Serial.print("45 Left Distance: ");
        Serial.println(left45Distance);

        turnRight(45);  // Back to the center (forward position)

        turnRight(90);  // Check 90-degree right
        long right90Distance = measureDistance();
        Serial.print("90 Right Distance: ");
        Serial.println(right90Distance);

        turnLeft(180);  // Check 90-degree left
        long left90Distance = measureDistance();
        Serial.print("90 Left Distance: ");
        Serial.println(left90Distance);

        turnRight(90);  // Return to forward position

        // Decide the best direction to move based on the measurements
        if (right90Distance > frontDistance && right90Distance > left90Distance) {
          turnRight(90);  // Turn 90 degrees right if the path is clear
        } else if (left90Distance > frontDistance && left90Distance > right90Distance) {
          turnLeft(90);  // Turn 90 degrees left if the path is clear
        } else if (right45Distance > frontDistance) {
          turnRight(45);  // Turn 45 degrees right
        } else if (left45Distance > frontDistance) {
          turnLeft(45);  // Turn 45 degrees left
        } else {
          moveBackward(maxSpeed);  // If no clear direction, move backward and try again
          delay(500);
          stopMotors();
        }
      } else {
        // If the path is clear, continue moving forward
        moveForward(maxSpeed);
      }
    }
  }
}

// Function to measure distance using ultrasonic sensor
long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration * 0.0343) / 2;  // Convert time to distance in cm

  return distance;
}

// Function to move forward
void moveForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

// Function to move backward
void moveBackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// Function to turn left by a specific angle (e.g., 45 or 90 degrees)
void turnLeft(int angle) {
  int turnTime = (angle == 45) ? 400 : 800;  // Adjust values based on testing
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  delay(turnTime);
  stopMotors();
}

// Function to turn right by a specific angle (e.g., 45 or 90 degrees)
void turnRight(int angle) {
  int turnTime = (angle == 45) ? 400 : 800;  // Adjust values based on testing
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  delay(turnTime);
  stopMotors();
}
