/*
 * sum.cpp
 *
 *  Created on: 2016年11月16日
 *      Author: asus
 */
#include <iostream>
using namespace std;

int main2(){
	int m,n,result=0;
	cin>>m>>n;
	while(m<=n){
		if(m%2==1)
		result+=m;
		m++;
	}
	cout<<result<<endl;
	return 0;
}




