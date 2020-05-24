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
int tempPin=A0;
const char* ssid = "Shaolin's World";
const char* password = "sixtimes21"; 

WiFiClient client;

unsigned long myChannelNumber = 1012728; 
const char * myWriteAPIKey = "SOSBGI5TYN22Q8MV";

void setup() 

{
  pinMode(tempPin,INPUT);
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
//int c=0;

void loop() 

{
  
val=analogRead(tempPin);
 val = val * 0.48828125;
float mv=(val/1024.0)*5000;
float cel=val;
float farh=(cel)*9/5 + 32;
Serial.print("Temperature=");
Serial.print(val);
Serial.print("*C");
Serial.println();
delay(1000);
Serial.print("Temperature=");
Serial.print(farh);
Serial.print("*F");
Serial.println();
float f=val-77;//farh-483;
String Tem = String(random(96,100));//f);
 Firebase.setString("/temp", String(farh));                                  //setup path and send readings

  //Firebase.setString("/DHT11/Temperature/"+String(c), fireTemp);                                //setup path and send readings

    if (Firebase.failed()) {

      Serial.print("pushing /logs failed:");

      Serial.println(Firebase.error()); 

      return;

  }  
//ThingSpeak.writeField(myChannelNumber, 5, farh, myWriteAPIKey);

}
