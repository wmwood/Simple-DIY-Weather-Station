
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

    drawData(doc["t"], doc["h"], doc["p"], doc["d"]);

    digitalWrite(LED_BUILTIN, LOW);

    lastUpdatedMillis = millis();
  }
  else {
    if  ((millis() - lastUpdatedMillis) >= 5000 && !LabelsHidden) {
      clearBody();
      drawConnecting();
      LabelsHidden = true;
    }
  }
}

void handleHeaders() {
  if (LabelsHidden) {
    clearBody();
    drawLabels();
    LabelsHidden = false;
  }
}
