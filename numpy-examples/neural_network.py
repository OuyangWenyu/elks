"""用numpy手写神经网络"""
import numpy as np

# 首先是标定神经网络的结构
NN_ARCHITECTURE = [{"input_dim": 2, "output_dim": 1, "activation": "relu"},
                   {"input_dim": 2, "output_dim": 1, "activation": "relu"},
                   {"input_dim": 2, "output_dim": 1, "activation": "relu"},
                   {"input_dim": 2, "output_dim": 1, "activation": "relu"},
                   {"input_dim": 2, "output_dim": 1, "activation": "relu"}]


def init_layers(nn_architecture, seed=99):
    """然后对权重进行初始化，为了保证每次计算的结果一致，初始化种子使用同样的值"""
    # 首先随机初始化种子
    np.random.seed(seed)
    # 初始化关键变量
    number_of_layers = len(nn_architecture)
    params_values = {}
    for idx, layer in enumerate(nn_architecture):
        layer_idx = idx+1
        layer_input_size = layer["input_dim"]
        layer_output_size = layer["output_dim"]
        # 对每一层，初始化W矩阵和向量b。要注意矩阵和向量的维度，因为
        params_values['W'+str(layer_idx)] = np.random.randn(
            layer_output_size, layer_input_size)*0.1
        params_values['b'+str(layer_idx)
                      ] = np.random.randn(layer_output_size, 1)*0.1
    return params_values


def sigmoid(z):
    """sigmoid激活函数"""
    return 1/(1+np.exp(-z))


def sigmoid_backward(parameter_list):
    """sigmoid函数导数"""
    pass


def relu(z):
    """relu激活函数"""
    return np.maximum(0, z)


def relu_backward(parameter_list):
    """relu函数导数"""
    pass
