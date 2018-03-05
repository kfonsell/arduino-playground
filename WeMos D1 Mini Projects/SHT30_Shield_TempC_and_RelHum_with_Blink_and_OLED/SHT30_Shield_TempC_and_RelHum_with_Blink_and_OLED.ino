#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WEMOS_SHT3X.h>

#define OLED_RESET 0 //GPIO0
Adafruit_SSD1306 display(OLED_RESET);
SHT3X sht30(0x45);

void setup() {  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  if(sht30.get()==0){
    
    Serial.print("Temperature in Celsius : ");
    display.println("Temp.");
    Serial.println(sht30.cTemp);
    display.print(sht30.cTemp);
    display.print((char)247);
    display.println("C");
    Serial.print("Relative Humidity : ");
    display.println("Rel.Hum.");
    Serial.println(sht30.humidity);
    display.print(sht30.humidity);
    display.println("%");
    display.display();
    Serial.println();
  }
  else
  {
    Serial.println("Error!");
    display.println("Error!");
  }
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(750);

}
