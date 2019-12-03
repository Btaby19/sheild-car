#include <Servo.h>
Servo myservo;  
  
  const int motorA1  = 5;  
  const int motorA2  = 6;  
  const int motorB1  = 10; 
  const int motorB2  = 9;

  const int handA1 = 4;
  const int handA2 = 7;

  const int handB1 = 3;
  const int handB2 = 11;
  
  const int servopin =12 ;
  
  const int BTState = 2;  


  int state;
  int vSpeed=255 ; 
  
void setup() {

  // wheel dc motor
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  // for ending factor
  pinMode(handA1, OUTPUT);
  pinMode(handA2, OUTPUT);

  // for hand
  pinMode(handB1, OUTPUT);
  pinMode(handB2, OUTPUT);

  // for Bluetooth 
  pinMode(BTState, INPUT);

  // for servo
  myservo.attach(servopin); 
  Serial.begin(9600);
}

void loop() {

 if(digitalRead(BTState)==LOW) { state='S'; }

  //Save income data to variable 'state'
    if(Serial.available() > 0){     
      state = Serial.read();   
    }

    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=230;}
    else if (state == '4'){
      vSpeed=255;}

      if(state =='F'){
        forward();
      }
      
      else if(state =='B')
      {
        backward();
      }
      else if(state =='L')
      {
        left();
      }

       else if(state =='R')
      {
        right();
      } 

      
      else if(state =='G')
      {
        forwardleft();
      }
      
      else if(state =='I')
      {
        forwardRight();
      }
      
      else if(state =='H')
      {
        backwardLeft();
      }
      
     else if(state =='J')
      {
        backwardRight();
      }
      
      else if(state =='S')
      {
        stop_bot();
      }

      // hand part
      
      // grip C, D ,E
      else if(state=='P'){
        myservo.write(60);
      }
       else if(state=='Q'){
        myservo.write(10);
      }
      else if(state=='K'){
        analogWrite(handA1, 0); 
        analogWrite(handA2, 0);
      }

      // factor mover move
      else if(state=='C'){
        factor_up();
      }
       else if(state=='D'){
        factor_down();
      }
      
       else if(state=='E'){
        analogWrite(handB1, 0); 
        analogWrite(handB2, 0);
      }

      // Servo Controll
      else if(state=='M'){
        myservo.write(60);
      }
      else if(state=='N'){
        myservo.write(10);
      }
      else if(state=='O'){
        
      }
}
void grip(){
  analogWrite(handA1, 255); 
  analogWrite(handA2, 0);
}
void release_hand(){
  analogWrite(handA1, 0); 
  analogWrite(handA2, 255);
}

void factor_up(){
  analogWrite(handB1, 255); 
  analogWrite(handB2, 0);
}
void factor_down(){
  analogWrite(handB1, 0); 
  analogWrite(handB2, 255);
}


void forward(){
  analogWrite(motorA1, vSpeed); 
  analogWrite(motorA2, 0);
  
  analogWrite(motorB1, vSpeed); 
  analogWrite(motorB2, 0); 
}
void backward(){
 analogWrite(motorA1, 0); 
 analogWrite(motorA2, vSpeed);
 
 analogWrite(motorB1, 0); 
 analogWrite(motorB2, vSpeed); 
}
void left(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, vSpeed); 
  
  analogWrite(motorB1, vSpeed);
  analogWrite(motorB2, 0); 
}
void right(){
  analogWrite(motorA1, vSpeed); 
  analogWrite(motorA2, 0); 
  analogWrite(motorB1, 0); 
  analogWrite(motorB2, vSpeed); 
}

void stop_bot(){
  analogWrite(motorA1, 0); 
  analogWrite(motorA2, 0); 
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}
void forwardleft(){
  analogWrite(motorA1, vSpeed);
  analogWrite(motorA2, 0);  
  analogWrite(motorB1, vSpeed-50);
  analogWrite(motorB2, 0); 
}
void forwardRight(){
  analogWrite(motorA1, vSpeed); 
  analogWrite(motorA2, 0); 
  analogWrite(motorB1, 0);     
  analogWrite(motorB2, vSpeed-50);
}
void backwardLeft(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, vSpeed); 
  analogWrite(motorB1, vSpeed-30);
  analogWrite(motorB2, 0); 
}
void backwardRight(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, vSpeed); 
  analogWrite(motorB1, 0);
  analogWrite(motorB2, vSpeed-50); 
}


