/*
 * mountaintop.cpp
 *
 *  Created on: 2017年1月17日
 *      Author: asus
 */

#include <iostream>
using namespace std;
int ccb(int num,int lower,int upper){
	if(num<lower)
		num=lower;
	else if(num>upper)
		num=upper;
	return num;
}
bool top(int *h,int m,int n,int i,int j){
	if(*(h+i*n+j)>=*(h+ccb(i+1,0,m-1)*n+j) &&
			*(h+i*n+j)>=*(h+ccb(i-1,0,m-1)*n+j) &&
			*(h+i*n+j)>=*(h+i*n+ccb(j+1,0,n-1)) &&
			*(h+i*n+j)>=*(h+i*n+ccb(j-1,0,n-1)))
		return true;
	else
		return false;
}

int main(){
	int m,n;
	cin>>m>>n;
	int height[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>height[i][j];
		}
	}
	for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(top(*height,m,n,i,j)){
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	return 0;
}


