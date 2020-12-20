/*
 * sumK.cpp
 *
 *  Created on: 2016年11月22日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main4(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int i=0;
	for(i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(a[i]+a[j]==k){
				cout<<"yes";
				i=n;
				break;
			}

		}
	}
	if(i<n) cout<<"no";
	return 0;
}


