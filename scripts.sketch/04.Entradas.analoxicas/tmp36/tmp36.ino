/*
 * Encéndense 5 LEDs en función do valor
 * analóxico lido no TMP36. 
 */

#define BRANCO 8
#define AZUL 9
#define VERDE 10
#define AMARELO 11
#define VERMELLO 12
#define TMP36 A0

int tempo = 200;
int vs = 0;         //Vs na saída do TMP36 en mV
float tempC = -50;  //Temp. ambiente en ºC
int idLED = -1;     //Identificador do LED

void setup() {
  pinMode(VERDE, OUTPUT);      pinMode(AMARELO, OUTPUT);
  pinMode(VERMELLO, OUTPUT);   pinMode(AZUL, OUTPUT);
  pinMode(BRANCO, OUTPUT);
}

void loop() {
  vs = map(analogRead(TMP36), 0, 1023, 0, 5000); //mapea a mV
  tempC = 1.* (vs - 500) / 10;  //Calcula temp en ºC
  idLED = constrain((int) tempC, 14, 30); //Restrinxe a [14, 30] ºC
  idLED = map(idLED, 14, 30, 0, 4);
  digitalWrite(BRANCO, LOW);     digitalWrite(AZUL, LOW);
  digitalWrite(VERDE, LOW);      digitalWrite(AMARELO, LOW);
  digitalWrite(VERMELLO, LOW);
  if(tempC >= 14) {
    switch(idLED) {
      case 4:
        digitalWrite(VERMELLO, HIGH);
      case 3:
        digitalWrite(AMARELO, HIGH);
      case 2:
        digitalWrite(VERDE, HIGH);
      case 1:
        digitalWrite(AZUL, HIGH);
      case 0:
        digitalWrite(BRANCO, HIGH);
    }
  }
  delay(tempo);
}
