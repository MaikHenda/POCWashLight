int echoPin = 11;
int trigPin = 12;
long duration;
int distance;

void setup() {
  for (int i = 2; i <= 7; i++) {
    pinMode (i, OUTPUT);
  }
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
}
void loop() {
  // Dit deel van de code vertelt de UltraSonic Sensor om de afstand te meten en leest de gemeten data
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  // Dit "If Statement" detecteerd of er binnen de range van 30 centimeter een object aanwezig is(handen)
  if (distance > 0 && distance <= 30) {
    ledtimer();
  }
}
 
void ledtimer() {
  digitalWrite (7, HIGH);
  delay(2000);
  for (int i = 6; i >= 2; i--) {
    digitalWrite (i, HIGH);
    if (i == 2) {
      digitalWrite (7, LOW);
    }
    delay(2000);
  }
  for (int i = 7; i >= 2; i--) {
    digitalWrite (i, LOW);

  }
}
