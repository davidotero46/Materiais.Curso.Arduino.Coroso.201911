/*
 * Control dun motor DC usando
 * o integrado L293D e o sensor
 * de temperatura TMP36.
 * 
 */

//Imos empregar o pin 13 tanto para 
//saída dixital como para PWM
#define CONTROL 11
#define AVANCE 9
#define RETROCESO 8

//O pin3 da lectura de temperatura
#define TMP A0

int temp;
int veloc = 0; //Veloc. do ventilador
int espera = 2000;

void setup() {
  pinMode(AVANCE, OUTPUT);
  pinMode(RETROCESO, OUTPUT);
  digitalWrite(AVANCE, LOW);
  digitalWrite(RETROCESO, LOW);
  analogWrite(CONTROL, 0);
  Serial.begin(9600);
}


void loop() {
  //Lectura do sensor de temperatura
  temp = map(analogRead(TMP), 0, 1023, 0, 5000);
  temp = (temp - 500) / 10; //Calcula temp en ºC
  Serial.print("Temperatura: " + String(temp) + " oC");
  //Restrinxe temp entre 15 e 35 ºC
  temp = constrain(temp, 15, 35);
  //... para facer catro intervalos:
  temp = map(temp, 15, 35, 0, 4);
  //A partir de 15 ºC aumenta a velocidade
  //do ventilador en tres intervalos:
  digitalWrite(AVANCE, HIGH);
  digitalWrite(RETROCESO, LOW);
  switch(temp) {
    //temp até 19 ºC: ventilador parado
    case 0: veloc = 0; break;
    //temp entre 20 ºC e 24 ºC: ventilador suave
    case 1: veloc = 140; break;
    //temp entre 25 ºC e 29 ºC: ventilador medio
    case 2: veloc = 212; break;
    //temp máis de 30 ºC: ventilador a tope
    case 3: 
    case 4: veloc = 255; break;
  }
  analogWrite(CONTROL, veloc);
  Serial.println("\tVeloc. ventilador: " + String(veloc));
  delay(espera);
}
