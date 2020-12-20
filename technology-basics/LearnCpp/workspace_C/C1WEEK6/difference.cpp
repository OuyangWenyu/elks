/*
 * difference.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main(){
	int a[6];
	for(int i=0;i<6;i++){
		cin>>a[i];
	}
	int maxOdd=0,minEven=100;
	for(int i=0;i<6;i++){
		if(a[i]%2==1 && a[i]>maxOdd)
			maxOdd=a[i];
		if(a[i]%2==0 && a[i]<minEven)
			minEven=a[i];
	}
	cout<<(maxOdd-minEven>0?(maxOdd-minEven):(minEven-maxOdd))<<endl;
	cout<<sizeof(short)<<endl;
	cout<<sizeof(int)<<endl;
	cout<<sizeof(long)<<endl;
	cout<<sizeof(double)<<endl;
	cout<<sizeof(float)<<endl;
	int b=037777777605;
	cout<<hex<<b<<endl;
	cout<<oct<<b<<endl;
	cout<<dec<<b<<endl;
	return 0;
}





