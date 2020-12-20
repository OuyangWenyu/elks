/*
 * chinayuan.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main6() {
	int n;
	cin>>n;
	int n100=n/100;
	int n50=(n-n100*100)/50;
	int n20=(n-n100*100-n50*50)/20;
	int n10=(n-n100*100-n50*50-n20*20)/10;
	int n5=(n-n100*100-n50*50-n20*20-n10*10)/5;
	int n1=n-n100*100-n50*50-n20*20-n10*10-n5*5;
	cout<<n100<<endl;
	cout<<n50<<endl;
	cout<<n20<<endl;
	cout<<n10<<endl;
	cout<<n5<<endl;
	cout<<n1<<endl;
	return 0;
}


