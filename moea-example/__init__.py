"""使用一个moea多目标优化进化算法的框架，基于python的platypus"""
from platypus import NSGAII, Problem, Real, GAOperator, SBX, PM


class Belegundu(Problem):

    def __init__(self):
        # 定义决策变量，目标函数和约束的个数
        super(Belegundu, self).__init__(2, 2, 2)
        # 各个决策变量的取值范围
        self.types[:] = [Real(0, 5), Real(0, 3)]
        # 约束的形式
        self.constraints[:] = "<=0"

    def evaluate(self, solution):
        # 可以把变量一个个取出，也可以数组直接赋值
        x = solution.variables[0]
        y = solution.variables[1]
        params = solution.variables
        # objectives是目标函数
        solution.objectives[:] = cal_fitness(params)
        # 定义解的约束
        solution.constraints[:] = [-x + y - 1, x + y - 7]


def fx1(params):
    x = params[0]
    y = params[1]
    return -2 * x + y


def fx2(params):
    x = params[0]
    y = params[1]
    return 2 * x + y


def cal_fitness(params):
    return [fx1(params), fx2(params)]


# 算法不仅可以用默认值，也可以指定种群数量，指定交叉(用的Variation表示交叉和变异，用Mutation表示变异)、变异等具体操作运算，
# 比如使用GAOperator，遗传算法算子，可以使用SBX做交叉重组运算和PM做变异运算。在具体的交叉变异函数里，定义相应的交叉率，交叉分布指数，变异率，变异分布指数等
algorithm = NSGAII(Belegundu(), population_size=500, variator=GAOperator(SBX(0.95, 20.0), PM(2, 25.0)))
algorithm.run(10000)

# plot the results using matplotlib
import matplotlib.pyplot as plt

plt.scatter([s.objectives[0] for s in algorithm.result],
            [s.objectives[1] for s in algorithm.result])
plt.xlim([-10, 3])
plt.ylim([0, 13])
plt.xlabel("$f_1(x)$")
plt.ylabel("$f_2(x)$")
plt.show()
