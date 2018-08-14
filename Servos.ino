/*
	Nome: Servos.ino
	Definir fun��es dos servos
*/

/*
  - Servos:
	Right: 0 <- 180
	Left: 180 <- 0
*/

// attachServo
void attachServo() {

  Luna.attach(26);
  Lovegood.attach(28);
  Rowena.attach(24);
  Ravenclaw.attach(22);

}

// stop - detach
void servoStop() {

  Rowena.detach();
  Ravenclaw.detach();
  Luna.detach();
  Lovegood.detach();

}

// goFront - ir para frente
void goFront(int Zeit) {

  attachServo();
  Rowena.write(0);
  Luna.write(180);

  if (Zeit > 0) {

    delay(Zeit);

    servoStop();

  }

}

// goLeft - virar para esquerda
void goLeft(int Zeit) {

  attachServo();
  Rowena.write(0);
  Ravenclaw.write(0);
  Luna.write(0);
  Lovegood.write(0);

  if (Zeit < 0) {

    while (true) {

      int lColor = colorDetect(lS2, lS3, lSOut);
      int irColor = irDetect(irA0);

      // Se sensor esquerdo detectar branco e sensor IR detectar preto
      if (lColor == 0 && irColor == 1) break;

    }

  }

  else if (Zeit == 0) goLeft(2000); // Valor para 90�

  else delay(Zeit);

  servoStop();

}

// goRight - virar para direita
void goRight(int Zeit) {

  attachServo();
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

  else if (Zeit == 0) goRight(2000); // Valor para 90�

  else delay(Zeit);

  servoStop();

}

// goBack - ir para tr�s
void goBack(int Zeit) {

  attachServo();
  Rowena.write(180);
  Luna.write(0);

  delay(Zeit);

  servoStop();

}

// go180 - girar 180� no lugar
void go180() {

  attachServo();
  Rowena.write(0);
  Ravenclaw.write(0);
  Luna.write(0);
  Lovegood.write(0);

  // Esperar tempo - MEDIR !!!!!!!!!!!
  delay(2000);

  servoStop();

}
