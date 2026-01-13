


#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi creds
const char* ssid = "hide yo kids, hide yo wifi";
const char* password = "vlk06tyj";

// create a web server on port 80
ESP8266WebServer server(80);

// LED connected to pin D2
const int ledPin = D2;

// Variable to store LED state
bool ledState = false;

// Function that sends the main HTML page
void handleRoot() {
  server.send(
    200,
    "text/html",
    "<html><title>Internet of Things - Demonstration</title>"
    "<meta charset=\"utf-8\" /></head><body>"
    "<h1>Velkommen til denne WebServer</h1>"
    "<p>Internet of Things (IoT) er \"tingenes Internet\" - dagligdags ting "
    "kommer på nettet og får ny værdi.</p>"
    "<p>Her kommunikerer du med en webserver på en lille microcontroller "
    "af typen Arduino, som styrer en digital udgang.</p>"
    "<p>Klik på nedenstående knap for at tænde eller slukke LED på port D2</p>"
    "<form action=\"/LED\" method=\"POST\">"
    "<input type=\"submit\" value=\"Skift tilstand på LED\" "
    "style=\"width:500px; height:100px; font-size:24px\">"
    "</form>"
    "<p>Med en Arduino ESP8266 kan du lave mange sjove projekter</p>"
    "</body></html>"
  );
}

// Function that handles POST request and toggles LED
void handleLED() {
  // Toggle LED state
  ledState = !ledState;
  digitalWrite(ledPin, ledState);

  // Redirect back to main page
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Configure LED pin as output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Define URL handlers
  server.on("/", HTTP_GET, handleRoot);   // Load webpage
  server.on("/LED", HTTP_POST, handleLED); // Handle button press

  // Start web server
  server.begin();

  // Print IP address to Serial Monitor
  Serial.println(WiFi.localIP());
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}
