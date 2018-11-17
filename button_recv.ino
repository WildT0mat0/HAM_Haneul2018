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

void check(int stat){
  if(stat == 1){
    lcd.clear();
    lcd.backlight();
    lcd.print("ANSWERED");
    stat--;
  }
}

void loop() {
  digitalWrite(volt, HIGH);
  int but_val = digitalRead(but);
  
    if(ch == 'A'){
      
      lcd.begin();
      lcd.backlight();
      lcd.print("QUESTION!");
      stat++;
      
      if(but_val == 1){
        Serial.write('a');
        while(ch != 'x'){  
        check(stat); //20초 전에 버튼 누르면 답이 간다.
        }
        Reset(); //20초가 넘으면 강제리셋
      }
      else {
        lcd.print("PUSH ME!");
        if(ch == 'x'){
          Reset(); //버튼 안눌렸는데 20초 넘으면 강제리셋
          }
        }
    }
    else {} 
}
  
  
