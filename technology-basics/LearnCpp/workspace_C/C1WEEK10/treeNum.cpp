/*
 * treeNum.cpp
 *
 *  Created on: 2016年11月30日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main5(){
	int L,M;
	cin>>L>>M;
	int a[M][2];
	int T[L+1];
	for(int i=0;i<L+1;i++){
		T[i]=1;
	}
	for(int i=0;i<M;i++){
		cin>>a[i][0]>>a[i][1];
		for(int j=a[i][0];j<=a[i][1];j++){
			T[j]=0;
		}
	}
	int count=0;
	for(int k=0;k<=L;k++){
		count=count+T[k];
	}
	cout<<count<<endl;
	return 0;
}


