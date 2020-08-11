bool LabelsHidden = true;
unsigned long lastUpdatedMillis = 0;

void drawHeader() {
  int leftMargin = (oled.displayWidth() - oled.strWidth(HUB_NAME)) / 2;
  oled.set1X();
  oled.setCursor(leftMargin, 0);
  oled.println(HUB_NAME);
}

void drawConnecting() {
  oled.setCursor(0, 4);
  oled.set1X();
  oled.print("Connecting...");
}

void clearBody() {
  oled.clear(0, 128, 2, 62);
}

void drawLabels() {
  oled.set1X();

  oled.setCursor(0, 2);
  oled.print("T:");

  oled.setCursor(82, 2);
  oled.print("H:");

  oled.setCursor(0, 4);
  oled.print("P:");

  oled.setCursor(0, 6);
  oled.print("D:");
}

void drawData(int temperature, int humidity, float pressure, int dew) {
  oled.set2X();

  oled.setCursor(12, 2);
  oled.print(temperature);
  oled.print("F ");

  oled.setCursor(94, 2);
  oled.print(humidity);
  oled.print("% ");

  oled.setCursor(12, 4);
  oled.print(pressure);
  oled.print("in     ");

  oled.setCursor(12, 6);
  oled.print(dew);
  oled.print("F ");
}
