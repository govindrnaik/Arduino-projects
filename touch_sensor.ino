
#include<Servo.h>
Servo servo;
void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
  servo.attach(3);
}
void loop() {
  if (digitalRead(2) == HIGH) {
    Serial.println("Sensor is touched & door opened");
    servo.write(180);
    delay(500);
  } else {
    servo.write(0);
    delay(500);
  }
}
