/*
 * twoDimArrTraverse.cpp
 *
 *  Created on: 2017年1月13日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main2(){
	int row,col;
	cin>>row>>col;
	int a[row][col];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>a[i][j];
		}
	}
	int i=0;int j=0;
	for(int sum=0;sum<row+col-1;sum++){
		while(i+j<=sum){
			cout<<a[i][j]<<endl;
			if(i+1>sum || i+1>=row || j-1<0)
				break;
			else{
				i++;
				j--;
			}
		}
		i=0;j=sum+1;
		while(j>=col){
			i++;
		    j--;
		}
	}
}


