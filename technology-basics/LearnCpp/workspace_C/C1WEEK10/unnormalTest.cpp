/*
 * unnormalTest.cpp
 *
 *  Created on: 2016年11月27日
 *      Author: asus
 */

#include <iostream>
#include <cmath>
using namespace std;

int main6() {
	int N;
	cin >> N;
	int a[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	int count=0;
	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < N-1; j++) {
			if(a[i][j]-a[i][j-1]<=-50 &&
			a[i][j]-a[i][j+1]<=-50 &&
			a[i][j]-a[i-1][j]<=-50 &&
			a[i][j]-a[i+1][j]<=-50)
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}

