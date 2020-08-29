# elks

日常杂记以备查，其中准备的成体系些的内容移出为独立项目。

## 主要内容

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
    
本项目以 python jupyter lab为代码展示的主要工具，python外其他语言相关库可在jupyter lab中安装实践。
因为利用xeus，可以在jupyterlab中开发不同语言的 jupyter kernel protocol，其中C++的版本是xeus-cling，可以参考：[xeus-cling](https://github.com/jupyter-xeus/xeus-cling)

注意如果需要运行本repo的C++代码，则必须要在linux或者mac环境下执行,并且不可以使用anaconda默认的conda环境，因为根据xeus-cling GitHub repo的readme文件所示，目前还不支持windows环境,
还有anaconda下xeus-cling 会有冲突导致安装失败，所以必须使用miniconda，并注意将自己的环境变量配置到miniconda下。

如果想在win10下尝试,可以先在win10下安装ubuntu,安装过程可参考:[Windows Subsystem for Linux Installation Guide for Windows 10](https://docs.microsoft.com/en-us/windows/wsl/install-win10)。

安装成功之后，可以通过wsl.exe来使用，也可以使用mobaxterm软件来连接，硬盘挂载到/mnt/文件夹下，cd /mnt 即可进入硬盘。

win10里Ubuntu下miniconda的安装和环境配置可以参考：[Win10下Ubuntu(WSL)中Python环境配置笔记](https://zhuanlan.zhihu.com/p/63897033)
windows下miniconda的安装和环境配置可以参考：[小白教程 | Miniconda安装及添加环境变量](https://mp.weixin.qq.com/s/yqyEknvYLIH5E0nMlWEDSQ?)

下面简单给出命令：

```Shell
# 进入你想要进入的文件夹位置
cd /mnt/xxx
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
./Miniconda3-latest-Linux-x86_64.sh
# 然后安装的时候选择你想要安装的位置，比如我的是：
/mnt/d/Code/miniconda3
# 接下来是否conda init，可以选择yes
yes
# 然后配置环境变量，vim /home/YOURNAME/.bashrc 我的用户名是owen，所以：
vim /home/owen/.bashrc
# 然后将自己的miniconda安装环境写入，比如我的是：
export PATH=/mnt/d/Code/miniconda3/bin:$PATH
# 保存后，执行：
source /home/owen/.bashrc
# 下面语句可以查看自己的环境变量配置
echo $PATH
# 可以查看自己的conda 版本
conda --version
```

然后安装虚拟环境以及packages如下：

```Shell
# 进入本repo根目录，比如我的是：
cd /mnt/d/Code/elks
conda create --prefix ./envs python=3.7
# 进入环境
conda activate /mnt/d/Code/elks/envs
# 如果是第一次执行conda activate,可能报错,执行conda init后,重启命令行即可
conda install -c conda-forge jupyterlab, xeus-cling
# 这里可以进入jupyter lab看看是否已有kernel，执行：
jupyter lab
# 然后命令中会出现地址，比如某一次运行我的地址是 http://127.0.0.1:8888/?token=ef73d758f3dd3ac0d8239f0df0231518a6af90ab2800598c
# 复制粘贴入你win10下的浏览器即可访问了，然后在浏览器下继续当前操作
# 进入当前环境
conda activate /mnt/d/Code/elks/envs
conda install -c conda-forge earthpy, hydrofunctions, seaborn, scikit-learn, sympy
conda install pytorch torchvision cpuonly -c pytorch
conda install -c conda-forge sphinx sphinx-autobuild sphinx_rtd_theme recommonmark
```

## 参与贡献

1. Fork 本项目
2. 新建 xxx 分支
3. 提交代码
4. 新建 Pull Request
