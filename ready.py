# Importing Libraries
import serial
import time
arduino = serial.Serial(port='COM7', baudrate=9600, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

while True:
    data = arduino.readline()
    time.sleep(0.5)
    value = write_read(num)
    #print(value) # printing the value
