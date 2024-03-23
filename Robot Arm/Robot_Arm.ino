#include <Servo.h>  
#include <LiquidCrystal_I2C.h>  
  
#define RV1 A0  
#define RV2 A1  
#define RV3 A2  
#define RV4 A3  
  
int pos1, servo1Pos;  
int pos2, servo2Pos;  
int pos3, servo3Pos;  
int pos4, servo4Pos;  
  
Servo servo1;  
Servo servo2;  
Servo servo3;  
Servo servo4;  
  
LiquidCrystal_I2C lcd(0x27, 16, 4);  
  
void setup() {  
  pinMode(RV1, INPUT);  
  pinMode(RV2, INPUT);  
  pinMode(RV3, INPUT);  
  pinMode(RV4, INPUT);  
  
  servo1.attach(7);  
  servo2.attach(6);  
  servo3.attach(5);  
  servo4.attach(4);  
  
  servo1.write(90);  
  servo2.write(90);  
  servo3.write(90);  
  servo4.write(90);  
  
  lcd.init();  
  lcd.clear();  
  lcd.setCursor(3, 0);  
  lcd.print("WELCOME TO");  
  lcd.setCursor(0, 1);  
  lcd.print("RobotArm Control");  
  lcd.setCursor(1, 2);  
  lcd.print("PROJECT");  
  delay(2000);  
  lcd.clear();  
}  
  
void loop() {  
  pos1 = analogRead(RV1);  
  servo1Pos = map(pos1, 0, 1023, 0, 180);  
  servo1.write(servo1Pos);  
  lcd.setCursor(0, 0);  
  lcd.print("SERVO1:");    
  lcd.setCursor(8, 0);  
  lcd.print(servo1Pos);  
  lcd.print(" ");  
  
  pos2 = analogRead(RV2);  
  servo2Pos = map(pos2, 0, 1023, 0, 180);  
  servo2.write(servo2Pos);  
  lcd.setCursor(0, 1);  
  lcd.print("SERVO2:");   
  lcd.setCursor(8, 1);  
  lcd.print(servo2Pos);  
  lcd.print(" ");  
  
  pos3 = analogRead(RV3);  
  servo3Pos = map(pos3, 0, 1023, 0, 180);  
  servo3.write(servo3Pos);  
  lcd.setCursor(0, 2);  
  lcd.print("SERVO3:");   
  lcd.setCursor(8, 2);   
  lcd.print(servo3Pos);  
  lcd.print(" ");  
  
  pos4 = analogRead(RV4);  
  servo4Pos = map(pos4, 0, 1023, 0, 180);  
  servo4.write(servo4Pos);  
  lcd.setCursor(0, 3);  
  lcd.print("SERVO4:");   
  lcd.setCursor(8, 3);  
  lcd.print(servo4Pos);  
  lcd.print(" ");  
  
  delay(10); 
}
