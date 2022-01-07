#include <Servo.h>
Servo ss;
int val;

void setup() {
  // put your setup code here, to run once:
  ss.attach(7);
  pinMode(A0, INPUT);

  pinMode(11,INPUT);
  pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(A0);
Serial.println(val);
val = map(val,0, 1023, 0,180);
ss.write(val);
}
