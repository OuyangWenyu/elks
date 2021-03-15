# elks

日常杂记以备查，其中准备的成体系些的内容移出为独立项目。

## 主要内容

- 常识
    - 水文水资源专业
    - 其他
- 数学
    - 方程基础
    - 统计基础
    - 机器学习简介
    - 系统简记
- 科研
    - 文献阅读简记
    - 科研写作简记
- 技术
    - Ubuntu基本使用
    - latex等文档写法
    - 某些编程语言简介
    
本项目以 jupyter lab为文字和代码主要编辑工具，可以在win10下直接安装依赖包并运行。win10下miniconda的安装和环境配置可以参考：[小白教程 | Miniconda安装及添加环境变量](https://mp.weixin.qq.com/s/yqyEknvYLIH5E0nMlWEDSQ?)。

不过因为有python外其他语言相关库可能更适合Ubuntu等环境，所以推荐在win10下使用ubuntu,安装过程可参考:[Windows Subsystem for Linux Installation Guide for Windows 10](https://docs.microsoft.com/en-us/windows/wsl/install-win10)。

安装成功之后，可以通过wsl.exe来使用，也可以使用mobaxterm软件来连接，硬盘挂载到/mnt/文件夹下，cd /mnt可进入；home文件夹cd即可进入，不过在windows下，home可是藏得挺深的，应该在用户文件夹下的 \AppData\Local\Packages\CanonicalGroupLimited.Ubuntu18.04onWindows_79rhkp1fndgsc\LocalState\rootfs\home ，大致上是这个文件夹，可能细节略有出入。

win10里Ubuntu下miniconda的安装和环境配置可以参考：[Win10下Ubuntu(WSL)中Python环境配置笔记](https://zhuanlan.zhihu.com/p/63897033)

下面简单给出win10下使用Ubuntu安装本repo所需库的命令：

```Shell
# 进入你想要进入的文件夹位置
cd
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
sudo sh Miniconda3-latest-Linux-x86_64.sh
# 然后安装的时候选择你想要安装的位置，我直接默认安装了
# 接下来是否conda init，可以选择yes，这样环境应该配置好了
yes
# 如果选择了no，则自己配置环境变量：
vim ~/.bashrc
# 然后将自己的miniconda安装环境写入，比如我的是：
export PATH=/home/owen411/miniconda3/bin:$PATH
# 保存后，执行：
source ~/.bashrc
# 下面语句可以查看自己的环境变量配置
echo $PATH
# 可以查看自己的conda 版本
conda --version
# 如果有权限问题，可以给自己权限，我的名字是owen411
sudo chown -R owen411 miniconda3
```

然后安装虚拟环境：

```Shell
# 进入本repo根目录，比如我的是：
cd /mnt/e/Code/elks
# 安装环境
conda env create -f environment.yml
```

主要的packages如下：

``` text
python=3.7, jupyterlab, earthpy, hydrofunctions, seaborn, scikit-learn, sympy, pytorch, torchvision, sphinx, sphinx-autobuild, sphinx_rtd_theme, recommonmark
```

安装时间较长，需要耐心等待，安装后：

```Shell
# 进入环境
conda activate elks
# 打开jupyter
jupyter lab
# 注意如果看不到网址，可以按ctrl+c，然后按n不停止，这时候命令行界面就停在显示网址的位置了，将网址copy入win10下的浏览器即可打开jupyter
```

## 参与贡献

1. Fork 本项目
2. 新建 xxx 分支
3. 提交代码
4. 新建 Pull Request
