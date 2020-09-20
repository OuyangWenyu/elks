#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
// 在此处补充你的代码
    Sample(const Sample& s){
    	v=s.v;
    	v=10;
    }
};
int main2() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}
