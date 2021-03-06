#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); //LCD 객체 선언, 안되면 당연히 I2C 주소 0x3F로 바꿔보기

int but1 = 40;
int but2 = 41;
int but3 = 42; 
int but4 = 43; //버튼 D40~D43로 설정. 기존 UNO R3에서 MEGA 2560으로 전환함에 따라 핀 변경.

int volt1 = 13; //전원 1번
int volt2 = 53; //전원 2번

int stat = 0; //상태 변수. 초기값 0, 버튼 눌리면 1로. 응답 없으면 다시 0으로.
unsigned long prev_time, cur_time = 0; //시간 값. 초기값 0
char ch = Serial.read(); // 시리얼 통신으로 수신부가 보내는 값
char val; // 입력하는 버튼에 따라 달리하기, A/B/C/D 총 4종류


void setup() {
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  pinMode(but4, INPUT);
  pinMode(volt1, OUTPUT);
  pinMode(volt2, OUTPUT);
  Serial.begin(9600);
}

void (* Reset)(void) = 0;

void repeat(char val){
  for(int num=0; num++; num<5){
  Serial.write(val);
  delay(1000);
  }
}

void printmsg(char ch){
  lcd.clear();
  lcd.backlight();
  lcd.print(ch);
  lcd.print("IS COMING");
  delay(3000);
  Reset();
  }

void checkTime(char val){
  cur_time = millis();
  while(cur_time - prev_time < 20000){
    if(ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd'){
      printmsg(ch);
      }
    else{}
    }
  lcd.clear();
  lcd.backlight();
  lcd.print("NO ANSWER");
  
  while(cur_time - prev_time >= 20000 && cur_time - prev_time <= 25000){ 
  Serial.write('x');
  lcd.clear();
  lcd.print("WAIT...");
  delay(3000);
  Reset();
  }
}

void isTeacherHere(int stat, char val){
  while(stat == 1){
    if(val == 'A'){
      repeat(val);
      delay(100);
      stat--;
      checkTime(val);
      }
    else if(val == 'B'){
      repeat(val);
      delay(100);
      stat--;
      checkTime(val);
      }
    else if(val == 'C'){
      repeat(val);
      delay(100);
      stat--;
      checkTime(val);
      }
    else if(val == 'D'){
      repeat(val);
      delay(100);
      stat--;
      checkTime(val);
      }
    else{}
    }
}

void loop() {
  digitalWrite(volt1, HIGH);
  digitalWrite(volt2, HIGH);
  int but1_val = digitalRead(but1);
  int but2_val = digitalRead(but2);
  int but3_val = digitalRead(but3);
  int but4_val = digitalRead(but4);
  
  if(but1_val == 1){ //A 눌림
    lcd.begin();
    lcd.backlight();
    lcd.print("BUTTON A");
    stat++;
    prev_time=millis();
    Serial.print("1");
    isTeacherHere(stat, 'A');
    }
  else if(but2_val == 1){ //B 눌림
    lcd.begin();
    lcd.backlight();
    lcd.clear();
    lcd.print("BUTTON B");
    stat++;
    prev_time=millis();
    Serial.print("2");
    isTeacherHere(stat, 'B');
    }
  else if(but3_val == 1){ //C 눌림
    lcd.begin();
    lcd.backlight();
    lcd.clear();
    lcd.print("BUTTON C");
    stat++;
    prev_time=millis();
    Serial.print("3");
    isTeacherHere(stat, 'C');
    } 
  else if(but4_val == 1){ //D 눌림
    lcd.begin();
    lcd.backlight();
    lcd.clear();
    lcd.print("BUTTON D");
    stat++;
    prev_time=millis();
    Serial.print("4");
    isTeacherHere(stat, 'D');
    } 
  else{
    lcd.begin();
    lcd.backlight();
    lcd.print("YOU CAN USE IT");
  } //아무것도 안눌리거나 여러개 한번에 눌리거나 


}
