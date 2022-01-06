int oldp;
int oldq;
int count;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  Serial.println("count is");
}

void loop() {
  // put your main code here, to run repeatedly:
  int p = digitalRead(6);
  
  int q = digitalRead(7);
  if (p == 0 && oldp == 1) {
    Serial.println("count is "+ String(count++));
  }
  if (q == 0 && oldq == 1) {
    Serial.println("count is "+String(count--));
  }
  oldp = p;
  oldq = q;
}
