#include <Wire.h>

#define iN1 2
#define iN2 3
#define iN3 4
#define iN4 5
#define ENB A0
#define ENA A1

char cmd;
int speedl = 250; // Left motor speed
int speedr = 250; // Right motor speed

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging

  // Set motor control pins as output
  for (int i = 2; i <= 5; i++) {
    pinMode(i, OUTPUT);
  }
  // Set motor enable pins as output (to control motor speed)
  pinMode(ENB, OUTPUT);
  pinMode(ENA, OUTPUT);

  Wire.begin();  // Initialize I2C communication as master
}

void backward() {
  digitalWrite(iN1, HIGH);
  digitalWrite(iN2, LOW);
  digitalWrite(iN3, HIGH);
  digitalWrite(iN4, LOW);
  analogWrite(ENB, speedl);  // Set motor speed
  analogWrite(ENA, speedr);
}

void forward() {
  digitalWrite(iN1, LOW);
  digitalWrite(iN2, HIGH);
  digitalWrite(iN3, LOW);
  digitalWrite(iN4, HIGH);
  analogWrite(ENB, speedl);
  analogWrite(ENA, speedr);
}

void Left() {
  digitalWrite(iN1, LOW);
  digitalWrite(iN2, HIGH);
  digitalWrite(iN3, LOW);
  digitalWrite(iN4, HIGH);
  analogWrite(ENB, speedl);
  analogWrite(ENA, 0);
}

void Right() {
  digitalWrite(iN1, LOW);
  digitalWrite(iN2, HIGH);
  digitalWrite(iN3, LOW);
  digitalWrite(iN4, HIGH);
  analogWrite(ENB, 0);
  analogWrite(ENA, speedr);
}

void stopp() {
  digitalWrite(iN1, LOW);
  digitalWrite(iN2, LOW);
  digitalWrite(iN3, LOW);
  digitalWrite(iN4, LOW);
  analogWrite(ENB, LOW);
  analogWrite(ENA, LOW);
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();  // Read incoming command

    Serial.println(cmd);   // Print the command to the serial monitor

    // Send the command to the slave Arduino
    Wire.beginTransmission(8);  // Address of the slave (use appropriate address)
    Wire.write(cmd);  // Send the command byte
    Wire.endTransmission();

    // Handle the motor control based on the command received
    switch (cmd) {
      case 'F': // Move Forward
        forward();
        break;
      case 'B': // Move Backward
        backward();
        break;
      case 'L': // Turn Left
        Left();
        break;
      case 'R': // Turn Right
        Right();
        break;
      case 'S': // Stop
        stopp();
        break;
      default:
        stopp();
        break;
    }
  }
}
