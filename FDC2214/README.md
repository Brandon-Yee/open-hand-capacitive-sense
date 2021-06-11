# Open Hand Capacitive Sensing TI FDC2214

## Overview
This package manages the communication with the FDC2214 capacitive sensing chip from TI. An Arduino Uno is used to provide I2C communication with the chip, as well as to pass sensor readings over serial to a main computer. The Arduino also provides power to the chip.

## Requirements
- FDC2214 Arduino Library
    * https://github.com/zharijs/FDC2214

- The capacitive sensor script averages the first 16 readings in order to normalize the values to be more readable.
- The Github page contains the pin layout to hook up to the Arduino Uno
