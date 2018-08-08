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

// Sensor US - Retornar distância
double usDetect(int trig, int echo) {
	// Limpar trig
	digitalWrite(trig, LOW);
	delayMicroseconds(2);

	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	
	double duration = pulseIn(echo, HIGH);
	double distance = duration * 0.034 / 2.0;

	return distance;
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
