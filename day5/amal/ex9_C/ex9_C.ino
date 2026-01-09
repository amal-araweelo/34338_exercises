// Define a union Conversion with a float member
// Add a 4-byte array to the union too
union Conversion {
  float f;
  unsigned char bytes[4];  // 4 * 1 byte
};


void setup() {
  // Serial setup
  Serial.begin(9600);
  while (!Serial)
    ;

  union Conversion conversion;

  // Store a float value in the union
  conversion.f = 35.6;

  // Print the float
  Serial.print("Float: ");
  Serial.println(conversion.f);

  // Print each byte value in the array in hex
  Serial.print("Bytes: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(conversion.bytes[i], HEX);
    Serial.println(" ");
  }

  // Trying the opposite (from bytes to float)  
  conversion.bytes[0] = 0x66;
  conversion.bytes[1] = 0x66;
  conversion.bytes[2] = 0xE;
  conversion.bytes[3] = 0x42;
  Serial.print("Float: ");
  Serial.println(conversion.f);
}

void loop() {
  // put your main code here, to run repeatedly:
}
