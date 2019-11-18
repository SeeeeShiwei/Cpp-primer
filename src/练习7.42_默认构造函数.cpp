//============================================================================
// Name        : booksotre_test.cpp
// Author      : Sesen
// Version     :
// Copyright   : Your copyright notice
// Description : 练习7.43
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class NoDefault
{
public:
	NoDefault(int i):number(i) {
		cout << "NoDefault 构造函数: " << number << endl;
	}

private:
	int number;
};

class C
{
public:
	C():CC(1) {
		cout << "C 默认构造函数" << endl;
	};
private:
	NoDefault CC;
};
int main() {
	C test;
	return 0;
}

/*
NoDefault 构造函数: 1
C 默认构造函数
 */
