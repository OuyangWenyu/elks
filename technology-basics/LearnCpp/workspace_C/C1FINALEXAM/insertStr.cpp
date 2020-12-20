/*
 * insertStr.cpp
 *
 *  Created on: 2016年12月1日
 *      Author: asus
 */

#include <iostream>
using namespace std;
int main() {
	char str[11], substr[4];
	while (cin >> str >> substr) {
		char temp = str[0];
		int flag = 0;
		for (int i = 1; str[i] != '\0'; i++) {
			if (temp - str[i] < 0) {
				temp = str[i];
				flag = i;
			}
		}
		for (int i = 0; i <= flag; i++)
			cout << str[i];
		cout << substr;
		for (int i = flag+1; str[i] != '\0'; i++)
			cout << str[i];
		cout<<endl;
	}
	return 0;
}

