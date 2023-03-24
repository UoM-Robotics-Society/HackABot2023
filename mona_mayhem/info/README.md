# Information 
![ICE9Robotics](Ice9.jpg?raw=true "Ice9Robotics")
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

Arduino Pins| Function| Input/Output Values
---|---|---
10| Left Motor PWM| 0-255
9| Right Motor PWM| 0-255
5|Left Motor Dir| 0=FW or 1=BW
6|Right Motor Dir| 0=FW or 1=BW
2| Motor Left Encoder| INT0 , 0 or 1 
3| Motor Right Encoder| INT1 , 0 or 1 
13| LED 1 (Top)| 0=OFF or 1=ON 
12| LED 2 (Bottom)| 0=OFF or 1=ON 
11| LED Light Module| 0=OFF or 1=ON 
4| IR Enable| Output: 0=OFF or 1=ON 
A7| Received IR Right| 0 (white obstacle) or 1023 (no obstacle) 
A0| Received IR Front-Right| 0 (white obstacle) or 1023 (no obstacle)
A1| Received IR Front| 0 (white obstacle) or 1023 (no obstacle)
A2| Received IR Front-Left| 0 (white obstacle) or 1023 (no obstacle) 
A3| Received IR Left| 0 (white obstacle) or 1023 (no obstacle)
