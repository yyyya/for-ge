/**

   wheelArr为直流电机所对应的DigitalIO口，分别为左前右前左后右后
   speedArr为上述电机的速度控制IO口

   电机旋转方式为00,11制动，01正转，10反转，使用lfrf等数组操控
   若转向不对，自行更改接口为此逻辑

   l298n接口从左到右依次为左速，左旋转，左旋转，右旋转，右旋转，右速

  寻迹传感器1为pin52

*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(32, 30, 28, 26, 24, 22); //定义脚位
int wheelArr[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int rf[8] = {0, 1, 0, 0, 0, 0, 0, 1};
int lf[8] = {0, 0, 0, 1, 0, 1, 0, 0};
int speedArr[4] = {10, 11, 12, 13};
void setup()
{
  lcd.begin(16, 2);
  int i = 0;

  for (i = 0; i < 12; i++) {//设置为减速电机信号输出
    pinMode(i, OUTPUT);
  }
  pinMode(52, INPUT);//52为寻迹传感器输入信号，白线为高电平

  for (i = 0; i < 4; i++) {
    analogWrite(speedArr[i], 140);
  }

lcd.print("Turn left...");
  for (int i = 0; i < 8; i++) {//初始状态为左前
    digitalWrite(wheelArr[i], lf[i]);
  }

}
void loop()
{
  //寻迹传感器2检测到
  if (digitalRead(52) == 1) {
        for (int i = 0; i < 8; i++) {
          digitalWrite(wheelArr[i], lf[i]);
          lcd.clear();
          lcd.print("Turn left...");
        }
      }else{
        for (int i = 0; i < 8; i++) {
          digitalWrite(wheelArr[i], rf[i]);
          lcd.clear();
          lcd.print("Turn right...");
        }
  }
  delay(100);
}
