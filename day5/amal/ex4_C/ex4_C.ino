void setup() {
  // Serial setup
  Serial.begin(9600);
  while (!Serial)
    ;

  int x = 10;
  int* p = &x;
  int** q = &p;  // double-pointer

  // Using q to modify value of x
  **q = 2;

  // Verify
  Serial.print("x = ");
  Serial.println(x);
}

void loop() {
  // put your main code here, to run repeatedly:
}
