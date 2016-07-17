int wheelArr[8] = {0, 1, 2, 3, 4, 5, 7, 8};
int lf[8] = {0, 1, 0, 0, 0, 0, 0, 1};//左前
int rf[8] = {0, 0, 0, 1, 0, 1, 0, 0};//右前
int speedArr[4] = {6, 9, 10, 11};
void setup()
{
  int i = 0;
  for (i = 0; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(12, INPUT);
  for (i = 0; i < 4; i++) {
    analogWrite(speedArr[i], 140);
  }

  for (int i = 0; i < 8; i++) {
    digitalWrite(wheelArr[i], lf[i]);
  }
}
void loop()
{
  if(digitalRead(12)==1){
    for (int i = 0; i < 8; i++) {
      digitalWrite(wheelArr[i], lf[i]);
    }
  }else{
    for (int i = 0; i < 8; i++) {
      digitalWrite(wheelArr[i], rf[i]);
    }
  }
  delay(200);
}

