int tempo = 100;
String texto = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) {
    //Serial.println("ok");
    texto = Serial.readStringUntil('\n');
    
    float resultado = interpola(texto.toFloat(), 0, 1023, 0, 255);
    Serial.println(resultado);
  }
  delay(tempo/4);
}

float interpola(int valor, int x0, int x1, int y0, int y1) {
  float interpolado = y0 + 1. * (y1 - y0) * (valor - x0) / (x1 - x0);
  return interpolado;
}
