/*
 * basePairs.cpp
 *
 *  Created on: 2017年1月17日
 *      Author: asus
 */
#include <iostream>
#include <cstring>
using namespace std;

int main2(){
	int n;
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++){
		char input[256];
		cin.getline(input,256);
		for(size_t j=0;j<strlen(input);j++){
			if(input[j]=='A')
				cout<<"T";
			else if(input[j]=='T')
				cout<<"A";
			else if(input[j]=='C')
				cout<<"G";
			else
			    cout<<"C";
		}
		cout<<endl;
	}
	return 0;
}



