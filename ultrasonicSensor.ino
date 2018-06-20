/* Ultrasonic Sensor HC-SR04 - Object Detection Sratch
 *
 */
 
#define trigPin 9
#define echoPin 10

int distance = 0;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    Serial.begin(9600);
}

int distanceCalc(int duration) {
    return duration*0.034/2;
}

void loop() {
    //Clearing the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    distance = distanceCalc(pulseIn(echoPin, HIGH));
    
    if(distance <= 10) {
        // ...
        // Detour and continue
    }
    
}
