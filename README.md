# elks

日常杂记以备查，其中准备的成体系些的内容移出为独立项目。

## 主要内容

关于专业方面科普——可参考[知乎某一相关问题的回答](https://www.zhihu.com/question/56339077)。

- 常识
    - 专业
    - 其他
- 数学
    - 统计基础
    - 机器学习算法简介
- 科研
    - 文献阅读简记
- 技术
    - Ubuntu基本使用
    - latex文档
    - C/C++基本概念
    
接下来给出运行本项目中的python程序所需的packages，conda安装：

```Shell
conda create --name elks python=3.7
conda activate elks
conda config --add channels conda-forge
# 修改.condarc：固定conda-forge 和 defaults 的顺序后，执行：
conda config --set channel_priority strict
conda install -c conda-forge jupyterlab
conda install -c conda-forge matplotlib
conda install -c conda-forge seaborn
conda install -c conda-forge earthpy
conda install -c conda-forge hydrofunctions
```

## 参与贡献

1. Fork 本项目
2. 新建 xxx 分支
3. 提交代码
4. 新建 Pull Request
