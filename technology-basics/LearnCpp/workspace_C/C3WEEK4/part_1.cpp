/*
 * part_1.cpp
 *
 *  Created on: 2017年4月9日
 *      Author: asus
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    void operator =(string s){
    	Complex c();
    	int k=0;
    	for(;s[k]!='+';k++);
 		r=atoi(s.substr(0,k+1).c_str());
    	int j=k+1;
    	for(;s[j]!='i';j++);
    	i=atoi(s.substr(k+1,j-k).c_str());
    }
};
int main1() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}



