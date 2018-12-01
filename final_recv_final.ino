#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD 객체 선언, 안되면 당연히 I2C 주소 0x3F로 바꿔보기

int but = 10; //버튼 D10로 설정. 필요에 따라 바꾸면 됨.
int volt1 = 9;
int volt2 = 13;

void setup() {
  pinMode(but, INPUT);
  pinMode(volt1, OUTPUT);
  pinMode(volt2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(volt1, HIGH);
  digitalWrite(volt2, HIGH);
  int but_val = digitalRead(but);
   lcd.begin();
   lcd.backlight();
   lcd.print("Have a good day!");
    char ch = Serial.read(); //계속적으로 문자를 읽어들인다
 
  
      if(ch == 'A') { //'H'를 읽을 경우 LED을 ON 시킨다
        Serial.print(ch);
        lcd.clear();
        lcd.print("STUD_CALLING");
        delay(100);
        lcd.blink();
        delay(50); 
         
          }
        if( digitalRead(10) == HIGH){
          Serial.write('a');
          lcd.noBacklight();
          lcd.noBlink();
          lcd.clear();
           delay(1000);
          }
}
  

