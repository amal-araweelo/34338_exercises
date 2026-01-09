void setup() {
  float temp = 36.6;
  float* p = &temp;  // float pointer for float data type

  // Changing the temp using the pointer
  *p = 35.5;

  // Serial setup
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.print("Temperature = ");
  Serial.println(temp);
}

void loop() {
  // put your main code here, to run repeatedly:
}
