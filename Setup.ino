#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"
#include <time.h>
#include <DHT.h>

#define LED 2

#define DHTPIN 14
#define DHTTYPE DHT11

#define WIFI_SSID "***"
#define WIFI_PASSWORD "***"

#define WIFI_AP_SSID "ESPAP"
#define WIFI_AP_PASSWORD "password"

#define FIREBASE_HOST "***.firebaseio.com"
#define FIREBASE_AUTH ""***""

#define FIREBASEDATO_HOST ""***.firebaseio.com"
#define FIREBASEDATO_AUTH ""***""

DHT dht(DHTPIN, DHTTYPE);
FirebaseData firebaseData;
FirebaseData firebaseDatadato;
WiFiServer server (80);

int timezone=2;
int dst=0;
String timestamp="";
int tempon=5;
int tempoff=600;
double tempdata = 0;
double tempext = 0;
double tempint = 4;
double tempsens = 0;
boolean state = 0;
int Delay1= 500;
int Delay2= 1000;
int Delay3= 5000;



void setup() {
  delay(Delay2);Serial.begin(115200);delay(Delay3);

  pinMode(LED,OUTPUT);
  digitalWrite(LED, !state);
  
  dht.begin();

  Firebase.begin(FIREBASEDATO_HOST,FIREBASEDATO_AUTH);
 
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("Connection to "+String(WIFI_SSID));
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(Delay1);
  }
  Serial.println ();
  Serial.print ("Connected, with IP address: ");Serial.println(WiFi.localIP());
  Serial.println("Configuration access point...");
  Serial.println(WiFi.softAP(WIFI_AP_SSID,WIFI_AP_PASSWORD)?"Configurated":"Failed");
  Serial.print("Connected, with address IP AP: ");Serial.println(WiFi.softAPIP());

  server.begin();
  Serial.print("Server activated! Use this URL to connect: http://");
  Serial.println(WiFi.localIP());
  
  configTime(timezone*3600, dst*0, "pool.ntp-org", "time.nist.gov");
  Serial.println ("Waiting for time");
  
  while (!time(nullptr)){
    Serial.print(".");
    delay(Delay1);
  }
  
  Serial.println("");
  
}
