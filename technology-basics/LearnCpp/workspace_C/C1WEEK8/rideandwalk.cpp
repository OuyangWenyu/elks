/*
 * rideandwalk.cpp
 *
 *  Created on: 2016年11月22日
 *      Author: asus
 */
#include <iostream>
using namespace std;

int main2(){
	int n;
	cin>>n;
	while(n--){
		double a;
		cin>>a;
		double tbike=27+23+a/3.0;
		double twalk=a/1.2;
		if(tbike<twalk)
			cout<<"Bike"<<endl;
		else if(twalk<tbike)
			cout<<"Walk"<<endl;
		else
			cout<<"All"<<endl;
	}
	return 0;
}



