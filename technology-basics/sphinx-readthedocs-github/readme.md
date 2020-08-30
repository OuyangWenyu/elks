# Sphinx+ReadtheDocs+GitHub

了解如何使用Sphinx+ReadtheDocs+GitHub给自己的项目添加文档。主要参考的资料有：

- [如何用Sphinx 、GitHub 、ReadtheDocs、搭建写书环境](https://wtf.readthedocs.io/en/latest/)
- [使用ReadtheDocs托管文档](https://www.xncoding.com/2017/01/22/fullstack/readthedoc.html)
- [使用ReadtheDocs给项目添加教程文档](https://www.iamlightsmile.com/articles/%E4%BD%BF%E7%94%A8ReadtheDocs%E7%BB%99%E9%A1%B9%E7%9B%AE%E6%B7%BB%E5%8A%A0%E6%95%99%E7%A8%8B%E6%96%87%E6%A1%A3/)
- [Welcome to Python-OpenSource-Project-Developer-Guide’s documentation!](http://www.wbh-doc.com.s3.amazonaws.com/Python-OpenSource-Project-Developer-Guide/index.html)
- [如何给自己的 python 项目添加免费在线文档 ?](https://juejin.im/post/6844903955059884046)

简单了解之后，个人认为这套工具的协作方式是这样的：

- Sphinx 是一个文档生成工具，可以把自己写的markdown或者RST的文件转成html以供在浏览器端显示，本地可以安装它来写文档测试生成html
- github 就是自己的代码仓网上托管的地方，github上也可以写文档，比如直接写md文件，直接用wiki，但是格式效果上都一般，所以主要是存代码，如果要更好地整理文档，还是尝试用ReadtheDocs
- ReadtheDocs 是一个在线文档托管服务，可以从各种版本控制系统中导入文档，那么每次提交代码后可以自动构建并上传至readthedocs网站，然后github项目地md文件只需给个链接即可访问到该文档。

简而言之，就是自己在自己代码项目里写RST文件，用本地的Sphinx来使对文档做配置，也可以预览自己的文件效果，然后上传到github，github和 ReadtheDocs 联系起来，ReadtheDocs就会自动监测github的更新，然后会自动生成html文档并给地址链接，将链接放到自己github项目的md文件下即可。

首先本地安装使用sphinx。

直接使用conda或者pip安装即可

```Shell
conda install -c conda-forge sphinx
pip install sphinx
```

接下来安装一些sphinx的相关插件。

```Shell
conda install -c conda-forge sphinx-autobuild sphinx_rtd_theme recommonmark
```

接下来进入项目实际上添加一个文档，这里就以现在这个项目为例。首先进入项目根目录，创建一个专门放文档的文件夹，并进入该文件夹。

```Shell
mkdir docs
cd docs
```

然后执行:

```Shell
sphinx-quickstart
```

这样就进入sphinx的配置。参考的配置如下：

```Shell
> Separate source and build directories (y/n) [n]: y
> Project name: elks
> Author name(s): owenyy
> Project release []: 0.1.0
> Project language [en]: zh_CN
```

可以查看文件目录：

```Shell
$ sudo apt install tree
$ tree --dirsfirst

.
├── build
├── source
│   ├── _static
│   ├── _templates
│   ├── conf.py
│   └── index.rst
├── Makefile
└── make.bat
```

可以看到source文件夹下面已经有了index.rst文件，是一个最简单的初始的文档。

接下来进行一些sphinx的配置，首先是主题配置，在conf.py文件中，可以看到默认的主题是html_theme = 'alabaster'。将其修改为sphinx_rtd_theme，将以下内容填入config.py即可

```Python
import os
import sys
sys.path.insert(0, os.path.abspath('.'))
import sphinx_rtd_theme
html_theme = "sphinx_rtd_theme"
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]
```

如果想要支持markdown，将以下内容填入到config.py

```Python
extensions = [
    'recommonmark'
]
```

现在build项目来看看效果，docs目录下执行，如果没有make工具，需要安装下：

```Shell
sudo apt install make 
make html
```

然后进入build/html目录后用浏览器打开index.html，即可看到效果，注意不要在jupyter中打开，因为这样看不到正常效果。


接下来看看如何使用ReadtheDocs给项目添加教程文档。

进入[readthedocs官网](https://readthedocs.org/)，注册自己的账号，注册之后验证自己的邮箱，然后 Connect your Accounts 连接到自己的github账号。

在导入github项目到readmedocs之前先将刚刚创建好的docs推送上github，然后再来关联。推送的时候注意在tignore文件中添加build/目录：

```.gitignore
/docs/build/
```

然后推送：

```git
git add -A
git commit -m 'update elks'
git push
```

进入ReadtheDocs个人面板，点击Import a Project，然后会刷新出自己github下的public项目，如果项目列表为空或者未显示当前项目，点击右上角等待刷新项目即可。这里我选择elks。然后勾选“编辑项目高级选项”，点击“下一页”。

自己填写内容，这里我的填写：

- Description：elks项目的中文文档
- 语言: Simplified Chinese

这时候如果就直接点击“Build version”，进行项目构建，可能会报错：

Sphinx error: master file [..]/checkouts/latest/contents.rst not found

根据：[Sphinx error: master file [..]/checkouts/latest/contents.rst not found](https://github.com/readthedocs/readthedocs.org/issues/2569)的说明，需要在conf.py文件中加入：

```Python
master_doc = 'index'
```

这样再重新git push，再尝试即可。
