/*
 * Presenta por display LCD 16x2
 * unha mensaxe estática e un 
 * cursor que encende e apaga.
 * 
 * Programa para mostrar o uso das
 * funcións básicas da librería
 * LiquidCristal.h.
 * 
 * Asume pins LCD --> Arduino:
 * GND Vcc Vo RS RW E D0 -- D7 A K
 * GND  5V || 10  9 8 ----5432 | GND
 *      Potenc                 Resist
 * Tamen se pode prescindir de RW 
 */

#include <LiquidCrystal.h>

//LiquidCrystal(rs, rw, enable, d4, d5, d6, d7)
LiquidCrystal lcd(10, 9, 8, 5, 4, 3, 2);

int espera = 500;

void setup() {
  //Inicia LCD e imprime duas linhas de
  //mensaxe estatico
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" LCD preparado");
  lcd.setCursor(5, 1);
  lcd.print("OK :-)");
}

void loop() {
  //Mostra e oculta o cursor alternativamente
  lcd.noCursor();
  delay(espera);
  lcd.cursor();
  delay(espera);
}
