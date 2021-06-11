# Open Hand Capacitive Sensing ROS

## Overview
The purpose of this package is to manage the sensor integration through ROS. AprilTags are used as the ground truth pose representation of the robot finger. ROS is used to synchronize pose measurements to the capacitive values from the TI FDC2214 capacitive sensing chip. 

## Requirements
Python
- bagpy
- numpy
- pandas
- matplotlib
- serial

ROS Packages
- usb_cam
- image_proc
- apriltag_ros
- (local) cap_sense

## Scripts

`launch_tag.launch`: runs the ROS nodes for getting AprilTag transforms and capacitive sensor values

`record_bag.sh`: runs rosbag command to record the transform and capacitive values to a rossbag

`process_bag.py`: transforms bag file output to csv files

`graph.py`: graphs the transforma and capacitance values from the csv files

## Packages

`apriltag_ros`: contains config files used to define the AprilTags used and its measured size

`cap_sense`: reads capacitive sensor values from FDC2214 over serial and publishes them as the rostopic 'capacitance'
