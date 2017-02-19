
void setup() {
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void Leader(){
  digitalWrite(13, HIGH);
  digitalWrite(3, HIGH);
  delay(9);
  digitalWrite(3, LOW);
  delayMicroseconds(4500);
}

void One() {
  digitalWrite(3, HIGH);
  delayMicroseconds(562);
  digitalWrite(3, LOW);
  delayMicroseconds(1687);
}

void Zero() {
  digitalWrite(3, HIGH);
  delayMicroseconds(562);
  digitalWrite(3, LOW);
  delayMicroseconds(562);
}

void Stop() {
  digitalWrite(3, HIGH);
  delayMicroseconds(562);
  digitalWrite(3, LOW);
  digitalWrite(13, LOW);
}

void SendAddress() {
  Zero();
  Zero();
  Zero();
  Zero();
  Zero();
  Zero();
  Zero();
  Zero();
  One();
  One();
  One();
  One();
  One();
  One();
  One();
  One();
}

void SetInput1() {
  Leader();
  SendAddress();
  Zero();
  Zero();
  One();
  Zero();
  Zero();
  Zero();
  Zero();
  Zero();
  One();
  One();
  Zero();
  One();
  One();
  One();
  One();
  One();
  Stop();
}

void SetInput2() {
  Leader();
  SendAddress();
  Zero();
  Zero();
  Zero();
  One();
  Zero();
  Zero();
  Zero();
  Zero();
  One();
  One();
  One();
  Zero();
  One();
  One();
  One();
  One();
  Stop();
}

void SetInput3() {
  Leader();
  SendAddress();
  Zero();
  One();
  Zero();
  One();
  Zero();
  Zero();
  Zero();
  Zero();
  One();
  Zero();
  One();
  Zero();
  One();
  One();
  One();
  One();
  Stop();
}

void loop() {
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '1')
      SetInput1();
    else if (inChar == '2')
      SetInput2();
    else if (inChar == '3')
      SetInput3();
  Serial.print(inChar);
  }
}


