import serial

# Define the serial port (adjust if different on your setup)
serialPort = "/dev/ttyACM0"

# Create a Serial object
arduino = serial.Serial(serialPort, 9600)

# Map button presses to RetroPie key presses (adjust as needed)
button_map = {
  "button_pressed": "KEY_A",  # Replace "KEY_A" with your desired button press action
  "button_released": None      # No action on release for this example
}

# Function to translate joystick values to movement (replace with your preferred method)
def translate_joystick(x, y):
  # Example: Simple mapping for up/down/left/right movement
  movement = ""
  if y > 512:
    movement = "DPAD_DOWN"
  elif y < 488:
    movement = "DPAD_UP"
  if x > 512:
    movement = "DPAD_RIGHT"
  elif x < 488:
    movement = "DPAD_LEFT"
  return movement

while True:
  command = arduino.readline().decode("utf-8").strip()

  # Handle button presses/releases
  if command in button_map:
    action = button_map[command]
    if action:
      # Use a library like "evdev" to send key presses to RetroPie
      # (Specific implementation depends on your chosen library)
      print(f"Sending key press: {action}")

  # Handle joystick movement
  elif command.startswith(joystickMove):
    x, y = map(int, command.split()[2:])
    movement = translate_joystick(x, y)
    if movement:
      # Use a library like "evdev" to send joystick movement to RetroPie
      # (Specific implementation depends on your chosen library)
      print(f"Sending joystick movement: {movement}")

  else:
    print("Unknown command:", command)
