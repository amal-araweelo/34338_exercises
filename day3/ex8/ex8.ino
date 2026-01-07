/*
Excersise 8

Reads potentiometer value and uses it to control an RGB led from purple to red

circuit:
* potentiometer with center connected to A0, others to 5 V and ground
* an RGB led connected to pins 9-11

Created 07 jan 2026
by Anssi Sohlman and Amal Almis

*/

//Baud rate for easy access
const unsigned long MY_BAUD = 115200;

// voltage applied to potentiometer, bits of A0 and the number of steps
const float V_REF = 5.0;
const float R_BITS = 10.0;
const float ADC_STEPS = (1 << int(R_BITS)) - 1;

int val = 0;  //The value to be read

// Pins for the RGB led
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(MY_BAUD);

  //set up pins for output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  //read and print the converted analogue value
  val = analogRead(A0);
  Serial.print("Potentiometer value: ");
  Serial.println(val);

  //convert digital value to voltage and print
  float voltage = (val / ADC_STEPS) * V_REF;
  Serial.print("Voltage: ");
  Serial.println(voltage, 3);

  // fade from purple to red
  // 0 is purple (127,0, 127)
  // 1023 is red (255, 0, 0)
  int redVal = int(127 + int((val + 1) / 8));  // calculate value for red
  int blueVal = int(127 - int((val) / 8));     // calculate value for blue
  int greenVal = 0;                            // green value is 0

  printRGBval(redVal, blueVal, greenVal);      // prints the decimal RGB value to serial
  updateLED(redVal, blueVal, greenVal);        // update LED with the entered RGB value

  Serial.println('\n');

  delay(200);
}

void printRGBval(int redVal, int blueVal, int greenVal) {  // Prints RGB value
  Serial.print("Red: ");
  Serial.print(redVal);
  Serial.print(" ");

  Serial.print("Green: ");
  Serial.print(greenVal);
  Serial.print(" ");

  Serial.print("Blue: ");
  Serial.print(blueVal);
  Serial.print(" ");

  Serial.println("");
}

void updateLED(int redVal, int blueVal, int greenVal) {  // Updates the LED color
  analogWrite(redPin, redVal);
  analogWrite(bluePin, blueVal);
  analogWrite(greenPin, greenVal);
}
