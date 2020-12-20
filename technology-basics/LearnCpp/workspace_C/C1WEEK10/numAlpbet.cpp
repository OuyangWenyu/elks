/*
 * numAlpbet.cpp
 *
 *  Created on: 2016年11月27日
 *      Author: asus
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main4() {
	char s[80];
	cin.getline(s, 80);
	int a[5]={0,0,0,0,0};
	for (int i = 0; i < 80; i++) {
		if(s[i]=='a')
			a[0]++;
		else if(s[i]=='e')
			a[1]++;
		else if(s[i]=='i')
			a[2]++;
		else if(s[i]=='o')
			a[3]++;
		else if(s[i]=='u')
			a[4]++;
	}
	cout<<a[0]<<setw(2)<<a[1]<<setw(2)<<a[2]<<setw(2)<<a[3]<<setw(2)<<a[4]<<setw(2)<<endl;
	return 0;
}

