#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// WiFi credentials
const char* ssid = "hide yo kids, hide yo wifi";
const char* password = "vlk06tyj";

// ThingSpeak connection
WiFiClient client;
unsigned long channelID = 3227727;             
const char* APIKey = "AI1AW54QN1V1BAKP";     // write key
const char* server = "api.thingspeak.com";   // ThingSpeak server

// Post delay (20 seconds)
const int postDelay = 20 * 1000;

// Hardware
const int ledPin = D2;

// Data variables
float rssiValue;
float ledValue;

void setup() {
  Serial.begin(115200);

  // LED setup
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);  // LED ON for demo

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  // Read values
  rssiValue = WiFi.RSSI();          // RSSI
  ledValue = digitalRead(ledPin);  // LED state

  // Initialize ThingSpeak
  ThingSpeak.begin(client);

  // Connect manually to ThingSpeak server
  client.connect(server, 80);

  // Field 1: RSSI
  ThingSpeak.setField(1, rssiValue);

  // Field 2: LED state
  ThingSpeak.setField(2, ledValue);

  // Upload data
  ThingSpeak.writeFields(channelID, APIKey);

  // Close connection
  client.stop();

  // Wait before next upload
  delay(postDelay);
}
