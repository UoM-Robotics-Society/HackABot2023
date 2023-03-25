# Importing Libraries
import serial
import time
arduino = serial.Serial(port='COM9', baudrate=9600, timeout=.1)
while True:
    time.sleep(2)
    data = arduino.readline()
    print(data)
