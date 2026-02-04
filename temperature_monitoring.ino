int sensorPin = A0;   // Define the sensor pin and LED pin
int greenLED = 3;
int redLED = 2;

void setup() {
  pinMode(greenLED, OUTPUT);   // Initial Green LED output
  pinMode(redLED, OUTPUT);     // Initial Red LED output
  Serial.begin(9600);          // Initial serial communication at 9600bps
}

void loop() {
  int reading = analogRead(sensorPin);   // Read the raw analog value

  float voltage = reading * (5.0 / 1024.0);   // Convert reading to voltage (0–5V)

  float tempC = (voltage - 0.5) * 100;   // Convert voltage to temperature in Celsius

  if (tempC >= 32) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  } 
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  // Print the result to the Serial Monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V | Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(1000);   // Wait 1 second before the next reading
}