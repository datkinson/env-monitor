#Authors: Daniel Atkinson
#Version: 0.1
import serial
ser = serial.Serial('/dev/ttyUSB0', 57600) #create serial object set to ttyUSB0 at a baud rate of 57600
try:
    if ser.isOpen(): #check if serial connection is open
        reading = ser.readline() #read a line from buffer "\n" is end of line character and must be recieved otherwise it will lock up
        ser.write("recieved") #try and only get this to send if a message was actually recieved
        print reading #display message recieved in terminal
    else:
        ser.open() #try and open serial connection
