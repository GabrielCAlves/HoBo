/*
 Nome: HoBo.ino
 Arquivo principal
*/

/*
 - Servos:
	Luna: 87º
   	 Ron: 92º
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

// Sensor US
const int usTrig = 22;
const int usEcho = 23;

void setup() {
	// Sensores de cor
	setupColor(rS0, rS1, rS2, rS3, rSOut);
	setupColor(lS0, lS1, lS2, lS3, lSOut);

	// Sensor IR
	setupIR(irA0);

	// Sensor US
	setupUS(usTrig, usEcho);

	// Tela OLED
	setupScreen();

	// Servos
	setupServo();

	// Begin Serial
	Serial.begin(9600);
}

void loop() {
	screen.clearDisplay();
	screen.setCursor(0, 0);

	int rColor = colorDetect(rS2, rS3, rSOut);
	int lColor = colorDetect(lS2, lS3, lSOut);
	int irColor = irDetect(irA0);
	int distance = usDetect(usTrig, usEcho);

	screen.print("R: ");

	switch (rColor) {
	case 0:
		screen.print("WHITE");
		break;
	case 1:
		screen.print("BLACK");
		break;
	case 2:
		screen.print("GREEN");
		break;
	}

	screen.println();
	screen.print("IR: ");

	switch (irColor) {
	case 0:
		screen.print("WHITE");
		break;
	case 1:
		screen.print("BLACK");
		break;
	}

	screen.println();
	screen.print("L: ");

	switch (lColor) {
	case 0:
		screen.print("WHITE");
		break;
	case 1:
		screen.print("BLACK");
		break;
	case 2:
		screen.print("GREEN");
		break;
	}

	screen.println();
	screen.print("US: ");
	screen.print(distance);
	screen.print(" cm");

	screen.display();
	delay(250);
}
