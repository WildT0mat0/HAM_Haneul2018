#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD 객체 선언, 안되면 당연히 I2C 주소 0x3F로 바꿔보기

int but1 = 5;
int but2 = 6;
int but3 = 7; 
int but4 = 8; //버튼 D5~D8로 설정. 필요에 따라 바꾸면 됨.
int volt = 9; //혹시 몰라서 전원 D9로 빼놓을라고 설정함. 필요없으면 말고
int stat = 0; //상태 변수. 초기값 0, 버튼 눌리면 1로. 응답 없으면 다시 0으로.
unsigned long prev_time, cur_time = 0; //시간 값. 초기값 0
char ch = Serial.read(); // 시리얼 통신으로 수신부가 보내는 값
char val; // 입력하는 버튼에 따라 달리하기, A/B/C/D 총 4종류


void setup() {
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  pinMode(but4, INPUT);
  pinMode(volt, OUTPUT);
  Serial.begin(9600);
}

void (* Reset)(void) = 0;

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
  Reset();
  }
}

void isTeacherHere(int stat, char val){
  while(stat == 1){
    if(val == 'A'){
      Serial.write(val);
      delay(100);
      stat--;
      checkTime(val);
      }
    else if(val == 'B'){
      Serial.write(val);
      delay(100);
      stat--;
      checkTime(val);
      }
    else if(val == 'C'){
      Serial.write(val);
      delay(100);
      stat--;
      checkTime(val);
      }
    else if(val == 'D'){
      Serial.write(val);
      delay(100);
      stat--;
      checkTime(val);
      }
    else{}
    }
}

void loop() {
  digitalWrite(volt, HIGH);
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
    isTeacherHere(stat, 'A');
    }
  else if(but2_val == 1){ //B 눌림
    lcd.begin();
    lcd.backlight();
    lcd.print("BUTTON B");
    stat++;
    prev_time=millis();
    isTeacherHere(stat, 'B');
    }
  else if(but3_val == 1){ //C 눌림
    lcd.begin();
    lcd.backlight();
    lcd.print("BUTTON C");
    stat++;
    prev_time=millis();
    isTeacherHere(stat, 'C');
    } 
  else if(but4_val == 1){ //D 눌림
    lcd.begin();
    lcd.backlight();
    lcd.print("BUTTON D");
    stat++;
    prev_time=millis();
    isTeacherHere(stat, 'D');
    } 
  else{} //아무것도 안눌리거나 여러개 한번에 눌리거나 


}
