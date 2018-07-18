# basics-multiplespislaves
**Basics series**: Multiple SPI slaves talking to the same Arduino Nano (TFT Display and MAX6675 Thermocouple to Digital converter)

The table below lists which pins are connected together.

| Nano Pin | SPI Name | MAX6675 Pin | XC4629 Pin |
|----------|----------|-------------|------------|
| D10      | SS*      |             |            |
| D11      | MOSI     |             | SDI        |
| D12      | MISO     | SO          |            |
| D13      | SCK      | SCK         | CLK        |

*Please note that SS (Slave Select) above, when used on pin 10, is used to determine whether the Arduino is a slave if it's an input, NOT as the selector for a slave to communicate with. Arduino isn't wired up to be an SPI slave (apparently), it can only be a master. None the less, the TFT library examples use Pin 10 for this purpose. To avoid confusion in this example I have chosen alternative pins for the slave select pins for each device.

In addition to the shared SPI pins, the following specific connections are also required (any nano pin can be used for these):

| Nano Pin | SPI Name | MAX6675 Pin | XC4629 Pin |
|----------|----------|-------------|------------|
| D7       | SS       |             | CS         |
| D4       | SS       | CS          |            |
| D9       |          |             | RS         |
| D8       |          |             | RST        |

SPI: 10 (SS), 11 (MOSI), 12 (MISO), 13 (SCK). These pins support SPI communication, which, although provided by the underlying hardware, is not currently included in the Arduino language.

## References
* https://www.circuitsathome.com/mcu/running-multiple-slave-devices-on-arduino-spi-bus/
* https://www.arduino.cc/en/reference/SPI
* https://github.com/adafruit/MAX6675-library
* https://www.thermocoupleinfo.com/thermocouple-color-codes.htm
* 
