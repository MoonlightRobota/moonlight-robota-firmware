#define PWMB 9
#define BIN2 8
#define BIN1 7
#define STBY 6
#define AIN1 5
#define AIN2 4
#define PWMA 3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Serial started...");

  pinMode(PWMB, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(A0, OUTPUT);
  buzzer(1);
  do {
    digitalWrite(STBY, 1);

    car();

  } while (digitalRead(2) != LOW);
  digitalWrite(STBY, 1);

  Serial.println("Started...");
  buzzer(2);
  //   motor(255, 255);
  //   delay(2000);
  //   motor(0, 0);




  motor(-255, 255);
  delay(1000);
  motor(0, 0);
  delay(2000);
  motor(255, -255);
  delay(1000);

  motor(0, 0);

  // delay(2500);
  // motor(-155, -155);
  // motor(-255, -255);
  // delay(1500);
  // motor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
}
void checkFront() {
  delay(1000);
  motor(255, 255);
  delay(2000);
  motor(0, 0);
  delay(5000);
  motor(-255, -255);
  delay(2000);
  motor(0, 0);
  delay(2000);
}
void checkRight() {
  delay(500);
  motor(-255, 255);
  delay(500);
  motor(0, 0);
  delay(2000);
  motor(255, -255);
  delay(600);
  motor(0, 0);
  delay(2000);
}
void car() {
  if (Serial.available() > 0) {
    char move = Serial.read();
    // Serial.println(move);
    motor(0, 0);
    switch (move) {
      case 'F':
        delay(500);
        motor(255, 255);
        delay(1000);
        motor(0, 0);
        delay(2500);

        break;
      case 'R':
        delay(500);
        motor(-255, 255);
        delay(500);
        motor(0, 0);
        delay(2500);
    
        break;
      case 'L':
        delay(500);
        motor(255, -255);
        delay(500);
        motor(0, 0);
        delay(2500);
     
        break;
    }
  }
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
  }
  if (pwmb > 0) {
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 1);
  } else if (pwmb < 0) {
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 0);
  }
}