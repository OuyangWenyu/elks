/*
 * fractionSum.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main2(){
	int n;
	cin>>n;
	int sumn=0,sumd=1;//储存结果，sumn/sumd
	while(n--){
		int num,deno;
		char slash;//专门用来吃掉/的
		cin>>num>>slash>>deno;
		//先相加a/b+c/d=(a*d+c*b)/(b*d)
		sumn=sumn*deno+num*sumd;
		sumd=sumd*deno;
	}
	//后约分
	//先求最大公约数gcd，这里用的是欧几里得法
	int a=sumd,b=sumn,c;
	while(a!=0){
		c=a;a=b%a;b=c;
	}
	int gcd=b;
	//分子分母同时除以gcd就可以完成约分
	sumd/=gcd;
	sumn/=gcd;
	if(sumd>1)
		cout<<sumn<<'/'<<sumd<<endl;
	else
		cout<<sumn<<endl;
	return 0;
}


