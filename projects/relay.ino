// atribuição dos pinos
const int btn_pin = 2;
const int tst_pin = 3;

// atribuindo timestamp inicial
unsigned long millisNow = millis();
unsigned long lastMillis = millis();

// função para ler botão
void readButton(int time){
  millisNow = millis();
  if (millisNow - lastMillis >= time){
  	digitalWrite(tst_pin, !digitalRead(tst_pin));
    lastMillis = millisNow;
  }
}

// configuração incial
void setup()
{
  pinMode(btn_pin, INPUT);
  pinMode(tst_pin, OUTPUT);
  digitalWrite(btn_pin, LOW);
  digitalWrite(tst_pin, LOW);
}

// loop principal
void loop()
{
  if (digitalRead(btn_pin)){
    readButton(200); // duplo clique no intervalo de 200ms é considerado como um único clique
  }
}