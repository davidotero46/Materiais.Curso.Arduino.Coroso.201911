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
  valor = map(valor, 0, 1023, 0, 4); //Mapea a 0, 1, 2, 3, 4
  digitalWrite(BRANCO, LOW);     digitalWrite(AZUL, LOW);
  digitalWrite(VERDE, LOW);      digitalWrite(AMARELO, LOW);
  digitalWrite(VERMELLO, LOW);
  switch(valor) {
    case 0:
      digitalWrite(BRANCO, HIGH);
      break;
    case 1:
      digitalWrite(AZUL, HIGH);
      break;
    case 2:
      digitalWrite(VERDE, HIGH);
      break;
    case 3:
      digitalWrite(AMARELO, HIGH);
      break;
    case 4:
      digitalWrite(VERMELLO, HIGH);
      break;
  }
  delay(tempo);
}
