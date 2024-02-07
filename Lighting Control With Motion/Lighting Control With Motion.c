#define trigPin 12
 #define echoPin 11
 long duration, distance;
 void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(3, OUTPUT);
 }
 void loop() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) * 0.0343;
 Serial.println(distance);
 delay(5);
if(distance<=20){
 digitalWrite(3,1);
 delay(4000);
 digitalWrite(3,0);
 }}