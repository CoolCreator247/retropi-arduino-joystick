const int vrXPin = A0;  // Replace with your VRX pin
const int vrYPin = A1;  // Replace with your VRY pin
const int threshold = 50;  // Adjust threshold for analog reading sensitivity

int vrXValue = 0;
int vrYValue = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ;  // Wait for serial connection
  }
}

void loop() {
  vrXValue = analogRead(vrXPin);
  vrYValue = analogRead(vrYPin);

  // Apply threshold (optional) to avoid sending small joystick movements
  if (abs(vrXValue - 512) > threshold) {
    vrXValue = map(vrXValue, 0, 1023, -127, 127);  // Map to -127 (left) to 127 (right)
  } else {
    vrXValue = 0;  // Set to 0 for small movements (centered)
  }

  if (abs(vrYValue - 512) > threshold) {
    vrYValue = map(vrYValue, 0, 1023, -127, 127);  // Map to -127 (up) to 127 (down)
  } else {
    vrYValue = 0;  // Set to 0 for small movements (centered)
  }

  // Send VRX and VRY values over serial (modify format if needed)
  Serial.print(vrXValue);
  Serial.print(',');
  Serial.println(vrYValue);
}
