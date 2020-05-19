const int buttonPin = 7;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
int counter = 0;
int _delay  =  6;    // Delay time
int _step   =  1;    // Increment/decrement size

int FadeOn(int pin)
{
  int fadeValue;
  // Ramp up pin
  for (fadeValue = 0 ; fadeValue <= 255; fadeValue += _step) {
    // sets the value (range from 0 to 255):
    analogWrite(pin, fadeValue);
    // wait to see the dimming effect
    delay(_delay);
  }
  analogWrite(pin, 255);
  return (fadeValue);
}

int FadeOff(int pin)
{
  int fadeValue;
  // Ramp down pin
  for (fadeValue = 255 ; fadeValue >= 0; fadeValue -= _step) {
    // sets the value (range from 0 to 255):
    analogWrite(pin, fadeValue);
    // wait to see the dimming effect
    delay(_delay);
  }
  analogWrite(pin, 0);
  return (fadeValue);
}

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  if (digitalRead(buttonPin) == LOW) {
    counter++;
    delay(200);
  }

  if (counter == 0) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    Serial.println(counter);
  }

  else if (counter == 1) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    Serial.println(counter);
  }

  else if (counter == 2) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    Serial.println(counter);
  }

  else if (counter == 3) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    Serial.println(counter);
  }

  else if (counter == 4) {
    analogWrite(redPin, 190);
    analogWrite(greenPin, 210);
    analogWrite(bluePin, 255);
    Serial.println(counter);
  }

  else if (counter == 5) {
      // phase 0: fade in red from min to max
    FadeOn(redPin);

    // phase 1: fade out blue from max to min
    FadeOff(bluePin);

    // phase 2: fade in green from min to max
    FadeOn(greenPin);

    // phase 3: fade out red from max to min
    FadeOff(redPin);

    // phase 4: fade in blue from min to max
    FadeOn(bluePin);

    // phase 5: fade out from max to min
    FadeOff(greenPin);

  }

  else {
    counter = 0;
  }
}
