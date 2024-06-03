void begin_balanca(){
  balanca.begin(DOUT, CLK);                          // inicializa a balança
  balanca.set_scale();      // ajusta fator de calibração
  balanca.tare();                                    // zera a Balança
}

void loop_balanca(){
  balanca.power_up(); // LIGANDO O SENSOR
  Serial.print(balanca.get_units()/100, 3);Serial.print(";"); 
  balanca.power_down(); // DESLIGANDO O SENSOR
}