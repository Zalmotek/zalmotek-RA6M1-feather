# Zalmotek Ra6M1 Feather DAC

Digital-to-Analog Converter (DAC) example for Zalmotek Ra6M1 Feather board powered by Renesas RA6M1.

## Overview

This project demonstrates DAC functionality on the Zalmotek Ra6M1 Feather board using Renesas RA6M1 microcontroller. The example allows users to input DAC values (1-4095) which are converted to analog output. This analog output is then fed back to an ADC channel for verification, with results displayed via RTT Viewer.

## Hardware Requirements

- Zalmotek Ra6M1 Feather board
- J-Link compatible debugger
- USB cable for power and communication

## Software Requirements

- e² studio IDE
- FSP (Flexible Software Package)
- J-Link RTT Viewer
- Renesas RA6M1 toolchain

## Features

- DAC output with 12-bit resolution (values 0-4095)
- ADC feedback to verify DAC conversion
- Real-time user input via RTT Viewer
- Configurable output range

## Code Functionality

The main application:
- Initializes the DAC module on the Ra6M1 Feather board
- Configures the ADC for reading the converted analog value
- Processes user input from RTT Viewer (values 1-4095)
- Sets the DAC output value based on user input
- Reads the corresponding ADC value for verification
- Displays ADC reading on RTT Viewer

## Getting Started

### Setup

1. Connect the Zalmotek Ra6M1 Feather board to your computer
2. Open the project in e² studio
3. Build and flash the project to the board
4. Open J-Link RTT Viewer to interact with the application
5. Follow the on-screen instructions to enter DAC values

### Configuration

The DAC has a valid input range of 1-4095:

```c
#define DAC_MIN_VAL   (1)
#define DAC_MAX_VAL   (4095)
```

## Project Structure

- `src/hal_entry.c`: Main application code with DAC and ADC functionality
- `src/dac_ep.h`: Header file with DAC-related definitions and constants
- `src/common_utils.h`: Utility functions for the application
- `src/SEGGER_RTT/`: RTT implementation for communication

## License

BSD-3-Clause License

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA6M1 Website](https://zalmotek.com/products/RA6M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 