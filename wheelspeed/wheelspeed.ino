void setup() {
  // put your setup code here, to run once:
  pinMode(0, OUTPUT);  //direction pin
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);//step pin
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  analogWrite(3,110);
}
