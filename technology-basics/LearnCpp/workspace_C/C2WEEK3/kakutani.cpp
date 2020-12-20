/*
 * kakutani.cpp
 *
 *  Created on: 2016年12月8日
 *      Author: asus
 */

#include <iostream>
using namespace std;

void conjecture(int n){
	if(n==1)
		cout<<"End"<<endl;
	else{
		if(n%2==0)
			cout<<n<<"/2="<<(n/2)<<endl;
		else
			cout<<n<<"*3+1="<<(n*3+1)<<endl;
		n=(n%2==0)?(n/2):(n*3+1);
		conjecture(n);
	}
}

int main2(){
	int n;
	cin>>n;
	conjecture(n);
	return 0;
}


