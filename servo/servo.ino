
#include <Servo.h>

Servo myservo;  


void setup() {
  myservo.attach(11); 
}

void loop() {
  myservo.write(60); 
  delay(1000); 
  myservo.write(0); 
  delay(1000); 
}

