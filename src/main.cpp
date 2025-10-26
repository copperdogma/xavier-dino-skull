#include <Arduino.h>

// LED pin - using the built-in LED on GPIO8 (ESP32-C3 DevKitM-1)
const int LED_PIN = 8;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  delay(300);
  
  // Configure LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  Serial.println("\n=== Dino Skull Capacitive Sensor ===");
  Serial.println("Initializing...");
  
  // Flash LED 4 times to indicate startup
  for (int i = 0; i < 4; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
  
  Serial.println("Ready! LED flashed 4 times.");
  Serial.println("Project initialized successfully.");
  Serial.println("Ready for capacitive sensor implementation.");
}

void loop() {
  // Main loop - currently just a placeholder
  // Future implementation will include:
  // - Capacitive touch sensing
  // - Servo control for jaw opening
  // - Safety checks and elastic band release
  
  delay(1000);
}
