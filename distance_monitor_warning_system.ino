#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// OLED pins
#define SCL_PIN 21
#define SDA_PIN 22

// RGB LED pins
#define red 2
#define green 4
#define blue 5

// Ultrasonic sensor pins
#define trig 15
#define echo 16

//buzzer pin
#define buzzer 18

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  Serial.begin(115200);

  // Configure LED pins
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  // Configure ultrasonic sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(trig, LOW);

  //configure buzzer
  pinMode(buzzer, OUTPUT);

  // Initialize I2C
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed!");
    while (true);
  }

  Serial.println("OLED initialized successfully!");

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("System Starting...");
  display.display();

  delay(1000);
}

void loop() {

  // Trigger ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  // Read echo duration (timeout: 30 ms)
  long duration = pulseIn(echo, HIGH, 30000);

  // Calculate distance
  float distance = duration * 0.0343 / 2;

  // Clear OLED
  display.clearDisplay();

  display.setCursor(0, 0);

  display.println("DISTANCE MONITOR");
  display.println("----------------");

  // Check sensor reading
  if (duration == 0) {

    Serial.println("No echo received!");

    display.println("No Echo!");

    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);

  }

  else {

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    display.print("Distance: ");
    display.print(distance, 1);
    display.println(" cm");

    // DANGER: Less than 10 cm
    if (distance < 10) {

      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);

      tone(buzzer, 1000);

      delay(100);

      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);

      noTone(buzzer);


      display.println();
      display.println("WARNING!!");
      display.println("Object Too Close!");


    }

    // WARNING: Between 10 and 20 cm
    else if (distance < 20) {

      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);

      display.println();
      display.println("CAUTION!");
      display.println("Object Nearby");

    }

    // SAFE: 20 cm or more
    else {

      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(blue, LOW);

      display.println();
      display.println("SAFE");
      display.println("No Immediate Danger");
    }
  }

  // Update OLED
  display.display();

  delay(200);
}