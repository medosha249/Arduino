const int red = 13;
 char reading; // data type used to store a character value.
 void setup( )
 {
 }
 pinMode(red, OUTPUT);
 Serial.begin(9600);
 void loop( ) {
 if(Serial.available()>0) {
 reading=Serial.read();
 switch(reading){
 case 'F': digitalWrite(red,1);
 break;
 case 'S': digitalWrite(red,0);
 break;
 }
 }
 }
