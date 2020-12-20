/*
 * matrixChange.cpp
 *
 *  Created on: 2016年11月27日
 *      Author: asus
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int a[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	int n, m;
	cin >> n >> m;
	if (n > 4 || m > 4 || n < 0 || m < 0)
		cout << "error" << endl;
	else {
		for (int i = 0; i < 5; i++) {
			int temp = a[m][i];
			a[m][i] = a[n][i];
			a[n][i] = temp;
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}

