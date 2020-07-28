const float a0 = 6.107799961;
const float a1 = 0.4436518521;
const float a2 = 0.01428945805;
const float a3 = 0.0002650648471;
const float a4 = 0.000003031240396;
const float a5 = 0.00000002034080948;
const float a6 = 0.00000000006136820929;

float calculateGPP(float temperature, float humidity) {
  temperature = (temperature - 32) * 0.55555; // Convert F to C
  float pws = a0 + temperature * (a1 + temperature * ( a2 + temperature * (a3 + temperature * ( a4 + temperature * (a5 + a6 * temperature)))));
  float pw = (humidity * pws) / 100.00;
  float p = 1013.25;
  float scale = 4354;
  float gpp = scale * pw / (p - pw);
  return round(gpp);
}
