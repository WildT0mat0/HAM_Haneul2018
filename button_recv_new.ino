#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD 객체 선언, 안되면 당연히 I2C 주소 0x3F로 바꿔보기

int but = 8; //버튼 D8로 설정. 필요에 따라 바꾸면 됨.
int volt = 9; //혹시 몰라서 전원 D9로 빼놓을라고 설정함. 필요없으면 말고
int stat = 0; //상태 변수. 초기값 0. 버튼 눌리면 1로, 응닶 없으면 다시 0으로.
char ch = Serial.read(); // 시리얼 통신으로 송신부가 보내는 값

void setup(){
  pinMode(but, INPUT);
  pinMode(volt, OUTPUT);
  Serial.begin(9600);
}
void (* Reset)(void)=0; //포럼에서 이러면 리셋된대요. 작년에도 이거 넣었던듯

void check(int stat, char ch){
  while(stat == 1){
    if(ch == 'A'){
      Serial.write('a');
      delay(100);
      }
    else if(ch == 'B'){
      Serial.write('b');
      delay(100);
      }
    else if(ch == 'C'){
      Serial.write('c');
      delay(100);
      }
    else if(ch == 'D'){
      Serial.write('d');
      delay(100);
      }
    else{}
  }
}

void loop() {
  digitalWrite(volt, HIGH);
  int but_val = digitalRead(but);
  lcd.clear();
  lcd.noBacklight();

  while(ch != 'x'){
    if(ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd'){
    stat++;
    check(stat, ch); 
    } 
    else{}
  }
  Reset();
}
  
