#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); 

int but1 = 40;
int but2 = 41;
int but3 = 42; 
int but4 = 43; 
int but5 = 50;

int v = 30;
int gnd = 31;

int volt1 = 13; //전원 1번
int volt2 = 53; //전원 2번
int stat = 0;

void setup(){
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  pinMode(but4, INPUT);
  pinMode(but5, INPUT);
  pinMode(volt1, OUTPUT);
  pinMode(volt2, OUTPUT);
  pinMode(v, OUTPUT);
  pinMode(gnd, OUTPUT);
  Serial.begin(9600);
  }

void (* Reset)(void) = 0;

void loop(){

  digitalWrite(volt1, HIGH);
  digitalWrite(volt2, HIGH);
  digitalWrite(v, HIGH);
  digitalWrite(gnd, LOW);
  int but1_val = digitalRead(but1);
  int but2_val = digitalRead(but2);
  int but3_val = digitalRead(but3);
  int but4_val = digitalRead(but4);
  int but5_val = digitalRead(but5);

  lcd.begin();
  lcd.clear();
  lcd.backlight();
  lcd.print("PUSH ME");
  delay(500);
  lcd.clear();
  
  if(but1_val == 1){     
      stat++;
bailout1:
          if(stat == 1){
               Serial.write("A");
                delay(1000);
                lcd.clear();
                lcd.backlight();
                lcd.print("WAIT FOR A...");      
                char ch = Serial.read();
                          if(ch == 'a'){
                             Serial.print(ch);
                             lcd.begin();
                             lcd.clear();
                             lcd.backlight();
                             lcd.print("TEACHER A HERE");
                             delay(5000);
                             lcd.clear();
                              stat--;
                              Reset();   
                           }
                           if(but5_val == 1){
                            //Reset();
                            }
                           else{
                              goto bailout1;
                             }  
                         }
                   }
                   
  if(but2_val == 1){     
      stat++;
bailout2:
          if(stat == 1){
               Serial.write("B");
                delay(1000);
                lcd.clear();
                lcd.backlight();
                lcd.print("WAIT FOR B...");      
                char ch = Serial.read();
                          if(ch == 'b'){
                             Serial.print(ch);
                             lcd.begin();
                             lcd.clear();
                             lcd.backlight();
                             lcd.print("TEACHER B HERE");
                             delay(5000);
                             lcd.clear();
                              stat--;
                              Reset();   
                           }
                           if(but5_val == 1){
                            //Reset();
                            }
                           else{
                              goto bailout2;
                             }  
                         }
                   }
                   

                   
    else if(but3_val == 1){     
      stat++;
bailout3:
          if(stat == 1){
               Serial.write("C");
                delay(1000);
                lcd.clear();
                lcd.backlight();
                lcd.print("WAIT FOR C...");       
                char ch = Serial.read();
                          if(ch == 'c'){
                             Serial.print(ch);
                             lcd.begin();
                             lcd.clear();
                             lcd.backlight();
                             lcd.print("TEACHER C HERE");
                             delay(5000);
                             lcd.clear();
                              stat--;   
                              Reset();
                           }
                           if(but5_val == 1){
                            //Reset();
                            }
                           else{
                              goto bailout3;
                             }  
                         }
                   }
                   
   else if(but4_val == 1){     
      stat++;
bailout4:
          if(stat == 1){
               Serial.write("D");
                delay(1000);
                lcd.clear();
                lcd.backlight();
                lcd.print("WAIT FOR D...");       
                char ch = Serial.read();
                          if(ch == 'd'){
                             Serial.print(ch);
                             lcd.begin();
                             lcd.clear();
                             lcd.backlight();
                             lcd.print("TEACHER D HERE");
                             delay(5000);
                             lcd.clear();
                              stat--;   
                              Reset();
                           }
                           if(but5_val == 1){
                            //Reset();
                            }
                           else{
                              goto bailout4;
                             }  
                    }
          }
}
