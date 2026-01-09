#include <LiquidCrystal_I2C.h>

/* Exercise 11

reads value from temperature sensor, calculates average of multiple measurements and prints average temperature on an LCD screen
Temperature is read every 100 ms and the number of averaged measurements is determinded by N_LOOPS.

Circuit:
* LM 35 DZ temperature sensor connected to A0, 5 V and ground
* I2C LCD-module connected to SCL, SDA, VIN and GND

Created 08 jan 2026
by Anssi Sohlman

*/

// Baud rate for serial monitor, mainly for debugging
const unsigned long MY_BAUD = 115200;

//Temperature limit for error message
const float TOOHOT = 23.5;

// the resolution and maximum voltage of A0
const int STEPS = 1023;
const float V_MAX = 5.0;

// Connecting to the LCD and creating an instance lcd via which the screen can be manipulated
LiquidCrystal_I2C lcd(0x27, 20, 4);

// For counting average temperature
const int N_LOOPS = 10;  // Number of readings to average
int count = 0;
double tempArr[N_LOOPS];  // Storing the measured temperatures

void setup() {

  Serial.begin(MY_BAUD);

  lcd.init();  // initialize the lcd
  lcd.backlight();

  //Write the text temperature
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");

  //Write the unit
  lcd.setCursor(5, 1);
  lcd.print((char)223);  //Picked up from a forum, no idea why this prints the degree sign
  lcd.print("C");
}

void loop() {

  //read the converted analogue value
  int val = analogRead(A0);

  //convert digital value to voltage
  float voltage = (float)val * (V_MAX / STEPS);

  //convert voltage to temperature and print
  float temp = voltage / 0.01;
  // Serial.print("Temperature:\t");
  // Serial.print(temp, 1);
  // Serial.print(" ");
  // // Serial.write(176); //Doesn't work
  // Serial.println("°C");
  // Serial.print("Counter:\t");
  // Serial.println(count);

  tempArr[count] = temp;
  count++;

  //Calculating average temperature
  if (count == N_LOOPS) {
    float sum = 0.0;
    float avgTemp = 0.0;

    //Adding temperatures
    for (int i = 0; i < N_LOOPS; i++) {
      sum = sum + tempArr[i];
    }

    avgTemp = sum / N_LOOPS;

    // Serial.println("");
    // Serial.print("Average temperature:\t");
    // Serial.print(avgTemp, 1);
    // Serial.print(" ");
    // // Serial.write(176); //Doesn't work
    // Serial.println("°C");

    //Updating the LCD

    lcd.setCursor(0, 1);
    lcd.print(avgTemp, 1);

    //Print warning if temparature is too high
    if (avgTemp > TOOHOT) {
      lcd.setCursor(13, 1);
      lcd.print("!!!");
    }

    count = 0;
  }

  Serial.println('\n');

  delay(100);
}
