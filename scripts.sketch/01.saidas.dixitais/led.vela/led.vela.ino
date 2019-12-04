/*
 * Encende e apaga un LED con
 * frecuencia variable
 */
#define LED 8

long tempo;
int tmin = 200, tmax = 1500;

void setup() {
  pinMode(LED, OUTPUT);
  randomSeed(23);
}

void loop() {
  tempo = random(tmin, tmax);
  digitalWrite(LED, HIGH);
  delay(tempo);
  digitalWrite(LED, LOW);
  delay(tempo);
}
