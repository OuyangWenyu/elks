/*
 * second.cpp
 *尝试一下结构体，这个结果有些样例测试不通过，因此还是用ASCII码的知识以及数组去解决这个题
 *  Created on: 2017年1月19日
 *      Author: asus
 */
#include <iostream>
using namespace std;

struct charNum{
	char ch;
	char CH;
	int num;
	int when;
};

void swap(charNum * a,charNum * b){
	char TEMP=a->CH;
	a->CH=b->CH;
	b->CH=TEMP;
	char temp=a->ch;
	a->ch=b->ch;
	b->CH=temp;
	int temp1=a->num;
	a->num=b->num;
	b->num=temp1;
	int temp2=a->when;
	a->when=b->when;
	b->when=temp2;
}

int mainError(){
	char str[501];
	cin.getline(str,501);
	int i=0;
	charNum cns[26]={{'a','A',0,-1},{'b','B',0,-1},{'c','C',0,-1},{'d','D',0,-1},
			{'e','E',0,-1},{'f','F',0,-1},{'g','G',0,-1},{'h','H',0,-1},
			{'i','I',0,-1},{'j','J',0,-1},{'k','K',0,-1},{'l','L',0,-1},
			{'m','M',0,-1},{'n','N',0,-1},{'o','O',0,-1},{'p','P',0,-1},
			{'q','Q',0,-1},{'r','R',0,-1},{'s','S',0,-1},{'t','T',0,-1},
			{'u','U',0,-1},{'v','V',0,-1},{'w','W',0,-1},{'x','X',0,-1},
			{'y','Y',0,-1},{'z','Z',0,-1}};
	while(str[i]!='\0'){
		for(int j=0;j<26;j++){
			if((cns+j)->ch==str[i] || (cns+j)->CH==str[i]){
				((cns+j)->num)++;
				if((cns+j)->when==-1)
					(cns+j)->when=i;
				break;
			}
		}
		i++;
	}
	for(int i=0;i<26;i++){
		for(int j=1;j<26-i;j++){
			if((cns+j-1)->num < (cns+j)->num){
				swap(cns+j-1,cns+j);
			}else if((cns+j-1)->num>0 && ((cns+j-1)->num == (cns+j)->num)){
				if((cns+j-1)->when > (cns+j)->when)
					swap(cns+j-1,cns+j);
			}
		}
	}
	for(int i=1;i<26;i++){
		if((cns+i)->num<cns->num){
			cout<<(cns+i)->CH<<"+"<<(cns+i)->ch<<":"<<(cns+i)->num;
			break;
		}
	}

	return 0;
}

