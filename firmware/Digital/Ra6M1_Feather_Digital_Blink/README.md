# Zalmotek RA6M1 Feather Digital Blink

A digital pin control example for Zalmotek RA6M1 Feather board powered by Renesas RA6M1 microcontroller.

## Overview

This project demonstrates sequential LED blinking using digital pins on the Zalmotek RA6M1 Feather board. It utilizes digital output pins D5, D6, D9, D10, D11, D12, and D13 to create a running light effect, showcasing basic GPIO functionality of the Renesas RA6M1 microcontroller.

## Hardware Requirements

- Zalmotek RA6M1 Feather board 
- LEDs or other indicators connected to pins D5, D6, D9, D10, D11, D12, and D13
- USB cable for programming and power

## Software Requirements

- Renesas e² studio IDE
- GCC ARM compiler
- Renesas FSP (Flexible Software Package)
- J-Link software for programming

## Features

- Sequential control of 7 digital output pins
- Configurable timing for LED blinking
- SEGGER RTT for debug output
- Simple GPIO initialization and control

## Code Functionality

The main application:
- Initializes the specified digital pins as outputs
- Sets up a sequential blinking pattern across the 7 pins
- Uses a 50ms delay between state changes
- Outputs pin state changes via SEGGER RTT for debugging
- Operates in a continuous loop

## Getting Started

### Setup

1. Connect the Zalmotek RA6M1 Feather board to your computer
2. Open the project in Renesas e² studio
3. Build the project
4. Program the board using J-Link
5. Observe the sequential blinking pattern on the connected LEDs

## Project Structure

- `src/hal_entry.cpp`: Main application code containing the LED blinking implementation
- `src/common_utils.h`: Common utility functions used by the application
- `src/SEGGER_RTT/`: Directory containing SEGGER RTT implementation for debug output

## License

Proprietary - Zalmotek

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA6M1 Website](https://zalmotek.com/products/RA6M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 