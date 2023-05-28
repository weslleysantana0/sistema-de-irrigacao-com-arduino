const int relayPin = 7; // Pino do Arduino conectado ao pino de controle do módulo de relé
const int moisturePin = A0; // Pino analógico do Arduino conectado ao pino de sinal do sensor de umidade do solo
const int moistureThreshold = 500; // Limiar de umidade do solo para acionar a irrigação (ajuste conforme necessário)

void setup() {
  pinMode(relayPin, OUTPUT); // Configura o pino do relé como saída
  digitalWrite(relayPin, LOW); // Desliga a bomba de água inicialmente
  Serial.begin(9600); // Inicializa a comunicação serial para depuração
}

void loop() {
  int moistureValue = analogRead(moisturePin); // Lê o valor analógico do sensor de umidade do solo
  Serial.print("Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue > moistureThreshold) {
    digitalWrite(relayPin, HIGH); // Liga a bomba de água
    Serial.println("Irrigation ON");
  } else {
    digitalWrite(relayPin, LOW); // Desliga a bomba de água
    Serial.println("Irrigation OFF");
  }

  delay(1000); // Aguarda um segundo antes de realizar a próxima leitura
}
