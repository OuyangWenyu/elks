/*
 * ful.cpp
 *
 *  Created on: 2016年12月5日
 *      Author: asus
 */

#include <iostream>
using namespace std;
int ind(int a,int l,int h){
	return a<l?l:(a>h?h:a);
}
int main() {
	int n;
	cin >> n;
	char c[n][n];
	int a[n][n];
	int flag[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			flag[i][j]=0;
			if(c[i][j]=='.')
				a[i][j]=0;
			else if(c[i][j]=='#')
				a[i][j]=-1;
			else{
				a[i][j]=1;
				flag[i][j]=1;
			}
		}
	}
	int m;
	cin >> m;
	for(int i=0;i<m-1;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(flag[j][k]==1 && a[j][k]==1){
					a[ind(j-1,0,n-1)][k]=(a[ind(j-1,0,n-1)][k]>=0)?1:-1;
					a[ind(j+1,0,n-1)][k]=(a[ind(j+1,0,n-1)][k]>=0)?1:-1;
					a[j][ind(k-1,0,n-1)]=(a[j][ind(k-1,0,n-1)]>=0)?1:-1;
					a[j][ind(k+1,0,n-1)]=(a[j][ind(k+1,0,n-1)]>=0)?1:-1;
				}
			}
		}
		for(int l=0;l<n;l++){
			for(int ll=0;ll<n;ll++){
				if(a[l][ll]==1)
					flag[l][ll]=1;
				else
					flag[l][ll]=0;
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum=sum+(a[i][j]==1?1:0);
		}
	}
	cout<<sum<<endl;
	return 0;
}

