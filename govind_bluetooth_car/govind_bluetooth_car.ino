char D;

void setup() {
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission

  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)  
  {
  D = Serial.read();
  if (D == 'f')
  {
    //  forword
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    

  } if (D == 'b')
  {
    //  reverse
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  } if (D == 'l')
  {

    //  left
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  } if (D == 'f')
  {

    //  right
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
delay (1000);
  }






}
