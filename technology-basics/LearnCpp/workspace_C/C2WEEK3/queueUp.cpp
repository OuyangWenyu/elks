/*
 * queueUp.cpp
 *
 *  Created on: 2016年12月8日
 *      Author: asus
 */

#include <iostream>
#include <cstring>
using namespace std;
bool b;
int f(char str[], char c1,char c2,int s) {
	if(strlen(str)==0){
		return (b= true,-1);
	}
	else{
		if(str[s]==c1){
			int n;
			(b,n)=f(str,c1,c2,s+1);
			if(b==false)
				return (b=false,n);
			else{
				if(str[n]==c2){
					cout<<s<<" "<<n<<endl;
					return f(str,c1,c2,n+1);
				}
				else
					return (b=false,n);
			}
		}
		else{
			return (b=true,s);
		}
	}
}

int main3() {
	char str[100];
	cin.getline(str,100);
	int i=1;
	while(str[i]==str[0]){
		i++;
	}
	f(str,str[0],str[i], 0);
	return 0;
}

