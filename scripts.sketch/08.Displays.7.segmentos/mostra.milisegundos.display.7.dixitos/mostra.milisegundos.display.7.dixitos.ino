/*
 * Mostra nun display de 7 segmentos
 * e catro díxitos, o tempo que leva
 * aceso o Arduino.
 */

//Descomentamos a seguinte linha se 
//o display e de anodo comun.
//#define ANODO_COMUN
#ifdef ANODO_COMUN
  #define HIGH 0
  #define LOW  1
#endif

//Declaramos os pins de cada número 
//mediante un array de byte[]
byte dixito[10][8] = {
  {1,1,1,1,1,1,0,0},     // 0
  {0,1,1,0,0,0,0,0},     // 1
  {1,1,0,1,1,0,1,0},     // 2
  {1,1,1,1,0,0,1,0},     // 3
  {0,0,1,0,0,1,1,0},     // 4
  {1,0,1,1,0,1,1,0},     // 5
  {1,0,1,1,1,1,1,0},     // 6
  {1,1,1,0,0,0,0,0},     // 7
  {1,1,1,1,1,1,1,0},     // 8
  {1,1,1,0,0,1,1,0},     // 9
};

void setup() {
  Serial.begin(9600);
  for(int i=2; i<13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  //Conta ate 9999 segundos
  int tempo = millis()/1000;
  calcularDixitos(tempo);
  Serial.print(String(tempo) + ": ");
  delay(1000);
}

void apagaDixitos() {
  for(int i=9; i<13; i++) {
    digitalWrite(i, LOW);
  }
}

void mostraDixito(int posDixito, int numero) {
  apagaDixitos();
  for(int i=0; i<8; i++) {
    digitalWrite(i+2, dixito[numero][i]);
  }
  //Activamos o dixito despois dos pins
  digitalWrite(posDixito + 9, HIGH);
}

void calcularDixitos(int numero) {
  int dixito0 = numero % 10;
  int dixito1 = (numero % 100) / 10;
  int dixito2 = (numero % 1000) / 100;
  int dixito3 = numero / 1000;

  mostraDixito(3, dixito3);
  mostraDixito(2, dixito2);
  mostraDixito(1, dixito1);
  mostraDixito(0, dixito0);
  
  Serial.print(dixito3);  Serial.print(dixito2);
  Serial.print(dixito1);  Serial.println(dixito0);
}
