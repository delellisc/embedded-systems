unsigned long millisANT = millis();
unsigned long millisATUAL = millis();

const int seq_size = 20;
int cor[20];

const int led_red = 2;
const int led_grn = 3;
const int led_yel = 4;
const int led_ble = 5;

const int btn_red = 6;
const int btn_grn = 7;
const int btn_yel = 8;
const int btn_ble = 9;

const int bzz_pin = 13;

void setup(){
    Serial.begin(9600);
    pinMode(led_red, OUTPUT);
    pinMode(led_grn, OUTPUT);
    pinMode(led_yel, OUTPUT);
    pinMode(led_ble, OUTPUT);
  	pinMode(bzz_pin, OUTPUT);
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

int read_btn(int btn_pin){
    millisATUAL = millis();
        while(millisATUAL - millisANT <= 10000){
            millisATUAL = millis();
            if (digitalRead(btn_pin)){
                Serial.print("ACERTOU MISERAVI");
                break;
            }
            else if(
                btn_pin != btn_red && digitalRead(btn_red) ||
                btn_pin != btn_grn && digitalRead(btn_grn) ||
                btn_pin != btn_yel && digitalRead(btn_yel) ||
                btn_pin != btn_ble && digitalRead(btn_ble)
            ){
                Serial.print("ERRROOOUUUUUUU\n");
                millisANT = millisATUAL;
                return 0;
            }
        }
    millisANT = millisATUAL;
    return 1;
}

int print_seq(int fim){
    for (int i = 0; i < fim; i++){
        Serial.print(i);
        Serial.print(": ");
        int valor = cor[i];
      	switch (valor) {
          case 2:
            tone(bzz_pin, 262, 200); // Low C - lowest pitch
            break;
          case 3:
            tone(bzz_pin, 523, 200); // Middle C - medium pitch
            break;
          case 4:
            tone(bzz_pin, 784, 200); // High G - high pitch
            break;
          case 5:
            tone(bzz_pin, 1047, 200); // Very high C - highest pitch
            break;
          default:
            tone(bzz_pin, 131, 500); // Very low C - error/default sound
            break;
        }
        digitalWrite(valor, HIGH);
        Serial.print(cor[i]);
      	Serial.print("\n");
        delay(200);
        digitalWrite(valor, LOW);
    }
    for (int i = 0; i < fim; i++){
        Serial.print(i);
        Serial.print(": ");
        int valor = cor[i];
        switch (valor) {
          case 2:
            if(!read_btn(btn_red)){
                return 0;
            }
            else{
                tone(bzz_pin, 262, 200); // Low C - lowest pitch    
            }
            break;
          case 3:
            if(!read_btn(btn_grn)){
                return 0;
            }
            else{
                tone(bzz_pin, 523, 200); // Middle C - medium pitch    
            }
            break;
          case 4:
            if(!read_btn(btn_yel)){
                return 0;
            }
            else{
                tone(bzz_pin, 784, 200); // High G - high pitch    
            }
            break;
          case 5:
            if(!read_btn(btn_ble)){
                return 0;
            }
            else{
                tone(bzz_pin, 1047, 200); // Very high C - highest pitch    
            }
            break;
          default:
            tone(bzz_pin, 131, 500); // Very low C - error/default sound
            break;
        }
        digitalWrite(valor, HIGH);
        delay(200);
        digitalWrite(valor, LOW);
        Serial.print("\n");
    }
    return 1;
}

int i = 1;

void loop(){ 
    Serial.print("\nIteration n: ");
    Serial.print(i);
    Serial.print("\n");
    ger_seq();
    for (int j = 0; j < seq_size + 1; j++){
      if(!print_seq(j)){
        return;
      }
    }
    i++;
}