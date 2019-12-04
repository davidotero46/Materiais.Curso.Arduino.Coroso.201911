/*
 * Escreb a frase 'Ola Arduino'
 * na matriz de LEDs 8x8, como
 * exemplo de uso.
 */

//Definimos pins filas
//da matriz
#define F1 2
#define F2 3
#define F3 4
#define F4 5
#define F5 6
#define F6 7
#define F7 8
#define F8 9

//Definimos pins cols
//da matriz
#define C1 10
#define C2 11
#define C3 12
#define C4 13
#define C5 A0
#define C6 A1
#define C7 A2
#define C8 A3

//Arrays para percorrer as filas e columnos da matriz
const byte filas[] = {F1, F2, F3, F4, F5, F6, F7, F8};
const byte cols[] = {C1, C2, C3, C4, C5, C6, C7, C8};

//Patrons de bits de cada letra ou simbolo a representar
byte TODOS[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte NING[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte COR1[] = {B00000000,B01100110,B11111111,B11111111,B11111111,B01111110,B00111100,B00011000};
byte COR2[] = {B00000000,B01100110,B10011001,B10000001,B10000001,B01000010,B00100100,B00011000};
byte A[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
byte B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
byte C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
byte D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
byte E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
byte F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
byte G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
byte H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
byte I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
byte K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
byte L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
byte M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
byte N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
byte O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
byte P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
byte Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
byte R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
byte S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
byte T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
byte V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
byte W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
byte X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
byte Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};

float conta = 0;
int tempo = 0, tempoMensaxe = 700;
int reten = 10;

void setup() {
    Serial.begin(9600);
    //Declaramos como saidas incluso
    //os pins analoxicos
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() {
  //Ponhemos un tempo maximo para a mensaxe
  //que se vai mapear ao numero de letras
  conta++;
  if(conta > tempoMensaxe) {
    conta = 0;
  }
  tempo = map(conta, 0, tempoMensaxe, 0, 17);
  switch(tempo) {
    case  0: setMatriz(O); delay(reten); break;
    case  1: setMatriz(L); delay(reten); break;
    case  2: setMatriz(A); delay(reten); break;
    case  3: setMatriz(NING); delay(reten); break;
    case  4: setMatriz(NING); delay(reten); break;
    case  5: setMatriz(A); delay(reten); break;
    case  6: setMatriz(R); delay(reten); break;
    case  7: setMatriz(D); delay(reten); break;
    case  8: setMatriz(U); delay(reten); break;
    case  9: setMatriz(I); delay(reten); break;
    case 10: setMatriz(N); delay(reten); break;
    case 11: setMatriz(O); delay(reten); break;
    case 12: setMatriz(NING); delay(reten); break;
    case 13: setMatriz(COR1); delay(reten); break;
    case 14: setMatriz(NING); delay(reten); break;
    case 15: setMatriz(COR2); delay(reten); break;
    case 16: setMatriz(NING); delay(reten); break;
    case 17: setMatriz(NING); delay(reten); break;
  }
}

void setMatriz(byte texto[]) {
  for(byte i=0; i<8; i++) {
    digitalWrite(filas[i], HIGH);
    for(byte j=0; j<8; j++) {
      digitalWrite(cols[j], (~texto[i]>>j) &  0x01);
      delayMicroseconds(100);
      digitalWrite(cols[j], 1);
    }
    digitalWrite(filas[i], LOW);
  }
} 
