/*
 * findSubscript.cpp
 *
 *  Created on: 2016年12月3日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main1(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int flag=1;
	for(int i=0;i<n;i++){
		if(a[i]==i){
			cout<<i<<endl;
			flag=0;
			break;
		}
	}
	if(flag)
		cout<<"N"<<endl;
	return 0;
}


