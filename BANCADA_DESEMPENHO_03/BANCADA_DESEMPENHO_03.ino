#include <Wire.h>
#include "SDP6x.h"
#include "HX711.h"                       
#include "DHT.h"

#define DHTPIN A2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
double temperatura;

#define DOUT  A1                      // HX711 DATA OUT = pino A0 do Arduino 
#define CLK   A0                      // HX711 SCK IN = pino A1 do Arduino e dht no A2

HX711 balanca;                        // define instancia balança HX711
float calibration_factor = 211020.00;     // Mudar em função do sensor

float difPressure, vcas, massa, df_pressao;
float densidade = 1.213;                  // Mudar em função do local
#define I_VCAS A3

void setup(){
  Wire.begin();
  Serial.begin(9600);
  //begin_temperatura();
  //begin_balanca();
  begin_vcas();
  difPressure = 0.0;
  Serial.println("Valores em fileira de: Balança, Temperatura, Pressão e Velocidade");
}

void loop(){
  //loop_temperatura();
  //loop_balanca(); 
  loop_vcas();
  Serial.print("\n");    
  delay(500);
}