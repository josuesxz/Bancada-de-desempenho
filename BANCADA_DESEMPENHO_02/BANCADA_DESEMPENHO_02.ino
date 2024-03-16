#include <Wire.h>
#include "SDP6x.h"
#include "HX711.h"                       
#include <DHT.h>; 

#define DOUT  A1                      // HX711 DATA OUT = pino A0 do Arduino 
#define CLK   A0                      // HX711 SCK IN = pino A1 do Arduino e dht no A2

#define DHTPIN A2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

double temperatura;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  dht.begin(); 
}

void loop(){
  temperatura = dht.readTemperature(); 
  Serial.print(temperatura); Serial.print(";"); 
  Serial.print("\n");    
  delay(500);
}