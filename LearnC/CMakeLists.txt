cmake_minimum_required(VERSION 3.14)
project(LearnC C)

set(CMAKE_C_STANDARD 99)

find_package(PkgConfig REQUIRED)
# 需要在环境变量中配置好.pc文件的路径
pkg_check_modules(NETCDF REQUIRED netcdf)
pkg_search_module(NETCDF REQUIRED netcdf)

add_executable(LearnC simple_nc4_rd.c)

# add_executable要在link、include等之前，否则会报错
# 设置要链接的库文件的名称TARGET_LINK_LIBRARIES
target_link_libraries(LearnC ${NETCDF_LIBRARIES})
target_link_libraries(LearnC /usr/local/lib/libnetcdf.so.15)
# 把头文件包含进来
target_include_directories(LearnC PUBLIC ${NETCDF_INCLUDE_DIRS})
target_compile_options(LearnC PUBLIC ${NETCDF_CFLAGS_OTHER})
