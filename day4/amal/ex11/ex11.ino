/*
  Exercise 11: Output temperature to LCD-screen

  Using a TMP36 an analog output of a sensor is read, converted to a voltage and 
  finally, converted to a temperature in degrees Celsius. This is printed to the LCD screen.

  By Amal Almis
  Created 08-01-2026

*/

int const tmpPin = A0;

#include <LiquidCrystal_I2C.h>

// Init screen
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Initial TMP36 temperature: ");
  pinMode(tmpPin, INPUT);

  lcd.init(); // Initialise the LCD
  lcd.backlight();
}

void loop() {
  int adcValue;
  float voltage;
  float temperatureC;
  float avgTempC = 0; // average temperature (10 measurements)

  // average temperature
  for (int i = 0; i<10; i++) {
    adcValue = analogRead(tmpPin);      // read analog value (between 0 and 1023)
    voltage = adcValue*(5.0/1024.0);    // convert to voltage
    temperatureC = (voltage-0.5)* 100.0; // tmp36 voltage offset (from data sheet)
    avgTempC += temperatureC/10.0;
  }
  // Print temperature value
  Serial.print(temperatureC, 1);  // 1 decimal place

  // Print degree symbol using UTF-8 (= 0xc2 0xb0)
  Serial.write(0xC2);
  Serial.write(0xB0);
  Serial.println("C");

  // LCD
  lcd.setCursor(0,0);
  lcd.print(avgTempC);
  lcd.print((char)223);
  lcd.setCursor(0,1);
  if (avgTempC >= 23){
    lcd.print("HIGH TEMP");
  }
  else if (avgTempC >= 22){
    lcd.print("RISING TEMP");
  }
  else{
    lcd.print("LOW TEMP");
  }
  delay(1000);
}
