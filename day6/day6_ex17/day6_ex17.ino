/* Exercise 17

Uploads the measured SSID and the state of a led light to ThingSpeak

circuit: an ESP8266 with:
* a button connected to D1 (internal pull-up resistor is used)
* A led connected to D2

Created 12 jan 2026
by Anssi Sohlman and Amal Almis
*/

#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "REDACTED";
const char* pass = "REDACTED";

WiFiClient client;

unsigned long channelID = 0000000;  //REDACTED
const char* APIKey = "REDACTED";    //your TS API
const char* server = "api.thingspeak.com";
const int readDelay = 1 * 1000;  //read every 1 seconds

//For controlling a led
const int CONTROLPIN = D1;
const int LEDPIN = D2;

// Uploaded every N seconds
const int N_LOOPS = 5;

//Initial state of button is off
int buttonState = HIGH;  //For button

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, pass);  // Connect to wifi

  //set pins for led and button
  pinMode(CONTROLPIN, INPUT_PULLUP);  // Button
  pinMode(LEDPIN, OUTPUT);
}

int rssi;  //reported rssi
int counter = 0;
int ledState = LOW;  //for led

void loop() {

  counter++;  //Goes from 1 to N_LOOPS

  //If button is down, switch led
  //Checked every second
  buttonState = digitalRead(CONTROLPIN);
  if (buttonState == LOW) {
    ledState = !ledState;
    digitalWrite(LEDPIN, ledState);
  }

  rssi = WiFi.RSSI();

  // Every N seconds the data is uploaded to ThingSpeak
  if (counter == N_LOOPS) {
    Serial.println(rssi);
    ThingSpeak.begin(client);
    client.connect(server, 80);    //connect(URL, Port)
    ThingSpeak.setField(2, rssi);  //set data on the 2 graph
    ThingSpeak.setField(3, ledState); //set data on the 3 graph
    ThingSpeak.writeFields(channelID, APIKey);  //post everything to TS
    client.stop();

    counter = 0;
  }

  delay(readDelay);
}
