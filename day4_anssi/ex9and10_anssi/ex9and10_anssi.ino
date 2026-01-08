/* Exercises 9 and 10

reads value from temperature sensor, prints the corresponding voltage and temperature into serial monitor
Also turns on a led depenging on whether the temperature is low, medium or high (Exercise 10).
Temperature is read every 1000 ms and there is no averaging applied.

Circuit:
* LM 35 DZ temperature sensor connected to A0, 5 V and ground
* green, yellow and red leds connected to digital pins 8-10

Created 08 jan 2026
by Anssi Sohlman

*/

// Baud rate for serial monitor
const unsigned long MY_BAUD = 115200;

// Pins for the leds
const int GREENPIN = 8;
const int YELLOWPIN = 9;
const int REDPIN = 10;

//Temperature limits for the different lights
const float LOWTEMP = 22.5;
const float HIGHTEMP = 23.5;

// the resolution and maximum voltage of A0
const int STEPS = 1023;
const float V_MAX = 5.0;


void setup() {

  Serial.begin(MY_BAUD);

  //set up pins for output
  pinMode(GREENPIN, OUTPUT);
  pinMode(YELLOWPIN, OUTPUT);
  pinMode(REDPIN, OUTPUT);

  //Answer to quesion 9b
  char c;
  for (int i = 0; i < 4; i++) {
    c = '0' + i * 2;
    Serial.print(c);
    Serial.write(176);
  }

  Serial.println('\n');

  // Temperature resolution for fun
  Serial.print("Temperature resolution:\t");
  Serial.print(V_MAX / STEPS / 0.01);
  Serial.println(" °C/unit");
  Serial.println("");
}

void loop() {

  //read and print the converted analogue value
  int val = analogRead(A0);
  Serial.print("A0 reading:\t");
  Serial.println(val);

  //convert digital value to voltage and print
  float voltage = (float)val * (V_MAX / STEPS);
  Serial.print("Voltage:\t");
  Serial.print(voltage, 3);
  Serial.println(" V");

  //convert voltage to temperature and print
  float temp = voltage / 0.01;
  Serial.print("Temperature:\t");
  Serial.print(temp, 2);
  Serial.print(" ");
  // Serial.write(176); //Doesn't work
  Serial.println("°C");

  //Turn on the corresponding led (and turn others off)
  if (temp < LOWTEMP) {
    //Turn on green light
    digitalWrite(GREENPIN, HIGH);
    digitalWrite(YELLOWPIN, LOW);
    digitalWrite(REDPIN, LOW);
    Serial.println("Green light is on");
  } else if (temp > HIGHTEMP) {
    //Turn on red light
    digitalWrite(GREENPIN, LOW);
    digitalWrite(YELLOWPIN, LOW);
    digitalWrite(REDPIN, HIGH);
    Serial.println("Red light is on");
  } else {
    //Turn on yellow light
    digitalWrite(GREENPIN, LOW);
    digitalWrite(YELLOWPIN, HIGH);
    digitalWrite(REDPIN, LOW);
    Serial.println("Yellow light is on");
  }

  Serial.println('\n');

  delay(1000);
}
