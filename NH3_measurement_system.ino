//Library
#define cellpin A0
#include "max6675.h" 
#include <DHT.h>;

//DHT temp & humidity sensor
#define DHTPIN 7     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

//thermocouple
int SO = 12;
int CS = 10;
int sck = 13;
MAX6675 module(sck, CS, SO);

int chk;
float hum;
float temp;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
int value=analogRead(cellpin);
float Volt=value*5.0/1023.0; //reading voltage
float temperature = module.readCelsius(); 

hum = dht.readHumidity();
temp= dht.readTemperature();
Serial.print("Humidity: ");
Serial.print(hum);
Serial.print(", Temp: ");
Serial.print(temp);
Serial.print(", NH3 volt: ");
Serial.print(Volt, 4);
Serial.print(", Out temp: ");
Serial.println(temperature);

delay (60000); //measurement time = 1 min
}
