/*
 * Script para medir a distancia
 * a un obxecto, empregando un
 * sensor de ultrasóns HC-SR04.
 * A partir dunha distancia mínima
 * encéndese un LED; esta distancia
 * pódese regular cun potenciómetro.
 * 
 * Inclúe a libreria NewPing para
 * facilitar a codificación e lectura.
 */
#include <NewPing.h>

#define TRIGGER 9
#define ECHO 10

#define POTENCIOMETRO A0
#define LED 8

#define DIST_MIN 20
#define DIST_MAX 200

unsigned int   distancia;
int valorPot, limite;
String mensaxe = "";
int espera = 400;

NewPing sensor(TRIGGER, ECHO, DIST_MAX);

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  distancia = sensor.ping_cm();
  
  //Regulamos a distancia mínima para 
  //que acenda o LED, co potenciómetro
  valorPot = analogRead(POTENCIOMETRO);
  limite = map(valorPot, 0, 1023, 0, DIST_MIN);

  //Encendemos LED se se supera a dist mínima
  if(distancia < limite) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);

  //Escribimos no porto serie os resultados
  mensaxe = "Distancia: " + String(distancia) + " cm";
  mensaxe += "\tLimite: " + String(limite) + " cm";
  Serial.println(mensaxe);
  delay(espera);
}
