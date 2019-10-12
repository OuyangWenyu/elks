# 抽样算法
import matplotlib.pyplot as plt
import time
import math


def random(num=2000):
    M = 1000
    A = 3 ^ 4
    B = 1
    x_0 = time.time()
    result = [x_0]
    while len(result) < num:
        result.append((result[-1] * A + B) % M)
    result.pop(0)
    return result


result = random(2000)
xaixs = [i for i, j in enumerate(result)]
print
result[:10]
f = plt.figure(1)
p1 = plt.scatter(xaixs, result)
# p2 = plt.hist(result)
plt.show()
