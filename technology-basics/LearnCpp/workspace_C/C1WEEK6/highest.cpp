/*
 * highest.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main4(){
	int n;
	cin>>n;
	int a,max=0;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a>max)
			max=a;
	}
	cout<<max;
	return 0;
}



