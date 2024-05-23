void begin_vcas(){
  difPressure = 0.0;
  pinMode(GND_VCAS, OUTPUT);
}

void loop_vcas(){
  digitalWrite(GND_VCAS, LOW);
  difPressure = SDP6x.GetPressureDiff();
  vcas = 0;
    if (difPressure > 0){
      vcas = sqrt((2.0 * difPressure)/densidade);
    } 
  Serial.print(difPressure);Serial.print("$");  
  Serial.println(vcas);
}