/*
 * Proba o funcionamento dun motor paso a paso
 * de maneira 'manual', facendo que dea cinco 
 * voltas completas en sentido horario e outras
 * cinco en sentido antihorario.
 */

//Pins para control do motor PaP
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

//Parámetros do motor, pasos totais e por fase
#define STEPS 4076 //Pasos totais por volta
#define NSTEPS 8 //Número de pasos por fase (4 en 1 e 2-fase)

//Conta do número de pasos realizado e intevalo temporal
int veloc = 1200;        //Velocidade do motor en us
int contador = 0;        //Leva a conta dos pasos do stepper

//Secuencias de encendido para usar co stepper
//(a) Secuencia 1-fase
//#define NSTEPS 4
//int secPasos[NSTEPS] = {B1000, B0100, B0010, B0001};

//(b) Secuencia 2-fases
//#define NSTEPS 4
//int secPasos[NSTEPS] = {B1100, B0110, B0011, B1001};

//(c) Secuencia media fase
#define NSTEPS 8
int secuenciaPasos[NSTEPS] = {B1000, B1100, B0100, B0110, 
                              B0010, B0011, B0001, B1001};

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  //Ponhemos a andar 5 voltas en sentido horario
  for(int i = 0; i < STEPS * 5; i++) {
    moverHorario();
    delayMicroseconds(veloc);
  }
  //Ponhemos a andar 5 voltas en sentido antihorario
  for(int i = 0; i < STEPS * 5; i++) {
    moverAntiHorario();
    delayMicroseconds(veloc);
  }
}

//Funcións auxialiares para:
//(a) Movemento horario do PaP
void moverHorario() {
  contador++; 
  contador %= NSTEPS;
  escribirPins(contador);
}

//(b) Movemento antihorario do PaP
void moverAntiHorario() {
  contador--;
  contador = (contador + NSTEPS) % NSTEPS;
  escribirPins(contador);
}

//(c) función auxiliar de (a) e (b), para
//    efectuar a escritura nos pins do ULN2003
void escribirPins(int paso) {
  digitalWrite(IN1, bitRead(secuenciaPasos[paso], 0));
  digitalWrite(IN2, bitRead(secuenciaPasos[paso], 1));
  digitalWrite(IN3, bitRead(secuenciaPasos[paso], 2));
  digitalWrite(IN4, bitRead(secuenciaPasos[paso], 3));
}
