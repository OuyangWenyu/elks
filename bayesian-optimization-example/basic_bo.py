"""贝叶斯优化是对计算耗费大的函数进行优化时一种常用的方法，详情可参见https://github.com/fmfn/BayesianOptimization.
这里是一个贝叶斯优化的示例程序"""
from bayes_opt import BayesianOptimization
from bayes_opt.observer import JSONLogger
from bayes_opt.event import Events
from bayes_opt.util import load_logs


def black_box_function(x, y):
    """Function with unknown internals we wish to maximize.

    This is just serving as an example, for all intents and
    purposes think of the internals of this function, i.e.: the process
    which generates its output values, as unknown.
    """
    return -x ** 2 - (y - 1) ** 2 + 1


# Bounded region of parameter space
pbounds = {'x': (2, 4), 'y': (-3, 3)}

optimizer = BayesianOptimization(
    f=black_box_function,
    pbounds=pbounds,
    verbose=2,  # verbose = 1 prints only when a maximum is observed, verbose = 0 is silent
    random_state=1,
)

optimizer.maximize(
    init_points=2,
    n_iter=3,
)

print(optimizer.max)

for i, res in enumerate(optimizer.res):
    print("Iteration {}: \n\t{}".format(i, res))

optimizer.set_bounds(new_bounds={"x": (-2, 3)})

optimizer.maximize(
    init_points=0,
    n_iter=5,
)

optimizer.probe(
    params={"x": 0.5, "y": 0.7},
    lazy=True,
)

optimizer.maximize(init_points=0, n_iter=0)

logger = JSONLogger(path="./logs.json")
optimizer.subscribe(Events.OPTMIZATION_STEP, logger)
optimizer.maximize(
    init_points=2,
    n_iter=3,
)

new_optimizer = BayesianOptimization(
    f=black_box_function,
    pbounds={"x": (-2, 2), "y": (-2, 2)},
    verbose=2,
    random_state=7,
)
print(len(new_optimizer.space))

load_logs(new_optimizer, logs=["./logs.json"]);

print("New optimizer is now aware of {} points.".format(len(new_optimizer.space)))

new_optimizer.maximize(
    init_points=0,
    n_iter=10,
)
