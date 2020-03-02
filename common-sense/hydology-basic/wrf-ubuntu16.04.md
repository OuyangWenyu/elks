# Compiling WRF 实践

依据官方在线指导文档[How to Compile WRF:The Complete Process](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compilation_tutorial.php)，结合另一篇[博客](http://bbs.06climate.com/forum.php?mod=viewthread&tid=57144)，在 Ubuntu 16.04 LTS 系统上进行实践。
该文档内容包括：确保计算环境正确设置；测试各个组成部分及其互相之间的兼容性；安装 WRF 和 WPS；以及最后准备运行 WPS 和 WRF。

不完全参考官方文档的原因，一是由于安装netcdf后，在C程序中导入不了头文件，配置C_LIBRARY_PATH等GCC编译选项后还是出错，因此觉得netcdf的安装有问题；二是官方文档给的依赖程序版本较低，而气象家园上的教程挺新的，可以尝试。

## 重要注意事项：开始前必读

- 为了在个人电脑上使用，必须 build 所有必需的 programs 和 compilers，还必须使它们在个人电脑上通过功能性及兼容性测试。
- 下面的步骤会带你通过 build 必需的库的步骤，但是如果碰到错误，需要自己在个人电脑上解决。
- 官方所有例子用 tsch，说明了“除非你熟悉其他的 shell，比如 bash，否则推荐使用 tsch”，我对bash比对tsch熟悉，所以下面的示例里我个人使用了 bash。

## 安装必需的软件

```console
sudo apt-get install build-essential csh tcsh gfortran m4 synaptic
```

synaptic是一个软件包管理器，后面部分软件需要用其安装。perl Ubuntu16.04默认已安装。awk也是自带安装的，可以检查是否安装：which awk，若是usr/bin/awk返回，则说明OK。

其他可选的一些安装，后期可能用得到：
samba，quota
  
```console
sudo apt-get install samba smbclient quota
```  

## 系统环境测试

- _一个 WRF3.8 版本对应的视频在[这里](https://www.youtube.com/watch?v=_9lBM4k7HQc)._

虽然视频是3.8版本的，但是和4.0版本的差别不大，与文档一致的地方均可参考，不一致的地方，以该文档为准。

首先也是最重要的，必须要拥有 a gfortran compiler, gcc 以及 cpp. 为了测试这些在你的个人电脑上是否存在，键入如下代码：

```console
$ which gfortran
/user/bin/gfortran
$ which cpp
/user/bin/cpp
$ which gcc
/user/bin/gcc
```

**注意**代码块中只有键入的代码而没有给出输出或者转到vim等编辑页面时，不必加"\$"，当有输出或者跳转到编辑页面时，才会给出“\$”符号。

如果你已经安装过了，应该为它们每个的 location 提供一个 path。推荐 gfortran 版本 4.4.0 及以上。使用一下语句确定你的 gfortran 版本。

```console
gcc --version
```

创建新文件夹： `TESTS`.用于测试。

需要运行一些简单的测试来确认 fortran 编译器被适当地 built，并且和 C 编译器兼容。
**注意：如果测试失败，需要寻找帮助，找出失败原因，并解决它，才能继续**

下载包含测试文件的[tar 文件](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/Fortran_C_tests.tar)，并放入`TESTS`文件夹，然后解压。

**注意**{path_to_dir}是指代你自己设置的路径的（比如在我的个人 PC 上为/home/dutwr），不要原样照抄。否则会在“计算机”目录下创建一个{path_to_dir}的默认隐藏的文件夹，不便查看，且由于和你本意不同，可能会导致其他错误。

```console
cd {path_to_dir}/TESTS
wget http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/Fortran_C_tests.tar
tar -xvf Fortran_C_tests.tar
```

There are 7 tests available, so start at the top and run through them, one at a time.

- Test 1: Fixed Format Fortran Test.

```console
$ gfortran TEST_1_fortran_only_fixed.f
$ ./a.out
SUCCESS test 1 fortran only fixed format
```

- Test 2: Free Format Fortran.

```console
$ gfortran TEST_2_fortran_only_free.f90
$ ./a.out
Assume Fortran 2003: has FLUSH, ALLOCATABLE, derived type, and ISO C Binding
SUCCESS test 2 fortran only free format
```

- Test 3: C.

```console
$ gcc TEST_3_c_only.c
$ ./a.out
SUCCESS test 3 c only
```

- Test 4: Fortran Calling a C Function (our gcc and gfortran have different defaults, so we force both to always use 64 bit [-m64] when combining them).

```console
$ gcc -c -m64 TEST_4_fortran+c_c.c
$ gfortran -c -m64 TEST_4_fortran+c_f.f90
$ gfortran -m64 TEST_4_fortran+c_f.o TEST_4_fortran+c_c.o
$ ./a.out
C function called by Fortran Values are xx = 2.00 and ii = 1
SUCCESS test 4 fortran calling c
```

In addition to the compilers required to manufacture the WRF executables, the WRF build system has scripts as the top level for the user interface. The WRF scripting system uses, and therefore is necessary having csh, perl and sh.
To test whether these scripting languages are working properly on the system, there are 3 tests to run. These tests were included in the "Fortran and C Tests Tar File".

- Test 5: csh.

```console
$ csh ./TEST_csh.csh
SUCCESS csh test
```

- Test 6: perl.

```console
$ ./TEST_perl.pl
SUCCESS perl test
```

- Test 7: sh.

```console
$ ./TEST_sh.sh
SUCCESS sh test
```

最后，在脚本中有一些无论使用哪个 shell 都可用的 UNIX 命令。以下标准的 UNIX 命令：
ar head sed
awk hostname sleep
cat ln sort
cd ls tar
cp make touch
cut mkdir tr
expr mv uname
file nm wc
grep printf which
gzip rm m4

## Building libraries

### 安装NetCDF

NetCDF的安装需要有HDF5lib，而HDF5的安装需要先有zlib和curl。所以先要安装zlib和curl。可以将zlib，curl,  jpeg, png，Jasper 一起安装了，并且建立了一个JASPER文件夹将这几个lib与include都放在一起，方便后期的环境设置。

桌面打开搜索软件，搜索并打开synaptic，点击搜索，输入libjpeg8，前面没有打钩的。双击打钩标记，标记后会变绿色高亮行，点击应用，然后点击apply进行安装。（libjpeg8是处理图片的，暂时不清楚为啥装）

同理输入glibc，然后就会看到结果有三个带glibc的选项，也apply。（glibc是GNU发布的libc库，即c运行库。glibc是linux系统中最底层的api，几乎其它任何运行库都会依赖于glibc。glibc除了封装linux操作系统所提供的系统服务外，它本身也提供了许多其它一些必要功能服务的实现）

同理输入grib2，然后就会看到结果有libgrib2c-dev和libgrib2c0d选项，也apply。（GRIB 码是与计算机无关的压缩的二进制编码,主要用来表示数值天气预报的产品资料。）

接下来开始各类必备软件安装。和官方文档说明的安装顺序不太一样，个人认为主要是C程序的静态库动态库头文件之类的比较麻烦，所以官方文档说的比较固定，但是应该是都可行的，这里以气象家园上的为主进行安装。

[zlib](https://zlib.net/)：
选择当前最新1.12.11版本下载，解压，因为Ubuntu很多软件都安装在/usr/local/中，因此这里把各个软件都按在这里，进入zlib文件夹，然后在终端执行以下代码，：

```code
./configure --prefix=/usr/local/zlib
sudo make
sudo make check
sudo make install
```

curl:

```code
sudo apt-get install curl
```

[libjpeg](https://www.ijg.org/):
前面已经安装过libjpeg8了，这里又安装了9，暂时不懂为什么，包括前面libjpeg8是为什么也不知道，官方文档压根没提，不管了，先安装了。下载当前最新jpegsrc.v9c.tar.gz之后，解压，移动到文件夹下，在终端执行以下代码：

```code
./configure --prefix=/usr/local/libjpeg
sudo make
sudo make install
```

[ligpng](http://www.libpng.org/pub/png/libpng.html):
This is a compression library necessary for compiling WPS (specifically ungrib) with GRIB2 capability，下载libpng当前最新版本1.6.37，然后解压，进入文件夹，执行代码：

```code
export LDFLAGS=-L/usr/local/zlib/lib
export CPPFLAGS=-I/usr/local/zlib/include
./configure --prefix=/usr/local/libpng
sudo make
sudo make install
```

[Jasper-1.900.1](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/jasper-1.900.1.tar.gz):
This is a compression library necessary for compiling WPS (specifically ungrib) with GRIB2 capability，安装的是官方推荐的1.9，因为高版本在后面可能出现不了ungrib.exe，高版本的Jasper需要修改jas_image.h文件，避免麻烦，安装1.9版本，下载解压，进入文件夹，执行代码：

```code
./configure --prefix=/usr/local/jasper
sudo make
sudo make install
```

以上部分安装完成之后，开始配置环境变量。如前所述，为了方便后期的环境设置，这里将建立一个JASPER（Ubuntu分大小写）文件夹将几个lib和include都放在了一起。执行以下代码：

```code
sudo mkdir /usr/local/JASPER
sudo mkdir /usr/local/JASPER/lib
sudo mkdir /usr/local/JASPER/include
sudo cp -r /usr/local/zlib/lib/* /usr/local/JASPER/lib
sudo cp -r /usr/local/libpng/lib/* /usr/local/JASPER/lib
sudo cp -r /usr/local/jasper/lib/* /usr/local/JASPER/lib
sudo cp -r /usr/local/zlib/include/* /usr/local/JASPER/include
sudo cp -r /usr/local/libpng/include/* /usr/local/JASPER/include
sudo cp -r /usr/local/jasper/include/* /usr/local/JASPER/include
```

然后开始设置环境变量等，进入.bashrc文件后，按E进入编辑模式，按i可编辑，在最后添加路径指向：

```code
$ sudo vim ~/.bashrc

(...)
#for zlib
export ZLIB_HOME=/usr/local/zlib
export LD_LIBRARY_PATH=$ZLIB_HOME/lib:$LD_LIBRARY_PATH
#for libpng
export LIBPNG_HOME=/usr/local/libpng
export LIBPNGLIB=/usr/local/libpng/lib
export LIBPNGINC=/usr/local/libpng/include
#set JASPER
export JASPER=/usr/local/JASPER
export JASPERLIB=/usr/local/JASPER/lib
export JASPERINC=/usr/local/JASPER/include
```

按":wq"保存并退出，并执行如下代码，使配置生效

```code
source ~/.bashrc
```

然后是hdf5的安装配置：
因为查的几个文档hdf5都是用的1.8版本的，所以就下载[1.8.21](https://portal.hdfgroup.org/display/support/HDF5+1.8.21)来使用了，很多软件安装源码都放在usr/local/src下，所以这里也可以放在该文件夹下。关于hdf5的安装代码，如下所示（执行make时会有很多warning，但是不影响；这部分时间稍长）：

```code
sudo tar -xf hdf5-1.8.21.tar -C /usr/local/src
cd /usr/local/src/hdf5-1.8.21
sudo ./configure --prefix=/usr/local/HDF5 --with-zlib=/usr/local/zlib
sudo make
sudo make check
sudo make install
sudo make check-install
```

安装之后，配置hdf5，几个文档里都莫名其妙地出现了一个$PRO_PATH，可是前面并没有这个路径名的定义，所以这里就不写它了，并按照NetCDF官方文档对HDF5进行安装及路径设置：

```code
$ sudo vim ~/.bashrc

(...)
# for hdf5
export LD_LIBRARY_PATH=/usr/local/HDF5/lib:$LD_LIBRARY_PATH

$ source ~/.bashrc
```

然后才开始安装NetCDF。

首先安装NetCDF-C。因为特定语言的版本更新的速度不一样，所以C版本的不安装太新的，且wrf官方或者各种资料里给的都是老版本的，还有4.5之后版本安装方式略有不同，所以为了方便，这里和查阅的资料保持一致，使用4.4版本的最新版4.4.1.1，从[github上](https://github.com/Unidata/netcdf-c/releases/v4.4.1.1)下载，然后执行下列代码，注意安装的时候对netcdf的配置，可能是WRF使用的是NetCDF-3，所以几个教程里的安装，都设置了--disable-netcdf-4：

```code
sudo tar -zxf netcdf-c-4.4.1.1.tar.gz -C /usr/local/src
cd /usr/local/src/netcdf-c-4.4.1.1/
sudo CPPFLAGS='-I/usr/local/HDF5/include -I/usr/local/zlib/include' LDFLAGS='-L/usr/local/HDF5/lib -L/usr/local/zlib/lib' ./configure --prefix=/usr/local/NETCDF --disable-netcdf-4
sudo make
sudo make check
sudo make install
```

其次安装NetCDF-fortran
和C版本4.4对应的是fortran版的4.4版，为了方便，根据查阅的资料，安装fortran版的[4.4.4版本](https://github.com/Unidata/netcdf-fortran/releases/tag/v4.4.4)，根据资料下载之后执行以下代码：

```code
sudo tar -xzf netcdf-fortran-4.4.4.tar.gz -C /usr/local/src
cd /usr/local/src/netcdf-fortran-4.4.4/
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/NETCDF/lib
export CPPFLAGS='-I/usr/local/NETCDF/include'
export LDFLAGS='-L/usr/local/NETCDF/lib'
sudo ./configure --prefix=/usr/local/NETCDF FC=gfortran
sudo make
sudo make check
sudo make install
```

但是很遗憾，在执行到configue的时候，这里会报错，configure: error: netcdf.h could not be found. Please set CPPFLAGS.，又是这个netcdf.h找不到的问题，所以说明前面的netcdf.h的安装有问题，需要重新设置CPPFLAGS，这时候按照网上说的设置C_INCLUDE_PATH等，都仍然不对。

- _A video of this part is available [here](https://www.youtube.com/watch?v=Ipd8vkAj8Fk)._

Before getting started, you need to make another directory. Go inside your `Build_WRF` directory and then make a directory called `LIBRARIES`.

```console
cd {path_to_dir}/Build_WRF
mkdir LIBRARIES
```

Depending on the type of run you wish to make, there are various libraries that should be installed. Go inside your `LIBRARIES` directory and then download all 5 tar files.
[mpich-3.0.4](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/mpich-3.0.4.tar.gz)
[netcdf-4.1.3](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/netcdf-4.1.3.tar.gz)
[Jasper-1.900.1](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/jasper-1.900.1.tar.gz)
[libpng-1.2.50](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/libpng-1.2.50.tar.gz)
[zlib-1.2.7](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/zlib-1.2.7.tar.gz)
**值得注意的是这些库必须用相同的编译器安装，后续会用来安装 WRF 和 WPS**
使用以下代码即可下载：

```console
cd {path_to_dir}/Build_WRF/LIBRARIES
wget http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/mpich-3.0.4.tar.gz http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/netcdf-4.1.3.tar.gz http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/jasper-1.900.1.tar.gz http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/libpng-1.2.50.tar.gz http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/zlib-1.2.7.tar.gz
```

**Configuring NetCDF library**: This library is always necessary! Modify the `.bashrc` file in the home directory of current user to set the environment variables.

```console
sudo vim ~/.bashrc
```

At the bottom of the file add these lines so that they will be set for future logins.

再次**注意**{path_to_dir}是指代你自己设置的路径的，不要原样照抄

```console

(...)
export DIR=/{path_to_dir}/Build_WRF/LIBRARIES
export CC=gcc
export CXX=g++
export FC=gfortran
export FCFLAGS=-m64
export F77=gfortran
export FFLAGS=-m64
```

Then source the file to make these settings active for current session.

```console
source ~/.bashrc
```

Unpack the `netcdf-4.1.3.tar.gz` file.

```console
tar -zxvf netcdf−4.1.3.tar.gz
```

Go into the `netcdf-4.1.3` directory and run the configure script with the parameters presented below, make and make install.

```console
cd {path_to_dir}/Build_WRF/LIBRARIES/netcdf-4.1.3
./configure --prefix=$DIR/netcdf --disable-dap --disable-netcdf-4 --disable-shared
sudo make
sudo make install
```

Modify again the `.bashrc` file and set two new environment variables at the bottom. Then source the file to make these settings active for current session and leave the directory.

```console
$ sudo vim ~/.bashrc

(...)
export PATH=$DIR/netcdf/bin:$PATH
export NETCDF=$DIR/netcdf

$ source ~/.bashrc
$ cd ..
```

如果之前已经设置过其他PATH，可以直接在PATH后添加，比如：

```console
$ sudo vim ~/.bashrc

(...)
export NETCDF=$DIR/netcdf
export PATH=$PATH:/home/dutwr/anaconda3/bin:$DIR/netcdf/bin

$ source ~/.bashrc
$ cd ..
```

**Configuring MPICH library**: This library is necessary if you are planning to build WRF in parallel. If your machine does not have more than 1 processor, or if you have no need to run WRF with multiple processors, you can skip installing MPICH.

In principle, any implementation of the MPI-2 standard should work with WRF; however, we have the most experience with MPICH, and therefore, that is what will be described here.

Assuming all the **export** commands were already issued while setting up NetCDF, you can continue on to install MPICH, issuing each of the following commands.

```console
$ cd {path_to_dir}/Build_WRF/LIBRARIES
$ tar -zxvf mpich-3.0.4.tar.gz
$ cd {path_to_dir}/Build_WRF/LIBRARIES/mpich-3.0.4
$ ./configure --prefix=$DIR/mpich
$ sudo make
$ sudo make install
$ sudo vim ~/.bashrc

(...)
export PATH=$DIR/mpich/bin:$PATH

$ source ~/.bashrc
$ cd ..
```

**Configuring zlib**: This is a compression library necessary for compiling WPS (specifically ungrib) with GRIB2 capability.
Assuming all the **export** commands from the NetCDF install are already set, you can move on to the commands to install zlib.

```console
$ cd {path_to_dir}/Build_WRF/LIBRARIES
$ sudo vim ~/.bashrc

(...)
export LDFLAGS=-L$DIR/grib2/lib
export CPPFLAGS=-I$DIR/grib2/include

$ source ~/.bashrc
$ tar -zxvf zlib-1.2.7.tar.gz
$ cd {path_to_dir}/Build_WRF/LIBRARIES/zlib-1.2.7
$ ./configure --prefix=$DIR/grib2
$ sudo make
$ sudo make install
$ cd ..
```

**Configuring libpng**: This is a compression library necessary for compiling WPS (specifically ungrib) with GRIB2 capability.
Assuming all the **export** commands from the NetCDF install are already set, you can move on to the commands to install libpng.

```console
cd {path_to_dir}/Build_WRF/LIBRARIES
tar -zxvf libpng-1.2.50.tar.gz
cd {path_to_dir}/Build_WRF/LIBRARIES/libpng-1.2.50
./configure --prefix=$DIR/grib2
sudo make
sudo make install
cd ..
```

**Configuring JasPer**: This is a compression library necessary for compiling WPS (specifically ungrib) with GRIB2 capability.
Assuming all the **export** commands from the NetCDF install are already set, you can move on to the commands to install jasper.

```console
cd {path_to_dir}/Build_WRF/LIBRARIES
tar -zxvf jasper-1.900.1.tar.gz
cd {path_to_dir}/Build_WRF/LIBRARIES/jasper-1.900.1
./configure --prefix=$DIR/grib2
sudo make
sudo make install
cd ..
```

如果安装有问题，可以进行卸载，make uninstall 或 手动删除。卸载顺序建议按照上述安装顺序倒序卸载。
如果在安装./configure的时候有添加参数，在卸载./configure的时候也把参数加上，不然卸载不了，比如下面的--prefix=目录名，没有这个参数，程序并不知道去哪里卸载。因为之前config配过了，都没变，所以这里可以直接在各个之前压缩包解压的文件夹下执行make uninstall卸载，卸载后/etc中的配置文件以及程序在其它目录生成的文件并不会删除掉，这一点要注意一下。
如果之前config的时候都配置了--prefix，指定了安装目录，那么可以直接把编译后的文件和安装的文件都直接手动删除即可。


## Libraries compatibility tests

- _A video of this part is available [here](https://www.youtube.com/watch?v=j205Ki84ZF4)._

Once the target machine is able to make small Fortran and C executables (what was verified in the System Environment Tests section), and after the NetCDF and MPI libraries are constructed (two of the libraries from the Building Libraries section), to emulate the WRF code's behavior, two additional small tests are required. We need to verify that the libraries are able to work with the compilers that are to be used for the WPS and WRF builds.
**注意：如果任何测试失败，则需要寻求帮助来解决相关问题**
Move to `TESTS` directory, download the tar file that contans these tests and unpack it.
[Fortran_C_NETCDF_MPI_tests.tar](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/Fortran_C_NETCDF_MPI_tests.tar)
可以使用如下代码：

```console
cd {path_to_dir}/TESTS
wget http://www2.mmm.ucar.edu/wrf/OnLineTutorial/compile_tutorial/tar_files/Fortran_C_NETCDF_MPI_tests.tar
$ tar -xvf Fortran_C_NETCDF_MPI_tests.tar
```

There are 2 tests.

- Test 1: Fortran + C + NetCDF

The NetCDF-only test requires the include file from the NETCDF package be in this directory. Copy the NetCDF include here and compile the Fortran and C codes for the purpose of this test (the -c option says to not try to build an executable).

```console
cp ${NETCDF}/include/netcdf.inc .
gfortran -c 01_fortran+c+netcdf_f.f
gcc -c 01_fortran+c+netcdf_c.c
gfortran 01_fortran+c+netcdf_f.o 01_fortran+c+netcdf_c.o -L${NETCDF}/lib -lnetcdff -lnetcdf
./a.out
```

The following should be displayed on your screen.

```console
C function called by Fortran
Values are xx = 2.00 and ii = 1
SUCCESS test 1 fortran + c + netcdf
```

- Test 2: Fortran + C + NetCDF + MPI

The NetCDF+MPI test requires include files from both of these packages be in this directory, but the MPI scripts automatically make the `mpif.h` file available without assistance, so no need to copy that one. Copy the NetCDF include file here and note that the MPI executables `mpif90` and `mpicc` are used below when compiling. Issue the following commands.

```console
cp ${NETCDF}/include/netcdf.inc .
mpif90 -c 02_fortran+c+netcdf+mpi_f.f
mpicc -c 02_fortran+c+netcdf+mpi_c.c
mpif90 02_fortran+c+netcdf+mpi_f.o 02_fortran+c+netcdf+mpi_c.o -L${NETCDF}/lib -lnetcdff -lnetcdf
mpirun ./a.out
```

The following should be displayed on your screen.

```console
C function called by Fortran
Values are xx = 2.00 and ii = 1
status = 2
SUCCESS test 2 fortran + c + netcdf + mpi
```

## Building WRF

- _A video of this part is available [here](https://www.youtube.com/watch?v=hkLrdlQnKTw)._

After ensuring that all libraries are compatible with the compilers, you can now prepare to build WRF. If you do not already have a `WRF` tar file, 你可以按照以下方式获取 WRF 源代码：如果你是新用户，需要用邮箱注册以下，注册完毕可以点击给的'Returning Users'链接，进入下载页面。对于 WRF4.0 的代码可以从 github 上获取，使用 git 获取代码，后期可以灵活地更新版本。move to your `Build_WRF` directory, 使用 git 语句 clone 代码。 Then go into the `WRF` directory and create a configuration file for your computer and compiler.

```console
cd {path_to_dir}/Build_WRF
git clone https://github.com/wrf-model/WRF
cd {path_to_dir}/Build_WRF/WRF
./configure
```

You will see various options. Choose the option that lists the compiler you are using and the way you wish to build WRF (i.e., serially or in parallel). Although there are 3 different types of parallel (smpar, dmpar, and dm+sm), it is recommend choosing dmpar option.

```console
checking for perl5... no
checking for perl... found /usr/bin/perl (perl)
Will use NETCDF in dir: /{path_to_dir}/Build_WRF/LIBRARIES/netcdf
HDF5 not set in environment. Will configure WRF for use without.
PHDF5 not set in environment. Will configure WRF for use without.
Will use 'time' to report timing information
$JASPERLIB or $JASPERINC not found in environment, configuring to build without grib2 I/O...
-----------------------------------------------------------------------------------------------
Please select from among the following Linux x86_64 options:

 1. (serial)  2. (smpar)  3. (dmpar)  4. (dm+sm) PGI (pgf90/gcc)
 2. (serial)  6. (smpar)  7. (dmpar)  8. (dm+sm) PGI (pgf90/pgcc): SGI MPT
 3. (serial) 10. (smpar) 11. (dmpar) 12. (dm+sm) PGI (pgf90/gcc): PGI accelerator
1.  (serial) 14. (smpar) 15. (dmpar) 16. (dm+sm) INTEL (ifort/icc)
                                     1.  (dm+sm) INTEL (iforticc): Xeon Phi (MIC architecture)
2.  (serial) 19. (smpar) 20. (dmpar) 21. (dm+sm) INTEL (ifort/icc): Xeon (SNB with AVX mods)
3.  (serial) 23. (smpar) 24. (dmpar) 25. (dm+sm) INTEL (ifort/icc): SGI MPT
4.  (serial) 27. (smpar) 28. (dmpar) 29. (dm+sm) INTEL (ifort/icc): IBM POE
5.  (serial)             31. (dmpar)             PATHSCALE (pathf90/pathcc)
6.  (serial) 33. (smpar) 34. (dmpar) 35. (dm+sm) GNU (gfortran/gcc)
7.  (serial) 37. (smpar) 38. (dmpar) 39. (dm+sm) IBM (xlf90_r/cc_r)
8.  (serial) 41. (smpar) 42. (dmpar) 43. (dm+sm) PGI (ftn/gcc): Cray XC CLE
9.  (serial) 45. (smpar) 46. (dmpar) 47. (dm+sm) CRAY CCE (ftn/cc): Cray XE and XC
10. (serial) 49. (smpar) 50. (dmpar) 51. (dm+sm) INTEL (ftn/icc): Cray XC
11. (serial) 53. (smpar) 54. (dmpar) 55. (dm+sm) PGI (pgf90/pgcc)
12. (serial) 57. (smpar) 58. (dmpar) 59. (dm+sm) PGI (pgf90/gcc): -f90=pgf90
13. (serial) 61. (smpar) 62. (dmpar) 63. (dm+sm) PGI (pgf90/pgcc): -f90=pgf90
14. (serial) 65. (smpar) 66. (dmpar) 67. (dm+sm) INTEL (ifort/icc): HSW/BDW
15. (serial) 69. (smpar) 70. (dmpar) 71. (dm+sm) INTEL (ifort/icc): KNL MIC
16. (serial)  73. (smpar)  74. (dmpar)  75. (dm+sm)   FUJITSU (frtpx/fccpx): FX10/FX100 SPARC64 IXfx/Xlfx

Enter selection [1-75] : 34
-----------------------------------------------------------------------------------------------
Compile for nesting? (1=basic, 2=preset moves, 3=vortex following) [default 1]: 1

Configuration successful!
-----------------------------------------------------------------------------------------------
testing for fseeko and fseeko64
fseeko64 is supported
-----------------------------------------------------------------------------------------------

(...)
```

Once your configuration is complete, you should have a `configure.wrf` file, and you are ready to compile. To compile WRF, you will need to decide which type of case you wish to compile. The options are listed below.

```console
em_real (3d real case)
em_quarter_ss (3d ideal case)
em_b_wave (3d ideal case)
em_les (3d ideal case)
em_heldsuarez (3d ideal case)
em_tropical_cyclone (3d ideal case)
em_hill2d_x (2d ideal case)
em_squall2d_x (2d ideal case)
em_squall2d_y (2d ideal case)
em_grav2d_x (2d ideal case)
em_seabreeze2d_x (2d ideal case)
em_scm_xy (1d ideal case)

./compile case_name >& log.compile
```

where case_name is one of the options listed above

For this purpose we are going to compile WRF for real cases. 我们采用如下命令也可执行上述语句。Compilation should take about 20-30 minutes. The ongoing compilation can be checked.

```console
./compile em_real >& compile.log &
tail -f compile.log
```

Once the compilation completes, to check whether it was successful, you need to look for executables in the `WRF/main` directory.

```console
$ ls -las main/*.exe
ndown.exe (one-way nesting)
real.exe (real data initialization)
tc.exe (for tc bogusing--serial only)
wrf.exe (model executable)
```

These executables are linked to 2 different directories. You can choose to run WRF from either directory.

```console
WRF/run
WRF/test/em_real
```

## Building WPS

- _A video of this part is available [here](https://www.youtube.com/watch?v=uCImaGGCWDs)._

After the WRF model is built, the next step is building the WPS program (if you plan to run real cases, as opposed to idealized cases). The WRF model MUST be properly built prior to trying to build the WPS programs. If you do not already have the WPS source code, move to your `Build_WRF` directory, 并从 github 上下载源代码. Then go into the WPS directory and make sure the WPS directory is clean.

```console
cd {path_to_dir}/Build_WRF
git clone https://github.com/wrf-model/WPS
cd {path_to_dir}/Build_WRF/WPS
./clean
```

The next step is to configure WPS, however, you first need to set some paths for the ungrib libraries and then you can configure.

```console
$ sudo vim ~/.bashrc

(...)
export JASPERLIB=$DIR/grib2/lib
export JASPERINC=$DIR/grib2/include

$ source ~/.bashrc
$ ./configure
```

You should be given a list of various options for compiler types, whether to compile in serial or parallel, and whether to compile ungrib with GRIB2 capability. Unless you plan to create extremely large domains, it is recommended to compile WPS in serial mode, regardless of whether you compiled WRF in parallel. It is also recommended that you choose a GRIB2 option (make sure you do not choose one that states "NO_GRIB2"). You may choose a non-grib2 option, but most data is now in grib2 format, so it is best to choose this option. You can still run grib1 data when you have built with grib2.

Choose the option that lists a compiler to match what you used to compile WRF, serial, and grib2. **Note: The option number will likely be different than the number you chose to compile WRF.**

```console
Will use NETCDF in dir: /home/modelagem/Build_WRF/LIBRARIES/netcdf
Found Jasper environment variables for GRIB2 support...
  $JASPERLIB = /home/modelagem/Build_WRF/LIBRARIES/grib2/lib
  $JASPERINC = /home/modelagem/Build_WRF/LIBRARIES/grib2/include
-----------------------------------------------------------------------------------------------
Please select from among the following supported platforms:

   1. Linux x86_64, gfortran (serial)
   2. Linux x86_64, gfortran (serial_NO_GRIB2)
   3. Linux x86_64, gfortran (dmpar)
   4. Linux x86_64, gfortran (dmpar_NO_GRIB2)
   5. Linux x86_64, PGI compiler (serial)
   6. Linux x86_64, PGI compiler (serial_NO_GRIB2)
   7. Linux x86_64, PGI compiler (dmpar)
   8. Linux x86_64, PGI compiler (dmpar_NO_GRIB2)
   9. Linux x86_64, PGI compiler, SGI MPT (serial)
  10. Linux x86_64, PGI compiler, SGI MPT (serial_NO_GRIB2)
  11. Linux x86_64, PGI compiler, SGI MPT (dmpar)
  12. Linux x86_64, PGI compiler, SGI MPT (dmpar_NO_GRIB2)
  13. Linux x86_64, IA64 and Opteron (serial)
  14. Linux x86_64, IA64 and Opteron (serial_NO_GRIB2)
  15. Linux x86_64, IA64 and Opteron (dmpar)
  16. Linux x86_64, IA64 and Opteron (dmpar_NO_GRIB2)
  17. Linux x86_64, Intel compiler (serial)
  18. Linux x86_64, Intel compiler (serial_NO_GRIB2)
  19. Linux x86_64, Intel compiler (dmpar)
  20. Linux x86_64, Intel compiler (dmpar_NO_GRIB2)
  21. Linux x86_64, Intel compiler, SGI MPT (serial)
  22. Linux x86_64, Intel compiler, SGI MPT (serial_NO_GRIB2)
  23. Linux x86_64, Intel compiler, SGI MPT (dmpar)
  24. Linux x86_64, Intel compiler, SGI MPT (dmpar_NO_GRIB2)
  25. Linux x86_64, Intel compiler, IBM POE (serial)
  26. Linux x86_64, Intel compiler, IBM POE (serial_NO_GRIB2)
  27. Linux x86_64, Intel compiler, IBM POE (dmpar)
  28. Linux x86_64, Intel compiler, IBM POE (dmpar_NO_GRIB2)
  29. Linux x86_64 g95 compiler (serial)
  30. Linux x86_64 g95 compiler (serial_NO_GRIB2)
  31. Linux x86_64 g95 compiler (dmpar)
  32. Linux x86_64 g95 compiler (dmpar_NO_GRIB2)
  33. Cray XE/XC CLE/Linux x86_64, Cray compiler (serial)
  34. Cray XE/XC CLE/Linux x86_64, Cray compiler (serial_NO_GRIB2)
  35. Cray XE/XC CLE/Linux x86_64, Cray compiler (dmpar)
  36. Cray XE/XC CLE/Linux x86_64, Cray compiler (dmpar_NO_GRIB2)
  37. Cray XC CLE/Linux x86_64, Intel compiler (serial)
  38. Cray XC CLE/Linux x86_64, Intel compiler (serial_NO_GRIB2)
  39. Cray XC CLE/Linux x86_64, Intel compiler (dmpar)
  40. Cray XC CLE/Linux x86_64, Intel compiler (dmpar_NO_GRIB2)

Enter selection [1-40] : 3
-----------------------------------------------------------------------------------------------
Configuration successful. To build the WPS, type: compile
-----------------------------------------------------------------------------------------------
```

The `metgrid.exe` and `geogrid.exe` programs rely on the WRF model's I/O libraries. There is a line in the `configure.wps` file that directs the WPS build system to the location of the I/O libraries from the WRF model.

```console
(...)
WRF_DIR = ../WRF
(...)
```

Above is the default setting. As long as the name of the WRF model's top-level directory is "WRF" and the WPS and WRF directories are at the same level (which they should be if you have followed exactly as instructed on this page so far), then the existing default setting is correct and there is no need to change it. If it is not correct, you must modify the configure file and then save the changes before compiling.

You can now compile WPS. Compilation should take a few minutes. The ongoing compilation can be checked.

```console
./compile >& compile.log &
tail -f compile.log
```

运行到如下所示代码时即 compile 结束，按 ctrl+c 即可结束。

```console
make[1]: Leaving directory '/home/dutwr/Build_WRF/WPS/util/src'
if [ -h int2nc.exe ] ; then \
    /bin/rm -f int2nc.exe ; \
fi ; \
if [ -h ../int2nc.exe ] ; then \
    /bin/rm -f ../int2nc.exe ; \
fi ; \
if [ -e src/int2nc.exe ] ; then \
    ln -sf src/int2nc.exe . ; \
fi
```

Once the compilation completes, to check whether it was successful, you need to look for 3 main executables in the WPS top-level directory. Then verify that they are not zero-sized.

```console
$ ls -ls *.exe
geogrid.exe -> geogrid/src/geogrid.exe
metgrid.exe -> metgrid/src/metgrid.exe
ungrib.exe -> ungrib/src/ungrib.exe
```

确认他们不是 0 大小的（在\*/src/文件夹内），使用一下语句可以查看文件大小：

```console
ls -ls geogrid/src/geogrid.exe
```

## Static geography data

- _A video of this part is available [here](https://www.youtube.com/watch?v=yxqpeK-l2ys)._

The WRF modeling system is able to create idealized simulations, though most users are interested in the real-data cases. To initiate a real-data case, the domain's physical location on the globe and the static information for that location must be created. This requires a data set that includes such fields as topography and land use categories.静态地理数据可以从[WRF 下载页面](http://www2.mmm.ucar.edu/wrf/users/download/get_sources_wps_geog.html)下载。用以下语句在 wps_files 文件夹内选择 geog_complete 数据下载即可。移动到`Build_WRF`文件夹，下载并解压。Once unpacked it will be called `geog`, rename to `WPS_GEOG`.

```console
cd {path_to_dir}/Build_WRF
wget http://www2.mmm.ucar.edu/wrf/src/wps_files/geog_complete.tar.gz
tar -xvf geog_complete.tar.gz
mv geog WPS_GEOG
```

The directory infomation is given to the geogrid program in the `namelist.wps` file in the `&geogrid` section.

```console
$ cd WPS
$ sudo vim namelist.wps

(...)
geog_data_path = '{path_to_dir}/Build_WRF/WPS_GEOG'
(...)
```

The data expands to approximately 10 GB. This data allows a user to run the geogrid.exe program.

## Real-time Data

对于真实数据案例，WRF 模型需要最新的气象信息以得到初始条件和边界条件。这些气象数据传统上是 Grid 文件，由以前运行的外部模型或分析提供。对一个半操作的设置，气象数据通常来源于全球模型，它允许定位 WRF 模型的域到全球任意地方。

NCEP（National Centers for Environmental Prediction）运行 GFS（Global Forecast System）一天 4 次（初始化有效时间是 0,6,12,18 UTC）。这是全球的，等压线的，0.5 度经纬度，预报数据集，它是免费的，通常在初始化时间 4 小时后可以获得。

单一的数据文件每个需求时段都需要获取。例如，如果想要预报的时间是初始化时间为 2014 年一月 31 日 UTC 0 点的 0,6,12 小时，我们需要以下时间：
2014013100 – 0 h
2014013106 – 6 h
2014013112 – 12 h
这些要转换为以下文件名称来访问：
gfs.2014013100/gfs.t00z.pgrb2.0p50.f000
gfs.2014013100/gfs.t00z.pgrb2.0p50.f006
gfs.2014013100/gfs.t00z.pgrb2.0p50.f012
注意初始数据和时间 (gfs.2014013100) 仍相同，并且预报循环保持相同（t00z）。增加的是预测小时(f00、f06、f12)。

在获取数据之前，在 Build_WRF 文件夹中建立一个 DATA 文件夹，然后进入文件夹：

```console
mkdir DATA
cd DATA
```

一个简单的交互命令来从 NCEP 服务器实时抓取这些文件示例如下（**注意**这仅仅是一个示例 time/date。典型地在 NCEP 数据服务器上，仅仅最近的 2-3 天在认识给定的时间可用。为了使用最新的实时数据，你需要调整命令来反映当前的日期和时间信息）：

```console
curl -s --disable-epsv --connect-timeout 30 -m 60 -u anonymous:USER_ID@INSTITUTION -o GFS_00h \ ftp://ftpprd.ncep.noaa.gov/pub/data/nccf/com/gfs/prod/gfs.2014013100/gfs.t00z.pgrb2.0p50.f000
curl -s --disable-epsv --connect-timeout 30 -m 60 -u anonymous:USER_ID@INSTITUTION -o GFS_06h \ ftp://ftpprd.ncep.noaa.gov/pub/data/nccf/com/gfs/prod/gfs.2014013100/gfs.t00z.pgrb2.0p50.f006
curl -s --disable-epsv --connect-timeout 30 -m 60 -u anonymous:USER_ID@INSTITUTION -o GFS_12h \ ftp://ftpprd.ncep.noaa.gov/pub/data/nccf/com/gfs/prod/gfs.2014013100/gfs.t00z.pgrb2.0p50.f012
```

典型地这些命令几秒内返回一个完整的文件。从这些命令返回的这些文件（GFS_00h, GFS_06h, GFS_12h）是 Grib2 格式的文件，能直接被 ungrib 程序使用。

您需要填写匿名的登录信息（这不是私有的，所以不需要担心这些脚本的安全性）。您可能最终会编写一个简短的脚本来自动增加初始化时间。

## Run WPS and WRF

**以下是运行 WPS 和 WRF 的基础指令。对更多的细节信息，可以查看[WRF-ARW Online Tutorial](http://www2.mmm.ucar.edu/wrf/OnLineTutorial/index.php)**

### Running WPS

现在准备好开始运行 WPS 和 WRF。从 WPS 文件夹开始。

```console
cd WPS
```

对 namelist.wps 做更改以反映您特定运行的信息。

在运行 geogrid 之前，请确保将 geog_data_path 设置为放置地理静态数据的位置。设置之后就可以运行 geogrid。

```console
./geogrid.exe >& log.geogrid
```

如果成功地为每个域创建了一个 goe_em\*文件，然后您及可以准备运行 ungrib。通过连接到输入的 GFS 数据开始：

```console
./link_grib.csh path_where_you_placed_GFS_files
```

Then link to the correct Vtable (GFS, for this case):

```console
ln -sf ungrib/Variable_Tables/Vtable.GFS Vtable
```

Then run the ungrib executable:

```console
./ungrib.exe
```

You should now have files with the prefix "FILE" (or if you named them something else, they should have that prefix)

You are now ready to run metgrid:

```console
./metgrid.exe >& log.metgrid
```

You should now have files with the prefix met_em\* for each of the time periods for which you are running.

### Running WRF

You are now ready to run WRF. Move into the WRF directory, and then into either the run/ directory, or the test/em_real/
directory:

```console
cd ../WRF/run
```

or

```console
cd ../WRF/test/em_real
```

Before running the "real" program, you need to make all necessary changes to reflect your particular case to the namelist.input file. Once that is complete, you need to copy or link your met_em\* files into the working directory:

```console
ln -sf ../../../WPS/met_em* .     (from the test/em_real directory), or
ln -sf ../../WPS/met_em* .            (from the run/ directory).
```

or, if you would rather copy the files in, instead of linking them, you can use the cp command, instead of the ln -sf command.
You can now run the "real" program. The command for running this may vary depending on your system and the number of processors you have available, but it should be something similar to:

```console
mpirun -np 1 ./real.exe
```

Check the end of your "rsl" files to make sure the run was successful:

```console
tail rsl.error.0000
```

If you see a "SUCCESS" in there, and you see a wrfbdy_d01 file, and wrfinput_d0\* files for each of your domains, then the run was successful.
To run WRF, type something similar to:

```console
mpirun -np 8 ./wrf.exe
```

Again, check your "rsl" file for "SUCCESS", and make sure you have all the wrfout\* files you anticipated having. If so, the run was successful, and you are ready to do analysis for your project.

- **_TODO 以下内容为3.8版本，4.0版本尚未完成_**

## Post processing

ARWpost is a Fortran program that reads WRF-ARW input and output files, then generates GrADS output files.

Once the output files have been generated, GrADS can be used to produce horizontal or vertical cross-section plots of scalar fields (contours) or vector fields (barbs or arrows), vertical profiles and soundings.

Is recommend the use of ARWpost Version 3 or higher. This code is not dependent on the successful compilation of the WRFV3 code, and can therefore be installed anywhere, even if WRFV3 is not installed on this computer.

Move to your `Build_WRF` directory, download the file and unpack it.

```console
cd {path_to_dir}/Build_WRF
wget http://www2.mmm.ucar.edu/wrf/src/ARWpost_V3.tar.gz
tar -zxvf ARWpost_V3.tar.gz
```

Once unpacked, move to `ARWpost` directory and look for the following files.

```console
$ cd {path_to_dir}/Build_WRF/ARWpost
$ ls -las
arch            # A directory containing configure and
                #    compilation control
clean            # Script to clean compiled code
compile            # Script to compile the code
configure        # Script to configure the compilation for
                # your system
namelist.ARWpost    # Namelist to control the running of the code
README            # A text file containing basic information
                # on running ARWpost
src                # Directory containing all source code
script            # Directory containing some grads sample
                # scripts
util            # Directory containing some utilities
```

Assuming that the NETCDF variable is set, it is possible to configure the ARWpost.

```console
./configure
```

You will see a list of options for your computer. Make sure the netCDF path is correct and pick the compile option for your machine.

```console
Will use NETCDF in dir: /home/drasousa/Build_WRF/LIBRARIES/netcdf
-----------------------------------------------------------------------------------------------
Please select from among the following supported platforms.

1.  PC Linux i486 i586 i686 x86_64, PGI compiler
2.  PC Linux i486 i586 i686 x86_64, Intel compiler
3.  PC Linux i486 i586 i686 x86_64, gfortran compiler

Enter selection [1-3] : 3
-----------------------------------------------------------------------------------------------
Configuration successful. To build the ARWpost, type: compile
-----------------------------------------------------------------------------------------------
```

Edit the `Makefile` file into the `src` directory and modify the `-L$(NETCDF)` line into the `ARWpost.exe` environment to look like:

```console
$ cd {path_to_dir}/ARWpost/src
$ nano Makefile

(...)
-L$(NETCDF)/lib -lnetcdf -lnetcdff -I$(NETCDF)/include -lnetcdf
(...)
```

Move to the `ARWpost` directory and modify the `CFLAGS` and `CPP` lines into `configure.arwp` file.

```console
$ cd {path_to_dir}/ARWpost
$ nano configure.arwp

(...)
CFLAGS = -fPIC -m64
CPP = /lib/cpp -P -traditional
(...)
```

Then compile the ARWpost. If successful, the executable ARWpost.exe will be created.

```console
$ ./compile
$ ls -ls *.exe
ARWpost.exe
```

## Extra steps

Install grads, nco and nedit:

```console
sudo apt-get install grads nco nedit
```

Configuring cdo library: Download de cdo tar file and unpack it. Once unpacked, go inside the unpacked cdo folder and run the configure script, make and make install. Then add the cdo environment into the `.bashrc` file and source it.

```console
$ cd {path_to_dir}/Build_WRF/LIBRARIES
$ wget https://code.zmaw.de/attachments/download/12760/cdo-1.7.2.tar.gz
$ tar -xvf cdo-1.7.2.tar.gz
$ cd cdo-1.7.2
$ ./configure --prefix=$DIR/cdo --with-netcdf=$DIR/netcdf --with-grib2=$DIR/grib2
$ make
$ make install
$ sudo nano ~/.bashrc

export PATH=$DIR/cdo/bin:$PATH

$ source ~/.bashrc
```

Configuring ncl library: Create a folder named ncl into the LIBRARY folder, download the ncl tar file and unpack it. Once unpacked add the ncl environment variables into the `.bashrc` file and source it. If you get missing `librtmp.so.0` library message while running the ncl, try to locate the missing library into your system and make a symbolic link.

```console
$ cd {path_to_dir}/Build_WRF/LIBRARIES
$ mkdir ncl
$ cd ncl
$ wget https://www.earthsystemgrid.org/download/fileDownload.html?logicalFileId=e087c7da-cd9a-11e4-bb80-00c0f03d5b7c
$ tar -zxvf ncl_ncarg-6.3.0.Linux_Debian7.8_x86_64_gcc472.tar.gz
$ sudo nano ~/.bashrc

export NCARG_ROOT=$DIR/ncl
export PATH=$NCARG_ROOT/bin:$PATH
export DISPLAY=:0.0

$ source ~/.bashrc
$ locate librtmp     # if you get error message while loading shared libraries

/usr/lib/x86_64-linux-gnu/librtmp.so.1

$ cd /usr/lib/
$ sudo ln -s /usr/lib/x86_64-linux-gnu/librtmp.so.1 librtmp.so.0

$ ng4ex gsun01n -clean        # execute this in super user mode if you get permission error
```
