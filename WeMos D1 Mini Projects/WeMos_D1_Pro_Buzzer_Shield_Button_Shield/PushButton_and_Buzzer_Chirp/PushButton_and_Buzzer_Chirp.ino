
const int buttonPin = D3;
const int ledPin = BUILTIN_LED;
int buzzer = D5;
int buttonState = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial state, LED off
  digitalWrite(ledPin, buttonState);
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
    tone(buzzer, 250, 20, 15);
  }
  delay(450);
}

void loop() {
  // read button state, HIGH when pressed, LOW when not
  buttonState = digitalRead(buttonPin);

  // if the push button pressed, switch on the LED
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);  // LED on
  } else {
    digitalWrite(ledPin, LOW); // LED off
    cricket();
  }
}
