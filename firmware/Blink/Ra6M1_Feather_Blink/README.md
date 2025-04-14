# Zalmotek RA6M1 Feather Blink

A simple LED blink application for the Zalmotek RA6M1 Feather development board powered by Renesas RA6M1 microcontroller.

## Overview

This project demonstrates the basic functionality of controlling GPIO pins on the Zalmotek RA6M1 Feather board. It toggles an LED connected to port 3, pin 1 (P301) at 300ms intervals, providing a simple, visual indication that the board is functioning correctly.

## Hardware Requirements

- Zalmotek RA6M1 Feather board
- USB cable for power and programming

## Software Requirements

- Renesas e² studio IDE
- Renesas FSP (Flexible Software Package)
- J-Link Debugger

## Features

- Simple LED blinking demonstration
- 300ms toggle interval timing using software delay
- Demonstration of GPIO pin control
- Debug output through SEGGER RTT

## Code Functionality

The main application:
- Initializes the GPIO pin (P301) for output
- Toggles the pin state between high and low with a 300ms delay
- Outputs status messages through SEGGER RTT
- Runs in a continuous loop

## Getting Started

### Setup

1. Connect the Zalmotek RA6M1 Feather board to your computer using a USB cable
2. Open the project in Renesas e² studio
3. Build the project
4. Program the board using the J-Link debugger
5. The LED will begin blinking immediately after programming

### Configuration

The LED blink application uses a simple software delay to control timing:

```c
void delay(int t) {
    R_BSP_SoftwareDelay(t, BSP_DELAY_UNITS_MILLISECONDS);
}

// In main loop
R_BSP_PinWrite(BSP_IO_PORT_03_PIN_01, BSP_IO_LEVEL_LOW);
APP_PRINT("LOW\n");
delay(300);

R_BSP_PinWrite(BSP_IO_PORT_03_PIN_01, BSP_IO_LEVEL_HIGH);
APP_PRINT("HIGH\n");
delay(300);
```

## Project Structure

- `src/hal_entry.cpp`: Main application code containing LED blink functionality
- `src/common_utils.h`: Utility functions and definitions
- `src/SEGGER_RTT/`: SEGGER Real-Time Transfer (RTT) for debug output
- `.settings/`: Project configuration settings
- `configuration.xml`: FSP configuration file

## License

Copyright © 2023 Zalmotek. All rights reserved.

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA6M1 Website](https://zalmotek.com/products/RA6M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 