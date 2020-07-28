void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  radio.begin(9600);

  Wire.begin();
  setupBME();
}
