\*
  * @file 5_serial_monitor.ino
  *
  *
  *
  *
  *
  *
  *
  *
  *
*\

int incomingByte = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { 
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println((char)incomingByte); // changed from Serial.println(incomingByte, DEC)
  }
}
