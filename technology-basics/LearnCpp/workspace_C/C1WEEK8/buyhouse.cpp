/*
 * buyhouse.cpp
 *
 *  Created on: 2016年11月22日
 *      Author: asus
 */

#include <iostream>
#include <cmath>
using namespace std;

int main3(){
	double N,K;
	while(cin>>N>>K){
		int M=1;
		double price=200;
		while(price*pow((1+K*0.01),(M-1))>N*M){
			M++;
			if(M>20)
				break;
		}
		if(M>20)
			cout<<"Impossible"<<endl;
		else
			cout<<M<<endl;
	}
	return 0;
}


