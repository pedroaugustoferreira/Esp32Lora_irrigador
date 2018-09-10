#include <FS.h>                   //this needs to be first, or it all crashes and burns...

#if defined(ESP8266)
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#else
#include <WiFi.h>          //https://github.com/esp8266/Arduino
#endif
// v2
//needed for library
#include <DNSServer.h>
#if defined(ESP8266)
#include <ESP8266WebServer.h>
#else
#include <WebServer.h>
#endif
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

#include <ArduinoJson.h>          //https://github.com/bblanchon/ArduinoJson
#include <SPIFFS.h>

#include <PubSubClient.h>
#include <Uteis.h>

//define your default values here, if there are different values in config.json, they are overwritten.
char mqtt_server[40];
char mqtt_port[6] = "8080";
char mqtt_user[34] = "mqtt_user";
char mqtt_password[34] = "mqtt_password";
char mqtt_topic[34] = "mqtt_topic";

const int PIN_AP = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN_AP, INPUT);
  Serial.println();

  //clean FS, for testing
  //SPIFFS.format();

 fs_read(mqtt_server,mqtt_port,mqtt_user,mqtt_password,mqtt_topic);
 config_wifi(mqtt_server,mqtt_port,mqtt_user,mqtt_password,mqtt_topic);
 
 

  Serial.println("local ip");
  Serial.println(WiFi.localIP());

   setup_mqtt(mqtt_server,mqtt_port,mqtt_user,mqtt_password,mqtt_topic);

}





void loop() {
reset_config(PIN_AP);
loop_mqtt(mqtt_server,mqtt_port,mqtt_user,mqtt_password,mqtt_topic);

}







