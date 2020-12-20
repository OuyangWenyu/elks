/*
 * median.cpp
 *
 *  Created on: 2016年11月28日
 *      Author: asus
 */
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		else{
		int a[N];
		int K = N / 2;
		int K1 = N / 2 - 1;
		for (int i = 0; i < N; i++) {
			int aa;
			cin >> aa;
			a[i] = aa;
		}
		int a1 = 0;
		int a2 = 0;
		for (int i = 0; i < N; i++) {
			int temp = a[i];
			int count = 0;
			for (int j = 0; j < N; j++) {
				if (a[j] >= temp && j != i)
					count++;
			}
			if (count == K1) {
				a1 = temp;
			}
			if (count == K) {
				a2 = temp;
			}
		}
		double res = (a1 + a2) / 2;
		int a3=floor(res);
		if(N%2==1)
			cout << a2 << endl;
		else
			cout << a3 << endl;
	}}
	return 0;
}
