/*
 * Script para medir a distancia
 * a un obxecto, empregando un
 * sensor de ultrasóns HC-SR04.
 * A partir dunha distancia mínima
 * encéndese un LED; esta distancia
 * pódese regular cun potenciómetro
 */

#define TRIGGER 9
#define ECHO 10
//Defimos macro para calcular distancia
#define calcDist(t) t*0.017   //en cm

#define POTENCIOMETRO A0
#define LED 8

#define DIST_MIN 200

float tempo, distancia;
int valorPot, limite;
String mensaxe = "";
int espera = 400;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  //Regulamos a distancia mínima para 
  //que acenda o LED, co potenciómetro
  valorPot = analogRead(POTENCIOMETRO);
  limite = map(valorPot, 0, 1023, 0, DIST_MIN);
  
  //Enviamos un pulso co HC-SR04
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  tempo = pulseIn(ECHO, HIGH);
  
  //Calculamos a distancia en cm
  distancia = calcDist(tempo);

  //Encendemos LED se se supera a dist mínima
  if(distancia < limite) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);

  //Escribimos no porto serie os resultados
  mensaxe = "Distancia: " + String(distancia) + " cm";
  mensaxe += "\tLimite: " + String(limite) + " cm";
  Serial.println(mensaxe);
  delay(espera);
}
