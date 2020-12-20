/*
 * racing.cpp
 *
 *  Created on: 2016年11月22日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main0(){
	int best;
	for(best=1;best<=4;best++){
		bool a=(best==2);
		bool b=(best==4);
		bool c=!(best==3);
		bool d=!b;
		if(a+b+c+d!=1)
			continue;//不符合只有1位专家说对的条件
		cout<<best<<endl;
		if(a==1)
			cout<<"A"<<endl;
		else if(b==1)
			cout<<"B"<<endl;
		else if(c==1)
			cout<<"C"<<endl;
		else
			cout<<"D"<<endl;
	}
	return 0;
}


