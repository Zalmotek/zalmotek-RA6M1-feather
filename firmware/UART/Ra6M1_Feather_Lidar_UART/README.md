# Zalmotek Ra6M1 Feather Lidar UART

A TF-Luna LiDAR sensor interface for the Zalmotek Ra6M1 Feather board powered by Renesas RA6M1 microcontroller.

## Overview

This project demonstrates how to interface a TF-Luna LiDAR sensor with the Zalmotek Ra6M1 Feather board using UART communication. The application reads distance and signal strength data from the LiDAR sensor through UART and displays the values via debug output.

## Hardware Requirements

- Zalmotek Ra6M1 Feather board 
- TF-Luna LiDAR sensor
- Connection cables/wires
- USB cable for programming and debugging

## Software Requirements

- e² studio IDE
- Renesas FSP (Flexible Software Package)
- J-Link Debugger
- Serial terminal program (optional for viewing output)

## Features

- UART communication with TF-Luna LiDAR sensor
- Real-time distance and signal strength measurement
- Serial compatibility layer for simplified communication
- Debug output via SEGGER RTT

## Code Functionality

The main application:
- Initializes the UART communication at the appropriate baud rate
- Continuously reads data packets from the TF-Luna LiDAR sensor
- Parses the incoming data to extract distance (in cm) and signal strength values
- Outputs the parsed data through debug print statements
- Implements a Serial compatibility layer for easier UART handling

## Getting Started

### Setup

1. Connect the TF-Luna LiDAR sensor to the Ra6M1 Feather board's UART pins
2. Connect the Ra6M1 Feather board to your computer via USB
3. Open the project in e² studio IDE
4. Build the project and program the Ra6M1 Feather board
5. Open a serial terminal or use RTT Viewer to see the distance and strength measurements

### Configuration

The TF-Luna LiDAR sensor communicates via UART at 115200 baud by default. The application reads 9-byte data packets and parses them to extract distance and signal strength:

```c
// Read data from UART
err = R_SCI_UART_Read(&g_uart0_ctrl, buf, BUF_SIZE);
if (FSP_SUCCESS == err && buf[0] == 0x59 && buf[1] == 0x59) {
    distance = (uint16_t)(buf[2] + buf[3] * 256);
    strength = (uint16_t)(buf[4] + buf[5] * 256);

    APP_PRINT("Distance: %u cm, strength: %u\r\n", distance, strength);
}
```

## Project Structure

- `src/hal_entry.cpp`: Main application entry point and LiDAR communication implementation
- `src/SerialCompatibility.h`: UART abstraction layer with Arduino-like serial interface
- `src/common_utils.h`: Common utility functions and macros
- `src/SEGGER_RTT/`: SEGGER real-time transfer debug output library

## License

Copyright © 2023 Zalmotek. All rights reserved.

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA6M1 Website](https://zalmotek.com/products/RA6M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 