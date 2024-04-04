void begin_balanca(){
  balanca.begin(DOUT, CLK);                          // inicializa a balança
  balanca.set_scale(calibration_factor);             // ajusta fator de calibração
  balanca.tare();                                    // zera a Balança
}

void loop_balanca(){
  Serial.print(balanca.get_units(), 3); Serial.print(";"); 
}