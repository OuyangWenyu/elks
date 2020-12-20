/*
 * secondnetwork.cpp
 *
 *  Created on: 2017年1月20日
 *      Author: asus
 */

#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int mainNetwork()
{
    int count1[26] = { 0 };
    char a[1000];
    cin.getline(a, 1000);
    //cout << isChar((a + 2));
    //cout << strlen(a)<<endl;
    for (int i = 0; i < strlen(a);++i)
    {
        if (a[i] >= 65 && a[i] <= 90)        //upper character
            count1[a[i] - 65]++;
        else if (a[i] >= 97 && a[i] <= 122)        //lower character to upper character
        {
            count1[a[i] - 97]++;
            a[i] -= 32;
        }
    }
    int firstMax = 0, secondMax = 0;
    for (int i = 0; i < 26;++i)
    {
        if (count1[firstMax] <= count1[i])        //找最大
            firstMax = i;
    }
    for (int i = 0;i < 26;++i)
    {
        if (count1[i] == count1[firstMax])            //最大清零
            count1[i] = 0;
    }
    for (int i = 0;i < 26;++i)
    {
        if (count1[secondMax] <= count1[i])            //找第二大（最大已经清零所以第二大其实是最大）
            secondMax = i;
    }
    int num = count1[secondMax];
    for (int i = 0;i < 26;++i)
    {
        if (count1[i] == count1[secondMax])            //第二大用500标记
            count1[i] = 500;
    }
    for (int i = 0;i < strlen(a);++i)
    {
        if (count1[a[i] - 65] == 500)                //找到第一个第二大的，输出
        {
            //printf("%c+%c:%d", a[i], a[i] + 32, num);
            cout<<char(a[i])<<"+"<<char(a[i]+32)<<":"<<num;
            return 0;
        }
    }
    return 0;
}


