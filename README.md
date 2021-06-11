# open-hand-capacitive-sense

This repository contains packages and scripts related to the Open Hand capacitive sensing project. The goal of the project is to use capacitive sensing for the sensing of joint pose on the Model O Yale OpenHand project (https://www.eng.yale.edu/grablab/openhand/model_o.html#about). 

## Model O
The Model O has 3 articulated fingers attached to a base that are controlled by motorized pivots for abduction and adduction. The finger joints are made of flexible urethane and are actuated by tendons attached to motors in the hand base. Due to the flexible nature of the fingers, they may deflect of flex when grasping an object.

## Capacitive sensing 
Texas Intrument's FDC2214 chip provides low power capacitive sensing. Currently, small PCB electrodes are used in order to try to encode joint angles in the finger base.

## Directories
- Each directory contains its own README with more specific information for each component
- DYNAMIXEL_XM430
    * scripts for controlling the motors that actuate the fingers
    
- FDC2214
    * scripts for reading values from the FDC2214 chip
    
- ROS
    * scripts for ROS packages for AprilTag transforms, reading capacitive sensor data, and plotting
    
- PCB
    * files for the PCB electrodes
    
## Recording Procedure
Hand and FDC2214 setup procedure
1. Connect the appropriate 4-pin motor cable to the 4-pin connector on the OpenCM 9.04 motor expansion board.
2. Setup the Arduino Uno and FDC2214 for communication
3. Connect the electrode wires in the desired configuration to the FDC2214 board.
4. Power on the Arudino Uno
5. Power on the OpenCM 9.04
6. You may need to open the Arduino IDE, connect to the OpenCM 9.04 board, and start the Serial Monitor for its program to start running.


ROS AprilTag and capacitive sensing nodes procedure:
1. Run the `/ROS/launch_tag.launch` script with `roslaunch` to run all the required nodes
    * there should be both `/tf` and `/capacitance` topics
2. Run `/ROS/record_bag.sh` to record the topics

Note:
You may likely need to go into the scripts and update Serial Port information.
- `cap_sense.py`: needs the Arduino Uno Serial Port
