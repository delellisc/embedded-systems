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

const int bzz_pin = 10;

#define red_sound 262
#define grn_sound 523
#define yel_sound 784
#define ble_sound 1047

void setup(){
    Serial.begin(9600);
    pinMode(led_red, OUTPUT);
    pinMode(led_grn, OUTPUT);
    pinMode(led_yel, OUTPUT);
    pinMode(led_ble, OUTPUT);
  	pinMode(bzz_pin, OUTPUT);
  	digitalWrite(bzz_pin, LOW);
    pinMode(btn_red, INPUT);
    pinMode(btn_grn, INPUT);
    pinMode(btn_yel, INPUT);
    pinMode(btn_ble, INPUT);
}

void init_sound() {
  const int melody[] = {494, 440, 349, 392, 587, 523};
  const int duration = 150;

  for (int i = 0; i < 6; i++) {
    tone(bzz_pin, melody[i], duration);
    delay(duration * 1.3);
  }

  noTone(bzz_pin);
}

void loss_sound() {
  const int melody[] = {
    494, 440, 330, 440, 523, 587,
    440, 523, 494, 523, 587, 392, 659
  };

  const int durations[] = {
    125, 125, 1000, 250, 250, 500,
    2000, 1000, 250, 250, 250, 250, 1000
  };

  const int numNotes = 13;

  for (int i = 0; i < numNotes; i++) {
    tone(bzz_pin, melody[i], durations[i]);
    delay(durations[i] * 1.3);
  }

  noTone(bzz_pin);
}

void ger_seq(){
  	randomSeed(analogRead(0));
    for (int i = 0; i < seq_size; i++){
        cor[i] = random(2,6);
    }
}

int read_btn(int btn_pin){
    millisATUAL = millis();
        while(millisATUAL - millisANT <= 10000){
            millisATUAL = millis();
            if (digitalRead(btn_pin)){
                Serial.print("ACERTO");
                return 1;
            }
            else if(
                btn_pin != btn_red && digitalRead(btn_red) ||
                btn_pin != btn_grn && digitalRead(btn_grn) ||
                btn_pin != btn_yel && digitalRead(btn_yel) ||
                btn_pin != btn_ble && digitalRead(btn_ble)
            ){
                Serial.print("ERRO\n");
                return 0;
            }
        }
    return 0;
}

int print_seq(int fim){
    for (int i = 0; i < fim; i++){
        Serial.print(i);
        Serial.print(": ");
        int valor = cor[i];
      	switch (valor) {
          case 2:
            tone(bzz_pin, red_sound, 200);
            break;
          case 3:
            tone(bzz_pin, grn_sound, 200);
            break;
          case 4:
            tone(bzz_pin, yel_sound, 200);
            break;
          case 5:
            tone(bzz_pin, ble_sound, 200);
            break;
          default:
            tone(bzz_pin, 131, 500);
            break;
        }
        digitalWrite(valor, HIGH);
      	delay(200);
        Serial.print(cor[i]);
      	Serial.print("\n");
        digitalWrite(valor, LOW);
      	delay(200);
    }
    for (int i = 0; i < fim; i++){
        Serial.print(i);
        Serial.print(": ");
        int valor = cor[i];
      	millisANT = millis();
        switch (valor) {
          case 2:
            if(!read_btn(btn_red)){
                return 0;
            }
            else{
                tone(bzz_pin, red_sound, 200);
            }
            break;
          case 3:
            if(!read_btn(btn_grn)){
                return 0;
            }
            else{
                tone(bzz_pin, grn_sound, 200);
            }
            break;
          case 4:
            if(!read_btn(btn_yel)){
                return 0;
            }
            else{
                tone(bzz_pin, yel_sound, 200);
            }
            break;
          case 5:
            if(!read_btn(btn_ble)){
                return 0;
            }
            else{
                tone(bzz_pin, ble_sound, 200);
            }
            break;
          default:
            tone(bzz_pin, 131, 500);
            break;
        }
        digitalWrite(valor, HIGH);
        delay(200);
        digitalWrite(valor, LOW);
      	delay(200);
        Serial.print("\n");
    }
    return 1;
}

int i = 1;

void loop(){ 
    Serial.print("\nLoop n: ");
    Serial.print(i);
    Serial.print("\n");
    ger_seq();
  	init_sound();
  	delay(500);
    for (int j = 0; j < seq_size + 1; j++){
      if(!print_seq(j)){
        loss_sound();
        delay(1000);
        return;
      }
    }
    i++;
}