#!/usr/bin/env python
# process_bag.py
# Reads ROS bag and generates graph

import bagpy
from bagpy import bagreader
import pandas as pd

b = bagreader('test1.bag')

# replace the topic name as per your need
TF_MSG = b.message_by_topic(topic='/tf')
CAP_MSG = b.message_by_topic(topic='/capacitance')
tf = pd.read_csv(TF_MSG)
cap = pd.read_csv(CAP_MSG)
