/*
	Nome: HoBo.ino
	Arquivo principal
*/

/*
 - Servos:
	Right: 0 <- 180
	Left: 180 <- 0

  Garden.attach(30);
  Claw.attach(32);
  Door.attach(34);
*/

#include <Servo.h>
#include <Ultrasonic.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Sensor Cor Direito
byte rS0 = 2;
byte rS1 = 3;
byte rS2 = 4;
byte rS3 = 5;
byte rSOut = 6;

// Sensor Cor Esquerdo
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
Ultrasonic usF(usFTrig, usFEcho);

// Sensor US Frente Inclinado
byte usFITrig = 36;
byte usFIEcho = 38;
Ultrasonic usFI(usFITrig, usFIEcho);

// Sensor US Frente Direita
byte usFRTrig = 52;
byte usFREcho = 50;
Ultrasonic usFR(usFRTrig, usFREcho);

// Sensor US Frente Esquerda
byte usFLTrig = 46;
byte usFLEcho = 48;
Ultrasonic usFL(usFLTrig, usFLEcho);

// Sensor US Direita
byte usRTrig = 41;
byte usREcho = 43;
Ultrasonic usR(usRTrig, usREcho);

// Sensor US Esquerda
byte usLTrig = 51;
byte usLEcho = 53;
Ultrasonic usL(usLTrig, usLEcho);

// Servos Direita
Servo Rowena;
Servo Ravenclaw;

// Servos Esquerda
Servo Luna;
Servo Lovegood;

// Servo Frente
Servo Garden;

// Servos Garra
Servo Claw;
Servo Door;

// Tela OLED
Adafruit_SSD1306 screen(-1);

void setup() {

	// Sensores de cor
	pinMode(rS0, OUTPUT);
  pinMode(rS1, OUTPUT);
  pinMode(rS2, OUTPUT);
  pinMode(rS3, OUTPUT);
  pinMode(rSOut, INPUT);
  digitalWrite(rS0, HIGH);
  digitalWrite(rS1, LOW);
  
  pinMode(lS0, OUTPUT);
  pinMode(lS1, OUTPUT);
  pinMode(lS2, OUTPUT);
  pinMode(lS3, OUTPUT);
  pinMode(lSOut, INPUT);
  digitalWrite(lS0, HIGH);
  digitalWrite(lS1, LOW);

	// Sensor IR
	pinMode(A0, INPUT);

	// Servos
	attachServo();

	// Tela OLED
	screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  screen.setTextColor(1);
  screen.setTextSize(2);

  // Parar servos
  servoStop();
  Claw.detach();
  Garden.detach();
  Door.detach();
  
	// Begin Serial
	Serial.begin(9600);

}

void loop() {

/*
  Serial.print("R:\t");
  Serial.print(colorDetect(rS2, rS3, rSOut));
  Serial.print("\tL:\t");
  Serial.print(colorDetect(lS2, lS3, lSOut));
  Serial.println(" ");
*/
  
}
