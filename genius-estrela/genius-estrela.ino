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


void print_seq(int fim){
  for (int i = 0; i < fim; i++){
    Serial.print(i);
    Serial.print(": ");
    int valor = cor[i];
    switch (valor) {
      case 2:
        Serial.print("Red");
        break;
      case 3:
        Serial.print("Green");
        break;
      case 4:
        Serial.print("Yellow");
        break;
      case 5:
        Serial.print("Blue");
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