/*   
  microstep driver ST-M5045
  Pul+ goes to +5V
  Pul- goes to Arduino Pin 36
  Dir+ goes to +5V
  Dir- goes to to Arduino Pin 34
  Enable+ to nothing
  Enable- to nothing
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(32, 30, 28, 26, 24, 22); //定义脚位

int sensorValue = 0;
int time1 = 0;
int time2 = 0;
void setup() {
  lcd.begin(16, 2);
}

void loop() {
  goFloor(1, 0);
  while (1); //wait for interrupt
}

int goFloor(int i, int direct) {
  pinMode(36, OUTPUT);  //direction pin
  pinMode(34, OUTPUT); //step pin
  digitalWrite(34, LOW);
  if (direct == 1) {
    digitalWrite(36, LOW);
    lcd.print("Up floor");
  } else {
    digitalWrite(36, HIGH);
    lcd.print("Down floor");
  }
  time1 = millis();
  lcd.setCursor(0, 1); //将闪烁的光标设置到column 0, line 1 (注释：从0开始数起，line 0是显示第一行，line 1是第二行。)
  lcd.print(i);
  while (1) {
    time2 = millis();
    if ((time2 - time1) <= i*20000) {
      sensorValue = 980;
      //sensorValue = map(sensorValue, 0, 1023, 3600, 1);
      digitalWrite(34, HIGH);
      delayMicroseconds(sensorValue);
      digitalWrite(34, LOW);
      delayMicroseconds(sensorValue);
      //  digitalWrite(7, HIGH);
      //  delayMicroseconds(sensorValue);
      //  digitalWrite(7, LOW);
      //  delayMicroseconds(sensorValue);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Done");
      return 1;
    }
  }
}

