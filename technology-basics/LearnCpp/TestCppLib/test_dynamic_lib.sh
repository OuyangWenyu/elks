rm -f libwind.so

g++ -shared -fpic -o libwind.so wind.cpp

g++ test.cpp -o test -L. -lwind
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./test
