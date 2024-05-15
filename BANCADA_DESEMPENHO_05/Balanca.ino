void begin_balanca(){
  balanca.begin(DOUT, CLK);                          // inicializa a balança
  balanca.set_scale(calibration_factor);      // ajusta fator de calibração
  balanca.tare(0);                                    // zera a Balança
}

void loop_balanca(){
  balanca.power_up(); // LIGANDO O SENSOR
  Serial.print("Balanca: ");
  Serial.println(balanca.get_units(), 3); 
  balanca.power_down();			        // put the ADC in sleep mode
  delay(500);
  balanca.power_down(); // DESLIGANDO O SENSOR
}