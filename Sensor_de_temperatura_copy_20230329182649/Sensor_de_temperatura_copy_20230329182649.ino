//Librerias

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//Inicializaciones

#define DHTPIN D7
#define rele D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


// Credenciales Web Server

const char* ssid = "POCO F3";
const char* password = "Clavesegura123";
ESP8266WebServer server(80);

// Conexion a tu Wi-Fi local
Serial.print("Conectando a  ");
Serial.print(ssid);
WiFi.begin(ssid, password);


  //Verificar si el Wifi esta conectado
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado..!");
  Serial.print("Tu direccion ip es: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("Servidor HTTP inicializado ");




void setup() {
  Serial.begin(9600);
  delay(10);
  dht.begin();
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
}


void loop() {

server.handleClient();


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
