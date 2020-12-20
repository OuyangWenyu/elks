/*
 * localMax.cpp
 *
 *  Created on: 2017年1月20日
 *      Author: asus
 */
#include <iostream>
using namespace std;
int main4() {
	//找到这样的数，集合中其它所有数，与它相比，不会出现x、y同时大于它的x、y的情况
	//按x轴坐标从小到大排序，那就直接先按照x排序，然后再逐个判断
	int n;
	cin >> n;
	int points[n][2];
	for (int i = 0; i < n; i++) {
		cin >> points[i][0] >> points[i][1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n - i; j++) {
			if (points[j - 1][0] > points[j][0] || ((points[j - 1][0] == points[j][0])&&
					(points[j - 1][1] > points[j][1]))) {
				int tempX = points[j - 1][0];
				points[j - 1][0] = points[j][0];
				points[j][0] = tempX;
				int tempY = points[j - 1][1];
				points[j - 1][1] = points[j][1];
				points[j][1] = tempY;
			}
		}
	}

	//要注意x轴坐标相等的情况，这种情况放在排序的时候解决
	for(int i=0;i<n-1;i++){
		bool maxY=true;
		for(int j=i+1;j<n;j++){
			if(points[i][1] <= points[j][1]){//这应该有个等号
				maxY=false;
				break;
			}
		}
		if(maxY){
			cout<<"("<<points[i][0]<<","<<points[i][1]<<")"<<",";
		}
	}
	cout<<"("<<points[n-1][0]<<","<<points[n-1][1]<<")";
	return 0;
}

