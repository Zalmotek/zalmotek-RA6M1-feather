# Zalmotek Ra6M1 Feather USB Serial

A USB Serial Communication project for the Zalmotek Ra6M1 Feather board powered by Renesas RA6M1 microcontroller.

## Overview

This project demonstrates USB CDC (Communications Device Class) functionality on the Zalmotek Ra6M1 Feather board. It implements a simple USB serial interface that allows data exchange between the board and a computer, displaying a counter (0-9) over the serial connection.

## Hardware Requirements

- Zalmotek Ra6M1 Feather board
- USB cable (Type-A to micro-USB)
- Computer with USB port

## Software Requirements

- Renesas e² studio IDE
- Renesas FSP (Flexible Software Package)
- USB CDC class driver (automatically installed on most operating systems)
- Serial terminal program (such as PuTTY, TeraTerm, or Serial Monitor)

## Features

- USB CDC implementation for serial communication
- Simple counter demonstration (0-9) sent periodically
- Plug-and-play USB device recognition
- System status indication

## Code Functionality

The main application:
- Initializes the USB peripheral in CDC mode
- Handles USB events and state transitions
- Sends cyclic counter data (0-9) to the host PC
- Processes incoming data from the USB host
- Implements USB CDC protocol requirements (SET_LINE_CODING, GET_LINE_CODING, etc.)

## Getting Started

### Setup

1. Connect the Zalmotek Ra6M1 Feather board to your computer using a USB cable
2. The board should be automatically detected as a COM port device
3. Open a serial terminal program and connect to the detected COM port
4. Configure serial settings (baud rate doesn't matter for USB CDC)
5. The device will display a counter from 0-9 in sequence

### Configuration

The USB descriptor is configured in the r_usb_pcdc_descriptor.c file. Default settings are used for the CDC implementation.

## Project Structure

- `src/hal_entry.c`: Main application code handling USB initialization and event processing
- `src/r_usb_pcdc_descriptor.c`: USB descriptors for the CDC device
- `src/common_init.c/h`: Common initialization functions
- `src/board_cfg.h`: Board-specific configuration

## License

Refer to the license information in source files.

## Additional Resources

- [Zalmotek Website](https://zalmotek.com)
- [Zalmotek RA6M1 Website](https://zalmotek.com/products/RA6M1-Feather-SoM/)
- [SEGGER RTT Documentation](https://www.segger.com/products/debug-probes/j-link/technology/about-real-time-transfer/) 