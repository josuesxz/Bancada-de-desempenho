#include <Wire.h>
#include "SDP6x.h"
#include "HX711.h"                       
#include "DHT.h"

#define DHTPIN A2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
double temperatura;

#define DOUT  A6                      // HX711 DATA OUT = pino A6 do Arduino 
#define CLK   A7                      // HX711 SCK IN = pino A7 do Arduino 
HX711 balanca;                        // define instancia balança HX711
float calibration_factor = 12169.9293;     // Mudar em função do sensor

float difPressure, vcas, massa;
float densidade = 1.213;                  // Mudar em função do local
#define GND_VCAS 13

#define pinTac 3
#define VCC_TAC 2 
volatile unsigned long pulseCount = 0; // Contador de pulsos
unsigned long lastPulseTime = 0; // Último momento em que um pulso foi detectado
unsigned long rpm = 0; // Rotação por minuto
float fator_correcao_tac = 0.870998;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  begin_temperatura();
  begin_balanca();
  begin_vcas();
  begin_tac();
  Serial.println("Valores em fileira de: Temperatura, Balança, Pressão, Velocidade e RPM");
}

void loop(){
  loop_temperatura();
  loop_balanca(); 
  loop_vcas();
  loop_tac();
  Serial.print("\n");    
  delay(500);
}