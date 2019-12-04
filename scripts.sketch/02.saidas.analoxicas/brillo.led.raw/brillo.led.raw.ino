#define LED 6
#define NIVEL00 0
#define NIVEL01 51
#define NIVEL02 102
#define NIVEL03 153
#define NIVEL04 204
#define NIVEL05 255

int tempo = 150;

void setup() {
  // Non é necesario declarar as 
  // saídas analóxicas.
}

void loop() {
  analogWrite(LED, NIVEL00);
  delay(tempo);
  analogWrite(LED, NIVEL01);
  delay(tempo);
  analogWrite(LED, NIVEL02);
  delay(tempo);
  analogWrite(LED, NIVEL03);
  delay(tempo);
  analogWrite(LED, NIVEL04);
  delay(tempo);
  analogWrite(LED, NIVEL05);
  delay(tempo);
  analogWrite(LED, NIVEL04);
  delay(tempo);
  analogWrite(LED, NIVEL03);
  delay(tempo);
  analogWrite(LED, NIVEL02);
  delay(tempo);
  analogWrite(LED, NIVEL01);
  delay(tempo);
  analogWrite(LED, NIVEL00);
  delay(tempo);
}
