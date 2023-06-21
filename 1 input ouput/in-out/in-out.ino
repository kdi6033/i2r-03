#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

// Output pin numbers
const int outputPins[4] = {26, 27, 32, 33};
// Input pin numbers
const int inputPins[4] = {16, 17, 18, 19};

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);

  // Check if AHT sensor is connected
  if (! aht.begin()) {
    Serial.println("Could not find AHT sensor!");
    while (1) delay(10);
  }

  // Set each output pin as an output
  for (int i = 0; i < 4; i++) {
    pinMode(outputPins[i], OUTPUT);
  }

  // Set each input pin as an input
  for (int i = 0; i < 4; i++) {
    pinMode(inputPins[i], INPUT);
  }
}

void loop() {
  // Cycle through each output pin
  for (int i = 0; i < 4; i++) {
    // Turn the current output pin on
    digitalWrite(outputPins[i], HIGH);

    // Wait for a second
    delay(1000);

    // Turn the current output pin off
    digitalWrite(outputPins[i], LOW);
  }

  // Cycle through each input pin
  for (int i = 0; i < 4; i++) {
    // Read the state of the current input pin
    int pinState = digitalRead(inputPins[i]);

    // Print the state of the current input pin
    Serial.print("Pin ");
    Serial.print(inputPins[i]);
    Serial.print(": ");
    Serial.println(pinState);
  }

  // Read temperature and humidity from AHT sensor
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  // Print temperature and humidity
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degrees C");

  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println("% rH");
  
  delay(2000); // Wait for 2 seconds before reading again
}



