/*
 * overturn.cpp
 *
 *  Created on: 2016年12月7日
 *      Author: asus
 */

#include <iostream>
#include <cstring>
using namespace std;

void turnover(char c[],size_t i,size_t n){
	if(i!=n){
		turnover(c,i+1,n);
		cout<<c[i];
	}
}

int main1(){
	char str[500];
	cin.getline(str,500);
	size_t begin=0;
	size_t end=5;
	for(size_t i=0;i<strlen(str);i++){
		if(str[i]==' '){
			cout<<' ';
		}
		else{
			if(i==0 || str[i-1]==' '){
				begin=i;
			}
			if(i+1==strlen(str) || str[i+1]==' '){
				end=i+1;
				turnover(str,begin,end);
			}
		}
	}


	return 0;
}


