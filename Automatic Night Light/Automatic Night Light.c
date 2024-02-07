 #define ldr A0
 #define led 3
 int threshold = 40;
 int level;
 void setup() {
 Serial.begin(9600);
 pinMode(led, OUTPUT);
 }
 void loop() {
 level = analogRead(ldr);
 Serial.println(level);
 if (level < threshold) { digitalWrite(led, 1); }
 else { digitalWrite(led, 0);}
 }

