void calibrateColor() {

Serial.print("R -\t");

// R(ED)
  digitalWrite(rS2, LOW);
  digitalWrite(rS3, LOW);
  int rightRedFrequency = pulseIn(rSOut, LOW);
  Serial.print("R: ");
  Serial.print(rightRedFrequency);
  Serial.print("\t");

  delay(100);

  // G(REEN)
  digitalWrite(rS2, HIGH);
  digitalWrite(rS3, HIGH);
  int rightGreenFrequency = pulseIn(rSOut, LOW);
  Serial.print("G: ");
  Serial.print(rightRedFrequency);
  Serial.print("\t");

  delay(100);

  // B(LUE)
  digitalWrite(rS2, LOW);
  digitalWrite(rS3, HIGH);
  int rightBlueFrequency = pulseIn(rSOut, LOW);
  Serial.print("B: ");
  Serial.print(rightBlueFrequency);

  delay(100);

  Serial.print("\tS: ");
  int sum = rightRedFrequency + rightGreenFrequency + rightBlueFrequency;
  Serial.print(sum);
  Serial.print("\tL -\t");

// R(ED)
  digitalWrite(lS2, LOW);
  digitalWrite(lS3, LOW);
  int leftRedFrequency = pulseIn(lSOut, LOW);
  Serial.print("R: ");
  Serial.print(leftRedFrequency);
  Serial.print("\t");

  delay(100);

  // G(REEN)
  digitalWrite(lS2, HIGH);
  digitalWrite(lS3, HIGH);
  int leftGreenFrequency = pulseIn(lSOut, LOW);
  Serial.print("G: ");
  Serial.print(leftRedFrequency);
  Serial.print("\t");

  delay(100);

  // B(LUE)
  digitalWrite(lS2, LOW);
  digitalWrite(lS3, HIGH);
  int leftBlueFrequency = pulseIn(lSOut, LOW);
  Serial.print("B: ");
  Serial.print(leftBlueFrequency);

  delay(100);

  Serial.print("\tS: ");
  sum = leftRedFrequency + leftGreenFrequency + leftBlueFrequency;
  Serial.print(sum);
  Serial.println(" ");

}
