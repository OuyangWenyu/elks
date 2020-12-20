/*
 * part_2.cpp
 *
 *  Created on: 2017年4月9日
 *      Author: asus
 */
#include <iostream>
using namespace std;
class MyInt {
    int nVal;
    public:
        MyInt(int n) { nVal = n; }
        int ReturnVal() { return nVal; }
// 在此处补充你的代码
        MyInt & operator -(int n){
        	nVal=nVal-n;
        	return *this;
        }
};
int main2 () {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal();
    return 0;
}



