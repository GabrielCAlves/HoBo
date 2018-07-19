/*
Name: Setup.ino
Definir pins
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
	Luna.attach();
	Lovegood.attach();
	Rowena.attach();
	Ravenclaw.attach();
	Garden.attach();
	Claw.attach();
	Door.attach();
}
