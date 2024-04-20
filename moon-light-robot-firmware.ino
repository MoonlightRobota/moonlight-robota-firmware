#define PWMB 9
#define BIN2 8
#define BIN1 7
#define AIN1 4
#define AIN2 5
#define PWMA 6
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial started...");

  pinMode(PWMB, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(A0, OUTPUT);
  buzzer(1);
  pinMode(12, INPUT_PULLUP);
  while (digitalRead(12) != 0);
  Serial.println("Started...");
  buzzer(2);
  motor(255,255);
  delay(2000);
  motor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
void buzzer(int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(A0, 1);
    delay(50);
    digitalWrite(A0, 0);
    delay(50);
  }
}
void motor(int pwma, int pwmb) {

  analogWrite(PWMA, abs(pwma));
  analogWrite(PWMB, abs(pwmb));
  if (pwma < 0) {
    digitalWrite(AIN1, 0);
    digitalWrite(AIN2, 1);
  } else if (pwma > 0) {
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 0);

  } else {
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 1);
  }
  if (pwmb > 0) {
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 1);
  } else if (pwmb < 0) {
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 0);

  } else {
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 1);
  }
}