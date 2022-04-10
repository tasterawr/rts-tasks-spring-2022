int ledPins [] =  {3, 5, 6, 9, 10};

int ledStates [] = {LOW, LOW, LOW, LOW, LOW};
unsigned long previousMillis [] = {0, 0, 0, 0, 0};
const long intervals[] = {900000, 333000, 27000, 150, 100};

void setup() {
  for (int i = 0; i < 5; i++){
      pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 5; i++){
    unsigned long currentMillis = micros();
    if (currentMillis - previousMillis[i] >= intervals[i]) {
      previousMillis[i] = currentMillis;
  
      if (ledStates[i] == LOW) {
        ledStates[i] = HIGH;
      } else {
        ledStates[i] = LOW;
      }
  
      digitalWrite(ledPins[i], ledStates[i]);
    }
  }
 
}
