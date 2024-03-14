# I2C Basic Communication Library

This repository contains a simple implementation of Inter-Integrated Circuit (I2C) communication protocol for AVR microcontrollers. The code is written in C and intended for use with Atmel AVR series microcontrollers.
## Features

    Basic implementation of I2C communication protocol.
    Functions for initializing I2C interface, transmitting data, and receiving data.
    Configurable clock frequency.

## Getting Started

    Clone this repository to your local machine.
    Open the project in your preferred AVR development environment.
    Build and upload the code to your AVR microcontroller.

## Usage

    Modify the BITRATE macro to adjust the I2C clock frequency.
    Use TWinit() to initialize the I2C interface.
    Utilize TWtransmit() and TWreceive() functions to send and receive data over I2C bus.

## Dependencies

    AVR-GCC
    AVR Libc

## License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/therealvoric/C-ATMega644P-LM75-TempSens/blob/main/LICENSE) file for details.
