void setup() {
  // Serial setup
  Serial.begin(9600);
  while(!Serial);
  
  // Define a Student struct with name, age, grade 
  struct Student {
    char name[5];
    int age;
    int grade;
  };

  // Create one Student variable 
  struct Student s1;

  // Fill in each field 
  s1.age=24;
  s1.grade=7;
  strcpy(s1.name, "Amal"); // since arrays are not assignable


  // Print the fields using dot notation
  Serial.print("Name: ");
  Serial.println(s1.name);
  Serial.print("Age: ");
  Serial.println(s1.age);
  Serial.print("Grade: ");
  Serial.println(s1.grade);
}

void loop() {
  // put your main code here, to run repeatedly:

}
