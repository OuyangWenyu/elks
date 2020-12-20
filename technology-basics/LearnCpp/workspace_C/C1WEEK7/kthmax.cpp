/*
 * kthmax.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main() {
	int N;
	cin>>N;
	int K;
	cin>>K;
	int a[N];
	for(int i=0;i<N;i++){
		cin>>a[i];
	}

	for(int i=0;i<N;i++){
		int count=0;
		int temp=a[i];
		for(int j=0;j<N;j++){
			if(a[j]>=temp && j!=i)
				count++;
		}
		if(count==K-1){
			cout<<temp;
			break;
		}
	}
	return 0;
}


