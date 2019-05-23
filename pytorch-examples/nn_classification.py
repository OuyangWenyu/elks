#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 18-7-5 下午9:09
# @Author  : Owenyy
# @Site    : 
# @File    : nn_classification.py
# @Software: PyCharm

import torch
from torch.autograd import Variable
import matplotlib.pyplot as plt

# 构造数据
n_data = torch.ones(100, 2)
x0 = torch.normal(2 * n_data, 1)
y0 = torch.zeros(100)
print(n_data)
print(x0)
print(y0)
