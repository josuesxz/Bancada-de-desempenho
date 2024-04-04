void begin_vcas(){
  pinMode(I_VCAS, INPUT);
}

void loop_vcas(){
  df_pressao = analogRead(I_VCAS);
  Serial.println(df_pressao); //tratar essa saída (ou criar uma biblioteca)
  delay(500);
}