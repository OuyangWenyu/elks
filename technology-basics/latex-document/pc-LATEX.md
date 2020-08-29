# Tex Live + VS Code

使用LATEX离线版，首先需要安装LATEX的一个版本，然后配置对应的编辑器。

## Tex Live 安装

根据[官网](https://www.latex-project.org/get/)介绍，LATEX有几种不同的版本，在windows下的推荐是MikTeX，proTeXt或者Tex Live，三者中好像只有Tex Live是跨平台的，因此，这里就选择它了。TeX Live网站：http://www.tug.org/texlive/ ，文档：http://www.tug.org/texlive/doc.html

首先，获取TeX Live：http://www.tug.org/texlive/acquire.html ，文档推荐的方式是在线安装，那就在线吧：http://www.tug.org/texlive/acquire-netinstall.html

下载windows下的exe包。点击运行。可能提示不安全，不要紧，可以允许。然后接下来按照提示依次执行下去即可。然后会弹出一个GUI的安装窗口。我就直接默认安装了。因为这是个在线安装，应该是边下载边安装的，所以整个安装过程还是比较耗时的，耐心等待即可，在这期间可以继续下面的安装。

## 配置VSCode

VS Code是一个代码神器，配合LATEX插件使用，颜值高，效果好，所以是一个不错的选择。这里主要参考：[使用VSCode编写LaTeX](https://zhuanlan.zhihu.com/p/38178015) 来完成相关的编辑器配置。

VSCode的安装配置可以参考：[史上最全vscode配置使用教程](https://zhuanlan.zhihu.com/p/113222681)

打开VSCode，在扩展商店安装 LATEX Workshop 插件。

新建一个tex源文件，这里是Test.tex，简单写入一些命令，可以看到代码已经被高亮显示了。关于如何编辑一个LATEX文件，可以参考本文件夹下 online-LATEX 里的内容。

接下来，修改LATEX Workshop 的配置。Ctrl+Shift+P 打开搜索框，输入 settings.json 搜索到该设置文件并打开。

然后将以下代码放入设置区内：

``` JSON
"latex-workshop.latex.tools": [
    {
        // 编译工具和命令
        "name": "xelatex",
        "command": "xelatex",
        "args": [
            "-synctex=1",
            "-interaction=nonstopmode",
            "-file-line-error",
            "-pdf",
            "%DOCFILE%"
        ]
    },
    {
        "name": "pdflatex",
        "command": "pdflatex",
        "args": [
            "-synctex=1",
            "-interaction=nonstopmode",
            "-file-line-error",
            "%DOCFILE%"
        ]
    },
    {
        "name": "bibtex",
        "command": "bibtex",
        "args": [
            "%DOCFILE%"
        ]
    }
],

"latex-workshop.latex.recipes": [
    {
        "name": "xelatex",
        "tools": [
            "xelatex"
        ],
    },
    {
        "name": "pdflatex",
        "tools": [
            "pdflatex"
        ]
    },
    {
        "name": "xe->bib->xe->xe",
        "tools": [
            "xelatex",
            "bibtex",
            "xelatex",
            "xelatex"
        ]
    },
    {
        "name": "pdf->bib->pdf->pdf",
        "tools": [
            "pdflatex",
            "bibtex",
            "pdflatex",
            "pdflatex"
        ]
    }
],
```

稍微解释下配置的内容，主要参考了：[LaTeX技巧932：如何配置Visual Studio Code作为LaTeX编辑器[新版更新]](https://www.latexstudio.net/archives/12260.html)

VS Code 默认添加了3个编译工具（tools）：分别是 latexmk，pdflatex 和 bibtex（所有的工具只编译一次）。编译 tex 文档方法，使用右键，选择 Build LaTeX Project（快捷键：Ctrl+Alt+B），默认使用 latexmk，查看 PDF 文件使用快捷键：Ctrl+Alt+V。 上面第一组设置命令，是可以配置三个编译工具里面具体的参数。


为了添加其他的编译方式（比如 xelatex），需要修改 LaTeX Workshop 的配置。中文环境常用的 xelatex，所以可以使用xelatex，这涉及第二组配置，配置的是编译链，没看到原blog有解释，应该是说编译过程中使用的工具配置。

使用viewer 可以配置外置阅读器，这里我还是选择使用内置的，所以就不配置了。

配置完成后，界面切到Test.tex，可以看到文件工具栏里有View LaTex PDF file 的图标（或者快捷键：Ctrl+Alt+V），点击就可以预览pdf文件。

## 管理参考文献

这部分主要参考了：[如何在LaTeX写作中管理参考文献?](https://www.zhihu.com/question/23565739)