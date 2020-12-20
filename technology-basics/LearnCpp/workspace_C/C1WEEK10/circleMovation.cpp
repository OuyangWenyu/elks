/*
 * circleMovation.cpp
 *
 *  Created on: 2016年11月27日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main1() {
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - m; i < n; i++) {
		int temp = a[i];
		for (int j = i; j > i - (n - m); j--) {
			a[j] = a[j - 1];
		}
		a[i-(n-m)] = temp;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}

