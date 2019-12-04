/*
 * Encende e apaga sucesivamente 5 LEDs
 * con frecuencia constante
 */
int tempo = 500;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  for(int i=8; i<13; i++) {
    digitalWrite(i, HIGH);
    delay(tempo);
    digitalWrite(i, LOW);
    delay(tempo);
  }
}
