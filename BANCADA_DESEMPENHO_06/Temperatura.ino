void begin_temperatura(){
  dht.begin(); 
}

void loop_temperatura(){
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();

  if(temperatura > 0 & umidade > 0){
  Serial.print(temperatura); Serial.print("#");
  Serial.print(umidade); Serial.print("%");
  }
  else{
      Serial.print("0.0"); Serial.print("#");
      Serial.print("0.0"); Serial.print("%");
  }
}