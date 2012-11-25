#Authors: Daniel Atkinson
#Version: 0.1
from serial import *

ser = serial.Serial('/dev/ttyUSB0', 57600) #create serial object set to ttyUSB0 at a baud rate of 57600
global last_reading
buffer = ''
def recieve(ser):
    buffer = buffer + ser.read(ser.inWaiting())
    if '\n' in buffer:
        lines = buffer.split('\n')
        last_reading = lines[-2]
        buffer = lines[-1]

while True:
    try:
        if ser.isOpen(): #check if serial connection is open
            recieve(ser) #read a line from buffer "\n" is end of line character and must be recieved otherwise it will lock up
            ser.write("recieved") #try and only get this to send if a message was actually recieved
            print last_reading #display message recieved in terminal
        else:
            ser.open() #try and open serial connection
