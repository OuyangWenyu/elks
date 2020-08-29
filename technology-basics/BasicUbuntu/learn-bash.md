# Bash基本操作

主要参考[bash-guide](https://github.com/Idnan/bash-guide)。简单汇总记录一些常用的bash命令，方便日常科研使用。关于linux一些基本知识，在本文件夹的其他文件里会有介绍。

首先简单介绍下bash，然后记录常用命令。

## bash简介

主要参考：[Linux bash总结(一) 基础部分(适合初学者学习和非初学者参考)](https://www.cnblogs.com/skywang12345/archive/2013/05/30/3106570.html)。

介绍bash之前，需要先介绍它的起源——shell。shell俗称壳，它是指UNIX系统下的一个**命令解析器**；主要**用于用户和系统的交互**。UNIX系统上有很多种Shell。首个shell，即Bourne Shell，于1978年在V7(AT&T的第7版)UNIX上推出。后来，又演变出C shell、**bash等不同版本的shell**。

bash，全称为 Bourne-Again Shell。它是一个为GNU项目编写的Unix shell。bash脚本功能非常强大，尤其是在**处理自动循环或大的任务方面可节省大量的时间**。bash是许多Linux平台的**内定Shell**，这也是介绍它主要的原因。

## 基本operations

首先有几个最常见的操作：export、whatis、whereis、which、clear

然后还有几类基本操作：

- 文件：cat、chmod、chown、cp、diff、file、find、gunzip、gzcat、gzip、head、lpq、lpr、lprm、ls、more、mv、rm、tail、touch
- 文本：awk、cut、echo、egrep、fgrep、fmt、grep、nl、sed、sort、tr、uniq、wc
- 文件夹：cd、mkdir、pwd
- SSH 系统信息和网络：bg、cal、date、df、dig、du、fg、finger、jobs、last、man、passwd、ping、ps、quota、scp、ssh、top、uname、uptime、w、wget、whoami、whois
- process监测：kill、killall、&、nohup

以上命令只先简单列出，后面在实际应用中用到再逐渐补充具体内容。

### 文件命令

chmod：chmod 是 change mod 的意思，它用来**改变文件或文件夹**的**读、写和执行权限**。方式：chmod -options filename。具体可参考：[chmod](https://ss64.com/bash/chmod.html)。这里简单记录下numeric mode的情况：

一位到四位数字——

1. 为谁设置属性：设置用户ID，即setuid（4），设置组ID，即setgid（2），保存文本图像，即sticky bit（1）
2. 拥有文件的用户的权限：读（4）、写（2）、执行（1）
3. 文件的组的其他用户的权限：读（4）、写（2）、执行（1）
4. 不在文件的组的其他用户的权限：读（4）、写（2）、执行（1）

然后5，6，7等就代表多个权限，比如：

- User (rwx) = 4+2+1 = 7
- Group(rx) = 4+1 = 5
- World (rx) = 4+1 = 5

最后chmode mode = 0755，很多时候第一位没有设置，所以numeric mode就是三位的。第一位稍微难理解一点，根据blog [ubuntu chmod 四位数中第一位表示什么意思？](https://www.cnblogs.com/rooney/archive/2012/04/10/2441498.html)所述：

- setuid：设置使文件在执行阶段具有文件所有者的权限。比如/usr/bin/passwd，如果一般用户执行该文件，则在执行过程中，该文件可以获得root权限，从而可以更改用户的密码。
- setgid：该权限只对目录有效。目录被设置该位后，任何用户在此目录下创建的文件都具有和该目录所属的组相同的组。
- sticky bit：该位可以理解为防删除位。 一个文件是否可以被某用户删除，主要取决于该文件所属的组是否对该用户具有写权限。如果没有写权限，则这个目录下的所有文件都不能被删除，同时也不能添加新的文件。 如果希望用户能够添加文件但同时不能删除文件，则可以对文件使用sticky bit位。设置该位后，就算用户对目录具有写权限也不能删除该文件。

当然也可以不用numeric mode，而使用字符串形式的，不过通常都会使用数字模式，比较方便。

touch：更新某个文件的访问和修改时间戳，如果文件不存在，将会被创建。

```bash
touch test.md
```

### 文本

echo：输出命令之后的**文本到标准输出**或**文件**。比如：

```bash
echo Hello World
echo -ne "Hello\nWorld\n"
```

### 文件夹

cd：进入某个文件目录，cd dirname

### SSH, 系统信息与网络操作

wget：下载文件，wget file 即可。

## 基本Shell编程

在bash脚本文件中编写的**第一行称为shebang**。任何脚本中的这一行决定了脚本像**独立可执行文件**一样执行的能力，而无需在终端中预先输入sh、bash、python、php等。

```bash
#!/usr/bin/env bash
```

### 变量

没有数据类型，直接可以创建变量。

```bash
str="hello world"
echo $str
```

### 数组

数组从0开始计数。多种定义数组的方式：

```bash
array[0]=1
array[1]=2
array[2]=3

array=([2]=3 [0]=2 [1]=1)

array=(1 2 3)
```

以下方式可以展示某个值：

```bash
${array[i]}     # where i is the index
```

### 字符串

字符串占位符的各种使用方式：

```bash
${variable#pattern}         # if the pattern matches the beginning of the variable's value, delete the shortest part that matches and return the rest
${variable##pattern}        # if the pattern matches the beginning of the variable's value, delete the longest part that matches and return the rest
${variable%pattern}         # if the pattern matches the end of the variable's value, delete the shortest part that matches and return the rest
${variable%%pattern}        # if the pattern matches the end of the variable's value, delete the longest part that matches and return the rest
${variable/pattern/string}  # the longest match to pattern in variable is replaced by string. Only the first match is replaced
${variable//pattern/string} # the longest match to pattern in variable is replaced by string. All matches are replaced
${#varname}     # returns the length of the value of the variable as a character string
```

### 条件判断

if else基本形式如下所示：

```bash
if [ expression ]; then
    will execute only if expression is true
else
    will execute if expression is false
fi
```

也可以使用case语句：

```bash
case expression in
    pattern1 )
        statements ;;
    pattern2 )
        statements ;;
    ...
esac
```

常用的逻辑表达式有：

```bash
statement1 && statement2  # both statements are true
statement1 || statement2  # at least one of the statements is true

str1=str2       # str1 matches str2
str1!=str2      # str1 does not match str2
str1<str2       # str1 is less than str2
str1>str2       # str1 is greater than str2
-n str1         # str1 is not null (has length greater than 0)
-z str1         # str1 is null (has length 0)

-a file         # file exists
-d file         # file exists and is a directory
-e file         # file exists; same -a
-f file         # file exists and is a regular file (i.e., not a directory or other special type of file)
-r file         # you have read permission
-s file         # file exists and is not empty
-w file         # you have write permission
-x file         # you have execute permission on file, or directory search permission if it is a directory
-N file         # file was modified since it was last read
-O file         # you own file
-G file         # file's group ID matches yours (or one of yours, if you are in multiple groups)

file1 -nt file2     # file1 is newer than file2
file1 -ot file2     # file1 is older than file2

-lt     # less than
-le     # less than or equal
-eq     # equal
-ge     # greater than or equal
-gt     # greater than
-ne     # not equal
```

### 循环

循环有三种方式：

- for
- while
- until

for有几种不同的表达方式：

```bash
for x := 1 to 10 do
begin
  statements
end

for name [in list]
do
  statements that can use $name
done

for (( initialisation ; ending condition ; update ))
do
  statements...
done
```

while Syntax:

```bash
while condition; do
  statements
done
```

until Syntax:

```bash
until condition; do
  statements
done
```

## 技巧

### 设置别名

在bash_profile中可以设置别名，运行“nano ~/.bash_profile”，然后输入比如：

```bash
alias dockerlogin='ssh www-data@adnan.local -p2222' # add your alias in .bash_profile
```

接着就可以在bash中使用dockerlogin来替代后面一长串。

### 快速到达指定文件夹

在.bashrc文件中设置，“nano ~/.bashrc”进入文件，输入以下命令：

```bash
export hotellogs="/workspace/hotel-api/storage/logs"
```

然后就可以在命令行中使用：

```bash
source ~/.bashrc
cd $hotellogs
```

### 重新执行之前的命令

在终端中使用上下方向键可以调出之前执行过的指令代码。

### 跳出陷阱

通过执行清理语句使得脚本更有鲁棒性：

```bash
function finish {
  # 在这里执行清理语句，例如，杀掉所有 fork 的进程。
  jobs -p | xargs kill
}
trap finish EXIT
```

### 保存环境变量

将export命令加入到~/.bash_profile 文件，比如：

```bash
echo export FOO=BAR >> ~/.bash_profile
```

### 访问脚本

可以在home文件夹下建立一个bin文件，然后将脚本放在其中，这样可以快速访问它们。如果不能的话，就在~/.bash_profile文件中加上环境变量，这样肯定就可以了：

```bash
# set PATH so it includes user's private bin if it exists
if [ -d "$HOME/bin" ] ; then
    PATH="$HOME/bin:$PATH"
fi
```

## 调试

可以很容易地通过传递不同的参数给 bash 命令来调试脚本。例如， -n 将会只检查脚本的语法错误而不执行脚本。 -v 将会在命令执行前输出它们。 -x 将会在命令行处理之后输出命令。

```bash
bash -n scriptname
bash -v scriptname
bash -x scriptname
```