int potPin = A0;    // select the input pin for the potentiometer
int ledPin = 9;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  pinMode(A0,INPUT);
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  analogWrite(ledPin, val);  // turn the ledPin on
                    // stop the program for some time
}
