/*
 * gradeJudge.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main4() {
	int n;
	cin >> n;

	int m;
	if (95 <= n && n <= 100)
		m = 1;

	else if (90 <= n && n< 95)
		m = 2;

	else if (85 <= n && n< 90)
		m = 3;

	else if (80 <= n&& n < 85)
		m = 4;

	else if (70 <= n && n< 80)
		m = 5;

	else if (60 <= n && n< 70)
		m = 6;

	else if (n < 60)
		m = 7;
	cout << m;
	return 0;
}

