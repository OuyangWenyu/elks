/*
 * applebug.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main2(){
	int n,x,y;
	cin>>n>>x>>y;
	int result=n-((int)y/x+((y%x>0)?1:0));
	if(result>0)
		cout<<result;
	else
		cout<<0;
	return 0;
}


