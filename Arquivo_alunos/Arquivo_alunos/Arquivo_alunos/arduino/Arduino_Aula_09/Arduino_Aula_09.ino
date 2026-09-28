// Aula 09 - Controle de nivel virtual por potenciometro
const byte POT = A0;
unsigned long ultimoEnvio = 0;

int mediaAnalogica() {
  long soma = 0;
  for (byte i = 0; i < 8; i++) soma += analogRead(POT);
  return soma / 8;
}

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("PRONTO");
}

void loop() {
  if (millis() - ultimoEnvio >= 50) {
    ultimoEnvio = millis();
    Serial.print("POT:");
    Serial.println(mediaAnalogica());
  }
}
