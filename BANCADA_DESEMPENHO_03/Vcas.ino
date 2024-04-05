void begin_vcas(){
  pinMode(I_VCAS, INPUT);
}

void loop_vcas(){

  vi = analogRead(I_VCAS);
  difPressure = SDP6x.GetPressureDiff();
  df_pressao = 5*(0.2*vi+5); //cálculo fornecido pelo manual do sensor que mostra o sinal de saída 

  Serial.println(df_pressao); 
  Serial.println(difPressure);
  delay(500);
}