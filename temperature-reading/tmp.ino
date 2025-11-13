// Atribuição dos pinos
const int temperature_sensor = A0;
const int fan = 4;
int last_state = 0;

// Configuração de entrada e saída
void setup()
{
  Serial.begin(9600);
  pinMode(temperature_sensor, INPUT);
  pinMode(fan, OUTPUT);
  digitalWrite(fan, LOW);
}

float convert_celsius(int milivolts)
{
  // (((20 / 1023) * 5) - 0,5) * 100
  // 20 -> -40ºC
  // 51 -> -25ºC
  // 104 -> 0ºC
  // 155 -> 25ºC
  // 205 -> 50ºC
  // 256 -> 75ºC
  // 307 -> 100ºC
  // 358 -> 125ºC
  // return (milivolts/2) - 50;
  // Serial.println(milivolts);
  // Serial.println(float(milivolts) / 1023);
  // Serial.println((float(milivolts) / 1023) * 5);
  // Serial.println(((float(milivolts) / 1023) * 5) - 0.5);
  // Serial.println((((float(milivolts) / 1023) * 5) - 0.5) * 100);
  return (((float(milivolts) / 1023) * 5) - 0.5) * 100;
}

void change_circuit_state(int fan_state)
{
  if(fan_state){
    Serial.println("LIGOU");
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }
  else{
    Serial.println("DESLIGOU");
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  }
}

// Lógica do circuito
void loop()
{
  int sensor_voltage = analogRead(temperature_sensor);
  float celsius_temperature = convert_celsius(sensor_voltage);
  int fan_state = celsius_temperature > 40;
  Serial.println(sensor_voltage);
  Serial.println(celsius_temperature);
  if(fan_state != last_state){
   digitalWrite(fan, fan_state);
   change_circuit_state(fan_state);
   last_state = fan_state;
  }
  delay(1000);
}