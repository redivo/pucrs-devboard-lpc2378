# pucrs-devboard-lpc2378

This project is a repository of functional libraries for PUCRS ARM DevBoard.
Here you can found C libraries and documentation about the board.

## Environment

For this project you have to install the following packages:
 - lpc21isp
 - gcc-arm-none-eabi

You can have these packets using apt-get.

## DevBoard info

This board was designed by Juliano Benfica in PUCRS and it was used in an academic context in
several undergraduate disciplines.

The core of the board is an ARM7 LCP2378.
It includes several peripheral devices such as:
 - USB connection
 - VGA connection
 - PS/2 connection
 - Display LCD NOKIA 6100
 - 16x2 LCD display
 - SD card connection
 - Smart Card connection
 - Thermal sensor LM75
 - LDR sensor
 - Ethernet PHY
 - Switches
 - Leds
 - GPIO pins
 - AD/DA pins
 - I²C pins
 - SPI pins

The board can be power supplied through a USB-B cable or through a 5V jack.

## Usage

For while all libraries are being compiled as static libraries and dependencies between them are not
being linked to avoid libraries too large.
So it is up to the final user to link all required libraries.
To help final user the information about direct dependencies is listed at header file documentation.

### Compiling This Project
This project uses CMakeLists.
If you are not familiar to CMakeList you can just run ```./build-project``` from the root repository
path and that script is gonna create the ```_build``` direcotry and prepare all stuff to
compilation.
Once you have your build directory ready you can run ```make``` to build or ```make install``` to
build and generate the directory ```<build path>/install/``` with all relevant artifacts.

### Compiling YOUR project
To compile your project you have to link the labraries you want use and their dependencies (listed
in lib header file).

Some recomendations:
 - Compile your ```main()``` with ```crt.o``` (included in ```<build path>/install/src```) on source
list
 - Compile your final binary to a HEX file with ```arm-none-eabi-objcopy -O ihex <main> main.hex```
 - Send to board with ```lpc21isp <build path>/main.hex /dev/tty<serial> 115200 12000```
