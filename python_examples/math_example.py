"""数学运算中常遇的一些错误"""
# RuntimeWarning: invalid value encountered in double_scalars
kss = 0.22917998605606738
kg = 0.832161545953715
period_num_1d = 24
# 开方运算会遇到根式下为负数的情况，会得到复数，如果数据类型是float，那么运算结果会为nan
kss_period = (1 - (1 - (kss + kg)) ** (1 / period_num_1d)) / (1 + kg / kss)
print(type(kss_period))
print(kss_period)
