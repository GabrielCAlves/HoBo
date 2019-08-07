int read_Red(int S2, int S3) {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  int frequency = pulseIn(sensorOut, LOW);

  return frequency;
}

int read_Green(int S2, int S3) {
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  int frequency = pulseIn(sensorOut, LOW);

  return frequency;
}

int read_Blue(int S2, int S3) {
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  int frequency = pulseIn(sensorOut, LOW);

  return frequency;
}

int read_Color(int S2, int S3) {
  int frequencyRed = read_Red(S2, S3);
  delay(10);
  int frequencyGreen = read_Green(S2, S3);
  delay(10);
  int frequencyBlue = read_Blue(S2, S3);
  delay(10);

  return (frequencyRed + frequencyGreen + frequencyBlue);
}
