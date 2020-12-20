/*
 * bacteria.cpp
 *
 *  Created on: 2016年12月4日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main5() {
	int n;
	cin >> n;
	int i = 0;
	int id[n];
	double rate[n];
	while (n > i) {
		int initial,final;
		cin >> id[i] >> initial >> final;
		rate[i]=(double)final/initial;
		i++;
	}

	for(int j=0;j<n-1;j++){
		for(int k=0;k<n-j-1;k++){
			if(rate[k]>rate[k+1]){
				double temp=rate[k];
				rate[k]=rate[k+1];
				rate[k+1]=temp;
				int tempId=id[k];
				id[k]=id[k+1];
				id[k+1]=tempId;
			}
		}
	}

	double diffMax=0.0;
	int idDiffMax=0;
	for(int i=1;i<n;i++){
		double diff=rate[i]-rate[i-1];
		if(diff>diffMax){
			diffMax=diff;
			idDiffMax=i;
		}
	}

	cout<<n-idDiffMax<<endl;
	for(int i=idDiffMax;i<n;i++)
		cout<<id[i]<<endl;
	cout<<idDiffMax<<endl;
	for(int i=0;i<idDiffMax;i++)
		cout<<id[i]<<endl;
	return 0;
}

