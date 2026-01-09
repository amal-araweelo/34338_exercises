/*
This code contains answers to all questions for day 5.
Themes include pointers, structs and unions.
Since the exercises are short, I included them all in a single file

An arduino board is required to run the code but it does not need to have anything connected to it

Created 9 january 2026
by Anssi Sohlman
*/

const unsigned long MY_BAUD = 115200;

// For ex5
struct Student {
  char* name;  //Pointer to memory to be allocated when needed
  int age;
  float grade;
};

// For ex6
struct Car {
  char* make;  //Pointer to memory to be allocated when needed
  int year;
};

// For ex7
union Data {
  int i;
  float f;
  char c;
};

//For ex8
union SensorData {
  int humidity;
  float temperature;
  char status;
};

//For ex8
struct Sensor {
  char name[20];
  union SensorData data;
};

//For ex9
union Conversion {
  float f;
  byte arr[4];  //Could also be unsigned char. Signed char resulted in some nonsense hex values
};


void setup() {

  Serial.begin(MY_BAUD);

  // ex1
  Serial.println("---Exercise 1---");

  int x = 10;
  int* p1 = &x;         //pointer to x
  Serial.println(*p1);  //print value at pointer
  Serial.println("");


  // ex2
  Serial.println("---Exercise 2---");

  float temperature = 36.6;
  float* p2 = &temperature;  //pointer to temperature
  *p2 = 26.5;                //Change temperature value
  Serial.println(temperature);
  Serial.println("");


  // ex3
  Serial.println("---Exercise 3---");

  int intArray[] = { 1, 2, 3, 4, 5 };
  int* p3 = &intArray[0];  //pointer to array

  //Print array values using pointer arithmetic
  for (int i = 0; i < 5; i++) {
    Serial.print(*(p3 + i));  // value at p3 is 1, p3+1 is 2 and so on
    Serial.print(" ");
  }
  Serial.println("");
  Serial.println("");


  // ex4
  Serial.println("---Exercise 4---");

  int x4 = 10;
  int* p4 = &x4;  //pointer to integer
  int** q = &p4;  //pointer to pointer
  **q = 5;        //changing integer value
  Serial.println(x4);
  Serial.println("");


  //ex5
  Serial.println("---Exercise 5---");

  Student s1; //create a student variable

  // Here name is set using only the memory necessary
  // A char array of static size would also have been possible
  char nameString[] = "Linda";

  //Count number of characters in name (exluding '\o')
  int letters = 0;
  for (int i = 0; nameString[i] != '\0'; i++) {
    letters++;
  }

  // Returns a pointer to new allocated memory that fits the name and ending '\0'
  s1.name = (char*)malloc(sizeof(char) * (letters + 1));

  // Copies the name to the newly allocated memory (strncpy could also work)
  for (int i = 0; nameString[i] != '\0'; i++) {
    *(s1.name + i) = nameString[i];
  }

  // Adds ending character
  *(s1.name + letters) = '\0';

  //set the rest of fields
  s1.age = 21;
  s1.grade = 5.62;

  //Prints the name
  for (int i = 0; *(s1.name + i) != '\0'; i++) {
    Serial.print(*(s1.name + i));
  }
  Serial.println("");

  //Print the rest
  Serial.println(s1.age);
  Serial.println(s1.grade, 1);

  // Free the allocated memory
  free(s1.name);
  s1.name = nullptr;

  Serial.println("");


  //ex6
  Serial.println("---Exercise 6---");

  Car myCar; //create a Car variable

  // Here name is set the same way as in exercise 5
  char makeString[] = "Audi";

  //Count number of characters in maker (exluding '\o')
  int letters_car = 0;
  for (int i = 0; makeString[i] != '\0'; i++) {
    letters_car++;
  }

  // Returns a pointer to new allocated memory that fits the name and ending \0
  myCar.make = (char*)malloc(sizeof(char) * (letters_car + 1));

  // Copies the name to the newly allocated space
  for (int i = 0; makeString[i] != '\0'; i++) {
    *(myCar.make + i) = makeString[i];
  }

  // Adds ending character
  *(myCar.make + letters_car) = '\0';

  //Set year
  myCar.year = 1999;

  // use the function printCar to print details of the car
  printCar(myCar);

  // Free the allocated memory
  free(myCar.make);
  myCar.make = nullptr;

  Serial.println("");


  //ex7
  Serial.println("---Exercise 7---");

  Data testUnion;
  testUnion.i = 10;
  int* iAddress = &testUnion.i;  //the address of the integer
  Serial.println(testUnion.i);
  Serial.print("Integer address (converted to integer): ");
  Serial.println((unsigned int)iAddress);  //Print memory address

  testUnion.f = 3.12;
  float* fAddress = &testUnion.f;  //the address of the float
  Serial.println(testUnion.f);
  Serial.print("Float address (converted to integer): ");
  Serial.println((unsigned int)fAddress);  //Print memory address (same as integer!)

  //print the value of integer when float has been set
  Serial.print("integer value (bad!): ");
  Serial.println(testUnion.i);

  Serial.println("");


  //ex8
  Serial.println("---Exercise 8---");

  Sensor mySensor;
  // Using a char array of static size for simplicity
  char sensorStr[] = "temperature sensor";
  strncpy(mySensor.name, sensorStr, sizeof(sensorStr));  //copy the string to the struct
  mySensor.data.temperature = 13.2;

  //Print sensor data
  Serial.println(mySensor.name);
  Serial.println(mySensor.data.temperature);

  Serial.println("");


  //ex9
  Serial.println("---Exercise 9---");

  Conversion myConversion;
  myConversion.f = 2.43;  //In arduino, float is 4 bytes
  Serial.println(myConversion.f);
  Serial.println("");
  Serial.println("hex\t\tdecimal"); //titles for individual bytes

  //Print the individual bytes
  for (int i = 0; i < 4; i++) {
    //print both decimal and hex for comparison
    Serial.print(myConversion.arr[i], HEX);
    Serial.print("\t\t");
    Serial.println(myConversion.arr[i], DEC);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

// Function for exercise 6
void printCar(Car someCar) {

  //Prints the name
  for (int i = 0; *(someCar.make + i) != '\0'; i++) {
    Serial.print(*(someCar.make + i));
  }

  Serial.println("");
  Serial.println(someCar.year);
}
