int trigPin = 11;
int echoPin = 12;
long duration, cm;

int led1 = 2;
int led2 = 3;
int led3 = 4;

long previous = 1;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;
  Serial.print("Centimeters: ");
  Serial.println(cm);

  checkLength(cm);

  delay(200);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
}

void checkLength(long data) {
  if(data <= 20) {
    Serial.println("00-20");
    digitalWrite(led1, LOW);
    previous = data;
  }
  else if(data > 20 && data <= 40) {
    Serial.println("20-40");
    digitalWrite(led2, LOW);
    previous = data;
  }
  else if(data > 40 && data < 500){
    Serial.println("40-70");
    digitalWrite(led3, LOW);
    previous = data;
  }
  else {
    Serial.println("again");
    checkLength(previous);
  }
}
