/*
 * invoice.cpp
 *
 *  Created on: 2016年12月4日
 *      Author: asus
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main3(){
	int id[3];
	int num[3];
	float ids[3]={0.00,0.00,0.00};
	float abc[3]={0.00,0.00,0.00};
	for(int i=0;i<3;i++){
		cin>>id[i]>>num[i];
		char c[num[i]];
		float f[num[i]];
		for(int j=0;j<num[i];j++){
			cin>>c[j]>>f[j];
			if(c[j]=='A')
				abc[0]=abc[0]+f[j];
			else if(c[j]=='B')
			    abc[1]=abc[1]+f[j];
			else if(c[j]=='C')
				abc[2]=abc[2]+f[j];
			ids[i]=ids[i]+f[j];
		}
	}
	char ABC[3]={'A','B','C'};
	for(int k=0;k<3;k++){
		cout<<k+1<<" "<<setiosflags(ios::showpoint)<<setprecision(3)<<ids[k]<<endl;
	}
	for(int k=0;k<3;k++){
		cout<<ABC[k]<<" "<<setiosflags(ios::showpoint)<<setprecision(3)<<abc[k]<<endl;
	}
	return 0;
}


