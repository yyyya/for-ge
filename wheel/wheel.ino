int wheelArr[8] = {0, 1, 2, 3, 4, 5, 7, 8};
int direct[8] = {0, 1, 1, 0, 1, 0, 0, 1};
int speedArr[4] = {6, 9, 10, 11};
void setup()
{
  int i = 0;
  for (i = 0; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(12, INPUT);
  for (i = 0; i < 4; i++) {
    analogWrite(speedArr[i], 250);
  }

  for (int i = 0; i < 8; i++) {
    digitalWrite(wheelArr[i], direct[i]);
  }
}
void loop()
{
}

