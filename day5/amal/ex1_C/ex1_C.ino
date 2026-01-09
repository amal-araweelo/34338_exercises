void setup() {
  int x = 10;
  int* p = &x; 
  Serial.begin(9600);
  while(!Serial);
  Serial.print("x = "); // printing value of x by dereferencing p
  Serial.println(*p);
}

void loop() {
  // put your main code here, to run repeatedly:

}
