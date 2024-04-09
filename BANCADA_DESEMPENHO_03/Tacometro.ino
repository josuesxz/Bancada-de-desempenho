void begin_tac(){
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, FALLING);
}

void loop_tac(){
  int sensorValue = digitalRead(sensorPin);
  Serial.println(sensorValue);

  // Se o sensor detectar um objeto (baixo nível)
  if (sensorValue == LOW) {
    Serial.println("Objeto detectado!");
  } 
  else {
    Serial.println("Nenhum objeto detectado.");
  }
}