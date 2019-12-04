/*
 * Presenta por display LCD 16x2
 * a distancia a un obxecto que 
 * proporciona un sensor ultrasons
 * 
 * Asume pins LCD --> Arduino:
 * GND Vcc Vo RS RW E D0 -- D7 A K
 * GND  5V || 10  9 8 ----5432 | GND
 *      Potenc                 Resist
 * Tamen se pode prescindir de RW 
 */

#include <LiquidCrystal.h>

#define TRIGGER 7
#define ECHO 6
//Definimos macro para calcular distancia
#define calcDist(t) t*0.017   //en cm

#define DIST_MIN 10
#define DIST_MAX 150

//Declaramos obxecto LiquidCristal
//LiquidCrystal(rs, rw, enable, d4, d5, d6, d7)
LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2);

float tempo, distancia;
String mensaxe = "Dist: ";

int espera = 400;

void setup() {
  //Declaramos pins do sensor ultrasons
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  //Inicia LCD e imprime duas linhas de
  //mensaxe estatico
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" LCD preparado");
  lcd.setCursor(5, 1);
  lcd.print("OK :-)");
  delay(15*espera);
}

void loop() {
  //Enviamos un pulso co HC-SR04
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(25);
  digitalWrite(TRIGGER, LOW);
  tempo = pulseIn(ECHO, HIGH);
  
  //Calculamos a distancia en cm
  distancia = calcDist(tempo);
  
  //Borra display
  lcd.clear();
  
  //Mostra lecturas do sensor
  lcd.setCursor(0, 0);
  lcd.print(mensaxe + String(distancia) + " cm");
  lcd.setCursor(0, 1);
  if(distancia <= DIST_MIN) {
    lcd.setCursor(1, 1);
    lcd.print("PRECAUCION!!");
  }
  if(distancia >= DIST_MAX) {
    lcd.setCursor(1, 1);
    lcd.print("FORA DE RANGO!");
  }
  //Mostra e oculta o cursor alternativamente
  lcd.noCursor();
  delay(espera);
  lcd.cursor();
  delay(espera);
}
