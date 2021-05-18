# Serial Data Reader from 2 Sources
import rospy
from sensor_msgs.msg

import serial

ser = serial.Serial('/dev/cu.usbmodem14101')
ser2 = serial.Serial('/dev/cu.usbmodem14201')
f = open("cap_sense_5_11_20_a.txt", 'w')

for i in range(4):
    ser_bytes = ser.readline()
    print(ser_bytes)
    f.write(str(ser_bytes))

print('Serial1 Connected')

for i in range(6):
    ser2_bytes = ser2.readline()
    print(ser2_bytes)
    f.write(str(ser2_bytes))

print('Serial2 Connected')

NUM_SAMPLES = 1000
count = 0
while count < NUM_SAMPLES:
    if ser2.in_waiting > 0:
        ser2_bytes = ser2.readline()
        ser2_bytes = ser2_bytes[0:len(ser2_bytes)-2].decode("latin-1")
        print(str(ser2_bytes), ', ')
        f.write(str(ser2_bytes))
        f.write(', ')
        while ser2.in_waiting == 0:
            if ser.in_waiting > 0:
                ser_bytes = ser.readline()
                ser_bytes = ser_bytes[0:len(ser_bytes)-2].decode("latin-1")
                print(str(ser_bytes), ', ')
                f.write(str(ser_bytes))
                f.write(', ')

        f.write('\n')
        ser.reset_input_buffer()
        count = count + 1

f.close()
