
#define LED 6

int brillo = 0;
int delta = 5;
int tempo = 100;

void setup() {
  // Non é necesario declarar as 
  // saídas analóxicas.
}

void loop() {
  analogWrite(LED, brillo);
  brillo += delta;
  if(brillo < 0 || brillo > 255) {
    delta = -delta;
    brillo += delta;
  }
  delay(tempo);
}
