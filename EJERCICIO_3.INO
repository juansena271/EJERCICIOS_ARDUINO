const int ledBits[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int decimal = 0;
const int buttonPin = 10;

void initializePins() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledBits[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void updateLEDs(int value) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledBits[i], bitRead(value, i));
  }
}

void incrementDecimal() {
  decimal++;
}

void setup() {
  initializePins(); 
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    incrementDecimal();  
    delay(300);  
  }

  updateLEDs(decimal); 
}
