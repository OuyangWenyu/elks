/*
 * num1.cpp
 *
 *  Created on: 2016年11月16日
 *      Author: asus
 */
#include <iostream>
using namespace std;

int main4(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		int num=0;
		while(n>0){
			num+=n%2;
			n/=2;
		}
		cout<<num<<endl;
	}
	return 0;
}


