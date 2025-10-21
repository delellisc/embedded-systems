unsigned long millisANT = millis();
unsigned long millisATUAL = millis();

int seq_size = 20;
int cor[20];

int led_red = 2;
int led_grn = 3;
int led_yel = 4;
int led_ble = 5;

int btn_red = 6;
int btn_grn = 7;
int btn_yel = 8;
int btn_ble = 9;

void setup(){
  Serial.begin(9600);
  pinMode(led_red, OUTPUT);
  pinMode(led_grn, OUTPUT);
  pinMode(led_yel, OUTPUT);
  pinMode(led_ble, OUTPUT);
  pinMode(btn_red, INPUT);
  pinMode(btn_grn, INPUT);
  pinMode(btn_yel, INPUT);
  pinMode(btn_ble, INPUT);
}

void ger_seq(){
  for (int i = 0; i < seq_size; i++){
    cor[i] = random(2,6);
  }
}

/*

void blink(int tempo){
  millisATUAL = millis();
  Serial.println(millisATUAL);
  if(millisATUAL - millisANT >= tempo){
    estado_LED = !estado_LED;
    digitalWrite(pin_LED, estado_LED);
    millisANT = millisATUAL;
  }
}

*/

/*
void read_btn(int btn_pin, int tempo){
  millisATUAL = millis();
   if(millisATUAL - millisANT >= tempo){
     if (digitalRead(btn_pin)){
     	return 1;
     }
     millisANT = millisATUAL;
  }
}
*/

int read_btn(int btn_pin, int tempo){
  millisATUAL = millis();
  while(millisATUAL - millisANT >= tempo){
    millisATUAL = millis();
    if (digitalRead(btn_pin)){
      millisANT = millisATUAL;
      return 1;
    }
  }
  millisANT = millisATUAL;
  return 0;
}

void read_btn_red(){
    millisATUAL = millis();
        while(millisATUAL - millisANT <= 10000){
            if (digitalRead(btn_red)){
                Serial.print("Red");
                break;
            }
        }
    millisANT = millisATUAL;
}

void read_btn_grn(){
    millisATUAL = millis();
        while(millisATUAL - millisANT <= 10000){
            if (digitalRead(btn_grn)){
                Serial.print("Green");
                break;
            }
        }
    millisANT = millisATUAL;
}

void read_btn_yel(){
    millisATUAL = millis();
        while(millisATUAL - millisANT <= 10000){
            if (digitalRead(btn_yel)){
                Serial.print("Yellow");
                break;
            }
        }
    millisANT = millisATUAL;
}

void read_btn_ble(){
    millisATUAL = millis();
        while(millisATUAL - millisANT <= 10000){
            if (digitalRead(btn_ble)){
                Serial.print("Blue");
                break;
            }
        }
    millisANT = millisATUAL;
}

void print_seq(int fim){
  for (int i = 0; i < fim; i++){
    Serial.print(i);
    Serial.print(": ");
    int valor = cor[i];
    switch (valor) {
      case 2:
        read_btn_red();
        break;
      case 3:
        read_btn_grn();
        break;
      case 4:
        read_btn_yel();
        break;
      case 5:
        read_btn_ble();
        break;
      default:
        break;
    }
    digitalWrite(valor, HIGH);
    //Serial.print(cor[i]);
    delay(500);
    digitalWrite(valor, LOW);
    Serial.print("\n");
  }
}

int i = 1;

void loop(){ 
  Serial.print("\nIteration n: ");
  Serial.print(i);
  Serial.print("\n");
  ger_seq();
  for (int j = 0; j < seq_size + 1; j++){
    print_seq(j);
  }
  i++;
}