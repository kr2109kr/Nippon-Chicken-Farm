#define MQ_PIN A0
#define RL 10
#define ADC_MAX 1023.0

float R0 = 9.83;

void ReadMQ() {
  float ppm = GetPPM() * 100;
  Blynk.virtualWrite(V2, ppm);
}

float GetRS() {
  int adc = analogRead(MQ_PIN);
  float voltageRatio = adc / ADC_MAX;
  voltageRatio = max(voltageRatio, 0.01f);
  float RS = RL * (1.0 - voltageRatio) / voltageRatio;
  return RS;
}

float GetPPM() {
  float RS = GetRS();
  float ratio = RS / R0;

  float ppm = 574.25 * pow(ratio, -2.222);
  return ppm;
}
