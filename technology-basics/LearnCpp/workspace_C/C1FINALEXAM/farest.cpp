/*
 * farest.cpp
 *
 *  Created on: 2016年12月1日
 *      Author: asus
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main3(){
	int n;
	cin>>n;
	double a[n][2];
	for(int i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1];
	double dis=0.0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			double temp=sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
			if(temp>dis) dis=temp;
		}
	}
	cout<<fixed<<setprecision(4)<<dis<<endl;
	return 0;
}


