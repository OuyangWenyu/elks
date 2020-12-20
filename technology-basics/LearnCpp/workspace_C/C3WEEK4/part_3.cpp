/*
 * part_3.cpp
 *
 *  Created on: 2017年4月9日
 *      Author: asus
 */
#include <iostream>
using namespace std;
// 在此处补充你的代码

class Array2 { //二维数组实际上是一维数组的一维数组
public:
private:
	int m_row;
	int m_col;
	int *m_data;
public:
	Array2() :
			m_row(0), m_col(0) {
		m_data=NULL;
	}

	Array2(int row, int col) :
			m_row(row), m_col(col) {
		m_data = new int[m_row * m_col];
	}

	~Array2() {
		if (m_data != NULL) {
			delete[] m_data;
			m_data = NULL;
		}
	}

	int getRow(){return m_row;}
	int getCol(){return m_col;}
	// 返回二维数组的第 k 行地址，注意加上 const 因为数组地址是不可变的
	int * const operator[](int k) {
		return &m_data[k * m_col];
	}

	int operator ()(int i, int j) {
		return m_data[i * m_col + j];
	}

	void operator = (Array2 matrix){
		m_row=matrix.getRow();
		m_col=matrix.getCol();
		m_data=new int[m_row * m_col];
		for(int i=0;i<m_row * m_col;i++){
			m_data[i]=matrix.m_data[i];
		}
	}
};
int main3() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;
	b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}

