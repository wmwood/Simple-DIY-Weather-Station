void loop() {
  readAndSendData(&radio);
}

void readAndSendData(Stream* client)
{
  float temp(NAN), hum(NAN), pres(NAN);

  BME280::TempUnit tempUnit(BME280::TempUnit_Fahrenheit);
  BME280::PresUnit presUnit(BME280::PresUnit_inHg);

  digitalWrite(LED_BUILTIN, HIGH);

  bme.read(pres, temp, hum, tempUnit, presUnit);

  StaticJsonDocument<capacity> doc;
  doc["t"] = temp;
  doc["h"] = hum;
  doc["p"] = pres;
  doc["d"] = EnvironmentCalculations::DewPoint(temp, hum, tempUnit);

  String data = "[WD]:";
  serializeJson(doc, data);
  client->println(data);
  digitalWrite(LED_BUILTIN, LOW);

  delay(1250);
}
