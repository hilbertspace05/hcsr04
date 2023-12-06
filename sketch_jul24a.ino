const int pingPin = 8;
const int echoPin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  if(cm < 15) {
    digitalWrite(7, HIGH);
  }

  if(cm < 20) {
    digitalWrite(6, HIGH);
  }

  if(cm < 25) {
    digitalWrite(5, HIGH);
  }

  if(cm < 30) {
    digitalWrite(4, HIGH);
  }

  if(cm < 35) {
    digitalWrite(3, HIGH);
  }

  if(cm < 40 || cm > 40) {
    digitalWrite(2, HIGH);
  }

  else {
    for(int i = 2; i < 8; i++) {
      digitalWrite(i, LOW);
    }
  }

}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
