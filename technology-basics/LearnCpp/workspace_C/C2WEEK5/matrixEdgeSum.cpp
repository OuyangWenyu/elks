/*
 * matrixEdgeSum.cpp
 *
 *  Created on: 2017年1月13日
 *      Author: asus
 */

#include <iostream>
using namespace std;

int main1(){
	int k;
	cin>>k;
	int sums[k];
	for(int temp=0;temp<k;temp++){
		int m,n;
		cin>>m>>n;
		int a[m][n];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}

		int firstCol=0;
		for(int i=0;i<m;i++)
			firstCol=firstCol+(**(a+i));

		int lastCol=0;
		for(int i=0;i<m;i++)
			lastCol=lastCol+*(a[i]+n-1);

		int firstRow=0;
		for(int i=0;i<n;i++)
			firstRow=firstRow+*(a[0]+i);

		int lastRow=0;
		for(int i=0;i<n;i++)
			lastRow=lastRow+*(a[m-1]+i);

		if(m==1)
			sums[temp]=firstRow;
		else if(n==1)
			sums[temp]=firstCol;
		else
			sums[temp]=firstCol+lastCol+firstRow+lastRow-a[0][0]-a[m-1][0]-a[0][n-1]-a[m-1][n-1];

	}

	for(int i=0;i<k;i++)
		cout<<sums[i]<<endl;
}


