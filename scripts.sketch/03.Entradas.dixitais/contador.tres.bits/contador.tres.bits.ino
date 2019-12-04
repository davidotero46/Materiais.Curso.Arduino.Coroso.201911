/*
 * Conta pulsacións do pusador
 * e mostra o resultado en 
 * binario de tres bits.
 *
 * 0 -- 000 -- 000    4 -- 100 -- v00
 * 1 -- 001 -- 00v    5 -- 101 -- v0v
 * 2 -- 010 -- 0a0    6 -- 110 -- va0
 * 3 -- 011 -- 0av    7 -- 111 -- vav 
 * 
 */

#define VERDE 10
#define AMARELO 11
#define VERMELLO 12
#define PULSADOR 8

int tempo = 200;
int conta = 0;
int pulsacion = false;

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERMELLO, OUTPUT);
  pinMode(PULSADOR, INPUT);
}

void loop() {
  pulsacion = digitalRead(PULSADOR);
  if(pulsacion) {
    conta++;
    if(conta > 7) {
      conta = 0;
    }
    if(conta % 2 == 1) {
      digitalWrite(VERDE, HIGH);
    } else {
      digitalWrite(VERDE, LOW);
    }
    if(conta == 2 || conta == 3 || conta == 6 || conta == 7) {
      digitalWrite(AMARELO, HIGH);
    } else {
      digitalWrite(AMARELO, LOW);
    }
    if(conta > 3) {
      digitalWrite(VERMELLO, HIGH);
    } else {
      digitalWrite(VERMELLO, LOW);
    }
  }
  pulsacion = false;
  delay(tempo);
}
