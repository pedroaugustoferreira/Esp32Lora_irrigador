#include <U8x8lib.h>


  U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);

String linha1 = "";
String linha2 = "";
String linha3 = "";
String linha4 = "";
boolean start = true;







void msg(String msg) {
u8x8.clear();
  
if(start){
  start=false;
  

    Serial.begin(115200);
     u8x8.begin();
u8x8.setFont(u8x8_font_chroma48medium8_r);
}

linha1=linha2;
linha2=linha3;
linha3=linha4;
linha4=msg;


u8x8.draw1x2String(0, 0, linha1.c_str());
u8x8.draw1x2String(0, 2, linha2.c_str());
u8x8.draw1x2String(0, 4, linha3.c_str());
u8x8.draw1x2String(0, 6, linha4.c_str());

Serial.println(msg);


}

