/*
 * ageAndDisease.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: asus
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main3(){
	int n;
	cin>>n;
	double first=0,second=0,third=0,forth=0;
	int num=n;
	while(n--){
		int age;
		cin>>age;
		if(age>=1 && age<=18)
			first=first+1;
		else if(age>=19 && age<=35)
			second=second+1;
		else if(age>=36 && age<=60)
			third=third+1;
		else if(age>60)
			forth=forth+1;
	}
	first=first/num*100;
	second=second/num*100;
	third=third/num*100;
	forth=forth/num*100;
	cout<<"1-18: "<<setiosflags(ios::fixed)<<setprecision(2)<<first<<"%"<<"\n";
	cout<<"19-35: "<<setiosflags(ios::fixed)<<setprecision(2)<<second<<"%"<<"\n";
	cout<<"36-60: "<<setiosflags(ios::fixed)<<setprecision(2)<<third<<"%"<<"\n";
	cout<<"60-: "<<setiosflags(ios::fixed)<<setprecision(2)<<forth<<"%"<<"\n";
	return 0;
}


