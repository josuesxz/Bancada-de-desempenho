void begin_balanca(){
  balanca.begin(DOUT, CLK);                          // inicializa a balança
  balanca.set_scale(calibration_factor);      // ajusta fator de calibração
  balanca.tare();                                    // zera a Balança
}

void loop_balanca(){
  balanca.power_up(); // LIGANDO O SENSOR
	Serial.print(balanca.get_units(), 3); //lendo e convertendo para de Kgf para N (1Kgf = 9.8066N)
  Serial.print(";"); 
  balanca.power_down(); // DESLIGANDO O SENSOR
}