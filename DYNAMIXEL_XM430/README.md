# OpenHand XM430 Drivers
This package contains scripts for controlling and communicating with the Dynamixel XM430 motors and OpenCM 9.04 module from Robotis. 


## Robotis Documentation
- `Dynamixel XM430`: https://emanual.robotis.com/docs/en/dxl/x/xm430-w350/
- `OpenCM 9.04`: https://emanual.robotis.com/docs/en/parts/controller/opencm904/
    * the OpenCM is usable with the Arduino IDE as a library

## Scripts
-  `increment_control.ino`: script to run incremental control of the finger. Sending serial input `j` and `k` move the finger position by a fixed amount. The DXL_ID can be changed to match one of the 4 pin connection port on the OpenCM 9.04 for motor communication.

- `wave_finger.ino`: script to wave a finger back and forth, speed can be controlled by the PERIOD and INCR values. This script is compatible with the ROS package that reads its values over Serial. The ROS package expects capacitance values separated by newlines with no other text.
