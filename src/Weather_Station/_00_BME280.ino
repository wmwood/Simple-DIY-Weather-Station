void setupBME() {
  while (!bme.begin())
  {
    delay(1000);
  }
}
