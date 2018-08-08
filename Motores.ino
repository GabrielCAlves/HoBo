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
	Luna.write(90);
	Lovegood.write(90);

}

// goFront - ir para frente
void goFront(int Zeit) {
	
	Rowena.write(0);
	Ravenclaw.write(0);
	Luna.write(180);
	Lovegood.write(180);

	delay(Zeit);

	stop();

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
