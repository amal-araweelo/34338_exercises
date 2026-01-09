
// Define a Sensor struct with a name field
struct Sensor {
  char name[12];
  // Inside Sensor, include a union with temperature, humidity, status
  union {
    float temp;
    int humidity;
    char status[10];
  };
};

void setup() {
  // Serial setup
  Serial.begin(9600);
  while (!Serial)
    ;
  // Create a Sensor value
  struct Sensor sensor;
  strcpy(sensor.name, "TMP36");

  // Store a temperature value in the union
  sensor.temp = 25.0;
  
  // Print the sensor name and temperature
  Serial.print("Sensor name: ");
  Serial.println(sensor.name);
  Serial.print("Temperature: ");
  Serial.println(sensor.temp);
}

void loop() {
  // put your main code here, to run repeatedly:
}
