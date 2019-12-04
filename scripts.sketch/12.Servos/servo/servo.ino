/*
 * Proba de funcionamento dun servomotor
 * empregando a librería <Servo.h>
 */

#include <Servo.h>

//Pin de control do servo
#define CTRL 9

//Declaramos o obxecto motor
//da clase Servo
Servo motor;
int veloc = 100;

void setup() {
  motor.attach(CTRL);
}

void loop() {
  //Move o servo entre 0º e 180º en
  //incrementos de 5º
  for(int i = 0; i <= 180; i++) {
    motor.write(i);
    delay(veloc);
  }
  delay(15*veloc);
  //Move o servo entre 180º e 0º en
  //decrementos de 5º
  for(int i = 180; i >= 0; i--) {
    motor.write(i);
    delay(veloc);
  }
}
