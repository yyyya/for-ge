#include <LiquidCrystal.h>
LiquidCrystal lcd(32, 30, 28, 26, 24, 22); //定义脚位

int wheelArr[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int lf[8] = {0, 1, 0, 0, 0, 0, 0, 1};//左前
int rf[8] = {0, 0, 0, 1, 0, 1, 0, 0};//右前
int time1 = 0;
int time2 = 0;
void setup() {
  lcd.begin(16, 2);
  controlInit();
}


void loop()
{
  traceLine();
}

void controlInit()
{
  int i = 0;
  for (i = 0; i < 12; i++) {//设置为减速电机信号输出
    pinMode(i, OUTPUT);
  }
  pinMode(52, INPUT);//52为寻迹传感器输入信号，白线为高电平
  for (i = 0; i < 4; i++) {
    analogWrite(speedArr[0], 140);
  }
  for (int i = 0; i < 8; i++) {//初始状态为左前
    digitalWrite(wheelArr[i], lf[i]);
  }
}

int traceLine() {
  while (1) {
    //interrupt,RFID读卡器检测到地面芯片，产生中断信号
    if (digitalRead(52) == 1) {
      for (int i = 0; i < 8; i++) {
        digitalWrite(wheelArr[i], lf[i]);
      }
    } else {
      for (int i = 0; i < 8; i++) {
        digitalWrite(wheelArr[i], rf[i]);
      }
    }
    delay(100);
  }
}

int compassInterrupt() {
  if (); //如果当前位置有待放书目，停下，调用步进电机升降
  //AccelStepper.ino
  //goFloor();
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
    if ((time2 - time1) <= i * 20000) {//  1cm/s
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
