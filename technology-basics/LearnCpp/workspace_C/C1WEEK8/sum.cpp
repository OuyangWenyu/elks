/*
 * sum.cpp
 *
 *  Created on: 2016年11月22日
 *      Author: asus
 */
#include <iostream>
using namespace std;

int main1(){
	int a,b[5],sum=0;
	cin>>a>>b[0]>>b[1]>>b[2]>>b[3]>>b[4];
	for(int i=0;i<5;i++){
		if(b[i]<a)
			sum=sum+b[i];
	}
	cout<<sum;
	return 0;
}



