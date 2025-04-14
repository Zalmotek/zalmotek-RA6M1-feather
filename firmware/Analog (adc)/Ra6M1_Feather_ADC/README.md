# Zalmotek RA6M1 Feather ADC

Analog-to-Digital Converter (ADC) demonstration for the Zalmotek RA6M1 Feather board powered by Renesas.

## Overview

This project demonstrates how to use the Analog-to-Digital Converter (ADC) functionality on the Zalmotek RA6M1 Feather board featuring Renesas technology. It samples analog inputs and converts them to digital values for processing and display.

## Hardware Requirements

- Zalmotek RA6M1 Feather board
- USB cable for power and programming
- Analog input source (potentiometer, sensor, etc.)

## Software Requirements

- e2 studio IDE
- Renesas FSP (Flexible Software Package)
- USB serial driver

## Features

- Configurable ADC sampling
- Multiple input channel support
- Continuous conversion mode
- Voltage level monitoring

## Code Functionality

The main application:
- Initializes ADC hardware on specific pins
- Configures ADC resolution and reference voltage
- Performs single or continuous conversions
- Processes and outputs digital values via serial communication
- Demonstrates proper error handling

## Getting Started

### Setup

1. Connect your analog input device to the analog input pin
2. Open the project in e2 studio
3. Build the project
4. Flash the firmware to your RA6M1 Feather board
5. Open a serial terminal to view the ADC readings

### Configuration

You can modify ADC settings in the configuration:

```c
// Example ADC configuration
#define ADC_RESOLUTION_BITS 12
#define ADC_REFERENCE_VOLTAGE 3.3
```

## Project Structure

- `src/`: Main source code files
- `ra/`: Renesas configuration files
- `ra_gen/`: Auto-generated code by FSP
- `ra_cfg/`: User configuration files

## License

This project is distributed under the MIT License.

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA6M1 Website](https://zalmotek.com/products/RA6M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 