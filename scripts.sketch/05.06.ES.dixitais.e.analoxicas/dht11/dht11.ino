/*
 * Script para medir temperatura
 * e humidade empregando o sensor
 * analóxico DHT11
 */
#include <DHT.h>

#define PIN_DHT A0

int tempo = 6000;
  DHT sensor(PIN_DHT, DHT11);  //Declaramos obxecto dht
float humidade, temperatura;

void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
  humidade = sensor.readHumidity();
  temperatura = sensor.readTemperature();

  //Detección de erros
  if(isnan(humidade) || isnan(temperatura)) {
    Serial.println("Fallo na lectura do DHT11");
    return;
  }
  Serial.print("Humidade:\t");
  Serial.print(humidade);
  Serial.print(" %\t\t");
  Serial.print("Temperatura:\t");
  Serial.print(temperatura);
  Serial.print(" ºC");
  Serial.print("\n");
  delay(tempo);
}
