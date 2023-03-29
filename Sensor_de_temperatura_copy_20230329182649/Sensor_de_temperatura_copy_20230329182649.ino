//Librerias

#include <DHT.h>

//Inicializaciones

#define DHTPIN D7
#define rele D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  delay(10);
  dht.begin();
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
}


void loop() {

//Declaracion de variables 

float h = dht.readHumidity();
float t = dht.readTemperature();

if (isnan(h) || isnan(t)) {
    Serial.println("No se pudo leer el sensor");
    return;
  }

// Lectura de humedad y control de Rele
// Rele se apaga si humedad es mayor a 85

 if (h > 85) {
   digitalWrite(rele, HIGH);
   Serial.print("Hay ");
   Serial.print(h);
  Serial.print(" % de humedad y ");
  Serial.print(t);
  Serial.print(" Grados de temperatura\r\n");
    Serial.print("El relé está encendido\r\n");
   delay(2000);
 } else {
   digitalWrite(rele, LOW);
      Serial.print("Hay ");
   Serial.print(h);
  Serial.print(" % de humedad y ");
  Serial.print(t);
  Serial.print(" Grados de temperatura\r\n");
   delay(2000);
  Serial.print("El relé está apagado\r\n");
 }
}
