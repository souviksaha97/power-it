void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage = (analogRead(A0)*5)/1024.0*6.7;
  float current = ((analogRead(A1)*5)/1024.0)/2.7;
  Serial.print(voltage);
  Serial.print("\t");
  Serial.println(current);
  delay(100);
  
}
