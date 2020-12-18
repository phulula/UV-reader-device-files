
//AUTHORS: Phulula Sibindlana, Atheera Miller, Charity Rodolo 

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C
 #define SSD1306_128_64

Adafruit_SSD1306 display(-1);          //reset display

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h");
#endif

 int x=0;
 int uvindex =9;       //hardcoded uv index
void setup() {
  
  // initialize and clear display
  
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  
  display.display();
 

}

void loop() {
 // put your main code here, to run repeatedly:
 // display definitions
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
  display.setCursor(0,0);
  display.print("UV index: ");
  display.print(uvindex);          //print the uv index 
  display.print("\n");
  display.println(uv_func());       //print the message returned in the uv_func fucntion
  display.print("Minutes suggested:");
  display.println(2);
  display.startscrollleft(0x02, 0x02);          //make the 2nd line in the display to scroll across(move to the left of) the display
  display.display();
  delay(20000);              //delay for screen to be visible.
}
// function to measure UV index(hardcoded because there was no sensor at this stage)
String uv_func (){
  String message ;         //message to display on screen. 
              
   
    if (uvindex <=2 and uvindex>=0){
      message = "Low uv index";
    }
    else if (uvindex <=5 and uvindex>=3){
      message  = "Mod index";
    }
    else if (uvindex <=7 and uvindex>=6){
      message = "High index";
    }
    else if (uvindex <=10 and uvindex>=8){
      message = "Very high index";
    }
    else if (uvindex>=11){
      message = "Extremely high";
    }
  
  return message;
 }
