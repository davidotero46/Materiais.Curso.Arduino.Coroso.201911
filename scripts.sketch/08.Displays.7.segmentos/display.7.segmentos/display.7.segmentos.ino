/*
 * Realiza unha conta atrás de 9 a 0,
 * empregando un display de 7-segmentos
 * 5101AS (Cátodo común).
 * 
 * Por ser cátodo común, temos que 
 * conectar o pin común a terra (GND).
 * Se fose ánado común, deberiamos 
 * conectar o pin común a VCC (5 V).
 * 
 * Os LEDs nomeanse con letras empezando
 * polo superior e seguindo no sentido
 * das agullas do reloxo: a, b, c, d, e, f, g
 * O ultimo é o g, que corresponde ao LED
 * central. Ademais, o h e o punto decimal.
 * 
 * Se ponhemos numeros as conexions empezando
 * polo inferior esquerdo cara a dereita e 
 * seguindo polo superior dereito cara a 
 * esquerda:
 * 1 - e (inf esq)      6 - b (sup der)
 * 2 - d (inf cent)     7 - a (sup cent)
 * 3 - comun            8 - comun
 * 4 - c (inf der)      9 - f (sup esq)
 * 5 - dp (punto dec)  10 - g (central)
 */

//Descomentamos a seguinte linha se 
//o display e de anodo comun.
//#define ANODO_COMUN
#ifdef ANODO_COMUN
  #define HIGH 0
  #define LOW  1
#endif

#define SUP     2
#define CENT    8
#define INF     5
#define SUPESQ  7
#define SUPDER  3
#define INFESQ  6
#define INFDER  4

int contador = 10;
int tempo = 1000;

void setup() {
  for(int i=2; i<=8; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  Serial.begin(9600);
}

void loop() {
  apagaDisplay();
  contador--;
  if(contador == -1) {
    contador = 9;
  }
  Serial.print(contador);
  switch(contador) {
    case 0: cero();  break;
    case 1: un();    break;
    case 2: dous();  break;
    case 3: tres();  break;
    case 4: catro(); break;
    case 5: cinco(); break;
    case 6: seis();  break;
    case 7: sete();  break;
    case 8: oito();  break;
    case 9: nove();  break;
  }
  delay(tempo);
}

void apagaDisplay() {
  for(int i=2; i<=8; i++) {
    digitalWrite(i, LOW);
  }
}

void cero() {
  digitalWrite(SUP, HIGH);
  digitalWrite(SUPDER, HIGH);
  digitalWrite(INFDER, HIGH);
  digitalWrite(INF, HIGH);
  digitalWrite(INFESQ, HIGH);
  digitalWrite(SUPESQ, HIGH);
}

void un() {
  digitalWrite(SUPDER, HIGH);
  digitalWrite(INFDER, HIGH);
}

void dous() {
  digitalWrite(SUP, HIGH);
  digitalWrite(SUPDER, HIGH);
  digitalWrite(CENT, HIGH);
  digitalWrite(INFESQ, HIGH);
  digitalWrite(INF, HIGH);
}

void tres() {
  digitalWrite(SUP, HIGH);
  digitalWrite(SUPDER, HIGH);
  digitalWrite(INFDER, HIGH);
  digitalWrite(INF, HIGH);
  digitalWrite(CENT, HIGH);
}

void catro() {
  digitalWrite(SUPESQ, HIGH);
  digitalWrite(SUPDER, HIGH);
  digitalWrite(INFDER, HIGH);
  digitalWrite(CENT, HIGH);
}

void cinco() {
  digitalWrite(SUP, HIGH);
  digitalWrite(SUPESQ, HIGH);
  digitalWrite(CENT, HIGH);
  digitalWrite(INFDER, HIGH);
  digitalWrite(INF, HIGH);
}

void seis() {
  digitalWrite(SUP, HIGH);
  digitalWrite(SUPDER, HIGH);
  digitalWrite(INFDER, HIGH);
  digitalWrite(INF, HIGH);
  digitalWrite(INFESQ, HIGH);
  digitalWrite(CENT, HIGH);
}

void sete() {
  digitalWrite(SUP, HIGH);
  digitalWrite(SUPDER, HIGH);
  digitalWrite(INFDER, HIGH);
}

void oito() {
  digitalWrite(SUP, HIGH);
  digitalWrite(SUPDER, HIGH);
  digitalWrite(INFDER, HIGH);
  digitalWrite(INF, HIGH);
  digitalWrite(INFESQ, HIGH);
  digitalWrite(SUPESQ, HIGH);
  digitalWrite(CENT, HIGH);
}

void nove() {
  digitalWrite(SUP, HIGH);
  digitalWrite(SUPESQ, HIGH);
  digitalWrite(SUPDER, HIGH);
  digitalWrite(INFDER, HIGH);
  digitalWrite(CENT, HIGH);
}
