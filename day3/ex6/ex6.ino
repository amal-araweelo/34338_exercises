/*
Exercise 6: Read from Serial Monitor
Turns on leds depending on input to serial monitor

Circuit: 5 leds connected to pins 2-6

Created 07 jan 2026
by Anssi Sohlman and Amal Almis

*/

//Baud rate for easy access
const unsigned long my_baud = 115200;

// Initial state for the byte that is read from serial
int readByte = 0;

void setup() {

  //We need to set up serial to communicate with the board
  Serial.begin(my_baud);

  // Set pins 2-6 to OUTPUT
  for (int i = 2; i < 7; i++) {
    pinMode(i, OUTPUT);
  }

  //Check answer to question 6b
  char mychar = '4';
  int val = mychar - '0';
  mychar = (char)(val + 'A' - 1);
  Serial.print("value of mychar is: ");
  Serial.println(mychar);
  Serial.print("\n");
}

void loop() {
  if (Serial.available() > 0) {
    //Read the byte and print it for debugging
    readByte = Serial.read();

    Serial.print("Received char ");
    Serial.println(readByte, DEC);
    // Turn leds on or off depending on input
    switch (readByte) {
      case 'a': case 'A':
        digitalWrite(2, HIGH);
        break;
      case 'b': case 'B':
        digitalWrite(3, HIGH);
        break;
      case 'c': case 'C':
        digitalWrite(4, HIGH);
        break;
      case 'd': case 'D':
        digitalWrite(5, HIGH);
        break;
      case 'e': case 'E':
        digitalWrite(6, HIGH);
        break;
      default:
      //Turn of all leds
        for (int i = 2; i < 7; i++) {
          digitalWrite(i, LOW);
        }
    }
  }
}
