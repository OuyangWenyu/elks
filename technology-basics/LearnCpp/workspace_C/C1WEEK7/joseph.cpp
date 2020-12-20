/*
 * joseph.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: asus
 */

#include <iostream>
using namespace std;

//一共最多有300只猴子
int succedent[300];//这个数组用于保存一个猴子后一位是谁，
//比如“next[5]的值是7”就是说5号猴子的下一位是7号猴子，6号猴子已经在之前退出了。
int precedent[300];//这个数组用于保存一个猴子前一位是谁，用法和上面的类似

int main1(){
	int n,m;
	while(true){
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		for(int i=0;i<n-1;i++){
			succedent[i]=i+1;
			precedent[i+1]=i;
		}
		succedent[n-1]=0;
		precedent[0]=n-1;

		int current=0;
		while(true){
			//如果一共要报m次号，那么取m-1次succedent之后就是需要退出的那只猴子
			for(int count=0;count<m-1;count++)
				current=succedent[current];

			int pre=precedent[current];
			int suc=succedent[current];
			//让current号猴子退出很简单，就是把前一位的“下一位”指向current的下一位，
			//下一位的“前一位”指向current的前一位就好了
			succedent[pre]=suc;
			precedent[suc]=pre;
			if(pre==suc){
				//如果只剩下两个了，那么每个人的前位和后位就是同一个了。
				//current是退出的，那么另一个就是剩下的。
				//我们的序号是从0编号的，输出时要加一
				cout<<pre+1<<endl;
				break;
			}
			current=suc;
		}
	}
	return 0;
}


