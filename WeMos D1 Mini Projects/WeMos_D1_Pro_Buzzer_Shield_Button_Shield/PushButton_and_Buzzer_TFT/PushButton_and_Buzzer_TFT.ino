#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#define TFT_CS     D4
#define TFT_RST    -1  // you can also connect this to the Arduino reset
// in which case, set this #define pin to -1!
#define TFT_DC     D3

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

const int buttonPin = D3;
const int ledPin = BUILTIN_LED;
int buzzer = D5;
int buttonState = 0;

void setup() {
  tft.initR(INITR_144GREENTAB);
  tft.setTextWrap(true); // Allow text to run off right edge
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(54, 40);
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextSize(3);
  tft.println("STAR");
  tft.println("WARS");
  tft.setRotation(tft.getRotation()+1);
  //delay(3000);
  
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial state, LED off
  digitalWrite(ledPin, buttonState);
}

void beep (int speakerPin, float noteFrequency, long noteDuration){
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many milliseconds there are per HIGH/LOW cycles.
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)
  {
  digitalWrite(speakerPin,HIGH);
  delayMicroseconds(microsecondsPerWave);
  digitalWrite(speakerPin,LOW);
  delayMicroseconds(microsecondsPerWave);
  }
}

void ohhh() {
  for (int i=1000; i<2000; i=i*1.02) { beep(buzzer,i,10); } for (int i=2000; i>1000; i=i*.98) {
  beep(buzzer,i,10);
  }
}

void uhoh() {
  for (int i=1000; i<1244; i=i*1.01) { beep(buzzer,i,30); } delay(200); for (int i=1244; i>1108; i=i*.99) {
  beep(buzzer,i,30);
 }
}

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration, unsigned long pause) {
  pinMode (_pin, OUTPUT );
  analogWriteFreq(frequency);
  analogWrite(_pin,500);
  delay(duration);
  analogWrite(_pin,0);
  delay(pause);
}

void cricket(){
  for(int i=0; i<4; i++){
    tone(buzzer, 50, 20, 15);
  }
  delay(50);
}

void musicSection1(){
  //delay(500);
  //Star Wars
  //1
  tone(buzzer, 440, 500, 150);
  tone(buzzer, 440, 500, 150);
  tone(buzzer, 440, 500, 150);

  tone(buzzer, 349, 350, 80);
  tone(buzzer, 523, 150, 80);
  tone(buzzer, 440, 500, 100);

  tone(buzzer, 349, 350, 80);
  tone(buzzer, 523, 150, 80);
  tone(buzzer, 440, 650, 100);

  delay(500);
  //2
  tone(buzzer, 659, 500, 150);
  tone(buzzer, 659, 500, 150);
  tone(buzzer, 659, 500, 150);

  tone(buzzer, 698, 350, 80);
  tone(buzzer, 523, 150, 80);
  tone(buzzer, 415, 500, 100);

  tone(buzzer, 349, 350, 80);
  tone(buzzer, 523, 150, 80);
  tone(buzzer, 440, 650, 100);

  delay(500);
}

void musicSection2(){
  //delay(500);
  //Star Wars
  //1
  tone(buzzer, 880, 500, 150);
  tone(buzzer, 440, 300, 150);
  tone(buzzer, 440, 150, 150);

  tone(buzzer, 880, 500, 80);
  tone(buzzer, 830, 325, 80);
  tone(buzzer, 784, 175, 100);

  tone(buzzer, 740, 125, 80);
  tone(buzzer, 698, 125, 80);
  tone(buzzer, 740, 250, 100);

  delay(325);
  //2
  tone(buzzer, 466, 250, 150);
  tone(buzzer, 622, 500, 150);
  tone(buzzer, 587, 325, 150);

  tone(buzzer, 554, 175, 80);
  tone(buzzer, 523, 125, 80);
  tone(buzzer, 494, 125, 100);

  tone(buzzer, 523, 250, 80);

  delay(350);
}

void musicVariant1(){
  //delay(500);
  //Star Wars
  //1
  tone(buzzer, 349, 250, 150);
  tone(buzzer, 415, 500, 150);
  tone(buzzer, 349, 350, 150);

  tone(buzzer, 440, 125, 80);
  tone(buzzer, 523, 500, 80);
  tone(buzzer, 440, 375, 100);

  tone(buzzer, 523, 125, 80);
  tone(buzzer, 659, 650, 80);

  delay(500);
}

void musicVariant2(){
  //delay(500);
  //Star Wars
  //1
  tone(buzzer, 349, 250, 150);
  tone(buzzer, 415, 500, 150);
  tone(buzzer, 349, 375, 150);

  tone(buzzer, 523, 125, 80);
  tone(buzzer, 440, 500, 80);
  tone(buzzer, 349, 375, 100);

  tone(buzzer, 523, 125, 80);
  tone(buzzer, 440, 650, 80);

  delay(650);
}

void loop() {
  // read button state, HIGH when pressed, LOW when not
  buttonState = digitalRead(buttonPin);

  // if the push button pressed, switch on the LED
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);  // LED on
  } else {
    digitalWrite(ledPin, LOW); // LED off
    //cricket();
    // Star Wars
    musicSection1();
    musicSection2();
    musicVariant1();
    musicSection2();
    musicVariant2();
    //ohhh();
    //uhoh();
  }
}
