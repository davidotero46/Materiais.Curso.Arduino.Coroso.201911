/*
 * Control dun motor DC usando
 * o integrado L293D e a comunicación
 * de ordes pola entrada serie. 
 * 
 * As ordes disponhibles son:
 * (a) parado ou stop,
 * (b) suave,
 * (c) medio,
 * (d) tope ou full,
 * (e) directo,
 * (f) inverso, ou
 * (g) número entre 0 e 255
 * 
 */

//Imos empregar o pin 13 tanto para 
//saída dixital como para PWM
#define CONTROL 13
#define AVANCE 11
#define RETROCESO 10

int veloc = 0; //Veloc. do ventilador
int espera = 600;
String orde = "";
//Direccion de avance do motor
bool directo = true;

void setup() {
  pinMode(AVANCE, OUTPUT);
  pinMode(RETROCESO, OUTPUT);
  digitalWrite(AVANCE, LOW);
  digitalWrite(RETROCESO, LOW);
  analogWrite(CONTROL, 0);
  Serial.begin(9600);
}


void loop() {
  //Lectura da entrada serie
  if(Serial.available()) {
    orde = Serial.readStringUntil('\n');
    orde.toLowerCase();
    if(orde.equals("parado") || orde.equals("stop")) veloc = 0;
    else if(orde.equals("suave")) veloc = 140;
    else if(orde.equals("medio")) veloc = 212;
    else if(orde.equals("tope") || orde.equals("full")) veloc = 255;
    else if(orde.equals("directo")) directo = true;
    else if(orde.equals("inverso")) directo = false;
    else {
      int tmp = orde.toInt();
      if(tmp >= 0 && tmp <= 255) veloc = tmp;
      else veloc = 0;
      orde = "";
    }
  }
  //Actualización da veloc. do ventilador
  digitalWrite(AVANCE, directo);
  digitalWrite(RETROCESO, !directo);
  analogWrite(CONTROL, veloc);
  Serial.print("Veloc. ventilador: " + String(veloc));
  Serial.println("\t\tAvance motor: " + String(directo));
  delay(espera);
}
