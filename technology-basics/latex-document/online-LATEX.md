# 在线LATEX--Overleaf

为了快速上手LATEX，比较好的方式是使用在线的LATEX编辑工具，比较常见的工具就是overleaf了，overleaf上面有大量的模板可供参考。因此，接下来主要针对overleaf的使用做些记录。

主要参考了:

- [Overleaf guides](https://www.overleaf.com/learn/latex/Main_Page)
- [如何使用 LaTeX 排版论文](https://www.overleaf.com/articles/ru-he-shi-yong-latex-pai-ban-lun-wen/bdynvrzpqmwq)

## Learn LaTeX in 30 minutes

了解LATEX的基本功能。

### What is LaTeX?

LaTeX 是一个写专业文章的工具，基于 WYSIWYM (what you see is what you mean) 的理念，让用户专注于内容创作。

### Why learn LATEX?

排版优雅，处理公式等复杂写作内容便利，且能保持通篇一致的布局。因为有着非常多的开源包可用，其功能非常强大。还有就是有非常多的[模板](https://www.sharelatex.com/templates)可供使用。

### Writing your first piece of LATEX

第一步就是创建一个新的LATEX 项目。注册overleaf之后，直接选择一个模板导入即可。最开始的类似hello world的latex代码是这样的：

```LATEX
\documentclass{article}

\begin{document}
First document. This is a simple example, with no 
extra parameters or packages included.
\end{document}
```

第一行声明了文档的类型documentclass是article。这个class决定了整个文档的外观形式。比如有book，report等。

然后就开始书写内容，内容都在\begin{document}和\end{document}之间，是文档的body。在overleaf中，点击recompile就可以看到导出的格式了。

### The preamble of a document

在文档中，所有位于\begin{document}之前的内容都被称作preamble。在preamble中，如前所述，定义了document的类型，书写的语言，要使用的package等。比如：

```LATEX
\documentclass[12pt, letterpaper]{article}
\usepackage[utf8]{inputenc}
```

如前所述，首先定义了文档类型，[] 括号中是一些额外的参数，包括字体，还有纸张大小。

然后\usepackage定义了document的编码方式。

### Adding a title, author and date

在preamble部分添加：\title{First document}， \author{Hubert Farnsworth}，\date{February 2014}等即可。

### Adding comments

comments就是非正文的内容，但是对于自己组织自己的文章是很有帮助的。注释符号是%

### Bold, italics and underlining

一些简单的文本格式：

- Bold: Bold text in LaTeX is written with the \textbf{...} command.
- Italics: Italicised text in LaTeX is written with the \textit{...} command.
- Underline: Underlined text in LaTeX is written with the \underline{...} command.

### Adding images

在overleaf中，首先，要将图片上传上来。然后通过\includegraphics{universe}这样的形式就可以将图片上传了。

不过LATEX自己是不能管理图片的，所以需要使用package。包能帮助管理展示形式，或者运行更多的功能。图片包比如graphicx ，它包括\includegraphics{...} and \graphicspath{...}等命令，前者告诉LATEX图片的位置，后者将图片纳入文档中。

图片的一些附属信息可以通过设置来获取：

```LATEX
\begin{figure}[h]
    \centering
    \includegraphics[width=0.25\textwidth]{mesh}
    \caption{a nice plot}
    \label{fig:mesh1}
\end{figure}

As you can see in the figure \ref{fig:mesh1}, the 
function grows near 0. Also, in the page \pageref{fig:mesh1} 
is the same example.
```

其中，

- \caption{a nice plot} 设置了图片的标题
- \label{fig:mesh1} 会设置一个指向图片的引用，这样在文本中可以使用
- \ref{fig:mesh1} 在文本中引用上一个label标记的图片的时候用这个格式。

### Creating lists in LATEX

创建list要都放在一个环境里，用\begin{...} 和 \end{...}包住。有两类list，一个是ordered list，一个是unordered list。

unordered的用itemize环境，每一项都以\item开始。

```LATEX
\begin{itemize}
  \item The individual entries are indicated with a black dot, a so-called bullet.
  \item The text in the entries may be of any length.
\end{itemize}
```

ordered list有类似的语法，只不过环境是enumerate。

```LATEX
\begin{enumerate}
  \item This is the first entry in our list
  \item The list numbers increase with each entry we add
\end{enumerate}
```

### Adding math to LATEX

LATEX的一个优势就是书写数学公式，有两种mode来写公式，一个是inline的，一个是display的。第一种就是在文本中嵌入形式的，后者就是单独成行的。inline模式如下所示：

```LATEX
In physics, the mass-energy equivalence is stated 
by the equation $E=mc^2$, discovered in 1905 by Albert Einstein.
```

display模式有两种版本：numbered和unnumbered，前者就是在公式行行末带有数字的。dispaly最好以\[ ... \], \begin{displaymath} ... \end{displaymath} 或者 \begin{equation} ... \end{equation}的形式。不建议使用$$ ... $$，因为有可能和其他包冲突。

许多公式命令需要amsmath 包，所以使用前需要导入。

### Basic Formatting

接下来就是文章的基本排版了，首先Abstracts。abstract就使用abstract环境，比如：

```LATEX
\begin{document}

\begin{abstract}
This is a simple paragraph at the beginning of the 
document. A brief introduction about the main subject.
\end{abstract}
\end{document}
```

接下来是段落和行。在latex中，敲两次回车，即文本之间隔一行的时候，LATEX会自动将其当作新的一个段落。如果想要新的一行又不是新段落，可以使用\newline命令。

多级标题的话，需要用到section， \section{}，\subsection等配合使用即可。更多信息可以参考：[Sections and chapters](https://www.overleaf.com/learn/latex/Sections_and_chapters)

### Creating tables

创建表格的话，就要使用 tabular 环境。比如\begin{tabular}{ c c c }，就是告诉LATEX 会有三列数据。因为通常要把表格居中，所以一般会使用\begin{center} \end{center} 包住表格的表示。

如果需要显示表格的边界，那么要有\begin{tabular}{ |c|c|c| } ，还要配合\hline：

```LATEX
\begin{center}
\begin{tabular}{ |c|c|c| } 
 \hline
 cell1 & cell2 & cell3 \\ 
 cell4 & cell5 & cell6 \\ 
 cell7 & cell8 & cell9 \\ 
 \hline
\end{tabular}
\end{center}
```

表格是比较麻烦的，所以更好的是去[TablesGenerator.com](https://www.tablesgenerator.com/)，使用在线工具来完成。

表格的标题等附属信息和图片类似，形式如下：

```LATEX
Table \ref{table:data} is an example of referenced \LaTeX{} elements.

\begin{table}[h!]
\centering
\begin{tabular}{||c c c c||} 
 \hline
 Col1 & Col2 & Col2 & Col3 \\ [0.5ex] 
 \hline\hline
 1 & 6 & 87837 & 787 \\ 
 2 & 7 & 78 & 5415 \\
 3 & 545 & 778 & 7507 \\
 4 & 545 & 18744 & 7560 \\
 5 & 88 & 788 & 6344 \\ [1ex] 
 \hline
\end{tabular}
\caption{Table to test captions and labels}
\label{table:data}
\end{table}
```

### Adding a Table of Contents

目录在写大论文的时候是有用的，\tableofcontents 命令会帮助来生成目录。

## LaTeX Graphics using TikZ

接下来，看看如何在LATEX直接绘图，以便在文章中使用。主要参考overleaf文档：[LaTeX Graphics using TikZ: A Tutorial for Beginners (Part 1)—Basic Drawing](https://www.overleaf.com/learn/latex/LaTeX_Graphics_using_TikZ:_A_Tutorial_for_Beginners_(Part_1)%E2%80%94Basic_Drawing)

### LaTeX Graphics using TikZ: A Tutorial for Beginners (Part 1)—Basic Drawing

TikZ 是一个LATEX的包，帮助创建高质量的diagrams，从介绍简单图形的绘制开始。

首先，需要导入tikz包，使用：\usepackage{tikz}

然后所有绘图要在 tikzpicture 环境下，像这样：

```LATEX
\begin{tikzpicture}
<code goes here>
\end{tikzpicture}
```

在TikZ命令中，最常用的就是\draw了。使用该命令，配合坐标即可绘制简单图形。比如：

```LATEX
\begin{tikzpicture}
\draw (0,0) -- (4,0) -- (4,4) -- (0,4) -- cycle;
\draw (0,0) rectangle (4,4);
\draw (0,0) parabola (4,4);
\end{tikzpicture}
```

绘制曲线的话可以使用control来控制坐标

```LATEX
\begin{tikzpicture}
\draw (0,0) .. controls (0,4) and (4,0) .. (4,4);
\end{tikzpicture}
```

还可以控制图形大小：

```LATEX
\begin{tikzpicture}
\draw (2,2) circle (3cm);
\draw (2,2) ellipse (3cm and 1cm);
\draw (3,0) arc (0:75:3cm);
\draw[red,thick,dashed] (2,2) circle (3cm);
\end{tikzpicture}
```

有时候还会绘制网格，这时候使用如下形式的命令：

```LATEX
\begin{tikzpicture}
\draw[step=1cm,gray,very thin] (-2,-2) grid (6,6);
\end{tikzpicture}
```

需要绘制坐标的话，可以:

```LATEX
\draw[thick,->] (0,0) -- (4.5,0) node[anchor=north west] {x axis};
\draw[thick,->] (0,0) -- (0,4.5) node[anchor=south east] {y axis};
```

### LaTeX Graphics using TikZ: A Tutorial for Beginners (Part 2)—Generating TikZ Code from GeoGebra

GeoGebra是一个很简易的绘制图形的工具，通过可视化的界面，可以很容易地构建自己想要的图形，因此可以在其中先绘制好，然后导出成对应的LATEX代码，即可在LATEX中使用。

### LaTeX Graphics using TikZ: A Tutorial for Beginners (Part 3)—Creating Flowcharts

如果需要绘制流程图，则需要使用tikz包中的shapes.geometric和arrows  library。

### LaTeX Graphics using TikZ: A Tutorial for Beginners (Part 4)—Circuit Diagrams Using Circuitikz

因为例子是电路图，所以使用了Circuitikz库。

### LaTeX Graphics using TikZ: A Tutorial for Beginners (Part 5)—Creating Mind Maps

最后这一部分介绍了思维导图的绘制方式。使用了mindmap的库。

导图是以node作为图或者树的结点的。python gages_conus_analysis.py --cfg basic/config_exp2.ini --ctx 2 --rs 1234 --te 300 --train_mode True