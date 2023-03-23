# Information 

## Example HTML 

In this folder you will find a series of example HMTL script files which are examples of what the webscrapper should read, please use these to build your software to collect robot and ball poses before testing it on the arena.

the format M1,10,10,2 is robot, X, Y, Theta (rotation)

    G = Goal poses
    C = Corner poses
    B = ball pose

## Example Sketches

This folder contins example sketches on how to use the MONA system, how to communicate between 2 NRF24 modules and other helpful sketches which you may find useful to use.



## MONA Arduino Config

To configure your Arduino IDE (1.8.3 or higher, please download from: https://www.arduino.cc/en/Main/Software) and to connect and program Mona robot, please follow the setting:

    Boards: "Arduino Pro or Pro Mini"
    Processor: "ATmega328 (3.3V, 8MHz)"
    Programmer: ArduinoISP.org

### Robot's specification:
- Speed: 20 cm/s
- Five short-range IR proximity sensors (<2cm)
- Wheels' encoder (250 ppr), wheels' diameter 30 mm
- Micro USB for programming and recharging battery
- 3.7 V Li-Po battery
- Communication: RS232, I2C, SPI links

