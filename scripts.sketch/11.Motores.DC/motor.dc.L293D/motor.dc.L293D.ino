/*
 * Control dun motor DC usando
 * o integrado L293D e a entrada
 * serie para introducir ordes.
 */

//Imos empregar o pin 12 tanto para 
//saída dixital como para PWM
#define CONTROL 11
#define AVANCE 9
#define RETROCESO 8

int espera = 1000;

void setup() {
  pinMode(AVANCE, OUTPUT);
  pinMode(RETROCESO, OUTPUT);
  digitalWrite(AVANCE, LOW);
  digitalWrite(RETROCESO, LOW);
  Serial.begin(9600);
}


void loop() {
  //Marcha/parao do motor co voltaxe HIGH
  analogWrite(CONTROL, 255);
  digitalWrite(AVANCE, HIGH);
  digitalWrite(RETROCESO, LOW);
  Serial.println("Motor avanzando...");
  delay(5*espera);
  digitalWrite(AVANCE, LOW);
  digitalWrite(RETROCESO, HIGH);
  Serial.println("Motor retrocedendo...");
  delay(5*espera);
  digitalWrite(CONTROL, 0);
  Serial.println("Motor parado...");
  delay(5*espera);

  //Redución de velocidade do motor dende
  //max (255) a min (0) en incrementos de 25
  //... co motor avanzando
  digitalWrite(AVANCE, HIGH);
  digitalWrite(RETROCESO, LOW);
  for(int veloc = 255; veloc >= 0; veloc -= 25) {
    analogWrite(CONTROL, veloc);
    Serial.println("Veloc. en pasos PWM: " + String(veloc));
    delay(espera);
  }

  //Incremento de velocidade do motor dende
  //min (0) a max (255) en incrementos de 25 
  //... co motor en retroceso
  digitalWrite(AVANCE, LOW);
  digitalWrite(RETROCESO, HIGH);
  for(int veloc = 0; veloc <= 255; veloc += 25) {
    analogWrite(CONTROL, veloc);
    Serial.println("Veloc. en pasos PWM: " + String(veloc));
    delay(espera);
  }
}
