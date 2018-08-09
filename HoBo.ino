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
#include <Ultrasonic.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Sensor de cor direito
byte rS0 = 2;
byte rS1 = 3;
byte rS2 = 4;
byte rS3 = 5;
byte rSOut = 6;

// Sensor de cor esquerdo
byte lS0 = 8;
byte lS1 = 9;
byte lS2 = 10;
byte lS3 = 11;
byte lSOut = 12;

// Sensor IR
byte irA0 = A0;

// Sensor US Frente
byte usFTrig = 42;
byte usFEcho = 44;

// Sensor US Frente Inclinado
byte usFITrig = 36;
byte usFIEcho = 38;

// Sensor US Frente Direita
byte usFRTrig = 52;
byte usFREcho = 50;

// Sensor US Frente Esquerda
byte usFLTrig = 46;
byte usFLEcho = 48;

// Sensor US Direita
byte usRTrig = 51;
byte usREcho = 53;

// Sensor US Esquerda
byte usLTrig = 41;
byte usLEcho = 43;

// Incluir tela oled
Adafruit_SSD1306 screen(-1);

// Incluir servos

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

// Incluir US

// Frente
Ultrasonic usF(usFTrig, usFEcho);

// Frente Inclinado
Ultrasonic usFI(usFITrig, usFIEcho);

// Frente Direita
Ultrasonic usFR(usFRTrig, usFREcho);

// Frente Esquerda
Ultrasonic usFL(usFLTrig, usFLEcho);

// Direita
Ultrasonic usR(usRTrig, usREcho);

// Esquerda
Ultrasonic usL(usLTrig, usLEcho);

void setup() {

	// Sensores de cor
	setupColor(rS0, rS1, rS2, rS3, rSOut);
	setupColor(lS0, lS1, lS2, lS3, lSOut);

	// Sensor IR
	setupIR(irA0);

	// Tela OLED
	setupScreen();

	// Servos
    setupServo();

	// Begin Serial
	Serial.begin(9600);

	stop();
}


void loop() {

	

	// lineFollower();

}

// FUNCTIONS ---------------------------

