#!/bin/bash

# Serial port configuration (adjust if necessary)
stty -F /dev/ttyUSB0 115200 cs8 -cstopb -parenb -icanon min 1 time 1

# Define movement thresholds (adjust based on joystick sensitivity)
x_threshold=20
y_threshold=20

# Define keyboard mappings for movement (modify as needed)
up_key="w"
down_key="s"
left_key="a"
right_key="d"

while true; do
  # Read a line from the serial port
  read LINE < /dev/ttyUSB0

  # Check if line length is valid (assuming comma-separated format)
  if [[ ${#LINE} -ge 5 ]]; then  # Minimum 5 characters for VRX, comma, and VRY
    # Extract VRX and VRY values
    read vr_x vr_y <<< $(echo "$LINE" | tr ',' ' ')

    # Handle joystick movement (adjust logic based on your key mappings)
    if [[ ${vr_x} -lt -($x_threshold) ]]; then
      # Leftward movement
      xdotool keydown "$left_key"
    elif [[ ${vr_x} -gt $x_threshold ]]; then
      # Rightward movement
      xdotool keydown
