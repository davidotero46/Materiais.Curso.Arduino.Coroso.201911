/* 
 *  Encende e apaga un LED con
 * frecuencia constante. 
 */

#define LED 8

int tempo = 10000;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(tempo);
  digitalWrite(LED, LOW);
  delay(tempo);
}
