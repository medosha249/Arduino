#define speedL 10
#define iN1 9
#define iN2 8
#define iN3 7
#define iN4 6
#define speedR 5
#define trig A1
#define echo A2
int speedr = 100;
int speedl = 100;
float dur,dis;
void setup() 
{
 Serial.begin(9600);
 for (int i=5;i<=10;i++){
 pinMode(i,OUTPUT);
}
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
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
  analogWrite(speedL,0);
 analogWrite(speedR,0);

}
void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur= pulseIn(echo, HIGH);
  dis = (dur/2)*0.0343;
  delay(500);
if (dis<45)
{
 stopp(); delay(250);
 backward(); delay(500);
 Right(); delay(1000);
} 
if(dis>45){forward();}
Serial.print("distance: ");
  Serial.print(dis);
  Serial.println(" cm");
}