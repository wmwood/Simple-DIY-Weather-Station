bool LabelsHidden = true;

void drawHeader() {
  int leftMargin = (oled.displayWidth() - oled.strWidth(HUB_NAME)) / 2;
  oled.set1X();
  oled.setCursor(leftMargin, 0);
  oled.println(HUB_NAME);
}

void drawWelcome() {
  oled.setCursor(0, 4);
  oled.set2X();
  oled.print("Loading...");
}

void clearWelcome() {
  oled.setCursor(0, 4);
  oled.set2X();
  oled.clearToEOL();
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
  oled.print("G:");
}

void drawData(int temperature, int humidity, float pressure, int gpp) {
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
  oled.print(gpp);
  oled.print("     ");
}
