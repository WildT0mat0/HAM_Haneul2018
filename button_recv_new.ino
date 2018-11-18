#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD 객체 선언, 안되면 당연히 I2C 주소 0x3F로 바꿔보기

int but = 8; //버튼 D8로 설정. 필요에 따라 바꾸면 됨.
int volt1 = 9;
int volt2 = 13;
int but_stat = digitalRead(but); //버튼 입력값 0/1
int stat = 0; //상태 변수. 초기값 0. 버튼 눌리면 1로, 응닶 없으면 다시 0으로.
char ch = Serial.read(); // 시리얼 통신으로 송신부가 보내는 값

void setup(){
  pinMode(but, INPUT);
  pinMode(volt1, OUTPUT);
  pinMode(volt2, OUTPUT);
  Serial.begin(9600);
}
void (* Reset)(void)=0; //포럼에서 이러면 리셋된대요. 작년에도 이거 넣었던듯

void repeat(char val){
  for(int num=0; num++; num<20){
  Serial.write(val);
  delay(1000);
  }
}

void check(int stat){
  while(stat == 1){
    lcd.clear();
    lcd.backlight();
    lcd.print("CALLING");
      if(but_stat == 1){
      stat--;
      repeat('a'); //a, b, c, d로 교체하면 됨
      }
    }
  }


void loop() {
  digitalWrite(volt1, HIGH);
  digitalWrite(volt2, HIGH);
  int but_val = digitalRead(but);
  lcd.clear();
  lcd.noBacklight();

  while(ch != 'x'){
    if(ch == 'A'){ //A, B, C, D로 교체하면 됨
    stat++;
    check(stat); 
    } 
    else{}
  }
  Reset();
}
  
