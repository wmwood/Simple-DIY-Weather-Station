void loop() {
  if (radio.available())
  {
    String data = radio.readStringUntil(10);

    if (!data.startsWith("[WD]:")) {
      return;
    }

    digitalWrite(LED_BUILTIN, HIGH);

#ifdef DEBUG
    Serial.println(data);
#endif

    data.replace("[WD]:", "");

    StaticJsonDocument<capacity> doc;
    deserializeJson(doc, data);

    handleHeaders();

    drawData(doc["t"], doc["h"], doc["p"], calculateGPP(doc["t"], doc["h"]));

    digitalWrite(LED_BUILTIN, LOW);
  }
}

void handleHeaders() {
  if (LabelsHidden) {
    clearWelcome();
    drawLabels();
    LabelsHidden = false;
  }
}
