/*
 * Presenta por display LCD 16x2
 * a distancia a un obxecto que 
 * proporciona un sensor ultrasons.
 *
 * Fai scrollo do texto a dereita
 * e esquerada, usando funcions
 * da libreria LiquidCrystal
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
String mFila1 = "", mFila2 = "";

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
  delay(4*espera);
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
  mFila1 = "Dist: " + String(distancia) + " cm";
  lcd.setCursor(0,0);
  lcd.print(mFila1);
  //Mostra aviso de limites do sensor
  if(distancia <= DIST_MIN)
    mFila2 = "PRECAUCION!!";
  else if(distancia >= DIST_MAX)
    mFila2 = "FORA DE RANGO!";
  else
    mFila2 = "";
  lcd.setCursor(0,1);
  lcd.print(mFila2);
  delay(espera);
  //Move o texto a dereita...
  for(int i=0; i<16; i++) {
    lcd.scrollDisplayRight();
    delay(espera/3);
  }
  //...volta a esquerda...
  for(int i=0; i<32; i++) {
    lcd.scrollDisplayLeft();
    delay(espera/3);
  }
  //...e novamente a dereita
  for(int i=0; i<16; i++) {
    lcd.scrollDisplayRight();
    delay(espera/3);
  }
  //Cursor encende e apaga
  lcd.noCursor();
  delay(espera);
  lcd.cursor();
  delay(espera);
}
