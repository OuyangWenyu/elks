rm -f wind.o
rm -f libwind.a

g++ -c wind.cpp -o wind.o
ar -cr libwind.a wind.o

g++ test.cpp -o test -static -L. -lwind
./test
