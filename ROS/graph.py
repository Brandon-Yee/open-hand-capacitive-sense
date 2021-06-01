#!/usr/bin/env python

# graph.py
# Graph data from csv
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.spatial.transform import Rotation

bag_folder = './test1'
cap = pd.read_csv(bag_folder + '/capacitance.csv')
tf = pd.read_csv(bag_folder + '/tf.csv')


tf_times = tf['Time']
transforms = tf['transforms'].apply(lambda x : x.split())
transforms = pd.DataFrame(transforms.to_list())
transforms[28] = transforms[28].apply(lambda x: x[:-1])
print(transforms.iloc[0])
translation = transforms.iloc[:, 15].to_numpy().astype(float)
translation = np.vstack((translation, transforms.iloc[:, 17].to_numpy().astype(float)))
translation = np.vstack((translation, transforms.iloc[:, 19].to_numpy().astype(float)))
translation = translation.T
print(translation.shape)

quaternions = transforms.iloc[:, 22].to_numpy().astype(float)
quaternions = np.vstack((quaternions, transforms.iloc[:, 24].to_numpy().astype(float)))
quaternions = np.vstack((quaternions, transforms.iloc[:, 26].to_numpy().astype(float)))
quaternions = np.vstack((quaternions, transforms.iloc[:, 28].to_numpy().astype(float)))
quaternions = quaternions.T
print(quaternions.shape)

rotations = Rotation.from_quat(quaternions).as_euler('xyz', degrees=True)
fig, ax1 = plt.subplots(figsize=(10,6))
ax1.plot(cap['Time'], cap['data'], c='r')

ax2 = ax1.twinx()
print(tf_times.shape)
print(rotations[:,0].shape)
#ax2.plot(tf_times, rotations)
ax2.scatter(tf_times, rotations[:,0], s=1)
ax2.scatter(tf_times, rotations[:,1], s=1)
ax2.scatter(tf_times, rotations[:,2], s=1)
fig.legend(['Cap', 'X', 'Y', 'Z'])
plt.show()
