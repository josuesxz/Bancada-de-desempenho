void begin_temperatura(){
  dht.begin(); 
}

void loop_temperatura(){
  temperatura = dht.readTemperature();
  if(temperatura > 0){
  Serial.print(temperatura);
  }
  else{
    Serial.print("0");
  }
  Serial.print("#");
}