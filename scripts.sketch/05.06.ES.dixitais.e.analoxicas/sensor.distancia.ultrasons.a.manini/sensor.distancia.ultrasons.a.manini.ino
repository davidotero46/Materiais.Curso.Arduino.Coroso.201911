/*
 * Script para medir a distancia
 * a un obxecto, empregando un
 * sensor de ultrasóns HC-SR04
 */

#define TRIGGER 9
#define ECHO 10
//Defimos macro para calcular distancia
#define calcDist(t) t*0.017

float tempo, distancia;
float tInicial, tFinal;
int echo;
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
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  echo = digitalRead(ECHO);
  tInicial = micros();
  while(echo == LOW) {
    echo = digitalRead(ECHO);
  }
  while(echo == HIGH) {
    echo = digitalRead(ECHO);
    tFinal = micros();
  }
  //A resta dos dous tempos danos
  //a duración do pulso desde que
  //se empeza a enviar até que se
  //deixa de recibir
  tempo = tFinal - tInicial;
  tempo /= 2; 
  
  //Calculamos a distancia en cm
  distancia = calcDist(tempo);

  //Escribimos no porto serie os resultados
  mensaxe = "Distancia: " + String(distancia) + " cm";
  Serial.println(mensaxe);
  delay(espera);
}

/*
 * Función para calcular a distancia en cm.
 * 
 * A distancia medida é o doble da obtida
 * polo sensor (ida e volta).
 * As unidades serán en cm/us, a velocidade
 * do son é 340 m/s = 
 * = 340 m/s * (1 s)/(1000000 us) * (100 cm)/(1 m) =
 * = 340 / 10000 cm/us = 0.034 cm/us
 */
float calcularDistancia(float t) {
  // v = 2*dist / tempo ==> dist = tempo*v/2
  // dist = tempo*0.034/2 = tempo*0.017 [cm]
  return t*0.017;
}
