/*
 * Script que controla unha lámpara mediante
 * un PIR, unha LDR e un pulsador.
 * O encendido da lámpara faise cun relay,
 * que se simula co ON/OFF dun LED.
 */


#define PIR 13
#define BUTTON 12
#define LDR A0
#define RELAY 8

bool pir = false;
bool button = false;
int ldr = false;
bool relay = false;
bool lampara = false;
int valorLDR = 0;
int umbralLDR = 600; //Oscuridade
unsigned long int demoraLampara = 8000;
unsigned long int tInicial = 0;
bool tempoCumplido = true;
String mensaxe = "";
int demora = 500;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(BUTTON, INPUT);
  pinMode(LDR, INPUT); //Non é preciso declaralo
  pinMode(RELAY, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorLDR = constrain(analogRead(LDR), 30, 900);
  valorLDR = map(valorLDR, 30, 900, 1023, 0);
  ldr = (valorLDR >= umbralLDR);
  pir = digitalRead(PIR);
  button = digitalRead(BUTTON);
  lampara = button || pir && ldr;
  //Se rele non activo AND hai que activar lampara AND
  //pasou suficiente tempo ==> actualizamos
  if(!relay && lampara && tempoCumplido) {
    relay = lampara;
    digitalWrite(RELAY, HIGH);
    tInicial = millis();
  }
  //Se se
  else if(tempoCumplido) {
    relay = false;  //Apagamos lampara
    digitalWrite(RELAY, LOW);
    tInicial = 0;   //Reiniciamos tempo actual
    delay(demora);  //Demoramos nova deteccion
  }
  mensaxe = "Lampara: " + String(lampara) + "\tBoton: " + String(button);
  mensaxe += "\tRele: " + String(relay) + "\t\tPIR: " + String(pir);
  mensaxe += "\t\tLDR: " + String(ldr) + "\tDT: " + String(tempoCumplido);
  Serial.println(mensaxe);
  tempoCumplido = millis() - tInicial >= demoraLampara ;
  delay(demora);
}
