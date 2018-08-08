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
void setupColor(int S0, int S1, int S2, int S3, int SOut) {

	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	pinMode(SOut, INPUT);
	digitalWrite(S0, HIGH);
	digitalWrite(S1, LOW);

}

// Setup - Sensor IR
void setupIR(int A0) {

	pinMode(A0, INPUT);

}

// Setup - Sensor US
void setupUS(int trig, int echo) {

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

	Luna.attach(7);
	Lovegood.attach(6);
	Rowena.attach(5);
	Ravenclaw.attach(4);
	Garden.attach(3);
	Claw.attach(2);
	Door.attach(1);

}
