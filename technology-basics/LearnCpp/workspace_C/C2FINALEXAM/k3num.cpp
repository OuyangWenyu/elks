/*
 * k3num.cpp
 *
 *  Created on: 2017年1月17日
 *      Author: asus
 */
#include <iostream>
using namespace std;

int main1(){
	int m,k;
	cin>>m>>k;
	int count=0;
	if(m%19==0){
		while(m/10>0){
			if(m%10==3)
				count++;
			m=m/10;
		}
		if(m==3)
			count++;
		if(count==k)
			cout<<"YES";
		else
			cout<<"NO";
	}else
		cout<<"NO";
	return 0;
}



