#!/bin/bash

roscore

roslaunch usb_cam usb_cam-test.launch

rosrun camera_calibration cameracalibrator.py --size 7x5 --square 0.31 \
image:=/usb_cam/image_raw camera:=/usb_cam

export ROS_NAMESPACE=usb_cam rosrun image_proc image_proc

rosrun image_view image_view image:=image_rect

roslaunch apriltag_ros continuous_detection.launch
