#define speedL 10
#define iN1 9
#define iN2 8
#define iN3 7
#define iN4 6
#define speedR 5
#define sensorL 4
#define sensorR 3
int speedl = 70;
int speedr = 70;
int sL = 0;
int sR = 0;
void setup() 
{
 Serial.begin(9600);
 for (int i=5;i<=10;i++){
 pinMode(i,OUTPUT);
}
pinMode(sensorL,INPUT);
pinMode(sensorR,INPUT);
}
void forward()
{
 digitalWrite(iN1,HIGH);
 digitalWrite(iN2,LOW);
 digitalWrite(iN3,HIGH);
 digitalWrite(iN4,LOW);
 analogWrite(speedL,speedl);
 analogWrite(speedR,speedr);
}
void backward()
{ 
 digitalWrite(iN1,LOW);
 digitalWrite(iN2,HIGH);
 digitalWrite(iN3,LOW);
 digitalWrite(iN4,HIGH);
 analogWrite(speedL,speedl);
 analogWrite(speedR,speedr);
}
void Right()
{
 digitalWrite(iN1,HIGH);
 digitalWrite(iN2,LOW);
 digitalWrite(iN3,LOW);
 digitalWrite(iN4,LOW);
 analogWrite(speedL,speedl);
 analogWrite(speedR,0);
}
void Left()
{
 digitalWrite(iN1,LOW);
 digitalWrite(iN2,LOW);
 digitalWrite(iN3,HIGH);
 digitalWrite(iN4,LOW);
 analogWrite(speedL,0);
 analogWrite(speedR,speedr);
}
void stopp()
{
 digitalWrite(iN1,LOW);
 digitalWrite(iN2,LOW);
 digitalWrite(iN3,LOW);
 digitalWrite(iN4,LOW);
 analogWrite(speedL,LOW);
 analogWrite(speedR,LOW);
}
void loop()
{
 sL = digitalRead(sensorL);
 sR = digitalRead(sensorR);
if(sL==0 && sR==0)
{
 forward();
}
 if(sL==0 && sR==1)
{
 Right();
} 
if(sL==1 && sR==0)
{
 Left();
}
if(sL==1 && sR==1)
{
stopp();

}
Serial.println(sR);
Serial.println(sL);
// xero black 
// One White
//Sensor Right white 1023
//Sensor Right black 38
//Sensor Left white 1023
//Sensor Left black 37
}