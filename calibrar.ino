int S0 = 4;
int S1 = 5;
int S2 = 6;
int S3 = 7;
int sensorOut = 8;

void setup() {
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);

}

void loop() {
  
  int result = 0;
  
  for(int i = 0; i < 5; i++) {

    result += read_Color(S2, S3);
    
  }

  result /= 5;

  Serial.print(result);
  Serial.print("  ");

  if(result < 100) Serial.print("WHITE");
  else if(result < 200) Serial.print("BLACK");
  else Serial.print("GREEN");
  
  Serial.print("\n");

  
}
