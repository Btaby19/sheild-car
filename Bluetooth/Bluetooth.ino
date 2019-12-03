#include <Servo.h>
 
//L293N Connection   
  const int motorA1  = 5;  
  const int motorA2  = 6;  
  const int motorB1  = 10; 
  const int motorB2  = 9;
  const int motorC1  = 3;  
  const int motorC2  = 4;    
//Bluetooth (HC-05) State pin on pin 2 of Arduino
  const int BTState = 2;
//Useful Variables
  int i=0;
  int j=0;
  int state;
  int vSpeed=255;     // Default speed, from 0 to 255

void setup() {
    // Set pins as outputs:
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(motorC1, OUTPUT);
    pinMode(motorC2, OUTPUT);
    pinMode(BTState, INPUT);    
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
  //Stop car when connection lost or bluetooth disconnected
     if(digitalRead(BTState)==LOW) { state='S'; }

  //Save income data to variable 'state'
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
  
  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
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
 	  
  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
    if (state == 'F') {
    	analogWrite(motorA1, 255); 
    	analogWrite(motorA2, 0);
      analogWrite(motorB1, 255); 
      analogWrite(motorB2, 0); 
    }
  /**********************Forward Left************************/
  //If state is equal with letter 'G', car will go forward left
    else if (state == 'G') {
    	analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);  
      analogWrite(motorB1, 200);    analogWrite(motorB2, 0); 
    }
  /**********************Forward Right************************/
  //If state is equal with letter 'I', car will go forward right
    else if (state == 'I') {
      	analogWrite(motorA1, vSpeed); 
      	analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);     
        analogWrite(motorB2, 200); 
    }
        /***********************Backward****************************/
  //If state is equal with letter 'B', car will go backward
    else if (state == 'B') {
      analogWrite(motorA1, 0); 
      analogWrite(motorA2, 255);
      analogWrite(motorB1, 0); 
      analogWrite(motorB2, 255); 
    }
  /**********************Backward Left************************/
  //If state is equal with letter 'H', car will go backward left
    else if (state == 'H') {
    	analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 200); analogWrite(motorB2, 0); 
    }
  /**********************Backward Right************************/
  //If state is equal with letter 'J', car will go backward right
    else if (state == 'J') {
    	analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 200); 
    }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
    else if (state == 'L') {
    	
      analogWrite(motorA1, 0);
      analogWrite(motorA2, 255); 
      analogWrite(motorB1, 255);
      analogWrite(motorB2, 0);  
    }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
    else if (state == 'R') {
      analogWrite(motorA1, 255); 
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, 0); 
      analogWrite(motorB2, 255); 
      		
    }
    else if (state == 'U') {
      analogWrite(motorC1, 0); 
      analogWrite(motorC2, 255);
      
    }
    else if (state == 'u') {
      analogWrite(motorC1, 0); 
      analogWrite(motorC2, 0);
     
    }
 
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }

    
}



