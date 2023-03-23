# Mona Info

### The files here are to help you get started with the system, there are many GitHub repos with example sketches if you search for them, these are the main documents containing the relevant information.

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
