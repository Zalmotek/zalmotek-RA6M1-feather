# Zalmotek RA6M1 Feather SPI MAX31723

A temperature sensing project using Zalmotek RA6M1 Feather board with Renesas technology to interface with a MAX31723 temperature sensor via SPI.

## Overview

This project demonstrates SPI communication between the Zalmotek RA6M1 Feather board and a MAX31723 digital temperature sensor. It uses the SCI-SPI peripheral of the Renesas RA6M1 microcontroller to read temperature values in Celsius and outputs the readings over USB serial.

## Hardware Requirements

- Zalmotek RA6M1 Feather board 
- MAX31723 temperature sensor
- USB cable for power and communication
- Connecting wires

## Software Requirements

- Renesas e² studio IDE
- Renesas FSP (Flexible Software Package)
- J-Link debugger software

## Features

- SPI communication with MAX31723 temperature sensor
- 12-bit temperature resolution configuration
- USB CDC serial output of temperature readings
- Error detection and handling

## Code Functionality

The main application:
- Initializes the SPI interface for communication with the MAX31723 sensor
- Configures the sensor for 12-bit temperature resolution
- Periodically reads temperature values from the sensor
- Formats and outputs temperature readings via USB serial
- Implements error handling for SPI communication failures

## Getting Started

### Setup

1. Connect the MAX31723 sensor to the RA6M1 Feather board:
   - Connect the sensor's CS pin to P210 (SPI CS)
   - Connect SPI clock and data pins according to the board's SPI interface
2. Connect the RA6M1 Feather board to your computer via USB
3. Open the project in e² studio
4. Build and flash the application to the board
5. Open a serial terminal to view temperature readings

### Configuration

The MAX31723 sensor is configured for 12-bit resolution with the following code:

```c
/* Value for configuration register write. Set resolution as 12-bits*/
const uint8_t config_sensor[3] =
{
 0x80, 0x06
};
```

## Project Structure

- `src/hal_entry.c`: Main application entry point and control flow
- `src/spi_max31723.h`: MAX31723 sensor interface implementation
- `src/usb_uart.h`: USB CDC serial communication implementation
- `src/common_utils.h`: Common utility functions and definitions

## License

Proprietary - Zalmotek

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA6M1 Website](https://zalmotek.com/products/RA6M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 