\*

Exercise 5: Read and write to serial monitor

This code reads one byte from serial and prints the received byte as decimal number/character to the serial.

Created 07 jan 2026
by Anssi Sohlman and Amal Almis

*/


int incomingByte = 0; // byte written to serial

void setup() {
  Serial.begin(9600); // setup serial
}

void loop() {
  if (Serial.available() > 0) { 
    incomingByte = Serial.read();
    Serial.print("I received: "); 
    Serial.println((char)incomingByte); // changed from Serial.println(incomingByte, DEC)
  }
}
