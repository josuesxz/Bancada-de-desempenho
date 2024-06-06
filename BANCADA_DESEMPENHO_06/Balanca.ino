void begin_balanca(){
  balanca.begin(DOUT, CLK);                          // inicializa a balança
  balanca.set_scale();      // ajusta fator de calibração
  balanca.tare();                                    // zera a Balança
}

void loop_balanca(){
  balanca.power_up(); // LIGANDO O SENSOR
  if(balanca.is_ready()){
  Serial.print(balanca.get_units()/100, 3);
  }
  else{
    Serial.print("0");
  }
  Serial.print(";"); 
  balanca.power_down(); // DESLIGANDO O SENSOR
}