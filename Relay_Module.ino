BLYNK_WRITE(V10) {
  digitalWrite(D0, param.asInt());
}

BLYNK_WRITE(V11) {
  digitalWrite(D3, param.asInt());
}

BLYNK_WRITE(V12) {
  digitalWrite(D5, param.asInt());
}

BLYNK_WRITE(V13) {
  digitalWrite(D6, param.asInt());
}

BLYNK_WRITE(V14) {
  digitalWrite(D7, param.asInt());
}

BLYNK_WRITE(V15) {
  digitalWrite(D8, param.asInt());
}

void SetupRelay() {
  pinMode(D0, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
}