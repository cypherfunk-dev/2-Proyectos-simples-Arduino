#include <dht.h>
dht DHT;
#define DHT11_PIN 8
#define rele 9
void setup(){
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
  Serial.begin(9600);
}

void loop()
{
  DHT.read11(DHT11_PIN);

  //TEMPERATURA//
  Serial.print("Temperatura = ");
  Serial.print(DHT.temperature);
  Serial.println(" C");

  //HUMEDAD RELATIVA//
  Serial.print("Humedad = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");
  delay(2000);
  int humedad = digitalRead(DHT.humidity);

  if (DHT.humidity > 85){
  digitalWrite(rele, HIGH);
  Serial.print("Esta humedo\r\n");
  delay(500);}
  else{
  digitalWrite(rele, LOW);
  Serial.print("Ta seca la cosa\r\n");
  delay(500);
  }


}
