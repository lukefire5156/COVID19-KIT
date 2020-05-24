#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#include <Firebase.h>  
#include <FirebaseArduino.h>  
#include <FirebaseCloudMessaging.h>  
#include <FirebaseError.h>  
#include <FirebaseHttpClient.h>  
#include <FirebaseObject.h> 

#define FIREBASE_HOST "fir-4d6dc.firebaseio.com"
#define FIREBASE_AUTH "NOwtSbDNI397K0GvcuGIAlmm7IAVbGnZoDgKPz4k"

#define WIFI_SSID "Lukefire"
#define WIFI_PASSWORD "asharma5156"

float val;
int tempPin=A3;

//const char* ssid = "Shaolin's World";
//const char* password = "sixtimes21"; 

WiFiClient client;

unsigned long myChannelNumber = 1012728; 
const char * myWriteAPIKey = "SOSBGI5TYN22Q8MV";

int sensorPin = 0;
double alpha = 0.75;
int period = 200;
double change = 0.0;
double minval = 0.0;

void setup() {
  
/*Serial.begin(9600);
WiFi.begin(ssid, password);
ThingSpeak.begin(client);*/

Serial.begin(115200);

  delay(500);               

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  

  Serial.print("Connecting to ");

  Serial.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");

    delay(500);

}
  Serial.println();

  Serial.print("Connected to ");

  Serial.println(WIFI_SSID);

  Serial.print("IP Address is : ");

  Serial.println(WiFi.localIP());                               // Will print local IP address

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);             // connect to firebase

//  dht.begin();                                        //Start reading dht sensor

}
void loop() {
static double oldValue = 0;
static double oldChange = 0;
 
int rawValue = analogRead (sensorPin);
double value = alpha * oldValue + (1 - alpha) * rawValue;
 
Serial.print (rawValue);
Serial.print (",");
Serial.println (value);
oldValue = value;
//String a=String(((1 - alpha) * rawValue)-random(59,69));
 
delay(period);
String hr= String(value);
 Firebase.setString("/heartBeat", String(rawValue-500));                                  //setup path and send readings

  //Firebase.setString("/DHT11/Temperature/"+String(c), fireTemp);                                //setup path and send readings

    if (Firebase.failed()) {

      Serial.print("pushing /logs failed:");

      Serial.println(Firebase.error()); 

      return;

  }  
//ThingSpeak.writeField(myChannelNumber, 5, farh, myWriteAPIKey);
}
