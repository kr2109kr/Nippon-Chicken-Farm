#include <DHT.h>

#define DHTPIN D1
#define DHTTYPE DHT21

DHT dht(DHTPIN, DHTTYPE);

void SetupDHT() {
  dht.begin();
}

void ReadDHT() {
  Temperature();
  Humidity();
}

void Temperature() {
  float temperature = dht.readTemperature();
  Blynk.virtualWrite(V0, temperature);
}

void Humidity() {
  float humidity = dht.readHumidity();
  Blynk.virtualWrite(V1, humidity);
}
