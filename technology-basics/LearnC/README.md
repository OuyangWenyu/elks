# LearnC
这是一个简单地了解C和C++的小文档，点到为止，重点是为了学习一些使用C或者C++编写的水文水资源相关模型。

## CMake文件

### 如何使用第三方库

很多安装的软件，在代码编译运行的时候都会报错，比如include的文件找不到，链接库找不到等等。
这是因为如果编译软件使用了外部库，事先并不知道它的头文件和链接库的位置。
得在编译命令中加上包含它们的查找路径。CMake中可以使用 find_package 命令来解决这个问题，也可以借用第三方的pkg-config来解决。

#### find_package

可以通过命令 cmake --help-module-list 得到你的CMake支持的模块的列表。如果不在支持的列表中，
则需要自己定义 Find<name>模块，将其放入工程的某个目录中，通过 SET(CMAKE_MODULE_PATH dir)设置查找路径，供工程FIND_PACKAGE使用。

#### pkg-config

以netcdf为例。netcdf安装后，在其lib文件夹下有pkgconfig.
首先需要在环境变量中配置PkgConfig的路径。比如这里netcdf的安装路径是/usr/local。
对于Ubuntu系统，可以用root权限打开/etc/profile文件，然后输入以下代码：

```code
PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
export PKG_CONFIG_PATH
```

然后在CMakeLists.txt中写入以下语句，注意顺序很重要。

```code
find_package(PkgConfig REQUIRED)
# 需要在环境变量中配置好.pc文件的路径
pkg_check_modules(NETCDF REQUIRED netcdf)
pkg_search_module(NETCDF REQUIRED netcdf)

add_executable(LearnC simple_nc4_rd.c)

# add_executable要在link、include等之前，否则会报错
# 把对应的库文件加载进来
target_link_libraries(LearnC ${NETCDF_LIBRARIES})
# 把头文件包含进来
target_include_directories(LearnC PUBLIC ${NETCDF_INCLUDE_DIRS})
target_compile_options(LearnC PUBLIC ${NETCDF_CFLAGS_OTHER})
```
如果还报错，有库没加进来，可以手动添加绝对路径，比如报错：
error while loading shared libraries: libnetcdf.so.15: cannot open shared object file
则可以添加：
target_link_libraries(LearnC /usr/local/lib/libnetcdf.so.15)