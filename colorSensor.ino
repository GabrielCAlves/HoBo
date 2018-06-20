/* TCS 3200 Color Sensor - Green Detect Scratch
 *
 */

// Defining right pins
 #define r_S0 4
 #define r_S1 5
 #define r_S2 6
 #define r_S3 7
 #define r_sensorOut 8

// Defining left pins

#define l_S0 9
#define l_S1 10
#define l_S2 11
#define l_S3 12
#define l_sensorOut 13

int r_frequency, l_frequency = 0;

void setup() {
  pinMode(r_S0, OUTPUT);
  pinMode(r_S1, OUTPUT);
  pinMode(r_S2, OUTPUT);
  pinMode(r_S3, OUTPUT);
  pinMode(r_sensorOut, INPUT);
  
  pinMode(l_S0, OUTPUT);
  pinMode(l_S1, OUTPUT);
  pinMode(l_S2, OUTPUT);
  pinMode(l_S3, OUTPUT);
  pinMode(l_sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  Serial.begin(9600);
}

bool greenDetect(int frequency) {
  // Checking if green is detected
  int greenValue = 200
  if(frequency > greenValue) return true;
  else return false;
}

void loop() {
  // Setting green filtered photodiodes to be read
  digitalWrite(r_S2, HIGH);
  digitalWrite(r_S3, HIGH);
  digitalWrite(l_S2, HIGH);
  digitalWrite(l_S3, HIGH);
  
  r_frequency = pulseIn(r_sensorOut, LOW);
  l_frequency = pulseIn(l_sensorOut, LOW);
  // Remaping the value of the frequency to the RGB Model of 0 to 255
  r_frequency = map(30, 90, 255, 0);
  l_frequency = map(30, 90, 255, 0);
  
  if(greenDetect(r_frequency) && greenDetect(l_frequency) {
    // ...
    // Turn and go back
  } else if(greenDetect(r_frequency) {
    // ...
    // Turn right
  } else if(greenDetect(l_frequency) {
    // ...
    // Turn left
  }
            
}
