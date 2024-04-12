const int pino = A0; // Pino analógico ao qual o sensor está conectado
const int minP = 0; 
const int maxP = 2000; //valor vide o manual determina na escala de até 2kPa 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(pino);
  
  // Mapeia os valores brutos do sensor para o poder analisar se há a necessidade de ajustes
  int valor = map(sensorValue, 0, 1023, minP, maxP);
  
  Serial.print("Diferença de pressão: ");
  Serial.println(valor);
  
  delay(100); // Ajuste conforme necessário
}
