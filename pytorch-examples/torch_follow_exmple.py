# 跟着例子学习PyTorch

# 先使用 numpy 实现网络。
# Numpy 提供了一个n维的数组对象, 并提供了许多操纵这个数组对象的函数.
#  Numpy 是科学计算的通用框架; Numpy 数组没有计算图, 也没有深度学习, 也没有梯度下降等方法实现的接口.
# 但是我们仍然可以很容易地使用 numpy 生成随机数据 并将产生的数据传入双层的神经网络,
#  并使用 numpy 来实现这个网络的正向传播和反向传播:

# -*- coding: utf-8 -*-

import numpy as np

# N 是一个batch的样本数量; D_in是输入维度;
# H 是隐藏层向量的维度; D_out是输出维度.
N, D_in, H, D_out = 64, 1000, 100, 10

# 创建随机的输入输出数据
x = np.random.randn(N, D_in)
y = np.random.randn(N, D_out)

# 随机初始化权重参数
w1 = np.random.randn(D_in, H)
w2 = np.random.randn(H, D_out)

learning_rate = 1e-6
for t in range(500):
    # 前向计算, 算出y的预测值
    h = x.dot(w1)
    h_relu = np.maximum(h, 0)
    y_pred = h_relu.dot(w2)

    # 计算并打印误差值
    loss = np.square(y_pred - y).sum()
    print(t, loss)

    # 在反向传播中, 计算出误差关于w1和w2的导数
    grad_y_pred = 2.0 * (y_pred - y)
    grad_w2 = h_relu.T.dot(grad_y_pred)
    grad_h_relu = grad_y_pred.dot(w2.T)
    grad_h = grad_h_relu.copy()
    grad_h[h < 0] = 0
    grad_w1 = x.T.dot(grad_h)

    # 更新权重
    w1 -= learning_rate * grad_w1
    w2 -= learning_rate * grad_w2

# Numpy 是一个伟大的框架, 但它不能利用 GPU 加速它数值计算.
#  对于现代的深度神经网络, GPU 往往是提供 50倍或更大的加速,
# 所以不幸的是, numpy 不足以满足现在深度学习的需求.
# 介绍一下最基本的 PyTorch 概念: Tensor .
# PyTorch Tensor 在概念上与 numpy 数组相同:
# Tensor 是一个n维数组, PyTorch 也提供了很多能在这些 Tensor 上操作的函数.
#  像 numpy 数组一样, PyTorch Tensor 也和numpy的数组对象一样不了解深度学习,计算图和梯度下降；
# 它们只是科学计算的通用工具.
# 然而不像 numpy, PyTorch Tensor 可以利用 GPU 加速他们的数字计算.
#  要在 GPU 上运行 PyTorch 张量, 只需将其转换为新的数据类型.

# 将 PyTorch Tensor 生成的随机数据传入双层的神经网络. 就像上面的 numpy 例子一样,
# 我们需要手动实现网络的正向传播和反向传播:
# -*- coding: utf-8 -*-

import torch


dtype = torch.FloatTensor
dtype = torch.cuda.FloatTensor # 取消注释以在GPU上运行

# N 批量大小; D_in是输入尺寸;
# H是隐藏尺寸; D_out是输出尺寸.
N, D_in, H, D_out = 64, 1000, 100, 10

# 创建随机输入和输出数据
x = torch.randn(N, D_in).type(dtype)
y = torch.randn(N, D_out).type(dtype)

# 随机初始化权重
w1 = torch.randn(D_in, H).type(dtype)
w2 = torch.randn(H, D_out).type(dtype)

learning_rate = 1e-6
for t in range(500):
    # 正向传递：计算预测y
    h = x.mm(w1)
    h_relu = h.clamp(min=0)
    y_pred = h_relu.mm(w2)

    # 计算并打印loss
    loss = (y_pred - y).pow(2).sum()
    print(t, loss)

    # 反向传播计算关于损失的w1和w2的梯度
    grad_y_pred = 2.0 * (y_pred - y)
    grad_w2 = h_relu.t().mm(grad_y_pred)
    grad_h_relu = grad_y_pred.mm(w2.t())
    grad_h = grad_h_relu.clone()
    grad_h[h < 0] = 0
    grad_w1 = x.t().mm(grad_h)

    # 使用梯度下降更新权重
    w1 -= learning_rate * grad_w1
    w2 -= learning_rate * grad_w2