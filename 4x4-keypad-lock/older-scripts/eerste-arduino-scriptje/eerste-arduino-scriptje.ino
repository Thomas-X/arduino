const int led1 = 13; // pin 13 digital
const int led2 = 12; // pin 13 digital

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void switchVoltage () {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(300);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
    switchVoltage();
}
