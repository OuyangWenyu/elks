/*
 * easyCalculator.cpp
 *
 *  Created on: 2016年12月1日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main2(){
	int a,b;
	char c;
	cin>>a>>b>>c;
	if(c=='+')
		cout<<a+b<<endl;
	else if(c=='-')
			cout<<a-b<<endl;
	else if(c=='*')
			cout<<a*b<<endl;
	else if(c=='/'){
		if(b==0)
			cout<<"Divided by zero!"<<endl;
		else	cout<<a/b<<endl;}
	else
		cout<<"Invalid operator!"<<endl;
	return 0;
}


