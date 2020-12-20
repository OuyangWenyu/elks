/*
 * inverse.cpp
 *
 *  Created on: 2016年11月16日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(0<n--)
		cout<<a[n]<<" ";
	return 0;
}


