/*
 * selfdivision.cpp
 *
 *  Created on: 2016年11月23日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=10;i<n+1;i++){
		int n10=i/10;
		int n1=i-n10*10;
		if(i%(n10+n1)==0)
			cout<<i<<endl;
	}
	return 0;
}


