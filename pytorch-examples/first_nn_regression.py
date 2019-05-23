import torch
import numpy as np
import torch.nn.functional as F
from torch.autograd import Variable
import matplotlib.pyplot as plt

# torch和numpy
np_data = np.arange(6).reshape((2, 3))
torch_data = torch.from_numpy(np_data)
tensor2array = torch_data.numpy()
print(
    '\nnumpy', np_data,
    '\ntorch tensor', torch_data,
    '\ntensor to array', tensor2array
)

# 进行计算的时候 numpy和torch的方式也有所不同
data = np.array([[1, 2], [3, 4]])
tensor = torch.FloatTensor(data)

print(
    '\nnumpy:', data.dot(data),
    '\ntorch:', torch.mm(tensor, tensor)
)

# variable变量
variable = Variable(tensor, requires_grad=True)

t_out = torch.mean(tensor * tensor)
v_out = torch.mean(variable * variable)

print(t_out)
print(v_out)

v_out.backward()
# v_out=1/4*sum(variable*variable) d(v_out)/d(variable)=variable/2
print(variable.grad)

print(variable)

print(variable.data)

print(variable.data.numpy())

# fake data
x = torch.linspace(-5, 5, 200)  # x data (tensor) ,shape=(100,1)
x = Variable(x)
x_np = x.data.numpy()  # 为了画图，转换为numpy的数据形式

y_relu = F.relu(x).data.numpy()
y_sigmoid = F.sigmoid(x).data.numpy()
y_tanh = F.tanh(x).data.numpy()
y_softplus = F.softplus(x).data.numpy()

# plt.figure(1, figsize=(8, 6))
# plt.subplot(221)
# plt.plot(x_np, y_relu, c='red', label='relu')
# plt.ylim((-1, 5))
# plt.legend(loc='best')
#
# plt.subplot(222)
# plt.plot(x_np, y_sigmoid, c='red', label='sigmoid')
# plt.ylim((-0.2, 1.2))
# plt.legend(loc='best')
#
# plt.subplot(223)
# plt.plot(x_np, y_tanh, c='red', label='tanh')
# plt.ylim((-1.2, 1.2))
# plt.legend(loc='best')
#
# plt.subplot(224)
# plt.plot(x_np, y_softplus, c='red', label='softplus')
# plt.ylim((-0.2, 6))
# plt.legend(loc='best')

# plt.show()

# 关系拟合
# unsqueeze见文档（不知道什么用法的都去查文档，文档很清楚）
x = torch.unsqueeze(torch.linspace(-1, 1, 100), dim=1)  # x data (tensor),shape=(100,1)
y = x.pow(2) + 0.2 * torch.rand(x.size())  # noisy y data (tensor), shape=(100, 1)
print(x)
print(y)
# 用 Variable 来修饰这些数据 tensor
x, y = Variable(x), Variable(y)


# 画图
# plt.scatter(x.data.numpy(), y.data.numpy())
# plt.show()

# 建立神经网络
class Net(torch.nn.Module):  # 继承 torch 的 Module
    def __init__(self, n_feature, n_hidden, n_output):
        super(Net, self).__init__()  # 继承 __init__ 功能
        # 定义每层用什么样的形式
        self.hidden = torch.nn.Linear(n_feature, n_hidden)  # 隐藏层线性输出
        self.predict = torch.nn.Linear(n_hidden, n_output)  # 输出层线性输出

    def forward(self, x):  # 这同时也是 Module 中的 forward 功能
        # 正向传播输入值, 神经网络分析出输出值
        x = F.relu(self.hidden(x))  # 激励函数(隐藏层的线性值)
        x = self.predict(x)  # 输出值
        return x


net = Net(1, 10, 1)
print(net)  # net 的结构

# 训练神经网络，optimizer 是训练的工具
optimizer = torch.optim.SGD(net.parameters(), lr=0.5)  # 传入 net 的所有参数, 学习率
loss_func = torch.nn.MSELoss()  # 预测值和真实值的误差计算公式 (均方差)

plt.ion()  # 画图
plt.show()
for t in range(100):
    prediction = net(x)  # 喂给 net 训练数据 x, 输出预测值

    loss = loss_func(prediction, y)  # 计算两者的误差

    optimizer.zero_grad()  # 清空上一步的残余更新参数值
    loss.backward()  # 误差反向传播, 计算参数更新值
    optimizer.step()  # 将参数更新值施加到 net 的 parameters 上
    # 接着上面来
    if t % 5 == 0:
        # plot and show learning process
        plt.cla()
        plt.scatter(x.data.numpy(), y.data.numpy())
        plt.plot(x.data.numpy(), prediction.data.numpy(), 'r-', lw=5)
        plt.text(0.5, 0, 'Loss=%.4f' % loss.data[0], fontdict={'size': 20, 'color': 'red'})
        plt.pause(0.1)
