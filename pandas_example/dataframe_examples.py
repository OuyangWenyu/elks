import pandas as pd
import numpy as np

"""对dataframe进行分组的例子"""
salaries = pd.DataFrame({
    'name': ['BOSS', 'Lilei', 'Lilei', 'Han', 'BOSS', 'BOSS', 'Han', 'BOSS'],
    'Year': [2016, 2016, 2016, 2016, 2017, 2017, 2017, 2017],
    'Salary': [999999, 20000, 25000, 3000, 9999999, 999999, 3500, 999999],
    'Bonus': [100000, 20000, 20000, 5000, 200000, 300000, 3000, 400000]
})
print(salaries.columns)
print(salaries.info())
print(salaries.describe())
salaries = salaries[['name', 'Year', 'Salary', 'Bonus']]
# 定顺序
print(salaries)
# 对dataframe按name进行分组
group_by_name = salaries.groupby('name')
# 获取分组后的某一组
df1 = group_by_name.get_group('Lilei')
print(df1)
print(df1.describe())
# 循环各组，并将名字在给定的序列中的group添加到数组中
config = pd.Series({'names': ['Lilei', 'BOSS']})
dfs = []
for name, group in group_by_name:
    print(name)
    if name in config['names']:
        dfs.append(group)

for i in range(len(dfs)):
    # 如果没有把name和group分开，那么dfs[i]的类型会是tuple，key为name，value是group，可参考接下来的输出
    print(type(dfs[i]))
    print(dfs[i])

# 如果没有把name和group分开，那么dfs[i]的类型会是tuple，key为name，value是group
dfs_s = []
for group in group_by_name:
    dfs_s.append(group)
for i in range(len(dfs_s)):
    print(type(dfs_s[i]))
    print(dfs_s[i])

"""pandas与numpy数据结构之间的转换"""
# pandas dataframe与numpy array之间的转换
df = pd.DataFrame({'A': [1, 2, 3], 'B': [4, 5, 6], 'C': [7, 8, 9]})
print(np.array(df))
