/*
 * tomorrow.cpp
 *
 *  Created on: 2016年12月4日
 *      Author: asus
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool isLeapYear(int year){
	return (year % 400==0 || (year%100!=0 && year%4==0));
}

int main4(){
	char c;
	char y[5];
	char m[3];
	char d[3];
	for(int i=0;i<10;i++){
		if(i<4)
			cin>>y[i];
		else if(i>4 && i<7)
			cin>>m[i-5];
		else if(i>7 && i<10)
			cin>>d[i-8];
		else
			cin>>c;
	}

	int year=atoi(y);
	int month=atoi(m);
	int day=atoi(d);
	int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeapYear(year))
		days[2]=29;
	if(day+1>days[month]){
		month=month+1;
		day=1;
		if(month>12){
			month=1;
			year=year+1;
		}
	}
	else
		day=day+1;
	cout<<year<< "-"<< setfill ('0') << setw (2)<<month<<"-"<< setfill ('0') << setw (2)<<day<<endl;
	return 0;
}


