// C++ code
//
/*
	
    Autor: DAVID ANDRES OTERO ELIA.
    Data: febrero del 2023
*/

#define ledB 2
#define ledG 12
#define ledR 13
#define Trigger 6
#define Echo 5
#define zumbador 8
#define CTRL 9

servo motor;
int veloc = 10;

//int melody [] = {
//};
//int durations [] = {
//};

void setup () {
  Serial.begin(9600);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW); 
  pinMode(zumbador, OUTPUT);
  
}


void loop() {
  
  long t; 
  long d;
  
  
  digitalWrite(Trigger, HIGH);
  delay(10);
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH);
  d = t/59;
  
  
  if (d<5) {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(zumbador, HIGH);
   for(int i = 0; i <= 180; i++) {
    motor.write(i);
    delay(veloc);
  }
  delay(15*veloc);
  //Move o servo entre 180º e 0º en
  //decrementos de 5º
  for(int i = 180; i >= 0; i--) {
    motor.write(i);
    delay(veloc);
    
    
    
  }
  else if (d<15) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(zumbador, HIGH);
    delay(100);
    digitalWrite(zumbador, LOW);
    delay(100);
  }

  else if (d<30) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(zumbador, LOW);
  }
  
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.println();
  delay(100);
}
