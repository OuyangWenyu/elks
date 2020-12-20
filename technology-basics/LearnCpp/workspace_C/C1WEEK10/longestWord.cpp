/*
 * longestWord.cpp
 *
 *  Created on: 2016年11月27日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main3() {
	char s[500];
	cin.getline(s,500);
	int i=0;
	int j=0;
	int temp=0;
	int longest=0;
	int longestBeginIndex=0;
	while(true){
		if(s[i]==' ' || s[i]=='.'){
			temp=i-j;
			if(temp>longest){
				longest=temp;
				longestBeginIndex=j;
			}
			j=i+1;
		}
		if(s[i]=='.')
			break;
		i++;
	}
	for(int k=longestBeginIndex;k<longestBeginIndex+longest;k++)
		cout<<s[k];
	return 0;
}


