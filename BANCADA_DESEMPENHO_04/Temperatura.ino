void begin_temperatura(){
  dht.begin(); 
}

void loop_temperatura(){
  temperatura = dht.readTemperature();
  Serial.print(temperatura); Serial.print(";");
}