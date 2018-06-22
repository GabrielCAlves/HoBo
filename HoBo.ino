/*
 * Ho-Bô: Um projeto para a OBR/2018 - Modalidade Prática
 * Correa, Quirino, Letícia e Villela
 */

///////////////////
/// SENSOR PINS ///
///////////////////

// US1 - Central (Desviar de obstáculos)
const int us1Trig = XX; // porta XX
const int us1Echo = XX; // Porta XX
// US2 -
const int us2Trig = XX; // Porta XX
const int us2Echo = XX; // Porta XX
// US3 -
const int us3Trig = XX; // Porta XX
const int us3Echo = XX; // Porta XX
//US4 -
const int us4Trig = XX; // Porta XX
const int us4Echo = XX; // Porta XX
//US5 -
const int us5Trig = XX; // Porta XX
const int us5Echo = XX; // Porta XX
//US6 -
const int us6Trig = XX; // Porta XX
const int us6Echo = XX; // Porta XX 

// Color Right - Detectar Verde/Seguir Linha
const int rS0 = XX;   // Porta XX
const int rS1 = XX;   // Porta XX
const int rS2 = XX;   // Porta XX
const int rS3 = XX;   // Porta XX
const int rSOut = XX; // Porta XX
// Color Left - Detectar Verde/Seguir Linha
const int lS0 = XX;   // Porta XX
const int lS1 = XX;   // Porta XX
const int lS2 = XX;   // Porta XX
const int lS3 = XX;   // Porta XX
const int lSOut = XX; // Porta XX

// IR - Seguir Linha
const int irA0 = A0;
const int irD0 = 8;

///////////////////////
/// SETUP FUNCTIONS ///
///////////////////////

// Definir pins do sensor US
void usSetup(int trig, int echo) {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

// Definir pins do sensor de cor
void colorSetup(int S0, int S1, int S2, int S3, int SOut) {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(SOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

// Definir pins do sensor de reflexão IR
void irSetup(int A0, int D0) {
  pinMode(A0, INPUT);
  pinMode(D0, INPUT);
}

/////////////////
/// FUNCTIONS ///
/////////////////

// Medir distância com sensor US
int usMeasure(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  return duration*0.034/2;
}

// Detectar cores com sensor de cor
int colorDetect(int S2, int S3, int SOut) {
  //Detect Red
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int redFrequency = pulseIn(SOut, LOW);
  redFrequency = map(redFrequency, 28, 95, 255, 0);
  
  //Detect Green
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int greenFrequency = pulseIn(SOut, LOW);
  greenFrequency = map(greenFrequency, 50, 110, 255, 0);

  //Detect Blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int blueFrequency = pulseIn(SOut, LOW);
  blueFrequency = map(blueFrequency, 22, 90, 255, 0);

  //White - return 0
  if(redFrequency > 200 && greenFrequency > 200 && blueFrequency > 200) return 0;
  //Black - return 1
  else if(redFrequency < 50 && greenFrequency < 50 && blueFrequency < 50) return 1;
  //Green - return 2
  else if(greenFrequency > redFrequency && greenFrequency > blueFrequency) return 2;
  //Other - return -1
  else return -1;
}

// Detectar branco e preto com o sensor IR
int irDetect(int A0) {
  if(analogRead(A0) > 200) return 1; // Black - return 1
  else return 0                      // White - return 0
}

////////////////////
/// SETUP & LOOP ///
////////////////////

void setup() {
  //Setup US
  usSetup(us1Trig, us1Echo);
  usSetup(us2Trig, us2Echo);
  usSetup(us3Trig, us3Echo);
  usSetup(us4Trig, us4Echo);
  usSetup(us5Trig, us5Echo);
  usSetup(us6Trig, us6Echo);

  // Setup Color
  colorSetup(rS0, rS1, rS1, rS3, rSOut);
  colorSetup(lS0, lS1, lS2, lS3, lSOut);

  // Setup IR
  irSetup(irA0, irD0);
  
  Serial.begin(9600);
}

void loop() {

  }
