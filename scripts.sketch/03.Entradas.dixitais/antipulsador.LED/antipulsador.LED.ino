/*
 * Ao premer o pulsador
 * o LED encende. 
 * 
 * Só se pode empregar un
 * único digitalWrite()
 *
 */


#define VERDE 10
#define PULSADOR 8

int tempo = 100;
bool pulsacion = false;

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(PULSADOR, INPUT);
}

void loop() {
  pulsacion = digitalRead(PULSADOR);
  digitalWrite(VERDE, !pulsacion);
  delay(tempo);
}
