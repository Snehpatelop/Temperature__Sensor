#define BLYNK_TEMPLATE_ID "TMPL3afXgVUwK"
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor"
#define BLYNK_AUTH_TOKEN "XLhkkQpBw4ltcC7GHNDYklXLVvTiZ5Kq"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 //data pin connected to d2 on ESP
#define DHTTYPE DHT11 // Name the sensor as an object


char auth[] = "XLhkkQpBw4ltcC7GHNDYklXLVvTiZ5Kq";
char ssid[] = "Sneh 1";
char pass[] = "spp@2005";


DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Connected Successfully");
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
float h = dht.readHumidity();
float t = dht.readTemperature();
float f = dht.readTemperature(true);
if (isnan(h)|| isnan(t)||isnan(f))
{
  Serial.println("Something is not working as intended");
  return;
}
Serial.print("Humidity");
Serial.print(h);
Serial.println("%");
Serial.print("Temperature");
Serial.print(t);
Serial.println("degreed celsius.");
Blynk.virtualWrite(V0, t);
Blynk.virtualWrite(V1, h);
delay(1000);

}
