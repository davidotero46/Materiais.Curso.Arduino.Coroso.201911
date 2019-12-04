/*
 * LED modifica o brillo conforme varía a luz ambiente.
 */

#define VERDE 10
#define LDR A0

int tempo = 1000;

void setup() {
  
}

void loop() {
  int valorLDR = analogRead(LDR);
  //Valores de entrada min/max: 210/997
  int valorLED =  (int) interpola(valorLDR, 210, 997, 0, 255);
  analogWrite(VERDE, 255 - valorLED);
  delay(tempo);
}

float interpola(int valor, int x0, int x1, int y0, int y1) {
  float interpolado = y0 + 1. * (y1 - y0) * (valor - x0) / (x1 - x0);
  return interpolado;
}
