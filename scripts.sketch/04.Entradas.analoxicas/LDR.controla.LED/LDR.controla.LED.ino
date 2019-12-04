/*
 * LED modifica o brillo
 * conforme varía a luz
 * ambiente.
 *
 */


#define VERDE 10
#define LDR A0

int tempo = 100;

void setup() {
  
}

void loop() {
  int valor = analogRead(LDR);
  valor /= 4;
  analogWrite(VERDE, valor);
  delay(tempo);
}
