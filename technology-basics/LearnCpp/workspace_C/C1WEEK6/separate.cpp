/*
 * separate.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main6(){
	int a;
	cin>>a;
	int hund=0,dec=0,uni=0;
	hund=a/100;
	dec=(a-hund*100)/10;
	uni=a-hund*100-dec*10;

	cout<<hund<<endl;
	cout<<dec<<endl;
	cout<<uni<<endl;
	return 0;
}



