/*
 * Proba o funcionamento dun motor paso a paso
 * usando a librería <Stepper.h> para que dea 
 * voltas en sentido horario ou antihorario en
 * función do ángulo dun potenciómetro.
 * 
 * O ángulo do potenciómetro tamén regula 
 * o valor absoluto da velocidade.
 */
#include <Stepper.h>

//Pins para control do motor PaP
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

//Pin para a lectura do potenciómetro
#define POT A0

//Parámetros do motor, pasos totais e por fase
#define STEPS 4076 //Pasos totais por volta
#define NSTEPS 8 //Número de pasos por fase (4 en 1 e 2-fase)

int veloc = 45;         //Velocidade do motor en rpm
int vPotenciometro = 0; //Lectura potenciómetro

Stepper motor(STEPS, IN1, IN2, IN3, IN4);

void setup() {
  motor.setSpeed(veloc);
  Serial.begin(9600);
}

void loop() {
  //Lemos o potenciómetro e mapeamos a [-STEPS, STEPS]
  vPotenciometro = map(analogRead(POT), 0, 1023, -STEPS, STEPS);
  motor.step(vPotenciometro);
  delay(800);
}
