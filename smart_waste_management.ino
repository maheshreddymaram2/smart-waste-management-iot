#include <Servo.h>
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

#define TRIG_PIN 8
#define ECHO_PIN 9
#define GREEN_LED_PIN 5
#define RED_LED_PIN 4
#define PIR_SENSOR_PIN 2
#define SERVO_PIN 3
#define POT_PIN A0

Servo servo;
Adafruit_LiquidCrystal lcd(0);  // Using default I2C address for Adafruit I2C backpack

long readUltrasonicDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(PIR_SENSOR_PIN, INPUT);
  servo.attach(SERVO_PIN);

  lcd.begin(16, 2);
  lcd.setBacklight(1); // Turn on LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Smart Waste");
  lcd.setCursor(0, 1);
  lcd.print("ManagementSystem");
  delay(2000);  // Wait for 2 seconds
  lcd.clear();
}

void loop() {
  long duration = readUltrasonicDistance(TRIG_PIN, ECHO_PIN);
  int wasteHeight = duration * 0.034 / 2; // cm

  // Read potentiometer value and control LCD backlight
  int potValue = analogRead(POT_PIN);
  int backlightValue = map(potValue, 0, 1023, 0, 1);
  lcd.setBacklight(backlightValue);

  // Display waste height
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Waste: ");
  lcd.print(wasteHeight);
  lcd.print(" cm");

  // If the bin is full (height <= 7 cm)
  if (wasteHeight <= 7) {
    digitalWrite(RED_LED_PIN, HIGH);  // Turn on red LED
    digitalWrite(GREEN_LED_PIN, LOW); // Turn off green LED
    lcd.setCursor(0, 1);
    lcd.print("Bin Empty ");
    
    // Show "Lid Opening" and then open the lid (servo)
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Lid Opening  ");
    servo.write(90);  // Open lid
    delay(1000);  // Wait for 1 second
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Lid Opened   ");
  }
  // If the bin is OK (height > 7 cm)
  else {
    digitalWrite(RED_LED_PIN, LOW);   // Turn off red LED
    digitalWrite(GREEN_LED_PIN, HIGH); // Turn on green LED
    lcd.setCursor(0, 1);
    lcd.print("Bin Ready TO FULL");
    
    // Show "Lid Closing" and then close the lid (servo)
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Lid Closing  ");
    servo.write(0);    // Close lid
    delay(1000);  // Wait for 1 second
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Lid Closed   ");
  }

  // Motion detection via PIR sensor
  int motion = digitalRead(PIR_SENSOR_PIN);
  if (motion == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Person Detected");
    servo.write(90);  // Open lid
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Lid Opened   ");
    delay(1000); // Show message for 1 second
  }

  delay(1000); // Delay before repeating the loop
}
