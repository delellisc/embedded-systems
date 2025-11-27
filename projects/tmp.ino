// Atribuição dos pinos
const int temperature_sensor = A0;
const int fan = 4;
int last_state = 0;
int green_led = 2;
int red_led = 3;

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
  return (((float(milivolts) / 1023) * 5) - 0.5) * 100;
}

void change_circuit_state(int fan_state)
{
  if(fan_state){
    Serial.println("LIGOU");
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, LOW);
  }
  else{
    Serial.println("DESLIGOU");
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, HIGH);
  }
}

// Lógica do circuito
void loop()
{
  int sensor_voltage = analogRead(temperature_sensor);
  float celsius_temperature = convert_celsius(sensor_voltage);
  int fan_state = celsius_temperature > 40;
  Serial.print("Voltagem: ");
  Serial.println(sensor_voltage);
  Serial.print("Temperatura em ºC: ");
  Serial.println(celsius_temperature);
  if(fan_state != last_state){
   digitalWrite(fan, fan_state);
   change_circuit_state(fan_state);
   last_state = fan_state;
  }
  delay(500);
}