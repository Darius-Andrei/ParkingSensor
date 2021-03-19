#define trigpin 11  
#define echopin 12
#define clock 10 
#define latch 9
#define data 8 
#define buzzer 5 
int range; 
long Time;
byte leds[]={0b10000000, 
0b11000000,
0b11100000,
0b11110000,
0b11111000,
0b11111100,
0b11111110,
0b11111111,
0b00000000 }; 
void setup()
{
  pinMode(trigpin, OUTPUT); 
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
  Time = pulseIn(echopin, HIGH);
  range = Time*0.034/2;
  Serial.print("Distance: ");
  Serial.println(range);
  if(range>=141){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[7]);
  digitalWrite(latch,HIGH);
  }
  if(range>=121&&range<=140){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[6]);
  digitalWrite(latch,HIGH);
    bzzr(1000);
  }
  if(range>=101&&range<=120){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[5]);
  digitalWrite(latch,HIGH);    
    bzzr(700);
  }
  if(range>=81&&range<=100){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[4]);
  digitalWrite(latch,HIGH); 
    bzzr(500);
  }
  if(range>=61&&range<=80){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[3]);
  digitalWrite(latch,HIGH); 
    bzzr(300);
  }
  if(range>=41&&range<=60){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[2]);
  digitalWrite(latch,HIGH);
    bzzr(200);
  }
  if(range>=21&&range<=40){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[1]);
  digitalWrite(latch,HIGH); 
    bzzr(100);
  }
  if(range>=11&&range<=20){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[0]);
  digitalWrite(latch,HIGH);
    bzzr(50);
  }
  if(range>=0&&range<=10){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,leds[8]);
  digitalWrite(latch,HIGH);
    bzzr(1);
  }
 }
void bzzr(int speed){
  digitalWrite(buzzer, LOW);
  static unsigned long time=millis();
  if(millis()-time >=speed){
  time=millis();
  digitalWrite(buzzer, HIGH);
      }
  }
