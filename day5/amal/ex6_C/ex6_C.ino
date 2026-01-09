// Define a Car struct with make and year
struct Car {
  char make[7];
  int year;
};

void setup() {
  // Serial setup
  Serial.begin(9600);
  while (!Serial)
    ;

  struct Car car;
  strcpy(car.make, "Toyota");
  car.year = 1980;

  printCar(car);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// Write a function that accepts a Car parameter
// note: here we have to access members using "->"
void printCar(Car c) {
  Serial.print("Car year: ");
  Serial.println(c.year);
  Serial.print("Car make: ");
  Serial.println(c.make);
}

