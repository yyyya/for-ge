#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //定义脚位
String comdata = "";
void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2); //设置LCD显示的数目。16 X 2：16格2行。
  lcd.print("  hello,world!"); //将hello,world!显示在LCD上
}
void loop()
{
  while (Serial.available() > 0)
  {
    comdata += char(Serial.read());
    delay(2);
  }
  if (comdata.length() > 0)
  {
    //lcd.print(millis()/1000); //开机后屏幕现实以秒几时的时间
    lcd.clear();
    lcd.print("  hello,world!"); //将hello,world!显示在LCD上
    lcd.setCursor(0, 1); //将闪烁的光标设置到column 0, line 1 (注释：从0开始数起，line 0是显示第一行，line 1是第二行。)
    lcd.print(comdata);
    comdata = "";
  }
}
