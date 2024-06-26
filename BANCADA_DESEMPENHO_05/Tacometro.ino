void begin_tac(){
  pinMode(pinTac, INPUT);
    pinMode(VCC_TAC, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pinTac), countPulse, FALLING); // Interrupção que irá verificar a variação do sensor
}

void loop_tac(){
  digitalWrite(VCC_TAC, HIGH);
  unsigned long currentTime = millis();
  if (currentTime - lastPulseTime >= 1000) { // define um intervalo para verificar a 
    rpm = (pulseCount * 60000UL) / (currentTime - lastPulseTime); //Cálculo do RPM
    Serial.print(rpm/fator_correcao_tac); Serial.print("@");
    lastPulseTime = currentTime; // Reinicia o contador de pulsos invalidando a condição 
    pulseCount = 0; 
  }
}

void countPulse() {
  pulseCount++; // Incrementa o contador de pulsos quando um pulso é detectado
}