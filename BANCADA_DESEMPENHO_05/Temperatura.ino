void begin_temperatura(){
  dht.begin(); 
}

void loop_temperatura(){
  temperatura = dht.readTemperature();
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
}