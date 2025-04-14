# Zalmotek Ra6M1 Feather Lidar I2C

A TF-Luna Lidar distance sensor integration with Zalmotek Ra6M1 Feather board powered by Renesas RA6M1 microcontroller using I2C communication.

## Overview

This project demonstrates how to interface a TF-Luna Lidar distance sensor with the Zalmotek Ra6M1 Feather board using I2C communication. The application continuously reads distance and signal strength measurements from the sensor and outputs the data through the debug console. This showcases the I2C master capabilities of the Renesas RA6M1 microcontroller.

## Hardware Requirements

- Zalmotek Ra6M1 Feather board 
- TF-Luna Lidar distance sensor
- Connecting wires
- USB cable for power and programming

## Software Requirements

- Renesas e² studio IDE
- Renesas FSP (Flexible Software Package)
- Git (optional, for version control)
- Serial terminal program (for viewing output)

## Features

- I2C communication with TF-Luna Lidar sensor
- Real-time distance measurement
- Signal strength monitoring
- Configurable sampling rate
- Debug output via SEGGER RTT

## Code Functionality

The main application:
- Initializes I2C communication with the TF-Luna sensor (address 0x10)
- Continuously sends data request commands to the sensor
- Reads 7 bytes of data containing distance and signal strength information
- Processes and displays the measurements through debug output
- Implements a 10ms delay between measurements for stable readings

## Getting Started

### Setup

1. Connect the TF-Luna sensor to the Ra6M1 Feather board:
   - VCC to 3.3V
   - GND to GND
   - SDA to I2C SDA pin
   - SCL to I2C SCL pin
2. Open the project in Renesas e² studio
3. Build the project
4. Program the Ra6M1 Feather board
5. Open a serial terminal to view the sensor readings

### Configuration

The I2C communication can be configured by modifying the device address and timing:

```c
uint8_t deviceAddress = 0x10;  // TF-Luna device I2C address

// In the main loop:
R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);  // Sampling rate
```

## Project Structure

- `src/hal_entry.cpp`: Main application code with sensor communication
- `src/Wire.h`: I2C communication library
- `src/i2c_op.h`: I2C operation helper functions
- `src/common_utils.h`: Common utility functions
- `src/SEGGER_RTT/`: Debug output capability

## License

Proprietary - Zalmotek

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA6M1 Website](https://zalmotek.com/products/RA6M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 