const int ledBits[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int decimal = 0;
const int buttonPin = 10;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledBits[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    incrementDecimal();
    delay(300);
  }

  updateLEDs();
}

void incrementDecimal() {
  decimal++;
}

void updateLEDs() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledBits[i], bitRead(decimal, i));
  }
}
