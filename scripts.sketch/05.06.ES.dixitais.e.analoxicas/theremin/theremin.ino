/*
 * Script que simula un Theremin.
 * Mediante unha LDR e un zumbador
 * detectamos a presencia dunha man
 * e mudamos a frecuencia emitida 
 * polo zumbador.
 */

#define LDR A0         //Pin analóxico da LDR
#define BUZZER 8       //Pin dixital do zumbador

#define SILENCE 800    //Sen son ao superar umbral
#define FEC_MIN 500    //Frecuencias min e max do
#define FEC_MAX 1500   //zumbador

int valorLDR, frecuencia;
String mensaxe = "";
int demora = 200;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  valorLDR = analogRead(LDR);
  if(valorLDR <= SILENCE) {
    frecuencia = map(valorLDR, 0, SILENCE, FEC_MIN, FEC_MAX);
    tone(BUZZER, frecuencia);
    mensaxe = "Valor LDR: " + String(valorLDR) + "\t";
    mensaxe += "Frecuencia: " + String(frecuencia) + "\n";
    Serial.print(mensaxe);
  }
  else {
    noTone(BUZZER);
  }
  //delay(demora);
}
