// C++ code
//

// Atribuição dos pinos
const int l_grn = 2;
const int l_red = 3;
const int bomba = 4;
const int sen_1 = 5; // L1 = A
const int sen_2 = 6; // L2 = C'
const int sen_3 = 7; // L3 = A'B'

// Configuração de entrada e saída
void setup()
{
  pinMode(l_grn, OUTPUT);
  pinMode(l_red, OUTPUT);
  pinMode(bomba, OUTPUT);
  pinMode(sen_1, INPUT);
  pinMode(sen_2, INPUT);
  pinMode(sen_3, INPUT);
  digitalWrite(l_grn, LOW);
  digitalWrite(l_red, LOW);
  digitalWrite(bomba, LOW);
}

// Lógica do circuito
void loop()
{
  int sen1_val = digitalRead(sen_1);
  int sen2_val = digitalRead(sen_2);
  int sen3_val = digitalRead(sen_3);
  
  // B = L3 = A'B'
  digitalWrite(bomba, !sen3_val && !sen1_val);
  // L1 = A
  digitalWrite(l_grn, sen1_val);
  // L2 = C'
  digitalWrite(l_red, !sen2_val);

  delay(500);
}