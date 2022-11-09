#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# File: demo.py

import os, cv2
from pickled import *
from load_data import *

# data_path = r'/home/rec_robot/recycle/keras/cifar10Dataset-master/data'
# file_list = r'/home/rec_robot/recycle/keras/cifar10Dataset-master/data/images.lst'
# save_path = "\\home\\rec_robot\\recycle\\keras\\cifar10Dataset-master\\batch"

if __name__ == '__main__':
  data, label, lst = read_data(r"/home/rec_robot/recycle/batch/imagelist_test.lst", "/home/rec_robot/recycle/keras/cifar10Dataset-master/testing", shape=32)
  '''file_path, data_path'''
  pickled(os.path.join("home","rec_robot","recycle","batch"), data, label, lst, bin_num = 1)
  '''save_path'''


