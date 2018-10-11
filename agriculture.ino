#include <DHT.h>
#define DHTTYPE DHT11   // DHT 11

int value;
DHT dht(2, DHTTYPE);

void setup(){
  dht.begin();
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop()
{
  value = analogRead(A0);
  Serial.println(value);
  if(value > 300)
  {
    Serial.println("Crops need water");
    digitalWrite(13,1);
  }
  else
  {
     Serial.println("Crops are watered");
     digitalWrite(13,0);
  }    
  Serial.print("Temperature = ");
  Serial.println(dht.readTemperature());
  Serial.print("Humidity = ");
  Serial.println(dht.readHumidity());
  delay(1000);
}
