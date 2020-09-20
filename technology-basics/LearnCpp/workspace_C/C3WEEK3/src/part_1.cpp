#include <iostream>
using namespace std;

class A {
public:
    int val;
// 在此处补充你的代码
    A(int n=0){ val = n; }
    int & GetObj() {
           return val;
       }
};
int main1()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
    return 0;
}
