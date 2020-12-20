/*
 * part_4.cpp
 *
 *  Created on: 2017年5月21日
 *      Author: asus
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
class Countclass {
	int a0;
	int a1;
	int a2;
	int a3;
	int a4;
	int a5;
public:
	Countclass(int a, int b, int c, int d, int e, int f) :
			a0(a), a1(b), a2(c), a3(d), a4(e), a5(f) {
	}
};
//先构造大整数类，然后对对象进行运算符重载，对数组直接进行重载是不被允许的，先把main函数写好，再写重载函数
class BigInteger {
private:
	int size;
	int * array;
public:
	BigInteger(int s, int* a) :
			size(s), array(a) {
	}
	BigInteger(const BigInteger & b) {
		size = b.size;
		array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = b.array[i];
	}
	int getSize(){return size;}
	int * getArray(){return array;}
	//两个位数一样的数组每一位相加，需要进位向上一位进一
	int plus(int* a, int* b, int *c, int index, int length) {
		if (index == length - 1) {
			int temp = (*(a + index)) + (*(b + index));
			*(c + index) = ((temp >= 10) ? (temp - 10) : temp);
			return ((temp >= 10) ? 1 : 0);
		}
		int digit = *(a + index) + *(b + index)
				+ plus(a, b, c, index + 1, length);
		if (digit >= 10) {
			*(c + index) = digit - 10;
			return 1;
		} else {
			*(c + index) = digit;
			return 0;
		}
	}
	BigInteger operator +(const BigInteger & b) {
		int length = size;
		int * ca = new int[length];
		int firstDigit = plus(array, b.array, ca, 0, length);
		//最高为不为0，需要开辟一位的新空间，把1存进来
		if (firstDigit == 1) {

		}
		BigInteger c(length, ca);
		return c;
	}

	//两个位数一样的数组每一位相减，需要借位向上一位借一，即返回-1
	int minus(int* a, int* b, int *c, int index, int length) {
		if (index == length - 1) {
			int temp = (*(a + index)) - (*(b + index));
			*(c + index) = ((temp < 0) ? (temp + 10) : temp);
			return ((temp < 0) ? -1 : 0);
		}
		int digit = (*(a + index)) - (*(b + index))
				+ minus(a, b, c, index + 1, length);
		if (digit < 0) {
			*(c + index) = digit + 10;
			return -1;
		} else {
			*(c + index) = digit;
			return 0;
		}
	}

	BigInteger operator -(const BigInteger & b) {
		int length = size;
		int * ca = new int[length];
		int firstDigit = minus(array, b.array, ca, 0, length);
		//最高位为-1，需要让最高位的数减10
		if (firstDigit == -1) {
			delete[] ca;
			ca = new int[length];
			firstDigit = minus(b.array, array, ca, 0, length);
			int flag = 0;
			while (*(ca + flag) == 0)
				flag++;
			*(ca + flag) = 0 - (*(ca + flag));
		}
		BigInteger c(length, ca);
		return c;
	}

	//乘以个位数，相当于几个数相加
	BigInteger multiply(int num) {
		BigInteger result(*this);
		if (num == 0) {
			for (int i = 0; i < size; i++) {
				result.array[i] = 0;
			}
		} else {
			for (int i = 0; i < num - 1; i++) {
				result = *this + result;
			}
		}
		return result;
	}
	//乘以10的n次方
	BigInteger multiply(const BigInteger & b) {
		BigInteger result(*this);
		int flag = 0;
		int num = 0;
		while (*(b.array + flag) == 0)
			flag++;
		if (flag < b.size)
			num = b.array[flag];
		result = result.multiply(num);
		if (num == 0)
			return result;
		int length = b.size - flag - 1;
		for (int i = 0; i < result.size - length; i++) {
			result.array[i] = result.array[i + length];
		}
		for (int i = result.size - length; i < result.size; i++) {
			result.array[i] = 0;
		}
		//Countclass cc2(result.getArray()[0],result.getArray()[1],result.getArray()[2],result.getArray()[3],result.getArray()[4],result.getArray()[5]);
		return result;
	}
	BigInteger operator *(const BigInteger & b) {
		int flag = 0;
		while (*(b.array + flag) == 0)
			flag++;
		int tempArray[this->size] { 0 };
		BigInteger c(this->size, tempArray);
		for (int i = flag; i < size; i++) {
			c = (this->multiply(b)) + c;
			*(b.array + flag) = 0;
			flag++;
		}
		return c;
	}
	bool operator ==(const BigInteger & b) {
		bool sizeEqual = (this->size == b.size);
		bool arrayEqual = true;
		for (int i = 0; i < this->size; i++) {
			if (this->array[i] != b.array[i]) {
				arrayEqual = false;
				break;
			}
		}
		return sizeEqual && arrayEqual;
	}
	bool operator >(const BigInteger & b) {
		bool bigger = false;
		for (int i = 0; i < this->size; i++) {
			if (this->array[i] == b.array[i])
				continue;
			else if (this->array[i] > b.array[i])
				return true;
			else
				break;
		}
		return bigger;
	}
	bool operator >=(const BigInteger & b) {
		return *this == b || *this > b;
	}
	bool operator <(const BigInteger & b) {
		bool smaller = false;
		for (int i = 0; i < this->size; i++) {
			if (this->array[i] == b.array[i])
				continue;
			else if (this->array[i] < b.array[i])
				return true;
			else
				break;
		}
		return smaller;
	}
	bool operator <=(const BigInteger & b) {
		return *this == b || *this < b;
	}
	BigInteger operator /(BigInteger & b) {
		int length = this->size;
		int tempArray[length] { 0 };
		BigInteger c(length, tempArray);
		BigInteger dividend(c); //被除数，每次取一位
		BigInteger remainder(c); //余数
		for (int i = 0; i < length; i++) {
			int tempArray1[length] { 0 };
			BigInteger temp(length, tempArray1); //余数更新
			temp.array[length - 1] = this->array[i];
			dividend = remainder.multiply(10) + temp;
			Countclass cc1(remainder.array[0], remainder.array[1],
					remainder.array[2], remainder.array[3],
					remainder.array[4], remainder.array[5]);
			Countclass cc2(dividend.array[0], dividend.array[1],
					dividend.array[2], dividend.array[3],
					dividend.array[4], dividend.array[5]);
			for (int j = 0; j < 10; j++) {
				if (b.multiply(j) <= dividend && b.multiply(j + 1) > dividend) {
					*(c.array + i) = j;
					remainder=dividend- b.multiply(j);
					Countclass cc3(c.array[0], c.array[1],
							c.array[2], c.array[3], c.array[4],
							c.array[5]);
					break;
				}
			}
		}
		BigInteger result(c); //被除数，每次取一位
		return result;
	}
};

int main4() {
	const int LENGTH = 100;
	char as[LENGTH];
	char bs[LENGTH];
	char o[1];
	cin.getline(as, LENGTH + 1);
	cin.getline(o, 2);
	cin.getline(bs, LENGTH + 1);
	int ai[LENGTH] = { 0 };
	int bi[LENGTH] = { 0 };
	int i = 0;
	int alength = 0;
	int blength = 0;
	while (as[i] != '\0') {
		alength++;
		i++;
	}
	i = 0;
	while (bs[i] != '\0') {
		blength++;
		i++;
	}
	i = 0;
	while (as[i] != '\0') {
		char * temp = new char[1];
		*temp = as[alength - 1 - i];
		*(ai + LENGTH - 1 - i) = atoi(temp);
		i++;
	}
	i = 0;
	while (bs[i] != '\0') {
		char * temp = new char[1];
		*temp = bs[blength - 1 - i];
		*(bi + LENGTH - 1 - i) = atoi(temp);
		i++;
	}
	BigInteger c(LENGTH, NULL);
	BigInteger a(LENGTH, ai);
	BigInteger b(LENGTH, bi);
	switch (*o) {
	case '+':
		c = a + b;
		break;
	case '-':
		c = a - b;
		break;
	case '*':
		c = a * b;
		break;
	case '/':
		c = a / b;
		break;
	}
	//从第一位不为0的地方开始输出，设置标志位，从标志位开始输出
	int flag = 0;
	while (*(c.getArray() + flag) == 0)
		flag++;
	if (flag == c.getSize())
		cout << 0;
	else {
		for (int i = flag; i < c.getSize(); i++)
			cout << *(c.getArray() + i);
	}
	cout << endl;
	return 0;
}

