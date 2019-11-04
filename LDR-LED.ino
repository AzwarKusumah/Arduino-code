 byte ldr= A2;
 byte led= 13;
 int nilai;

 void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
 }

void loop(){
  nilai= analogRead(ldr);
  Serial.print("Nilai LDR: ");
   Serial.println(nilai);

  if(nilai < 500){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }

}
