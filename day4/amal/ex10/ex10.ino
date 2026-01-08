/*
  Exercise 10: Make diodes light up depending on temperature

  Using a TMP36 an analog output of a sensor is read, converted to a voltage and 
  finally, converted to a temperature in degrees Celsius. Depending on the temperature,
  a red/yellow or green LED is turned on.

  By Amal Almis
  Created 08-01-2026

*/

int const tmpPin = A0;
int const greenLED = 10;
int const yellowLED = 9;
int const redLED = 8;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("Initial TMP36 temperature: ");
  pinMode(tmpPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  int adcValue = analogRead(tmpPin);             // read analog value (between 0 and 1023)
  float voltage = adcValue * (5.0 / 1023.0);     // convert to voltage
  float temperatureC = (voltage - 0.5) * 100.0;  // tmp36 voltage offset (from data sheet)

  // Print temperature value
  Serial.print(temperatureC, 1);  // 1 decimal place

  // Print degree symbol using UTF-8 (= 0xc2 0xb0)
  Serial.write(0xC2);
  Serial.write(0xB0);
  Serial.println("C");
  delay(1000);

  // led logic
  if (temperatureC > 24.0) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  } else if (temperatureC > 23.0) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
}
