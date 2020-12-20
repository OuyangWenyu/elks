/*
 * divisible.cpp
 *
 *  Created on: 2016年12月1日
 *      Author: asus
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main1(){
	int n;
	while(cin>>n){
		int a[3];
		a[0]=3;a[1]=5;a[2]=7;
		for(int i=0;i<3;i++){
			if(n%a[i]==0)
				cout<<a[i]<<" ";
		}
		if(n%3!=0 && n%5!=0 && n%7!=0)
			cout<<"n";
		cout<<endl;
	}
	return 0;
}


