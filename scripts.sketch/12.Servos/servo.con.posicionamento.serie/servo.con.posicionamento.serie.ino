/*
 * Proba de funcionamento dun servomotor
 * empregando a librería <Servo.h>
 * e a entrada serie para o posicionamento
 * do mesmo.
 */

#include <Servo.h>

//Pin de control do servo
#define CTRL 9

//Declaramos o obxecto motor
//da clase Servo
Servo motor;
int veloc = 20;

String orde ="";
int posicion = 0;

void setup() {
  motor.attach(CTRL);
  Serial.begin(9600);
}

void loop() {
  //Comprobamos se hai orde no teclado
  if(Serial.available()) {
    orde = Serial.readStringUntil('\n');
    orde.toLowerCase();
    if(orde.equals("esquerda")) posicion = 180;
    else if(orde.equals("dereita")) posicion = 0;
    else if(orde.equals("centro")) posicion = 90;
    else {
      int tmp = orde.toInt();
      if(tmp >= 0 && tmp <= 180) posicion = tmp;
      else posicion = 0;      
    }
  }
  motor.write(posicion);
  delay(veloc);
}
