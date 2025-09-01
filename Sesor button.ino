//Sensor button:

boolean ledState = 0;
boolean buttonWasUp = true;

void setup() {
  pinMode(7, OUTPUT); // pin for the led or something else
  pinMode(3, INPUT_PULLUP); // pin for ttp223
}

void loop() {
  // узнаем состояние кнопки
  boolean buttonIsUp = digitalRead(2);

  // если кнопка нажата меняем состояние пина 7
  if (buttonWasUp && !buttonIsUp) {
    delay(10);
    buttonIsUp = digitalRead(2);
    if (!buttonIsUp) { ledState = !ledState; }
  }
  buttonWasUp = buttonIsUp;

  digitalWrite(7, ledState);
}