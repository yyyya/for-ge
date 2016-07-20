int num=0;
 
void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, blink, FALLING);//当int.0电平改变时,触发中断函数blink
}
 
void loop()
{
  Serial.println(num);
}
 
void blink()//中断函数
{
  num+=1;
  detachInterrupt(0);
}
