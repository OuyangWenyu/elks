/*
 * second.cpp
 *
 *  Created on: 2017年1月19日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main2() {
	char str[1000];
	cin.getline(str, 1000);
	//首先，把大小写统一了，小写变大写，因为大写的ASCII值小一些，直接改变ASCII码值
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
	}

	//然后就运用数组的统计功能，把每个字母出现的次数记录下来
		int count[26] = { 0 };
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] >= 65 && str[i] <= 90)
				count[str[i] - 65]++;
		}
	int firstMax = 0, secondMax = 0;
	    for (int i = 0; i < 26;++i)
	    {
	        if (count[firstMax] <= count[i])        //找最大
	            firstMax = i;
	    }
	    for (int i = 0;i < 26;++i)
	    {
	        if (count[i] == count[firstMax])            //最大清零
	            count[i] = 0;
	    }
	    for (int i = 0;i < 26;++i)
	    {
	        if (count[secondMax] <= count[i])            //找第二大（最大已经清零所以第二大其实是最大）
	            secondMax = i;
	    }
	    int num = count[secondMax];
	    for (int i = 0;i < 26;++i)
	    {
	        if (count[i] == count[secondMax])            //第二大用500标记
	            count[i] = 1000;
	    }
	    for (int i = 0;str[i]!='\0';++i)
	    {
	        if (count[str[i] - 65] == 1000)                //找到第一个第二大的，输出
	        {
	            cout<<char(str[i])<<"+"<<char(str[i]+32)<<":"<<num;
	            break;
	        }
	    }



	    /*//为了知道拍完序之后原字母是哪个，初始化一组数组
	char alpBet[26] = { 0 };
	for (int i = 0; i < 26; i++)
		alpBet[i] = 65 + i;

	//对count排序，连同alpbet一起进行排序，找出第二多的字母都有哪些？？？？？排序有问题？？？？不知道问题出在哪里？？？
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j < 26 - i; j++) {
			if (count[j - 1] < count[j]) {
				int temp = count[j - 1];
				count[j - 1] = count[j];
				count[j] = temp;
				char tempChar = alpBet[i];
				alpBet[i] = alpBet[i - 1];
				alpBet[i - 1] = tempChar;

			}
		}
	}
	int second = 0;
	for (int i = 0; i < 26; i++) {
		if (count[i] < count[0]) {
			second = count[i];
			break;
		}
	}

	//排序完毕，输出结果
	for (int i = 0; str[i] != '\0'; ++i) {
		if (count[str[i] - 65] == second)                //找到第一个第二大的，输出
				{
			cout << char(str[i]) << "+" << char(str[i] + 32) << ":" << second;
		}
	}
*/
	return 0;
}

