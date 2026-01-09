void setup() {
  // Serial setup
  Serial.begin(9600);
  while (!Serial)
    ;

  int a[5] = { 1, 2, 3, 4, 5 };
  int* p = &a[0];


  // Move pointer along by 1 
  for (int i = 0; i < 5; i++) {
    if (i!=0) // do not move pointer in the first iteration
      p += 1;
    Serial.println(*p);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
