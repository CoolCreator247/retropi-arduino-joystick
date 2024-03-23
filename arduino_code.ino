#include <ezButton.h>

#define VRX_PIN A0  // Arduino pin connected to VRX pin
#define VRY_PIN A1  // Arduino pin connected to VRY pin
#define SW_PIN  2   // Arduino pin connected to SW pin

ezButton button(SW_PIN);

const String buttonPressed = "button_pressed";
const String buttonReleased = "button_released";
const String joystickMove = "joystick_move";

void setup() {
  Serial.begin(9600);
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  // read analog X and Y analog values
  int xValue = analogRead(VRX_PIN);
  int yValue = analogRead(VRY_PIN);

  // Read the button value
  int bValue = button.getState();

  if (button.isPressed()) {
    Serial.println(buttonPressed);
  } else if (button.isReleased()) {
    Serial.println(buttonReleased);
  } else {
    Serial.println(joystickMove + " " + String(xValue) + " " + String(yValue));
  }
}
