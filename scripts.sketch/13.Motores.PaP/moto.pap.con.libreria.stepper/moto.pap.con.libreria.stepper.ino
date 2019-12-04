/*
 * Proba o funcionamento dun motor paso a paso
 * usando a librería <Stepper.h> para que dea 
 * cinco voltas completas en sentido horario e
 * outras cinco en sentido antihorario.
 */
#include <Stepper.h>

//Pins para control do motor PaP
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

//Parámetros do motor, pasos totais e por fase
#define STEPS 4076 //Pasos totais por volta
#define NSTEPS 8 //Número de pasos por fase (4 en 1 e 2-fase)

int veloc = 45;        //Velocidade do motor en rpm

Stepper motor(STEPS, IN1, IN2, IN3, IN4);

void setup() {
  motor.setSpeed(veloc);
  Serial.begin(9600);
}

void loop() {
  //Ponhemos a andar 5 voltas en sentido horario
  for(int i = 0; i < 5; i++) {
    Serial.print(String(i) + "a volta en sentido horario");
    motor.step(STEPS);
    delay(1000);
  }
  //Ponhemos a andar 5 voltas en sentido antihorario
  for(int i = 0; i < 5; i++) {
    Serial.print(String(i) + "a volta en sentido antihorario");
    motor.step(-STEPS);
    delay(1000);
  }
}
