#include <Servo.h>
Servo myservo;
int pos = 0;
int waktuKalibrasi = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean ambilWaktuSebentar;
int pirSensor = 12;
void setup(){
  myservo.attach(4);
  pinMode(pirSensor, INPUT);

    for(int i = 0; i < waktuKalibrasi; i++){
      delay(1000);
    }
    while (digitalRead(pirSensor) == HIGH) {
      delay(200);
    }
  }

void loop(){
  if(digitalRead(pirSensor) == HIGH){
    for(pos = 0; pos < 180; pos += 1)
    {
      myservo.write(pos);
      delay(5);
    }
    for(pos = 180; pos>=1; pos-=1)
    {
      myservo.write(pos);
      delay(5);
    }
 
    if(lockLow){
      lockLow = false;
      delay(50);
    }
    ambilWaktuSebentar = true;
  }

  if(digitalRead(pirSensor) == LOW){
    if(ambilWaktuSebentar){
      lowIn = millis();
      ambilWaktuSebentar = false;
    }
    if(!lockLow && millis() - lowIn > pause){
      lockLow = true;
      delay(50);
    }
  }
}
;
