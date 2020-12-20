/*
 * operation.cpp
 *
 *  Created on: 2017年1月19日
 *      Author: asus
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main3() {
	int a, b, c;
	char str[100];
	cin.get(str, 100);
	char cha[10];
	char chb[10];
	char chc[10];
	int pos1, pos2;
	for (int i = 0; str[i] != '\0'; i++) {
		cha[i] = str[i];
		if (str[i] == ',') {
			pos1 = i;
			break;
		}
	}
	a = atoi(cha);
	for (int i = pos1 + 1; str[i] != '\0'; i++) {
		chb[i - pos1 - 1] = str[i];
		if (str[i] == ',') {
			pos2 = i;
			break;
		}
	}
	b = atoi(chb);
	for (int i = pos2 + 1; str[i] != '\0'; i++)
		chc[i - pos2 - 1] = str[i];

	c = atoi(chc);
	if (a + b == c)
		cout << "+";
	else if (a - b == c)
		cout << "-";
	else if (a * b == c)
		cout << "*";
	else if (a / b == c)
		cout << "/";
	else if (a % b == c)
		cout << "%";
	else
		cout << "error";
	return 0;
}

