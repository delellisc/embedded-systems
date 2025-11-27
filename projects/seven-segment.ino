// Available at https://wokwi.com/projects/448792856600842241

const int a2 = 9;
const int b2 = 8;
const int c2 = 7;
const int d2 = 6;
const int e2 = 5;
const int f2 = 4;
const int g2 = 3;
const int dp2 = 2;
int digit_pins[8] = {a2, b2, c2, d2, e2, f2, g2, dp2};
int zero[6] = {a2, b2, c2, d2, e2, f2};
int one[2] = {b2, c2};
int two[5] = {a2, b2, g2, e2, d2};

void turn_off_segments(){
  for(int i = 0; i < 8; i++){
    pinMode(digit_pins[i], LOW);
  }
}

void setup() {
  for(int i = 0; i < 8; i++){
    pinMode(digit_pins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 6; i++){
    digitalWrite(zero[i], HIGH);
  }
  delay(1000);
  turn_off_segments();
  for(int i = 0; i < 2; i++){
    digitalWrite(one[i], HIGH);
  }
  delay(1000);
  turn_off_segments();
  for(int i = 0; i < 5; i++){
    digitalWrite(two[i], HIGH);
  }
  delay(1000);
  turn_off_segments();
}