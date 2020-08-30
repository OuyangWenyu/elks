# Travis-CI 简介

简单了解下项目构建测试方面一个常用的工具，并尝试用到自己的项目里。主要参考资料：

- [持续集成服务 Travis CI 教程](http://www.ruanyifeng.com/blog/2017/12/travis_ci_tutorial.html)
- [使用Travis进行持续集成](https://www.liaoxuefeng.com/article/1083103562955136)
- [如何简单入门使用Travis-CI持续集成](https://github.com/nukc/how-to-use-travis-ci)

编写代码只是软件开发的一小部分，更多的时间往往花在构建（build）和测试（test）。为了提高软件开发的效率，构建和测试的自动化工具，即持续集成的工具层出不穷。

持续集成：Continuous Integration，简称CI，意思是，在一个项目中，任何人对代码库的任何改动，都会触发CI服务器自动对项目进行构建，自动运行测试，甚至自动部署到测试环境。这样做的好处就是，随时发现问题，随时修复。因为修复问题的成本随着时间的推移而增长，越早发现，修复成本越低。

Travis CI 就是这类工具之中，市场份额最大的一个。它绑定 Github 上面的项目，只要有新的代码，就会自动抓取。然后，提供一个运行环境，执行测试，完成构建，还能部署到服务器。github上的项目如果有 build|passing 这样一个标识，就可以看出这个项目是构建成功的（让大家知道项目没有问题），如果不成功则会显示 build|failing。

使用Travis CI 的条件：

- 拥有 GitHub 帐号
- 该帐号下面有一个项目
- 该项目里面有可运行的代码
- 该项目还包含构建或测试脚本

这些条件没问题，就可以尝试使用 Travis CI 了。

首先，访问官方网站 travis-ci.org，点击右上角的sign in，使用 Github 账户登入 Travis CI。

Travis 会列出 Github 上面你的所有仓库，以及我所属于的组织。此时，选择需要 Travis 构建的仓库，打开仓库旁边的开关。一旦激活了一个仓库，Travis 会监听这个仓库的所有变化。

我这里以我fork的 et-demands 项目为例。因为这个项目已经有了这些内容，我只需要学习了解即可。

Travis 要求项目的根目录下面，必须有一个.travis.yml文件。这是配置文件，指定了 Travis 的行为。该文件必须保存在 Github 仓库里面，一旦代码仓库有新的 Commit，Travis 就会去找这个文件，执行里面的命令。

这个文件采用 YAML 格式。下面是一个 et-demands 这个 python 项目的.travis.yml文件。

```yaml
language: python

python:
  - "2.7"
  - "3.5"
  - "3.6"

install:
  - pip install pytest
  - pip install pytest-cov
  - pip install coveralls
  
script:
#  - python -m pytest
   - pytest --cov 
after_success:
  - coveralls
```

- language字段指定了默认运行环境，这里设定使用 Python 环境。
- script字段指定要运行的脚本，script: true表示不执行任何脚本，状态直接设为成功。

Travis 的运行流程很简单，任何项目都会经过两个阶段。

1. install 阶段：安装依赖
2. script 阶段：运行脚本

所以，install字段是用来指定安装脚本的。上面例子是有多个脚本，所以用 - 的形式给出多个。如果不需要安装，即跳过安装阶段，就直接设为true。

script字段用来指定构建或测试脚本。script与install不一样，如果第一个命令失败，后面会继续执行。但是，整个构建阶段的状态是失败。而install第一个失败之后，后面都不会执行了。

script阶段结束以后，还可以设置通知步骤（notification）和部署步骤（deployment），它们不是必须的。部署的脚本可以在script阶段执行，也可以使用 Travis 为几十种常见服务提供的快捷部署功能。

Travis 为上面这些阶段提供了7个钩子。

- before_install：install 阶段之前执行
- before_script：script 阶段之前执行
- after_failure：script 阶段失败时执行
- after_success：script 阶段成功时执行
- before_deploy：deploy 步骤之前执行
- after_deploy：deploy 步骤之后执行
- after_script：script 阶段之后执行

完整的生命周期，从开始到结束是下面的流程。

1. before_install
2. install
3. before_script
4. script
5. aftersuccess or afterfailure
6. [OPTIONAL] before_deploy
7. [OPTIONAL] deploy
8. [OPTIONAL] after_deploy
9. after_script

Travis 每次运行，可能会返回四种状态。

- passed：运行成功，所有步骤的退出码都是0
- canceled：用户取消执行
- errored：before_install、install、before_script有非零退出码，运行会立即停止
- failed ：script有非零状态码 ，会继续运行
