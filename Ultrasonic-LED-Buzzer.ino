#define trigPin 7

#define echoPin 6

#define led1 13

#define led2 12

#define led3 11

#define buzzer 5

int sound = 250;

void setup() {

Serial.begin (9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(led1, OUTPUT);

pinMode(led2, OUTPUT);

pinMode(led3, OUTPUT);

pinMode(buzzer, OUTPUT);

}

void loop() {

long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

if (distance <= 25) {

digitalWrite(led1, HIGH);

sound = 1000;

}

else {

digitalWrite(led1,LOW);

}

if (distance <= 15) {

digitalWrite(led2, HIGH);

sound = 2000                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ;

}

else {

digitalWrite(led2, LOW);

}

if (distance < 8) {

digitalWrite(led3, HIGH);

sound = 1500;

}

else {

digitalWrite(led3, LOW);

}

if (distance > 50 || distance <= 0){

Serial.println("Jarak diluar jangkauan!");

noTone(buzzer);
   
}

else {

Serial.print(distance);

Serial.println(" cm");

tone(buzzer, sound);

}

delay(300);

}
