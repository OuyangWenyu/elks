/*
 * assignWard.cpp
 *
 *  Created on: 2017年1月14日
 *      Author: asus
 */

#include <iostream>
#include <iomanip>
using namespace std;

void sort(int num[], double lev[], int length) {
	for (int i = 0; i < length; i++) {
		for (int j = 1; j < length - i; j++) {
			if (lev[j - 1] < lev[j]) {
				double temp = lev[j];
				lev[j] = lev[j - 1];
				lev[j - 1] = temp;
				int tempNum = num[j];
				num[j] = num[j - 1];
				num[j - 1] = tempNum;
			}
		}
	}
}

int main1() {
	int m;
	double a;
	cin >> m >> a;
	int num[m];
	double level[m];
	for (int i = 0; i < m; i++)
		cin >> num[i] >> level[i];
	sort(num, level, m);
	if (level[0] < a)
		cout << "None." << endl;
	else {
		for (int i = 0; i < m; i++) {
			if (level[i] >= a) {
				cout << setfill('0') << std::setw(3) << num[i] << " ";
				cout << fixed << setprecision(1) << level[i] << endl;
			}
		}
	}
	return 0;
}

