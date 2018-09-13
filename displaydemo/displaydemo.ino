// This example just provide basic function test;
// For more informations, please vist www.heltec.cn or mail to support@heltec.cn

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`

#define SDA    4
#define SCL   15
#define RST   16 //RST must be set by software

#define V2     1

#ifdef V2 //WIFI Kit series V1 not support Vext control
  #define Vext  21
#endif
SSD1306  display(0x3c, SDA, SCL, RST);

#define DEMO_DURATION 3000
typedef void (*Demo)(void);


String linha1 = "";
String linha2 = "";
String linha3 = "";
boolean start = true;

void setup() {


  Serial.begin(115200);


 


   

msg("pedro");
delay(1000);
msg("gisele");
delay(1000);
msg("agostinha");
delay(1000);
msg("bete");
delay(1000);
msg("afonso");

}



void msg(String msg) {
if(start){
  start=false;
  Serial.println("OPA");

    pinMode(RST,OUTPUT);
  digitalWrite(Vext, LOW);    // OLED USE Vext as power supply, must turn ON Vext before OLED init
  delay(50); 
   display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}


   Serial.println(msg);
   display.clear();

//linha3 = linha2;
//linha2 = linha1;
//linha1 = msg;

linha1=linha2;
linha2=linha3;
linha3=msg;


    display.setTextAlignment(TEXT_ALIGN_LEFT);
    
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 0, linha1);
    display.drawString(0, 20, linha2);
    display.drawString(0, 40, linha3);







 display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(10, 128, String(millis()));
  // write the buffer to the display
  display.display();

}











void loop() {

 

}





