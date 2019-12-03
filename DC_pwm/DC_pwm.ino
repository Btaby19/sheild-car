void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {

  analogWrite(7,255);
  analogWrite(8,0);
  delay(1500);
  analogWrite(7,0);
  analogWrite(8,255);
  delay(1500);

}
