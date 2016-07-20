/**
 * 
 * wheelArr为直流电机所对应的DigitalIO口，分别为左前左后右前右后
 * speedArr为上述电机的速度控制IO口
 * 
 * 电机旋转方式为00,11制动，01正转，10反转，使用lfrf等数组操控
 * 若转向不对，自行更改接口为此逻辑
 * 
 * l298n接口从左到右依次为左速，左旋转，左旋转，右旋转，右旋转，右速
 * 
 */
int wheelArr[8] = {0, 1, 2, 3, 4, 5, 7, 8};
int lf[8] = {0, 1, 0, 0, 0, 0, 0, 1};//左前
int rf[8] = {0, 0, 0, 1, 0, 1, 0, 0};//右前
int speedArr[4] = {6, 9, 10, 11};
void setup()
{
  int i = 0;
  
  for (i = 0; i < 12; i++) {//1-11设置为减速电机信号输出
    pinMode(i, OUTPUT);
  }
  pinMode(12, INPUT);//12为寻迹传感器输入信号，白线为高电平
  
  for (i = 0; i < 4; i++) {
    analogWrite(speedArr[i], 140);
  }

  for (int i = 0; i < 8; i++) {//初始状态为左前
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

