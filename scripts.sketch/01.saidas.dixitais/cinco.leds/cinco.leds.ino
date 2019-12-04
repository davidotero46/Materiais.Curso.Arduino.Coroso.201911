/*
 * Encende e apaga sucesivamente 5 LEDs
 * con frecuencia constante
 */
#define LED 8

int tempo = 500;

void setup() {
  //Inicializa 5 LEDs
  for(int i=0; i<5; i++) {
    pinMode(LED + i, OUTPUT);
  }
}

void loop() {
  //On/Off LEDs alternativamente
  for(int i=0; i<5; i++) {
    digitalWrite(LED + i, HIGH);
    delay(tempo);
    digitalWrite(LED + i, LOW);
    delay(tempo);
  }
}
