============
rst文件基本语法
============

本文主要参考了

- [reStructuredText 语法](https://3vshej.cn/rstSyntax/)

reStructuredText 是扩展名为 .rst 的纯文本文件，含义为”重新构建的文本”，也被简称为：RST 或 reST；是 Python 编程语言的 Docutils 项目的一部分，Python Doc-SIG (Documentation Special Interest Group)。该项目类似于 Java 的 JavaDoc 或 Perl 的 POD 项目。 Docutils 能够从 Python 程序中提取注释和信息，格式化成程序文档。

.rst 文件是轻量级标记语言的一种，被设计为容易阅读和编写的纯文本，并且可以借助 Docutils 这样的程序进行文档处理，也可以转换为 HTML 或 PDF 等多种格式，或由 Sphinx-Doc 这样的程序转换为 LaTex、man 等更多格式。

首先是多级标题的写法。一级标题如上所示。

二级标题是

二级标题
============

目录使用：

.. toctree::
   :maxdepth: 2
   
不过在pycharm下预览会报错，不要紧，这是对的。

列表形式：

水平列表指令生成水平列表. 它将列表项横向显示并减少项目的间距使其较为紧凑.

.. hlist::
   :columns: 3

   * 列表
   * 的子
   * 项会
   * 水平
   * 排列