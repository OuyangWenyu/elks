/*
 * elephant.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main3(){
	int h,r;
	cin>>h>>r;
	double Pi=3.14159;
	double V0=Pi*r*r*h;
	int a=20000/V0;
	int result=a+1;
	cout<<result;
	return 0;
}


