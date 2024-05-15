#include <Wire.h>
#include "SDP6x.h"
#include "HX711.h"                       
#include "DHT.h"

#define DHTPIN A2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
double temperatura;

#define DOUT  7                     // HX711 DATA OUT = pino D7 do Arduino 
#define CLK   6                       // HX711 SCK IN = pino D6 do Arduino 
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
  begin_balanca();
  begin_tac();
  begin_temperatura();
  begin_vcas();
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Valores em fileira de: Temperatura, Balança, Pressão, Velocidade e RPM");
}

void loop(){
  loop_balanca();
  loop_tac(); 
  loop_temperatura();
  loop_vcas();
  Serial.print("\n");    
  delay(1000);
}