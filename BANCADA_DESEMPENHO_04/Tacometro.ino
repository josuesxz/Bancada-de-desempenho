void begin_tac(){
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, FALLING);
}

void loop_tac(){
  unsigned long currentTime = millis();
  if (currentTime - lastPulseTime >= 1000) {
    rpm = (pulseCount * 60000UL) / (currentTime - lastPulseTime); // Converte pulsos por milissegundo para RPM
    Serial.print("RPM: ");
    Serial.println(rpm);
    lastPulseTime = currentTime;
    pulseCount = 0; // Reinicia o contador de pulsos
  }
}

void countPulse() {
  pulseCount++; // Incrementa o contador de pulsos quando um pulso é detectado
}