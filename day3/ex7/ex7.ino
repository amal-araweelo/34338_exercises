/*
*
*
*
*
*/

// Following pins are PWM
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Enter 3 comma-separated integers between 0-255: ");

  // Set pin modes
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
    int redVal = Serial.parseInt();         // read first integer (red)
    int blueVal = Serial.parseInt();        // read second integer (blue)
    int greenVal = Serial.parseInt();       // read third integer (green)
    printRGBval(redVal, blueVal, greenVal); // prints the decimal RGB value to serial
    updateLED(redVal, blueVal, greenVal);   // update LED with the entered RGB value
  }
}

void printRGBval(int redVal, int blueVal, int greenVal){   // Prints RGB value
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

void updateLED(int redVal, int blueVal, int greenVal){ // Updates the LED color
  analogWrite(redPin, redVal);
  analogWrite(bluePin, blueVal);
  analogWrite(greenPin, greenVal);
}