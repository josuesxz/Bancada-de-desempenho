void begin_tac(){
  pinMode(pinTac, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinTac), countPulse, FALLING); // Interrupção que irá verificar a variação do sensor
}

void loop_tac(){
  unsigned long currentTime = millis();
  if (currentTime - lastPulseTime >= 1000) { // define um intervalo para verificar a 
    rpm = (pulseCount * 60000UL) / (currentTime - lastPulseTime); //Cálculo do RPM
    Serial.print("RPM: ");
    Serial.println(rpm/fator_correcao_tac);
    lastPulseTime = currentTime; // Reinicia o contador de pulsos invalidando a condição 
    pulseCount = 0; 
  }
}

void countPulse() {
  pulseCount++; // Incrementa o contador de pulsos quando um pulso é detectado
}