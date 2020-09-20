//============================================================================
// Name        : C3WEEK2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : 在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。
//============================================================================
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Student {
private:
	char name[30];
	unsigned int age;
	char id[30];
	unsigned int grade1;
	unsigned int grade2;
	unsigned int grade3;
	unsigned int grade4;
public:
	unsigned int avg();
	void input();
	void output();
};


unsigned int Student::avg() {
	return (unsigned int) (grade1 + grade2 + grade3 + grade4) / 4;
}

void Student::input() {
	char str1[30];
	cin.getline(str1, 30, ',');
	strcpy(name, str1);
	char str2[30];
	cin.getline(str2, 30, ',');
	age=atoi(str2);
	char str3[30];
	cin.getline(str3, 30, ',');
	strcpy(id, str3);
	char str4[30];
	cin.getline(str4, 30, ',');
	grade1=atoi(str4);
	char str5[30];
	cin.getline(str5, 30, ',');
	grade2=atoi(str5);
	char str6[30];
	cin.getline(str6, 30, ',');
	grade3=atoi(str6);
	char str7[30];
	cin.getline(str7, 30);
	grade4=atoi(str7);
}
void Student::output(){
	cout<<name<<","<<age<<","<<id<<","<<avg()<<endl;
}

int main() {
	Student s;
	s.input();
	s.output();
	return 0;
}
