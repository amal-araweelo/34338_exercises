// Define a union Data with members for int, float, and char
union Data {
  int n;
  float avg;
  char c;
};


void setup() {
  // Serial setup
  Serial.begin(9600);
  while (!Serial)
    ;
  // Create one Data variable
  union Data data;

  // Store an int, then print it
  data.n = 5;
  Serial.println(data.n);

  // Store a float in the same union, then print it
  data.avg = 3.33;
  Serial.println(data.avg);

  // Print integer again
  Serial.println(data.n);
}

void loop() {
  // put your main code here, to run repeatedly:
}
