/*
Nome: Functions.ino
Definir funções
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

// Line Follower - Decision making
void lineFollower() {
	int rColor = colorDetect(rS2, rS3, rSOut);
	int lColor = colorDetect(lS2, lS3, lSOut);
	int irColor = irDetect(irA0);
	int distance = usDetect(usTrig, usEcho);

	// Pelo menos um dos sensores de cor detecta verde - Confirmar cores
	if (rColor == 2 || lColor == 2) {
		// Ir para frente...

		// Atualizar variáveis
		rColor = colorDetect(rS2, rS3, rSOut);
		lColor = colorDetect(lS2, lS3, lSOut);
	}

	// Ambos os sensores de cor detectam verde - Meia-volta
	if (rColor == 2 && rColor == 2) {
		// Dar meia-volta...
	}

	// Apenas o sensor direito detecta verde - Virar para direita
	else if (rColor == 2) {
		// Virar para direita...
	}

	// Apenas o sensor esquerdo detecta verde - Virar para esquerda
	else if (lColor == 2) {
		// Virar para esquerda...
	}

	// Os três sensores detectam preto - Seguir reto
	else if (rColor == 1 && lColor == 1 && irColor == 1) {
		// Seguir reto...
	}

	// Sensor IR detecta preto + Sensor Direito ou Esquerdo detecta preto - Ir para frente e decidir
	else if (irColor == 1 && (rColor == 1 || lColor == 1)) {
		// Seguir reto e decidir...
	}

	// Sensor IR detecta branco + Sensor Direito ou Esquerdo detecta preto - Virar
	else if (irColor == 0) {

		// Sensor Direito detecta preto - Virar para direita
		if (rColor == 1) {
			// Virar para direita...
		}

		// Sensor Esquerdo detecta preto - Virar para esquerda
		if (lColor == 1) {
			// Virar para esquerda...
		}

	}

}