/*
	Nome: Functions.ino
	Definir funções
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

// Sensores de cor - Retornar cor
int colorDetect(int S2, int S3, int SOut) {
	// R(ED)
	digitalWrite(S2, LOW);
	digitalWrite(S3, LOW);
	int RedFrequency = pulseIn(SOut, LOW);
	delay(100);

	// G(REEN)
	digitalWrite(S2, HIGH);
	digitalWrite(S3, HIGH);
	int GreenFrequency = pulseIn(SOut, LOW);

	int sum = RedFrequency + GreenFrequency;

	// 1 - Preto
	if (sum >= 70) return 1;
	// 2 - Verde
	else if (sum >= 60) return 2;
	// 0 - Branco
	else return 0;
}

// Sensor IR - Retornar cor
int irDetect(int A0) {
	int analogic = analogRead(A0);
	
	// 1 - Preto
	if (analogic > 200) return 1;
	// 0 - Branco
	else return 0;
}

// Sensor US - Retornar média de 5 leituras
int usDetect(Ultrasonic us) {

	int media = 0;
	for (int i = 0; i < 5; i++) {

		int tempo = us.timing();
		int dist = us.convert(tempo, Ultrasonic::CM);
		media += dist;

		delay(2);

	}

	return media / 5;

}

// Obstacle Deflect - Desviar do osbtáculo
void obstacleDeflect() {

	stop();
	bool prob = rand() > 0.5;

	if (prob) {

		goLeft(5);
		goFront(10);
		goRight(5);
		goFront(10);
		goRight(10);
		goFront(10);
		goLeft(5);

	}

	else {

		goRight(5);
		goFront(10);
		goLeft(5);
		goFront(10);
		goLeft(10);
		goFront(10);
		goRight(5);

	}

}

// Line Follower - Decision making
void lineFollower() {

	int rColor = colorDetect(rS2, rS3, rSOut);
	int lColor = colorDetect(lS2, lS3, lSOut);
	int irColor = irDetect(irA0);

	// Pelo menos um dos sensores de cor detecta verde - Confirmar cores
	if (rColor == 2 || lColor == 2) {

		delay(500);
		stop();

		// Atualizar variáveis
		rColor = colorDetect(rS2, rS3, rSOut);
		lColor = colorDetect(lS2, lS3, lSOut);

	}

	// Os dois sensores detectam verde - Meia-volta
	if (rColor == 2 && lColor == 2) {

		stop();
		go180();
		goFront(500);
		return;

	}

	// Sensor esquerdo detecta verde - Vira para a esquerda 90º
	if (rColor == 2) {

		stop();
		goLeft(1000);
		return;
	}

	// Sensor direito detecta verde - Vira para a direita 90º
	if (lColor == 2) {

		stop();
		goRight(1000);
		return;
	}

	// Sensor direito detecta preto + sensor IR detecta preto + sensor esquerdo detecta branco - 90º
	if (rColor == 1 && irColor == 1 && lColor == 0) {

		delay(1000);
		stop();
		
		int newIR = irDetect(irA0);

		if (newIR == 1) {

			return;

		}

		else {

			goBack(1000);
			goRight(1000);
			return;

		}
	}

	// Sensor esquerdo detecta preto + sensor IR detecta preto + sensor direito detecta branco - 90º
	if (lColor == 1 && irColor == 1 && rColor == 0) {

		delay(1000);
		stop();

		int newIR = irDetect(irA0);

		if (newIR == 1) {

			return;

		}

		else {

			goBack(1000);
			goLeft(1000);
			return;

		}
	}

	// Sensor direito detecta preto + sensor IR detecta branco - Até detectar
	if (rColor == 1 && irColor == 0) {

		stop();
		goBack(500);
		goRight(-1);

	}

	// Sensor esquerdo detecta preto + sensor IR detecta branco - Até detectar
	if (lColor == 1 && irColor == 0) {

		stop();
		goBack(500);
		goLeft(-1);

	}

}

// SETUP ----------------------

/*
	Name: Setup.ino
	Definir pins
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

// Setup - Sensor de cor
void setupColor(byte S0, byte S1, byte S2, byte S3, byte SOut) {

	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	pinMode(SOut, INPUT);
	digitalWrite(S0, HIGH);
	digitalWrite(S1, LOW);

}

// Setup - Sensor IR
void setupIR(byte A0) {

	pinMode(A0, INPUT);

}

// Setup - Sensor US
void setupUS(byte trig, byte echo) {

	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);

}

// Setup - Tela OLED
void setupScreen() {

	screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	screen.setTextColor(1);
	screen.setTextSize(2);

}

// Setup - Servo
void setupServo() {

	Luna.attach(26);
	Lovegood.attach(28);
	Rowena.attach(24);
	Ravenclaw.attach(22);
	Garden.attach(30);
	Claw.attach(2);
	Door.attach(1);

}

// Mototred ---------------

/*
	Nome: Motores.ino
	Definir funções dos motores
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

// stop - parar
void stop() {

	Rowena.write(82);
	Ravenclaw.write(86);
	Luna.write(87);
	Lovegood.write(90);

}

// goFront - ir para frente
void goFront(int Zeit) {
	
	Rowena.write(0);
	Ravenclaw.write(0);
	Luna.write(180);
	Lovegood.write(180);

	if (Zeit < 0) {

		delay(Zeit);

		Rowena.write(82);
		Ravenclaw.write(86);
		Luna.write(87);
		Lovegood.write(90);

	}

}

// goLeft - virar para esquerda
void goLeft(int Zeit) {

	Rowena.write(0);
	Ravenclaw.write(0);
	Luna.write(45);
	Lovegood.write(45);

	if (Zeit < 0) {

		while (true) {

			int lColor = colorDetect(lS2, lS3, lSOut);
			int irColor = irDetect(irA0);

			// Se sensor esquerdo detectar branco e sensor IR detectar preto
			if (lColor == 0 && irColor == 1) break;

		}

	}

	else delay(Zeit);

	stop();

}

// goRight - virar para direita
void goRight(int Zeit) {

	Rowena.write(135);
	Ravenclaw.write(135);
	Luna.write(180);
	Lovegood.write(180);

	if (Zeit < 0) {

		while (true) {

			int rColor = colorDetect(rS2, rS3, rSOut);
			int irColor = irDetect(irA0);

			// Se sensor esquerdo detectar branco e sensor IR detectar preto
			if (rColor == 0 && irColor == 1) break;

		}

	}

	else delay(Zeit);

	stop();

}

// goBack - ir para trás
void goBack(int Zeit) {

	Rowena.write(180);
	Ravenclaw.write(180);
	Luna.write(0);
	Lovegood.write(0);

	delay(Zeit);

	stop();

}

// go180 - girar 180º no lugar
void go180() {

	Rowena.write(0);
	Ravenclaw.write(0);
	Luna.write(0);
	Lovegood.write(0);

	// Esperar tempo - MEDIR !!!!!!!!!!!
	delay(2000);

	stop();

}
