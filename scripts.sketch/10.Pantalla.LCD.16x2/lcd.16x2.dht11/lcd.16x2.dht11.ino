/*
 * Presenta por display LCD 16x2
 * a temperatura e humidade que
 * proporciona un sensor DHT11.
 * 
 * Asume pins LCD --> Arduino:
 * GND Vcc Vo RS RW E D0 -- D7 A K
 * GND  5V || 10  9 8 ----5432 | GND
 *      Potenc                 Resist
 * Tamen se pode prescindir de RW 
 */

#include <LiquidCrystal.h>
#include <DHT.h>

#define PIN_DHT A0

//Declaramos obxecto LiquidCristal
//LiquidCrystal(rs, rw, enable, d4, d5, d6, d7)
LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2);
//Declaramos obxecto dht
DHT sensor(PIN_DHT, DHT11);
float humidade, temperatura;
String mensHumid = "Humid: ", mensTemp = "Temp: ";

int espera = 800;

void setup() {
  //Inicia sensor DHT11
  sensor.begin();
  //Inicia LCD e imprime duas linhas de
  //mensaxe estatico
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" LCD preparado");
  lcd.setCursor(5, 1);
  lcd.print("OK :-)");
}

void loop() {
  humidade = sensor.readHumidity();
  temperatura = sensor.readTemperature();
  mensHumid += String(humidade) + " %";
  //Deteccion de erros
  if(isnan(humidade) || isnan(temperatura)) {
    lcd.setCursor(0, 0);
    lcd.print("Fallo en DHT11");
    lcd.setCursor(3, 1);
    lcd.print("Agarde");
    delay(5*espera);
    return;
  }
  //Mostra lecturas do DHT11 a vez
  lcd.setCursor(0, 0);
  lcd.print(mensHumid + String(humidade) + " %");
  lcd.setCursor(0, 1);
  lcd.print(mensTemp + String(temperatura) + " ºC");
  //Mostra e oculta o cursor alternativamente
  lcd.noCursor();
  delay(espera);
  lcd.cursor();
  delay(espera);
}
