/*
 * Script para medir a distancia
 * a un obxecto, empregando un
 * sensor de ultrasóns HC-SR04
 */

#define TRIGGER 9
#define ECHO 10
//Defimos macro para calcular distancia
#define calcDist(t) t*0.017   //en cm

float tempo, distancia;
String mensaxe = "";
int espera = 200;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
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

  //Escribimos no porto serie os resultados
  mensaxe = "Distancia: " + String(distancia) + " cm.";
  Serial.println(mensaxe);
  delay(espera);
}
