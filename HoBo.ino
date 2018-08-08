/*
	Nome: HoBo.ino
	Arquivo principal
*/

/*
 - Servos:
	Rowena: 82
	Ravenclaw: 86
	Luna: 90
	Lovegood: 90

	Right: 0 <- 180
	Left: 180 <- 0
*/

#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Incluir tela oled
Adafruit_SSD1306 screen(-1);

// Incluir servos
// Nome - Sobrenome // Frente - Trás

// Direita
Servo Rowena;
Servo Ravenclaw;

// Esquerda
Servo Luna;
Servo Lovegood;

// Frente
Servo Garden;

// Garra
Servo Claw;
Servo Door;

// Sensor de cor direito
const int rS0 = 2;
const int rS1 = 3;
const int rS2 = 4;
const int rS3 = 5;
const int rSOut = 6;

// Sensor de cor esquerdo
const int lS0 = 8;
const int lS1 = 9;
const int lS2 = 10;
const int lS3 = 11;
const int lSOut = 12;

// Sensor IR
const int irA0 = A0;

// Sensor US Frente
const int usFTrig = 22;
const int usFEcho = 23;

// Sensor US Frente Inclinado
const int usFITrig = 24;
const int usFIEcho = 25;

// Sensor US Frente Direita
const int usFRTrig = 26;
const int usFREcho = 27;

// Sensor US Frente Esquerda
const int usFLTrig = 28;
const int usFLEcho = 29;

// Sensor US Direita
const int usRTrig = 30;
const int usREcho = 31;

// Sensor US Esquerda
const int usLTrig = 32;
const int usLEcho = 33;

void setup() {

	// Sensores de cor
	setupColor(rS0, rS1, rS2, rS3, rSOut);
	setupColor(lS0, lS1, lS2, lS3, lSOut);

	// Sensor IR
	setupIR(irA0);

	// Sensores US
	setupUS(usFTrig, usFEcho);
	setupUS(usFITrig, usFIEcho);
	setupUS(usFRTrig, usFREcho);
	setupUS(usFLTrig, usFLEcho);
	setupUS(usRTrig, usREcho);
	setupUS(usLTrig, usLEcho);

	// Tela OLED
	setupScreen();

	// Servos
    setupServo();

	// Begin Serial
	Serial.begin(9600);

}

void loop() {

	Rowena.write(0);
	Ravenclaw.write(0);
	Luna.write(180);
	Lovegood.write(180);

	lineFollower();

}
