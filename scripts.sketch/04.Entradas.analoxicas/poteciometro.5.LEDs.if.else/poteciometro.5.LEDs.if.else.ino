/*
 * Encéndense 5 LEDs en función do valor
 * analóxico lido no potenciómetro. 
 */

#define BRANCO 8
#define AZUL 9
#define VERDE 10
#define AMARELO 11
#define VERMELLO 12
#define POTENCIOMETRO A0

int tempo = 200;
int valor = 0;

void setup() {
  pinMode(VERDE, OUTPUT);      pinMode(AMARELO, OUTPUT);
  pinMode(VERMELLO, OUTPUT);   pinMode(AZUL, OUTPUT);
  pinMode(BRANCO, OUTPUT);
}

void loop() {
  valor = analogRead(POTENCIOMETRO); //Entre 0 e 1023
  valor = constrain(valor, 0, 1023);
  digitalWrite(BRANCO, LOW);     digitalWrite(AZUL, LOW);
  digitalWrite(VERDE, LOW);      digitalWrite(AMARELO, LOW);
  digitalWrite(VERMELLO, LOW);
  if(valor > 0 && valor < 204) digitalWrite(BRANCO, HIGH);
  else if(valor >= 204 && valor < 408) digitalWrite(AZUL, HIGH);
  else if(valor >= 408 && valor < 612) digitalWrite(VERDE, HIGH);
  else if(valor >= 612 && valor < 816) digitalWrite(AMARELO, HIGH);
  else if(valor >= 816 && valor <= 1023) digitalWrite(VERMELLO, HIGH);
  delay(tempo);
}
