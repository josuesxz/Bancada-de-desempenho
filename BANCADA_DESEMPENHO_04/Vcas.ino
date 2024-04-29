void begin_vcas(){
  pinMode(I_VCAS, INPUT);
  pinMode(GND_VCAS, OUTPUT);
}

void loop_vcas(){
  digitalWrite(GND_VCAS, LOW);
  vi = analogRead(I_VCAS);
  difPressure = SDP6x.GetPressureDiff();
  df_pressao = 5*(0.2*vi+5); //cálculo fornecido pelo manual do sensor que mostra o sinal de saída 

  Serial.println(df_pressao); 
  Serial.println(difPressure);
  delay(500);
}