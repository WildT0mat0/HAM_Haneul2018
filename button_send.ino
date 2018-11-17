#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD 객체 선언, 안되면 당연히 I2C 주소 0x3F로 바꿔보기

int but = 8; //버튼 D8로 설정. 필요에 따라 바꾸면 됨.
int volt = 9; //혹시 몰라서 전원 D9로 빼놓을라고 설정함. 필요없으면 말고
int stat = 0; //상태 변수. 초기값 0, 버튼 눌리면 1로. 응답 없으면 다시 0으로.
unsigned long prev_time, cur_time = 0; //시간 값. 초기값 0
char ch = Serial.read(); // 시리얼 통신으로 수신부가 보내는 값


void setup() {
  pinMode(but, INPUT);
  pinMode(volt, OUTPUT);
  Serial.begin(9600);
}

/*void checkTime(){
  return millis();
  }
*/

void (* Reset)(void)=0; //포럼에서 이러면 리셋된대요. 작년에도 이거 넣었던듯

void isTeacherHere(int stat){
  if(stat == 1){
    Serial.write('A'); //버튼 누르면 A 보내기
    cur_time = millis();
    
    while(prev_time - cur_time < 20000){ // 20000ms = 20s
      lcd.clear();
      lcd.backlight();
      lcd.print("WAITING...");
      if(ch == 'a'){ //수신부가 응답시 a를 보냄
        lcd.clear();
        lcd.backlight();
        lcd.print("TEACHER HERE!");
        stat--;
        delay(10000);
        lcd.clear();
        lcd.noBacklight();
        
        }
      else{}
      } //20초 끝나면 while 탈출, 밑에서 무응답 메시지 출력.
    lcd.clear();
    lcd.backlight();
    lcd.print("NO TEACHER!");
    lcd.noBacklight();
    stat--;
    Serial.write('x');
    Reset(); //리셋하는 함수 호출
  }
  
  else if(stat != 1){ //이거 뜨면 큰일남. 아무것도 안뜨는 것보다 큰일남.
    lcd.clear();
    lcd.backlight();
    lcd.print("ERROR");
    }
  }


  
void loop() {
  digitalWrite(volt, HIGH);
  int but_val = digitalRead(but);
  
  if(but_val == HIGH){
    lcd.begin();
    lcd.backlight();
    lcd.print("BUTTON PUSHED");
    stat++;
    prev_time = millis();
    isTeacherHere(stat);
  }
  
  else{}
}
