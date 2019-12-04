/*
 * Control dun motor de CC
 * usando un transistor NPN BC547
 */

//Imos empregar o pin 12 tanto para 
//saída dixital como para PWM
#define CONTROL 12

int espera = 1000;

void setup() {
  pinMode(CONTROL, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  //Marcha/parao do motor cao voltaxe HIGH
  digitalWrite(CONTROL, HIGH);
  delay(espera);
  digitalWrite(CONTROL, LOW);
  delay(espera);

  //Redución de velocidade do motor dende
  //max (255) a min (0) en incrementos de 5
  for(int veloc = 255; veloc >= 0; veloc -= 5) {
    analogWrite(CONTROL, veloc);
    Serial.println("Veloc. en pasos PWM: " + String(veloc));
    delay(espera/2);
  }

  //Incremento de velocidade do motor dende
  //min (0) a max (255) en incrementos de 5 
  for(int veloc = 0; veloc <= 255; veloc += 5) {
    analogWrite(CONTROL, veloc);
    Serial.println("Veloc. en pasos PWM: " + String(veloc));
    delay(espera/2);
  }
}
