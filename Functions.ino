/*
	Nome: Functions.ino
	Definir funções
*/

/*
  - Servos:
	Right: 0 <- 180
	Left: 180 <- 0
*/

// Sensores de cor - Retornar cor
int colorDetect(int S2, int S3, int SOut) {

  int sum = 0;

  for (int i = 0; i < 5; i++) {

    // R(ED)
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    int RedFrequency = pulseIn(SOut, LOW);
    delay(100);

    // G(REEN)
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    int GreenFrequency = pulseIn(SOut, LOW);

    // B(LUE)
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    int blueFrequency = pulseIn(SOut, LOW);

    sum += RedFrequency + GreenFrequency + blueFrequency;

  }

  sum /= 5;
  
  // 1 - Preto
  if (sum >= 120) return 1;
  // 2 - Verde
  else if (sum >= 90) return 2;
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

    delay(3);

  }

  return media / 5;

}

// Obstacle Deflect - Desviar do osbtáculo
void obstacleDeflect() {

  servoStop();
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
    servoStop();

    // Atualizar variáveis
    rColor = colorDetect(rS2, rS3, rSOut);
    lColor = colorDetect(lS2, lS3, lSOut);

  }

  // Os dois sensores detectam verde - Meia-volta
  if (rColor == 2 && lColor == 2) {

    servoStop();
    go180();
    goFront(500);
    return;

  }

  // Sensor esquerdo detecta verde - Vira para a esquerda 90º
  if (rColor == 2) {

    servoStop();
    goLeft(1000);
    return;
  }

  // Sensor direito detecta verde - Vira para a direita 90º
  if (lColor == 2) {

    servoStop();
    goRight(1000);
    return;
  }

  // Sensor direito detecta preto + sensor IR detecta preto + sensor esquerdo detecta branco - 90º
  if (rColor == 1 && irColor == 1 && lColor == 0) {

    delay(1000);
    servoStop();

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
    servoStop();

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

    servoStop();
    goBack(500);
    goRight(-1);
    return;

  }

  // Sensor esquerdo detecta preto + sensor IR detecta branco - Até detectar
  if (lColor == 1 && irColor == 0) {

    servoStop();
    goBack(500);
    goLeft(-1);
    return;

  }
 
  goFront(-1);

}
