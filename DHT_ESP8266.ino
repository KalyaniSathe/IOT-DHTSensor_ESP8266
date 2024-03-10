#include <cogcloudesp8266.h>
#include<DHT.h>

DHT d(D3, DHT11);

String ssid = "akconnect";
String pass = "Ramnagarnashik";

String apikey = "04b0f1689efd42ce906ee34b77991d40";

void setup ()
{
  
  Serial.begin(9600);
  cogInitCloud (ssid,pass,apikey);
  //cogBindPin (BUILTIN_LED, "Lamp Button");
}

void loop ()
{
  //float chk = d.read11(3);
  cogAppLoop();
  float t = d.readTemperature();
  float h = d.readHumidity(); 
  Serial.println(t);
  Serial.println(h);
  cogStoreCloudVariable("Temperature",String(t));
  cogStoreCloudVariable("Humidity",String(h));
}
