#!/usr/bin/env python
# Capacitive Sensor Publisher
import rospy
import serial
from std_msgs.msg import Int32

SERIAL_PORT = '/dev/ttyACM0'
BAUDRATE = 9600

# Capacitive sense publisher
def publish_message():
    ser = serial.Serial(SERIAL_PORT)
    pub = rospy.Publisher('capacitance', Int32, queue_size=1)
    rospy.init_node('cap_sense', anonymous=True)
    rate = rospy.Rate(100) 
    while not rospy.is_shutdown():
        if ser.in_waiting:
            bytes = ser.readline()[:-2].decode("latin-1") # remove newline + return chars
            if len(bytes) > 0:
                pub.publish(int(bytes))
                ser.reset_input_buffer()
                
        rate.sleep()

# Main        
if __name__ == '__main__':
    try:
        publish_message()
    except rospy.ROSInterruptException:
        pass
