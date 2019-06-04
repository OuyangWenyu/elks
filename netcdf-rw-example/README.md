# netcdf使用
nc格式数据是水文模型应用中常见的一种格式，很多软件比如WRF、VIC等都会用到，至于为什么经常用，可以参考官方[用户手册](https://www.unidata.ucar.edu/software/netcdf/docs/index.html)。

## 安装netcdf
因为水文上很多模型使用范围较小，社区人员不多，因此软件持续开发的能力相对较弱，所以使用的依赖库的版本很多都不是最新的，netcdf也不例外，但是水文软件安装时候可以组织自己的独立文件夹，因此单独安装一些库时，比如这里的netcdf，推荐依据官方[用户手册](https://www.unidata.ucar.edu/software/netcdf/docs/getting_and_building_netcdf.html)安装最新的稳定版本，以下是个人实践。

### Ubuntu下的安装

Ubuntu 16.04下进行安装。

首先需要进行netCDF-C的安装，因为其他库都依赖netCDF，比如Fortran、Python、Java、C++等库，C库的安装是必要条件。

#### 获取netCDF-C

可以通过apt-get获取pre-built的库，也可以直接获取最新版本的源码，这里选择从源码安装，因为下载[源码](https://github.com/Unidata/netcdf-c/releases)，这里选择下载tar.gz版本，zip版应该也没区别。

#### 构建netCDF-C

netCDF库需要第三方的库才能实现完整的功能。

依赖有：
- 对netCDF-4的支持需要：
  - HDF5 1.8.9 or later.
  - HDF5 1.10.1 or later.
- zlib 1.2.5 or later (for netCDF-4 compression)
- curl 7.18.0 or later (for DAP remote access client support)
- For parallel I/O support on classic netCDF files
  - PnetCDF 1.6.0 or later

注意：对4.4.1以前的版本，只能使用HDF5 1.8.X版本。

这里的构建采用支持netCDF-4和远程数据客户端以及并行计算的方式。同学

下载病构建zlib：

```code

```

### windows下的安装

## 资料 
补充一些资料如下：
[Python programming guide for Earth Scientists](http://python.hydrology-amsterdam.nl/manuals/hydro_python_manual.pdf)；
[netcdf4-python](https://github.com/Unidata/netcdf4-python)；
[Generating NetCDF files with Python](http://www.ceda.ac.uk/static/media/uploads/ncas-reading-2015/11_create_netcdf_python.pdf)；
[Python-NetCDF reading and writing example with plotting](http://schubert.atmos.colostate.edu/~cslocum/netcdf_example.html)。